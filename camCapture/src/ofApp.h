#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
    //ビデオ入力
    ofVideoGrabber cam;
    //輪郭の検出
    ofxCv::ContourFinder contourFinder;
};
