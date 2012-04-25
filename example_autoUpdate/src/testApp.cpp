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
 * @version     1.0.1d2
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	//ofSetVerticalSync(true);
	
	ofLogToConsole();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	
	// Start url notification.
	ofRegisterURLNotification(this);
	// With this we call the urlResponse event.
	// If it is placed at setup() the app check his version at starting spplication.
	// You can move ofLoadURLAsync it anywhere you want.
	//ofLoadURLAsync("http://www.wrong-entertainment.com/code/ofxAppUpdater/appcastSample.xml","load");
	ofLoadURLAsync("https://github.com/WrongEntertainment/ofxAppUpdater/raw/develope/release_storage/appcast.xml", "load");
	
	
	// We store our updater Variables here (FOR THE CURRENT APPLICATION RELEASE).
	// For our ofxAppUpdater::init method we need the following variables:
	// - An Application Release version (string)
	// - A Server-URL who will be stored the Appcast.xml file.
	//
	// KEEP CLEAN THE FOLLWING VARIABLES TO UPDATE AND RELEASE OUR SOFTWARE SAVETY.
	// FOR THIS YOU CAN USE THE [semantic versioning]( http://semver.org ) STYLE.
	// 
	// The appcast.xml and release.zip are stored at github repository.
	//updater.init("0.0.0", "https://github.com/WrongEntertainment/ofxAppUpdater/raw/develope/release_storage/appcast.xml");
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	/*switch (ofGetFrameNum()) {
		case 10:
			updater.autoUpdate();
			break;
		default:
			break;
	}*/
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(ofColor::white);
	
	ofSetColor(ofColor::black);
	ofDrawBitmapString("Message:", 70, 90);
	ofDrawBitmapString(updater.message, 150, 90);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::urlResponse(ofHttpResponse & response){
	
	// based on http://forum.openframeworks.cc/index.php/topic,8398.0.html
    /*if(response.status==200 ){  
        cout << response.request.name << endl;  
        cout << response.data.getText() << endl;
		
		xml.loadFromBuffer(response.data);
		
		// set string variables with appcast tags.
		// If you want to change the cantent later, you can
		// !We have no variables to save at ofxAppcast class!
		channelTitle = appcast.getChannelTitle(xml);
		channelLink = appcast.getChannelLink(xml);
		channelDate = appcast.getChannelPubDate(xml);
		itemTitle = appcast.getTitle(xml, 0);
		itemDescription = appcast.getDescription(xml, 0);
		itemDate = appcast.getPubDate(xml, 0);
		itemUrl = appcast.getEnclosureUrl(xml, 0);
		appcastVersion = appcast.getAppcastVersion(xml, 0);
		appcastAuthor = appcast.getAppcastAuthor(xml, 0);
		appcastLicense = appcast.getAppcastLicense(xml, 0);
		appcastDownloads = appcast.getAppcastDownloadCount(xml, 0);
		
		// This is a list example of all get methods.
		cout << "\nGet a tag from our channel: \n";
		cout << "getChannelTitle            = " << channelTitle << endl;
		cout << "getChannelLink             = " << channelLink << endl;
		cout << "getChannelDescription      = " << appcast.getChannelDescription(xml) << endl;
		cout << "getChannelLanguage         = " << appcast.getChannelLanguage(xml) << endl;
		cout << "getChannelPubDate          = " << channelDate << endl;
		cout << "\nGet the tags from our first item: \n";
		cout << "getTitle                   = " << itemTitle << endl;
		cout << "getDescription             = " << itemDescription << endl;
		cout << "getPubDate                 = " << itemDate << endl;
		cout << "getEnclosureUrl            = " << itemUrl << endl;
		cout << "getEnclosureType           = " << appcast.getEnclosureType(xml, 0) << endl;
		cout << "\nGet the appcast tags from our first item: \n";
		cout << "getAppcastVersion          = " << appcastVersion << endl;
		cout << "getAppcastAuthor           = " << appcastAuthor << endl;
		cout << "getAppcastAuthorUrl        = " << appcast.getAppcastAuthorUrl(xml, 0) << endl;
		cout << "getAppcastAuthorEmail      = " << appcast.getAppcastAuthorEmail(xml, 0) << endl;
		cout << "getAppcastShortDescription = " << appcast.getAppcastShortDescription(xml, 0) << endl;
		cout << "getAppcastLicense          = " << appcastLicense << endl;
		cout << "getAppcastLicenseUrl       = " << appcast.getAppcastLicenseUrl(xml, 0) << endl;
		cout << "getAppcastHash             = " << appcast.getAppcastHash(xml, 0) << endl;
		cout << "getAppcastHashAlgo         = " << appcast.getAppcastHashAlgo(xml, 0) << endl;
		cout << "getAppcastRating           = " << appcast.getAppcastRating(xml, 0) << endl;
		cout << "getAppcastRatingVotes      = " << appcast.getAppcastRatingVotes(xml, 0) << endl;
		cout << "getAppcastDownloadCount    = " << appcastDownloads << endl;
		cout << "getAppcastKeywords         = " << appcast.getAppcastKeywords(xml, 0) << endl;
		cout << "getAppcastDocLink          = " << appcast.getAppcastDocLink(xml, 0) << endl;
		cout << "getAppcastSourceLink       = " << appcast.getAppcastSourceLink(xml, 0) << endl;
		cout << "getAppcastPreviewLink      = " << appcast.getAppcastPreviewLink(xml, 0) << endl;
		
		
    }else{  
        cout << response.status << " " << response.error << endl;  
    }
	
	//ofSleepMillis(200);
	//ofUnregisterURLNotification(this);
	
	 */
	
}
