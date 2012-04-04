#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	/* Initiolize ofxUpdater class. */
	updater.init(1,
				 "versioninfo.xml",
				 "http://www.wrong-entertainment.com/code/wngUpdater/");
	/* Or use the init method which you can set your internet connection. */
	//updater.init(1, 122, false);
	
	
	// TEST
	//updater.checkVersion(1, 1);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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