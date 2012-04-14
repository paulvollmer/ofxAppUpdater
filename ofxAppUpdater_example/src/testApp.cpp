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
 * @modified    2012.04.14
 * @version     1.0.1a
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	ofLogToConsole();
	
	
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
	updater.init("0.1.1",
				 "https://raw.github.com/WrongEntertainment/ofxAppUpdater/master/release_storage/",
				 "versioninfo_1_0_1.xml",
				 "release_1_0_0.zip");
	
	// TODO: a changelog system for release history.
	// The changes will be shown at the application-update info alert.
	
	
	// TEST
	// This is used for development testing.
	//updater.checking();
	//updater.checkVersion(1, 1);
	//updater.parseXML("versioninfo.xml");
	//updater.loadXml(updater.serverUrl+updater.versionInfoXml);
	//updater.unzip(ofFilePath::getCurrentWorkingDirectory()+"tempDownloadfile_002.zip");
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(0);
	
	
	// Display our ofxAppUpdater Information.
	//
	// Here is a list of the drawModes:
	// - 0 = Default Mode (mo update checked)
	// - 1 = After Checking (Version OK)
	// - 2 = After Checking (New Version)
	// - 3 = Download ready
	switch (updater.mode) {
		case 0:
			ofSetColor(0, 255, 255);
			ofDrawBitmapString("Press 'u' for update check!", 10, 20);
			break;
			
		case 1:
			// Draw something..
			//ofSetColor(0, 255, 255);
			//ofDrawBitmapString("You're running the latest Application Release!", 10, 20);
			
			// .. or display a System Alert.
			ofSystemAlertDialog("You're running the latest Application Release!");
			updater.mode = -1;
			
			break;
		
		case 2:
			ofSetColor(ofColor::yellow);
			ofRect(5, 5, ofGetWidth()-10, 38);
			
			ofSetColor(ofColor::black);
			ofDrawBitmapString("A new Version is Available! \nPress 'd' for downloading new Release.", 10, 20);
			ofSetColor(ofColor::yellow);
			ofDrawBitmapString("Current-Version: " + ofToString(updater.currentVersion), 10, 70);
			ofDrawBitmapString("Latest-Version:  " + ofToString(updater.latestVersion), 10, 90);
			ofDrawBitmapString("Author:          " + updater.author, 10, 110);
			ofDrawBitmapString("ModifiedDate:    " + updater.modifiedDate, 10, 130);
			ofDrawBitmapString("Changes:         " + updater.changes, 10, 150);
			break;
		
		case 3:
			ofSetColor(0, 255, 255);
			ofDrawBitmapString("Download Ready! Press 'r' to Restart your Application.", 100, 50);
			break;
		
		case 4:
			ofSetColor(0, 255, 255);
			ofDrawBitmapString("Restarting Application!", 100, 50);
			break;
		
		default:
			break;
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	switch (key) {
			
		// We use the key <u> to check if a new update is available.
		case 'u':
			if (updater.mode == 0) {
				updater.checking();
			}
			break;
		
		// key <d> to download the latest release.
		case 'd':
			if (updater.mode == 2) updater.downloading();
			break;
		
		// key <r> to restart the app.
		case 'r':
			if (updater.mode == 3) updater.restart();
			break;
			
		// Default
		default:
			break;
	}
	
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
