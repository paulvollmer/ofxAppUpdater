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
 * @modified    2012.04.25
 * @version     1.0.1e
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofLogToConsole();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	// Description at example_appcast setup()
	ofRegisterURLNotification(this);
	const string phpHelperUrl = "http://www.wrong-entertainment.com/code/getHttps.php?url=";
	const string httpsUrl = "https://www.github.com/WrongEntertainment/ofxAppUpdater/raw/develop/release_storage/appcastSample.xml";
	updater.init("0.0.1", phpHelperUrl+httpsUrl);
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(ofColor::white);
	
	ofSetColor(ofColor::black);
	
	// Display our ofxAppUpdater Information.
	//
	// Here is a list of the modes:
	// - DEFAULT (mo update checked)
	// -  (Version OK)
	// - 2 = After Checking (New Version)
	// - 3 = Download ready
	switch (updater.mode) {
		case DEFAULT:
			ofDrawBitmapString("DEFAULT\nPress 'u' to check version.", 50, 30);
			break;
			
		case LATEST_RELEASE:
			ofDrawBitmapString("LATEST_RELEASE", 50, 30);
			ofDrawBitmapString("ofxAppUpdater Message:         " + updater.message, 50, 50);
			ofDrawBitmapString("ofxAppUpdater Current-Version: " + updater.currentVersion, 50, 70);
			ofDrawBitmapString("ofxAppUpdater Latest-Version:  " + updater.latestVersion, 50, 90);
			break;
		
		case NEW_RELEASE:
			ofDrawBitmapString("NEW_RELEASE", 50, 30);
			ofDrawBitmapString("ofxAppUpdater Message:         " + updater.message, 50, 50);
			ofDrawBitmapString("ofxAppUpdater Current-Version: " + updater.currentVersion, 50, 70);
			ofDrawBitmapString("ofxAppUpdater Latest-Version:  " + updater.latestVersion, 50, 90);
			break;
		
		case DOWNLOAD:
			ofDrawBitmapString("DOWNLOAD", 50, 30);
			ofDrawBitmapString(updater.message, 100, 50);
			break;
		
		case RELAUNCH:
			ofDrawBitmapString("RELAUNCH", 50, 30);
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
			ofLoadURLAsync("http://www.wrong-entertainment.com/code/ofxAppUpdater/appcastSample.xml", "load");
			break;
		
		// Key <d> to download the latest release.
		case 'd':
			//updater.download();
			//ofLoadURLAsync(updater.appcast.getEnclosureUrl(updater.xml, 0), "load");
			break;
		
		// Key <r> to restart the app.
		case 'r':
			//updater.relaunch();
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
	
	// based on http://forum.openframeworks.cc/index.php/topic,8398.0.html
    if(response.status == 200){  
        cout << response.request.name << endl;  
        cout << response.data.getText() << endl;
		
		updater.xml.loadFromBuffer(response.data);
		
		updater.checkVersion(updater.xml);
		
	} else {  
        cout << response.status << " " << response.error << endl;  
    }
	
	ofSleepMillis(200);
	
	// Unregister URLNotification to close event.
	ofUnregisterURLNotification(this);
	

}
