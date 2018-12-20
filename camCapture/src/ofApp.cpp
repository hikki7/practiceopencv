#include "ofApp.h"
using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofBackground(0);
    cam.initGrabber(ofGetWidth(),ofGetHeight());
    
    //輪郭検出の値の指定
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(200);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()){
        //閾値の指定(0~255までの値しか持たない)
        contourFinder.setThreshold(ofMap(mouseX, 0, ofGetWidth(), 0, 255));
        //輪郭の検出
        contourFinder.findContours(cam);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofScale(-1, 1);
    //cam.draw(0, 0);
    ofSetColor(255);
    //ofScale(-1,1);
    contourFinder.draw();
}

