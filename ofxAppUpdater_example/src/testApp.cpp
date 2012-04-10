/**
 * ofxAppUpdater_example is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxAppUpdater_example is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxAppUpdater_example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxAppUpdater_example; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.05
 * @version     0.1.0
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	/* Initiolize ofxUpdater class. */
	updater.init(OFXAPPUPDATER_VERSION,
				 OFXAPPUPDATER_VERSIONFILE,
				 OFXAPPUPDATER_SERVER,
				 OFXAPPUPDATER_ZIPFILE);
	/* Or use the init method which you can set your internet connection. *
	updater.init(OFXAPPUPDATER_VERSION,
				 OFXAPPUPDATER_VERSIONFILE,
				 OFXAPPUPDATER_SERVER,
				 OFXAPPUPDATER_ZIPFILE,
				 false);*/
	
	
	/*
	updater.internetConnection;
	updater.userVersion;
	updater.latestVersion;
	*/
	
	
	// TEST
	//updater.checkVersion(1, 1);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(0);
	
	/* Display our ofxAppUpdater Information. */
	int textX = 100;
	int textY = 50;
	ofSetColor(0, 255, 255);
	ofDrawBitmapString("ofxAppUpdater", textX, textY);
	textY+=20;
	
	ofSetColor(0, 255, 0);
	ofDrawBitmapString("User-Version:   " + ofToString(updater.userVersion), textX, textY);
	textY+=20;
	ofDrawBitmapString("Latest-Version: " + ofToString(updater.latestVersion), textX, textY);
	textY+=20;
	ofDrawBitmapString("Author:         " + updater.author, textX, textY);
	textY+=20;
	ofDrawBitmapString("Modified:       " + updater.modified, textX, textY);
	textY+=20;
	ofDrawBitmapString("Changes:        " + updater.changes, textX, textY);
	textY+=20;
	
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
