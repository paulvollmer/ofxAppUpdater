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
 * @modified    2012.04.16
 * @version     1.0.1b
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	ofLogToConsole();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	ofRegisterURLNotification(this);
	
	
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
	updater.init("0.0.1",
				 "https://raw.github.com/WrongEntertainment/ofxAppUpdater/master/release_storage/",
				 "versioninfo_1_0_1.xml",
				 "release_1_0_0.zip",
				 true);
	updater.internetConnection = true;
	
	cout << ofFilePath::getCurrentWorkingDirectory() << endl;
	
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
			ofDrawBitmapString("Author:          " + updater.author, 10, 110);
			ofDrawBitmapString("ModifiedDate:    " + updater.modifiedDate, 10, 130);
			ofDrawBitmapString("Changes:         " + updater.changes, 10, 150);
			break;
		
		case DOWNLOAD:
			ofSetColor(ofColor::black);
			ofDrawBitmapString(updater.message+"\nPress 'r' to Restart your Application.", 100, 50);
			break;
		
		case RESTART:
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
			updater.restart();
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
