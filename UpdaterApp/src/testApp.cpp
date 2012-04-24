/**
 * UpdaterApp is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * UpdaterApp is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * UpdaterApp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with UpdaterApp; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.23
 * @version     0.0.1a
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	// of settings
	ofSetVerticalSync(true);
	ofSetWindowTitle("UpdaterApp version 0.0.1");
	ofRegisterURLNotification(this);
	// ofLog settings
	ofLogToConsole();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	
	// Get the working directory of the app.
	// this we need to load files form UpdateManager.app/Contents/MacOS/
	workingDir = ofFilePath::getCurrentWorkingDirectory();
	
	
	// Load fonts
	vera9.loadFont(workingDir+"/Vera.ttf", 9, false, true);
	veraBold12.loadFont(workingDir+"/VeraBd.ttf", 12, true, true);
	
	
	// Gui settings
	// Set the size of our left control area
	leftControlWidth = 300;
	// setup gui
	autoUpdateToggle.setup("Auto Update", 10, leftControlWidth, 20);
	LogUpdateToggle.setup("Log Update Prosess", 10, leftControlWidth, 20);
	userInformationToggle.setup("Submit User Information", 10, leftControlWidth, 20);
	// set gui position
	autoUpdateToggle.setPosition(ofGetWidth()-leftControlWidth, 55);
	LogUpdateToggle.setPosition(ofGetWidth()-leftControlWidth, 76);
	userInformationToggle.setPosition(ofGetWidth()-leftControlWidth, 97);
	
	
	// updater settings
	updater.init("0.0.5", "http://www.wrong-entertainment.com/code/ofxAppUpdater/UpdaterApp_appcast.xml");
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(ofColor::white);
	
	
	ofEnableSmoothing();
	
	
	// Left Control background
	ofSetColor(ofColor::gray);
	ofRect(leftControlBackgroundX, 0, leftControlWidth+10, ofGetHeight());
	// header background
	ofSetColor(ofColor::black);
	ofRect(0, 0, ofGetWidth(), 40);
	// Appcast text
	ofSetColor(ofColor::white);
	veraBold12.drawString("Appcast", 20, 25);
	// Update Setting test
	ofSetColor(ofColor::white);
	veraBold12.drawString("Update Settings", leftControlBackgroundX+10, 25);
	
	
	// Left Control Gui
	autoUpdateToggle.draw();
	LogUpdateToggle.draw();
	userInformationToggle.draw();
	
	
	
	ofDisableSmoothing();
	
	
	// create rectange for custom download button
	ofRectangle updateButton;
	updateButton.set(20, 50, 40, 40);
	
	
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
			
			chTitle = appcast.getChannelTitle(updater.xml);
			chDescription = appcast.getChannelDescription(updater.xml);
			chDate = appcast.getChannelPubDate(updater.xml);
			
			acVersion =appcast.getAppcastVersion(updater.xml, 0);
			acAuthor = appcast.getAppcastAuthor(updater.xml, 0);
			acDoclink = appcast.getAppcastDocLink(updater.xml, 0);
			acSourcelink = appcast.getAppcastSourceLink(updater.xml, 0);
			break;
			
			
		case LATEST_RELEASE:
			ofSetColor(ofColor::black);
			veraBold12.drawString(updater.message+"\nversion "+updater.latestVersion, 20, 65);
			//vera9.drawString("Latest version: " + updater.latestVersion, 20, 105);
			/*ofSetColor(ofColor::black);
			ofRect(updateButton.x, updateButton.y, updateButton.width, updateButton.height);
			// X
			ofSetColor(ofColor::white);
			ofLine(25, 55, 55, 85);
			ofLine(55, 55, 25, 85);*/
			
			displayAppcast();
			break;
		
			
		case NEW_RELEASE:
			ofSetColor(ofColor::black);
			veraBold12.drawString(updater.message+"\nDownload update now!", 75, 65);
			vera9.drawString("Latest version: " + updater.latestVersion +  ", current version: " + updater.currentVersion, 20, 105);
			//vera9.drawString(appcast.getChannelTitle(updater.xml), 20, 140);
			
			// Download Button
			ofSetColor(ofColor::black);
			if(updateButton.inside(ofGetMouseX(), ofGetMouseY())){
				ofSetColor(0, 200, 255);
				if(ofGetMousePressed(0)){
					cout << "pressed\n";
					updater.download("tempDownload.zip");
				}
			}
			ofRect(updateButton.x, updateButton.y, updateButton.width, updateButton.height);
			// Arrow
			ofSetColor(ofColor::white);
			ofLine(40, 55, 40, 85);
			ofLine(25, 70, 40, 85);
			ofLine(55, 70, 40, 85);
			
			displayAppcast();
			break;
		
			
		case DOWNLOAD:
			ofSetColor(ofColor::green);
			ofRect(updateButton.x, updateButton.y, updateButton.width, updateButton.height);
			ofSetColor(ofColor::white);
			ofLine(ofGetWidth()-25, 15, ofGetWidth()-20, 25);
			ofLine(ofGetWidth()-15, 15, ofGetWidth()-20, 25);
			
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
			ofSetColor(ofColor::black);
			veraBold12.drawString("Something went Wrong.\nWe could not connect with server.", 20, 65);
			
			break;
		
		default:
			break;
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	// We use different keys to check, download and restart if a new release is available.
	/*switch (key) {
		
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
	}*/
	
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
	
	if (w >= 800) {
		leftControlBackgroundX = ofGetWidth()-leftControlWidth-10;
		// copycat from setup
		autoUpdateToggle.setPosition(ofGetWidth()-leftControlWidth, 50);
		LogUpdateToggle.setPosition(ofGetWidth()-leftControlWidth, 71);
		userInformationToggle.setPosition(ofGetWidth()-leftControlWidth, 92);
	}
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
/*void testApp::dragEvent(ofDragInfo dragInfo){ 

}*/

void testApp::exit(){
	
}

void testApp::urlResponse(ofHttpResponse & response){
	/*if(response.status == 200 && response.request.name == "async_req") {
		cout << "loading" << endl;
	} else {
		cout << response.status << " " << response.error << endl;
		if(response.status != -1) {
			cout << "loading = false \n" ;
		}
	}
*/
	
}


void testApp::displayAppcast(){
	
	ofSetColor(ofColor::black);
	veraBold12.drawString(chTitle, 20, 140);
	vera9.drawString("Last modified: " + chDate, 20, 155);
	
	vector <string> temp = ofSplitString(chDescription, " // ");
	//cout << temp.size() << endl;
	for(int i=0; i<temp.size(); i++){
		//cout << temp[i] << endl;
		vera9.drawString(ofToString(temp[i]), 20, 180+(20*i));
	}
	
	vera9.drawString("Version: "+acVersion, ofGetWidth()-leftControlWidth, 220);
	vera9.drawString("Author: "+acAuthor, ofGetWidth()-leftControlWidth, 240);
	vera9.drawString("Documentation: "+acDoclink, ofGetWidth()-leftControlWidth, 260);
	vera9.drawString("Source: "+acSourcelink, ofGetWidth()-leftControlWidth, 280);
	
	
}
