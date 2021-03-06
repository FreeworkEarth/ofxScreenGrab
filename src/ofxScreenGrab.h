/*
 Screen capture utility for recording your laptop screen. OSX only.
 Based on code found from this discussion: 
 http://forum.openframeworks.cc/t/grabbing-from-the-screen-osx/2946
*/


#pragma once

#include "ofMain.h"
#ifndef _WIN32
#include "macGlutfix.h"
#else
#include <iostream>
#include <ole2.h>
#include <olectl.h>
#include "ofMain.h"
#include <time.h>
#include <omp.h>
#endif
class ofxScreenGrab
{
public:
    void setup(int width, int height, bool retina=false);
    void grabScreen(int x, int y);
    void grabScreen() {grabScreen(0, 0);}
    void draw(int x, int y, int w, int h);
    void draw(int x, int y) {draw(x, y, width, height);}
    ofTexture& getTextureReference() {return tex;}
    int getWidth() {return width * rx;}
    int getHeight() {return height * rx;}

#ifdef _WIN32
	unsigned char * pixelsBelowWindow( int x, int y, int w, int h );
	RGBQUAD *screenPixels;
	int screen_x, screen_y;
	HBITMAP screen_bitmap;
	HDC compatible_screen_context;
	HDC screen_context;
	BITMAPINFOHEADER info;
	unsigned char * pPixels;

#endif
protected:
    int width, height;
    ofTexture tex;
    int rx;
};