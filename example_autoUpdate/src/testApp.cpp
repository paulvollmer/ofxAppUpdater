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



//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofLogToConsole();
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	// Description at example_appcast setup()
	const string phpHelperUrl = "http://www.wrong-entertainment.com/code/ofxAppUpdater/php_helper/getHttps.php?url=";
	const string httpsUrl = "https://www.github.com/WrongEntertainment/ofxAppUpdater/raw/develop/release_storage/sample_appcast.xml";
	autoUpdate.init(CURRENT_VERSION, phpHelperUrl+httpsUrl);
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	autoUpdate.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(ofColor::white);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::urlResponse(ofHttpResponse & response){
	
	autoUpdate.urlResponse(response);

}
