#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFullscreen(true);
    ofBackground(0);
    
    //--------------------------cvの初期設定
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(200);
    //差分の学習時間
    background.setLearningRate(900);
    //背景の閾値を20にする
    background.setThresholdValue(20);
    
    //--------------------------guiの初期設定
    resetBg.addListener(this, &ofApp::resetBackground);
    gui.setup();
    gui.add(bgThresh.setup("background thresh", 50, 0, 100));
    gui.add(contourThresh.setup("contour finder thresh",127,0,255));
    gui.add(resetBg.setup("reset background"));
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()){
        
        //背景差分画像の生成
        background.setThresholdValue(bgThresh);
        background.update(cam, thresholded);
        thresholded.update();
        
        //背景差分画像の輪郭抽出
        contourFinder.setThreshold(contourThresh);
        contourFinder.findContours(thresholded);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //差分画像の描画
    ofSetColor(255);
    thresholded.draw(0,0);
    
    //輪郭の描画
    ofSetColor(255, 0, 0);
    contourFinder.draw();
    
    //guiの描画
    gui.draw();

}

void ofApp::resetBackground(){
    background.reset();
}

