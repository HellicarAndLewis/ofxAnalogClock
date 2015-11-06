//
//  Clock.h
//  OF
//
//  Created by James Bentley on 1/29/15.
//
//

#pragma once

#include "ofMain.h"

class Clock {
public:
    Clock();
    Clock(ofRectangle boundingRect);
    Clock(int radius);
    ~Clock();
    
    void update(int h, int m, int s);
    string getTime();
    void update();
    void display(int x, int y);
    void loadClockImg(std::string clockImgLink);
    void loadHourImg(std::string hourHandLink);
    void loadMinImg(std::string minuteHandLink);
    void loadSecImg(std::string secondImgLink);
    
    void loadClockImg(ofImage clockImg);
    void loadHourImg(ofImage hourHand);
    void loadMinImg(ofImage minuteHand);
    void loadSecImg(ofImage secondImg);
    
private:
    int radius;
    
    ofRectangle bounds;
    
    int h, m, s;
    
    ofImage clockImg, hourImg, minuteImg, secondImg;
    bool clockImgLoaded, hourImgLoaded, minuteImgLoaded, secondImgLoaded;
    
    float secondsAngle;
    float minutesAngle;
    float hoursAngle;
};