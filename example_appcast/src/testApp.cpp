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
	
	vera.loadFont("vera.ttf", 9, true, false);
	
	// Start url notification.
	ofRegisterURLNotification(this);
	// With this we call the urlResponse event.
	// If it is placed at setup() the app check version at start.
	// You can move ofLoadURLAsync it anywhere you want.
	// NOTE: on every ofLoadURLAsync the app will check the version!
	// IMPORTANT: https is not working!
	//            You need a small php script to get content.
	//            check the releaseStorage/php_helper folder for php script.
	
	// If you want to load from http, you can use ofLoadURLAsync without php script
	//ofLoadURLAsync("http://www.wrong-entertainment.com/code/ofxAppUpdater/appcastSample.xml", "load");
	
	// Or the https solution...
	const string phpHelperUrl = "http://www.wrong-entertainment.com/code/getHttps.php?url=";
	const string httpsUrl = "https://www.github.com/WrongEntertainment/ofxAppUpdater/raw/master/release_storage/appcast.xml";
	ofLoadURLAsync(phpHelperUrl+httpsUrl, "load");
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(ofColor::white);
	
	ofSetColor(ofColor::black);
	vera.drawString("ofxAppcast", 100, 100);
	vera.drawString(channelTitle, 100, 120);
	vera.drawString(channelLink, 100, 140);
	vera.drawString(channelDate, 100, 160);
	
	vera.drawString(itemTitle, 100, 200);
	vera.drawString(itemDescription, 100, 220);
	vera.drawString(itemDate, 100, 240);
	vera.drawString(itemUrl, 100, 260);
	
	vera.drawString("appcastVersion: "+appcastVersion, 100, 300);
	vera.drawString("appcastAuthor: "+appcastAuthor, 100, 320);
	vera.drawString("appcastLicense: "+appcastLicense, 100, 340);
	vera.drawString("appcastDownloads: "+appcastDownloads, 100, 360);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	// You can reload your appcast.xml like this
	// NOTE: We have unregister URLNotification at the end of urlResponse()
	//       Uncomment it to reload
	//ofLoadURLAsync("http://www.wrong-entertainment.com/code/ofxAppUpdater/appcastSample.xml","load");
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::urlResponse(ofHttpResponse & response){
	
	// based on http://forum.openframeworks.cc/index.php/topic,8398.0.html
    if(response.status==200 ){  
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
		
		// This is a list of all appcast get methods.
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
		cout << "getAppcastDocsLink          = " << appcast.getAppcastDocsLink(xml, 0) << endl;
		cout << "getAppcastSourcesLink       = " << appcast.getAppcastSourcesLink(xml, 0) << endl;
		cout << "getAppcastPreviewLink      = " << appcast.getAppcastPreviewLink(xml, 0) << endl;
		
		
    }else{  
        cout << response.status << " " << response.error << endl;  
    }
	
	ofSleepMillis(200);
	
	// Unregister URLNotification to close event.
	ofUnregisterURLNotification(this);
	
}
