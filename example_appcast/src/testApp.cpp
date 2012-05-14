/**
 *  ofxAppUpdater
 *
 *  
 *  The MIT License
 *
 *  Copyright (c) 2012 Paul Vollmer, http://www.wng.cc
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *  
 *  @testet_oF          0.07
 *  @testet_plattform   MacOs 10.6
 *                      ??? Win
 *                      ??? Linux
 *  @dependencies       ofxXmlSettings
 *  @modified           2012.05.14
 *  @version            0.1.1e
 */

#include "testApp.h"






/**
 * At this example we need only the ofxAppcast class to include.
 * This class contains only get methods to work without creating variables at init.
 * So it's very clean but handle with care your get.. calls.
 */
//--------------------------------------------------------------
void testApp::setup(){
	
	vera9.loadFont("Vera.ttf", 9, true, true);
	veraBold12.loadFont("VeraBd.ttf", 12, true, true);
	
	
	// Start url notification.
	ofRegisterURLNotification(this);
	// With this we call the urlResponse event.
	// If it is placed at setup() the app check version at start.
	// You can move ofLoadURLAsync it anywhere you want.
	// NOTE: on every ofLoadURLAsync the app will check the version!
	// IMPORTANT: https is not working!
	//            You need a small php script to get content.
	//            check the releaseStorage/php_helper folder for php script.
	//            https://github.com/WrongEntertainment/ofxAppUpdater/tree/master/release_storage/php_helper
	
	// If you want to load from http, you can use ofLoadURLAsync without php script
	//ofLoadURLAsync("http://www.wrong-entertainment.com/code/ofxAppUpdater/sample_appcast.xml", "load");
	
	// Or the https solution...
	string phpHelperUrl = "http://www.wrong-entertainment.com/code/ofxAppUpdater/php_helper/getHttps.php?url=";
	string httpsUrl = "https://www.github.com/WrongEntertainment/ofxAppUpdater/raw/master/release_storage/sample_appcast.xml";
	ofLoadURLAsync(phpHelperUrl+httpsUrl, "load");
	
	
	// Set default item values.
	currentAppcastItem = 0;
	totalAppcastItems = 0;
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(ofColor::white);
	
	ofSetColor(ofColor::black);
	veraBold12.drawString("<channel> tags", 50, 30);
	vera9.drawString("channelTitle: ", 50, 50);
	vera9.drawString("channelLink: ", 50, 70);
	vera9.drawString("channelDate:", 50, 90);
	vera9.drawString(channelTitle, 200, 50);
	vera9.drawString(channelLink, 200, 70);
	vera9.drawString(channelDate, 200, 90);
	
	veraBold12.drawString("<channel:item> tags", 50, 130);
	vera9.drawString("total items: ", 50, 150);
	vera9.drawString("itemTitle: ", 50, 170);
	vera9.drawString("itemDescription: ", 50, 190);
	vera9.drawString("itemDate: ", 50, 210);
	vera9.drawString("itemUrl: ", 50, 230);
	vera9.drawString("appcastVersion: ", 50, 250);
	vera9.drawString("appcastAuthor: ", 50, 270);
	vera9.drawString("appcastLicense: ", 50, 290);
	vera9.drawString("appcastDownloads: ", 50, 310);
	vera9.drawString(ofToString(totalAppcastItems)+", current item: "+ofToString(currentAppcastItem), 200, 150);
	vera9.drawString(itemTitle, 200, 170);
	vera9.drawString(itemDescription, 200, 190);
	vera9.drawString(itemDate, 200, 210);
	vera9.drawString(itemUrl, 200, 230);
	vera9.drawString(appcastVersion, 200, 250);
	vera9.drawString(appcastAuthor, 200, 270);
	vera9.drawString(appcastLicense, 200, 290);
	vera9.drawString(appcastDownloads, 200, 310);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	switch (key) {
		case 'c':
			// You can reload your appcast.xml like this
			// We have unregister URLNotification at the end of urlResponse().
			// because of this we need to register new notification.
			ofRegisterURLNotification(this);
			// get the raw file from github via php helper. See releaseStorage/php_helper
			// TODO: create wiki doc.
			ofLoadURLAsync("http://www.wrong-entertainment.com/code/ofxAppUpdater/php_helper/getHttps.php?url=https://www.github.com/WrongEntertainment/ofxAppUpdater/raw/master/release_storage/sample_appcast.xml", "load");
			break;
			
		case OF_KEY_RIGHT:
			if(currentAppcastItem < appcast.getNumItems(xml)){
				currentAppcastItem++;
				cout << "currentAppcastItem: " << currentAppcastItem << endl;
				setAppcastVars(currentAppcastItem);
			}
			break;
			
		case OF_KEY_LEFT:
			if(currentAppcastItem > 0 ){
				currentAppcastItem--;
				cout << "currentAppcastItem: " << currentAppcastItem << endl;
				setAppcastVars(currentAppcastItem);
			}
			break;
			
		default:
			break;
	}
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::urlResponse(ofHttpResponse & response){
	
    if(response.status==200 ){  
        cout << response.request.name << endl;  
        cout << response.data.getText() << endl;
		
		xml.loadFromBuffer(response.data);
		
		setAppcastVars(currentAppcastItem);
		
		// This is a list of all appcast get methods.
		cout << "\nGet a tag from our channel: \n";
		cout << "getChannelTitle            = " << channelTitle << endl;
		cout << "getChannelLink             = " << channelLink << endl;
		cout << "getChannelDescription      = " << appcast.getChannelDescription(xml) << endl;
		cout << "getChannelLanguage         = " << appcast.getChannelLanguage(xml) << endl;
		cout << "getChannelPubDate          = " << channelDate << endl;
		cout << "\nGet the tags from our first item: \n";
		cout << "getNumItems                = " << totalAppcastItems << endl;
		cout << "getTitle                   = " << itemTitle << endl;
		cout << "getDescription             = " << itemDescription << endl;
		cout << "getPubDate                 = " << itemDate << endl;
		cout << "getEnclosureUrl            = " << itemUrl << endl;
		cout << "getEnclosureType           = " << appcast.getEnclosureType(xml, currentAppcastItem) << endl;
		cout << "\nGet the appcast tags from our first item: \n";
		cout << "getAppcastVersion          = " << appcastVersion << endl;
		cout << "getAppcastAuthor           = " << appcastAuthor << endl;
		cout << "getAppcastAuthorUrl        = " << appcast.getAppcastAuthorUrl(xml, currentAppcastItem) << endl;
		cout << "getAppcastAuthorEmail      = " << appcast.getAppcastAuthorEmail(xml, currentAppcastItem) << endl;
		cout << "getAppcastShortDescription = " << appcast.getAppcastShortDescription(xml, currentAppcastItem) << endl;
		cout << "getAppcastLicense          = " << appcastLicense << endl;
		cout << "getAppcastLicenseUrl       = " << appcast.getAppcastLicenseUrl(xml, currentAppcastItem) << endl;
		cout << "getAppcastHash             = " << appcast.getAppcastHash(xml, currentAppcastItem) << endl;
		cout << "getAppcastHashAlgo         = " << appcast.getAppcastHashAlgo(xml, currentAppcastItem) << endl;
		cout << "getAppcastRating           = " << appcast.getAppcastRating(xml, currentAppcastItem) << endl;
		cout << "getAppcastRatingVotes      = " << appcast.getAppcastRatingVotes(xml, currentAppcastItem) << endl;
		cout << "getAppcastDownloadCount    = " << appcastDownloads << endl;
		cout << "getAppcastKeywords         = " << appcast.getAppcastKeywords(xml, currentAppcastItem) << endl;
		cout << "getAppcastDocsLink         = " << appcast.getAppcastDocsLink(xml, currentAppcastItem) << endl;
		cout << "getAppcastSourcesLink      = " << appcast.getAppcastSourcesLink(xml, currentAppcastItem) << endl;
		cout << "getAppcastPreviewLink      = " << appcast.getAppcastPreviewLink(xml, currentAppcastItem) << endl;
		
		
    } else {  
        cout << response.status << " " << response.error << endl;  
    }
	
	ofSleepMillis(100);
	
	// Unregister URLNotification to close event.
	ofUnregisterURLNotification(this);
	
}


// a method to set the string variables from our appcast file.
void testApp::setAppcastVars(int currentAppcastItem){
	// set string variables with appcast tags.
	// We have no variables at ofxAppcast class to save memory!
	channelTitle = appcast.getChannelTitle(xml);
	channelLink = appcast.getChannelLink(xml);
	channelDate = appcast.getChannelPubDate(xml);
	totalAppcastItems = appcast.getNumItems(xml);
	itemTitle = appcast.getTitle(xml, currentAppcastItem);
	itemDescription = appcast.getDescription(xml, currentAppcastItem);
	itemDate = appcast.getPubDate(xml, currentAppcastItem);
	itemUrl = appcast.getEnclosureUrl(xml, currentAppcastItem);
	appcastVersion = appcast.getAppcastVersion(xml, currentAppcastItem);
	appcastAuthor = appcast.getAppcastAuthor(xml, currentAppcastItem);
	appcastLicense = appcast.getAppcastLicense(xml, currentAppcastItem);
	appcastDownloads = appcast.getAppcastDownloadCount(xml, currentAppcastItem);
}