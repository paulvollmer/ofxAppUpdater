/**
 * autoUpdate_example is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * autoUpdate_example is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * autoUpdate_example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with autoUpdate_example; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.20
 * @version     1.0.1b
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofLogToConsole();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	
	// We store our updater Variables here (FOR THE CURRENT APPLICATION RELEASE).
	// For our ofxAppUpdater::init method we need the following variables:
	// - An Application Release version (string)
	// - A Server-URL who will be stored the Appcast.xml file.
	// - A boolean that set the internetConnection.
	//   If it's true, the ofxAppUpdater class start the update process.
	//
	// KEEP CLEAN THE FOLLWING VARIABLES TO UPDATE AND RELEASE OUR SOFTWARE SAVELY.
	// FOR THIS YOU CAN USE THE [semantic versioning]( http://semver.org ) STYLE.
	// 
	// The appcast.xml and release.zip are stored at github repository.
	updater.init("2.0.0",
				 "http://dl.dropbox.com/u/2874680/appcast_3.xml",
				 true);
	
	updater.autoUpdate();
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	/*ofBackground(ofColor::white);
	
	ofEnableAlphaBlending();
	ofSetColor(ofColor::black, 30);
	ofRect(10, 10, ofGetWidth()-20, ofGetHeight()-20);
	ofDisableAlphaBlending();
	
	ofSetColor(ofColor::black);
	ofDrawBitmapString("Current Version: "+updater.currentVersion+", latest Version: "+updater.latestVersion, 70, 70);
	ofDrawBitmapString("Message:", 70, 90);
	ofDrawBitmapString(updater.message, 70, 110);*/
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::exit(){
	
}
