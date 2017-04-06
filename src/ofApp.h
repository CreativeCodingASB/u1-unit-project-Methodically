#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
    
        ofLight pointLight;
        ofLight pointLight2;
        ofLight pointLight3;
        ofColor color[6];
        ofEasyCam cam;

        ofBoxPrimitive box[8000];
        void Box(int recurse, int posX, int posY, int posZ, int size);
        int boxNum=0;
};
