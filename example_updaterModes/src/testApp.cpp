/**
 * ofxAppUpdater is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxAppUpdater is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxAppUpdater is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxAppUpdater; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.20
 * @version     1.0.1c
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	ofLogToConsole();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	ofRegisterURLNotification(this);
	
	
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
	updater.init("0.9.0",
				 "https://github.com/WrongEntertainment/ofxAppUpdater/raw/develope/release_storage/appcast.xml",
				 true);
	
	//cout << "getCurrentWorkingDirectory: " << ofFilePath::getCurrentWorkingDirectory() << endl;
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(ofColor::white);
	
	
	// Display our ofxAppUpdater Information.
	//
	// Here is a list of the modes:
	// - DEFAULT (mo update checked)
	// -  (Version OK)
	// - 2 = After Checking (New Version)
	// - 3 = Download ready
	switch (updater.mode) {
		case DEFAULT:
			ofSetColor(ofColor::black);
			ofDrawBitmapString("Press 'u' for update check!", 10, 20);
			break;
			
		case LATEST_RELEASE:
			// Display a System Alert Dialog.
			ofSystemAlertDialog(updater.message);
			updater.mode = FINISHED;
			break;
		
		case NEW_RELEASE:
			ofSetColor(ofColor::yellow);
			ofRect(5, 5, ofGetWidth()-10, 38);
			ofSetColor(ofColor::black);
			ofDrawBitmapString(updater.message+"\nPress 'd' for downloading new Release.", 10, 20);
			ofDrawBitmapString("Current-Version: " + updater.currentVersion, 10, 70);
			ofDrawBitmapString("Latest-Version:  " + updater.latestVersion, 10, 90);
			break;
		
		case DOWNLOAD:
			ofSetColor(ofColor::black);
			ofDrawBitmapString(updater.message+"\nPress 'r' to Restart your Application.", 100, 50);
			break;
		
		case RELAUNCH:
			ofSetColor(ofColor::black);
			ofDrawBitmapString(updater.message, 100, 50);
			break;
		
		case FINISHED:
			
			break;
		
		default:
			break;
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	// We use different keys to check, download and restart if a new release is available.
	switch (key) {
		
		// Key <u> to check if a new update is available.
		case 'u':
			updater.checkVersion();
			break;
		
		// Key <d> to download the latest release.
		case 'd':
			updater.download();
			break;
		
		// Key <r> to restart the app.
		case 'r':
			updater.relaunch();
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

void testApp::urlResponse(ofHttpResponse & response){
	if(response.status == 200 && response.request.name == "async_req") {
		cout << "loading" << endl;
	} else {
		cout << response.status << " " << response.error << endl;
		if(response.status != -1) {
			cout << "loading = false \n" ;
		}
	}

}
