//
//  ofxAnalogClock.cpp
//  ofxAnalogClock
//
//  Created by James Bentley on 11/6/15.
//
//

#include "ofxAnalogClock.h"

Clock::Clock() {
    radius = 0;
    bounds = ofRectangle(0, 0, 0 ,0);
    clockImgLoaded = hourImgLoaded = minuteImgLoaded = secondImgLoaded = false;
}

Clock::Clock(int radius) {
    this->radius = radius;
    bounds = ofRectangle(0, 0, this->radius, this->radius);
    clockImgLoaded = hourImgLoaded = minuteImgLoaded = secondImgLoaded = false;
}

Clock::Clock(ofRectangle bounds) {
    this->bounds = bounds;
    this->radius = MIN(bounds.getWidth(), bounds.getHeight());
    clockImgLoaded = hourImgLoaded = minuteImgLoaded = secondImgLoaded = false;
}

Clock::~Clock() {
    
}

void Clock::update(int sec, int min, int hour) {
    secondsAngle = 6 * sec - 90;
    minutesAngle = 6 * min - 90;
    hoursAngle = 30 * hour + (min / 2) - 90;
}

void Clock::update() {
    int hour = ofToInt(ofGetTimestampString("%H"));
    int min = ofToInt(ofGetTimestampString("%M"));
    int sec = ofToInt(ofGetTimestampString("%S"));
    secondsAngle = 6 * sec - 90;
    minutesAngle = 6 * min - 90;
    hoursAngle = 30 * hour + (min / 2) - 90;
}

string Clock::getTime() {
    return ofGetTimestampString();
}

void Clock::loadClockImg(std::string clockImgLink) {
    this->clockImgLoaded = clockImg.loadImage(clockImgLink);
}

void Clock::loadClockImg(ofImage clockImg) {
    this->clockImgLoaded = true;
    this->clockImg = clockImg;
}

void Clock::loadHourImg(std::string hourImgLink) {
    this->hourImgLoaded = hourImg.loadImage(hourImgLink);
}

void Clock::loadHourImg(ofImage hourImg) {
    this->hourImgLoaded = true;
    this->hourImg = hourImg;
}

void Clock::loadMinImg(std::string minuteImgLink) {
    this->minuteImgLoaded = minuteImg.loadImage(minuteImgLink);
}

void Clock::loadMinImg(ofImage minuteImg) {
    this->minuteImgLoaded = true;
    this->minuteImg = minuteImg;
}

void Clock::loadSecImg(std::string secondImgLink) {
    this->secondImgLoaded = secondImg.loadImage(secondImgLink);
}

void Clock::loadSecImg(ofImage secondImg) {
    this->secondImgLoaded = true;
    this->secondImg = secondImg;
}

void Clock::display(int x, int y) {
    
    // Draw the clockface
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(x, y);
    ofSetColor(255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetCircleResolution(20);
    if(clockImgLoaded) {
        clockImg.draw(0, 0, bounds.getWidth(), bounds.getHeight());
    } else {
        ofCircle(0, 0, radius);
    }
    
    // Draw the hour hand
    ofPushMatrix();
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofRotateZ( hoursAngle );
    if(hourImgLoaded) {
        ofTranslate(0, -hourImg.getHeight()/2);
        hourImg.draw(0, 0);
    } else {
        ofSetHexColor(0x000000);
        ofTranslate(0, -radius*0.1/2);
        ofRect(0, 0, radius*0.6, radius*0.1);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    // Draw the minute hand
    ofRotateZ( minutesAngle );
    if(minuteImgLoaded) {
        ofTranslate(0, -minuteImg.getHeight()/2);
        minuteImg.draw(0, 0);
    } else {
        ofSetHexColor(0x000000);
        ofTranslate(0, -radius*0.05/2);
        ofRect(0, 0, radius*0.8, radius*0.05);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    // Draw the second hand
    ofRotateZ( secondsAngle );
    if(secondImgLoaded) {
        ofTranslate(0, -secondImg.getHeight()/2);
        secondImg.draw(0, 0);
    } else {
        ofSetHexColor(0x000000);
        ofTranslate(0, -radius*0.01/2);
        ofRect(0, 0, radius*0.9, radius*0.01);
    }
    ofPopMatrix();
    
    ofPopMatrix();
    ofPopStyle();
}

