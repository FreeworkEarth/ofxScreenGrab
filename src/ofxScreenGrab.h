/*
 Screen capture utility for recording your laptop screen. OSX only.
 Based on code found from this discussion: 
 http://forum.openframeworks.cc/t/grabbing-from-the-screen-osx/2946
*/


#pragma once

#include "ofMain.h"
#include "macGlutfix.h"

class ofxScreenGrab
{
public:
    void setup(int width, int height);
    void grabScreen(int x, int y);
    void grabScreen() {grabScreen(0, 0);}
    void draw(int x, int y);
    ofTexture* getTexture() {return &tex;}

private:
    int width, height;
    ofTexture tex;

};