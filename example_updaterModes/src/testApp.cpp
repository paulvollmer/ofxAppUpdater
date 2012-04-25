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
 * @modified    2012.04.22
 * @version     1.0.1c2
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	ofLogToConsole();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	//ofRegisterURLNotification(this);
	
	
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
	updater.init("0.0.0",
				 "https://raw.github.com/WrongEntertainment/ofxAppUpdater/master/release_storage/appcast.xml",
				 true);
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(ofColor::white);
	
	// Our update button size and position.
	ofRectangle updateButton;
	updateButton.set(ofGetWidth()-30, 10, 20, 20);
	
	// Display our ofxAppUpdater Information.
	//
	// Here is a list of the modes:
	// - DEFAULT (mo update checked)
	// -  (Version OK)
	// - 2 = After Checking (New Version)
	// - 3 = Download ready
	switch (updater.mode) {
		case DEFAULT:
			/*ofSetColor(ofColor::black);
			ofDrawBitmapString("Press 'u' for update check!", 10, 20);*/
			updater.checkVersion();
			break;
			
		case LATEST_RELEASE:
			ofSetColor(ofColor::gray);
			ofRect(5, 5, ofGetWidth()-10, ofGetHeight()-10);
			ofSetColor(ofColor::black);
			ofDrawBitmapString("This is our default content.", 100, 100);
			ofDrawBitmapString("ofxAppUpdater Message:         " + updater.message, 100, 120);
			ofDrawBitmapString("ofxAppUpdater Current-Version: " + updater.currentVersion, 100, 140);
			ofDrawBitmapString("ofxAppUpdater Latest-Version:  " + updater.latestVersion, 100, 160);
			break;
		
		case NEW_RELEASE:
			ofSetColor(ofColor::black);
			ofRect(updateButton.x, updateButton.y, updateButton.width, updateButton.height);
			ofSetColor(ofColor::white);
			ofTriangle(ofGetWidth()-25, 15, ofGetWidth()-15, 15, ofGetWidth()-20, 25);
			
			if(updateButton.inside(ofGetMouseX(), ofGetMouseY())){
				ofSetColor(ofColor::black);
				ofDrawBitmapString(updater.message+"\nClick to download the update.", ofGetWidth()-250, 50);
				
				if(ofGetMousePressed(0)){
					cout << "pressed\n";
					updater.download("tempDownload.zip");
				}
			}
			break;
		
		case DOWNLOAD:
			ofSetColor(ofColor::green);
			ofRect(updateButton.x, updateButton.y, updateButton.width, updateButton.height);
			ofSetColor(ofColor::white);
			ofTriangle(ofGetWidth()-25, 15, ofGetWidth()-15, 15, ofGetWidth()-20, 25);
			
			if(updateButton.inside(ofGetMouseX(), ofGetMouseY())){
				ofSetColor(ofColor::black);
				ofDrawBitmapString(updater.message+"\nClick to Relauch App.", ofGetWidth()-250, 50);
				
				if(ofGetMousePressed(0)){
					cout << "pressed\n";
					updater.relaunch();
				}
			}
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
