#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetVerticalSync(true);
	
	ofEnableDepthTest();
	
	cam.setDistance(100);
    
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    
    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
    
    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    
    color[0].set(255, 255, 255);   //white
    color[1].set(255, 213, 0);     //yellow
    color[2].set(0, 81, 186);      //blue
    color[3].set(0, 158, 96);      //green
    color[4].set(255, 88, 0);      //red
    color[5].set(196, 30, 58);     //orange
    
    Box(3, 0, 0, 0, 270);
}
//--------------------------------------------------------------
void ofApp::draw()
{
    cam.begin();
    
    ofEnableDepthTest();
//    ofEnableLighting();
//    pointLight.enable();
//    pointLight2.enable();
//    pointLight3.enable();
    
    float spinX = sin(ofGetElapsedTimef()*.35f);
    float spinY = cos(ofGetElapsedTimef()*.075f);
    
    ofBackground(0);
    ofPushMatrix();
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
//    ofRotateX(spinX*360);
//    ofRotateY(spinY*360);xw
    for(int i=0; i<8000; i++)
    {
        box[i].draw();
    }
    ofPopMatrix();
}
void ofApp::Box(int recurse, int posX, int posY, int posZ, int size)
{
    if(recurse>0)
    {
        Box(recurse-1, posX-size/3, posY-size/3, posZ-size/3, size/3);
        Box(recurse-1, posX, posY-size/3, posZ-size/3, size/3);
        Box(recurse-1, posX+size/3, posY-size/3, posZ-size/3, size/3);
        
        Box(recurse-1, posX-size/3, posY+size/3, posZ-size/3, size/3);
        Box(recurse-1, posX, posY+size/3, posZ-size/3, size/3);
        Box(recurse-1, posX+size/3, posY+size/3, posZ-size/3, size/3);
        
        Box(recurse-1, posX-size/3, posY-size/3, posZ+size/3, size/3);
        Box(recurse-1, posX, posY-size/3, posZ+size/3, size/3);
        Box(recurse-1, posX+size/3, posY-size/3, posZ+size/3, size/3);
        
        Box(recurse-1, posX-size/3, posY+size/3, posZ+size/3, size/3);
        Box(recurse-1, posX, posY+size/3, posZ+size/3, size/3);
        Box(recurse-1, posX+size/3, posY+size/3, posZ+size/3, size/3);
        
        Box(recurse-1, posX-size/3, posY-size/3, posZ, size/3);
        Box(recurse-1, posX-size/3, posY+size/3, posZ, size/3);
        Box(recurse-1, posX+size/3, posY-size/3, posZ, size/3);
        Box(recurse-1, posX+size/3, posY+size/3, posZ, size/3);
        
        Box(recurse-1, posX-size/3, posY, posZ-size/3, size/3);
        Box(recurse-1, posX-size/3, posY, posZ+size/3, size/3);
        Box(recurse-1, posX+size/3, posY, posZ-size/3, size/3);
        Box(recurse-1, posX+size/3, posY, posZ+size/3, size/3);
    }
    else
    {
        box[boxNum].setPosition(posX, posY, posZ);
        box[boxNum].set(size);
        
        box[boxNum].setSideColor(box[boxNum].SIDE_FRONT, color[0]);
        box[boxNum].setSideColor(box[boxNum].SIDE_BACK, color[1]);
        box[boxNum].setSideColor(box[boxNum].SIDE_LEFT, color[2]);
        box[boxNum].setSideColor(box[boxNum].SIDE_RIGHT, color[3]);
        box[boxNum].setSideColor(box[boxNum].SIDE_TOP, color[4]);
        box[boxNum].setSideColor(box[boxNum].SIDE_BOTTOM, color[5]);
        boxNum++;
    }
}









