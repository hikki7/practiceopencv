#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void resetBackground();
    
    ofVideoGrabber cam;
    //輪郭を探すやつ
    ofxCv::ContourFinder contourFinder;
    //背景を登録する
    ofxCv::RunningBackground background;
    ofImage thresholded;
    
    ofxPanel gui;
    //背景との差分の閾値
    ofxFloatSlider bgThresh;
    //輪郭の抽出の閾値
    ofxFloatSlider contourThresh;
    ofxButton resetBg;
		
};
