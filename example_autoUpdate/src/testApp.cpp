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
 * @modified    2012.04.16
 * @version     1.0.1a
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofLogToConsole();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	
	// We store our updater Variables here (for the current Application Release).
	// For our ofxAppUpdater::init method we need the following variables:
	// - An Application Release version (float value)
	// - A Server-URL who will be stored the Application Release files.
	// - A versioninfo Filename
	// - A .zip Filename (this contains the latest released Application version).
	//
	// Keep clean the follwing Variables to update and release our software savely.
	// For this you can use the [ semantic versioning ]( http://semver.org ) style.
	// 
	// The versioninfo.xml and release.zip are stored at github repository.
	// https://raw.github.com/WrongEntertainment/ofxAppUpdater/master/release_storage/versioninfo_1_0_0.xml
	updater.init("1.0.1",
				 "https://raw.github.com/WrongEntertainment/ofxAppUpdater/master/release_storage/",
				 "versioninfo_1_0_1.xml",
				 "release_1_0_0.zip");
	
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
