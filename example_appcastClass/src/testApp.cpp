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
 * @modified    2012.04.23
 * @version     1.0.1d
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	vera.loadFont("vera.ttf", 9, true, false);
	
	ofRegisterURLNotification(this);
	ofLoadURLAsync("http://www.wrong-entertainment.com/code/ofxAppUpdater/appcastSample.xml","load");
	
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
	ofLoadURLAsync("http://www.wrong-entertainment.com/code/ofxAppUpdater/appcastSample.xml","load");
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

//--------------------------------------------------------------
void testApp::exit(){
	ofUnregisterURLNotification(this);
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
		
		// This is a list example of all get methods.
		/*
		cout << "\nGet a tag from our channel: \n";
		cout << "getChannelTitle            = " << appcast.getChannelTitle() << endl;
		cout << "getChannelLink             = " << appcast.getChannelLink() << endl;
		cout << "getChannelDescription      = " << appcast.getChannelDescription() << endl;
		cout << "getChannelLanguage         = " << appcast.getChannelLanguage() << endl;
		cout << "getChannelPubDate          = " << appcast.getChannelPubDate() << endl;
		cout << "\nGet the tags from our first item: \n";
		cout << "getTitle                   = " << appcast.getTitle(0) << endl;
		cout << "getDescription             = " << appcast.getDescription(0) << endl;
		cout << "getPubDate                 = " << appcast.getPubDate(0) << endl;
		cout << "getEnclosureUrl            = " << appcast.getEnclosureUrl(0) << endl;
		cout << "getEnclosureType           = " << appcast.getEnclosureType(0) << endl;
		cout << "\nGet the appcast tags from our first item: \n";
		cout << "getAppcastVersion          = " << appcast.getAppcastVersion(0) << endl;
		cout << "getAppcastAuthor           = " << appcast.getAppcastAuthor(0) << endl;
		cout << "getAppcastAuthorUrl        = " << appcast.getAppcastAuthorUrl(0) << endl;
		cout << "getAppcastAuthorEmail      = " << appcast.getAppcastAuthorEmail(0) << endl;
		cout << "getAppcastShortDescription = " << appcast.getAppcastShortDescription(0) << endl;
		cout << "getAppcastLicense          = " << appcast.getAppcastLicense(0) << endl;
		cout << "getAppcastLicenseUrl       = " << appcast.getAppcastLicenseUrl(0) << endl;
		cout << "getAppcastHash             = " << appcast.getAppcastHash(0) << endl;
		cout << "getAppcastHashAlgo         = " << appcast.getAppcastHashAlgo(0) << endl;
		cout << "getAppcastRating           = " << appcast.getAppcastRating(0) << endl;
		cout << "getAppcastRatingVotes      = " << appcast.getAppcastRatingVotes(0) << endl;
		cout << "getAppcastDownloadCount    = " << appcast.getAppcastDownloadCount(0) << endl;
		cout << "getAppcastKeywords         = " << appcast.getAppcastKeywords(0) << endl;
		cout << "getAppcastDocLink          = " << appcast.getAppcastDocLink(0) << endl;
		cout << "getAppcastSourceLink       = " << appcast.getAppcastSourceLink(0) << endl;
		cout << "getAppcastPreviewLink      = " << appcast.getAppcastPreviewLink(0) << endl;
		*/
		
    }else{  
        cout << response.status << " " << response.error << endl;  
    }
	
}
