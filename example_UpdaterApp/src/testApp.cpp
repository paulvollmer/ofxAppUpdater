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
 * @version     0.0.1
 */





#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
}

//--------------------------------------------------------------
void testApp::update(){
	if(ofGetFrameNum() == 25){
		string shPath;
		shPath = ofToDataPath( "openChildApp.sh", true );
		
		char *shPathChar;
		shPathChar = new char[ shPath.length() + 1 ];
		
		strcpy( shPathChar, shPath.c_str() );
		
		//--
		int pid = fork();
		cout << "pid :: " << pid << endl;
		
		switch(pid){
			case -1 :
				cout << "Uh-Oh! fork() failed.\n" << endl;
			case  0 :
				execl( shPathChar, shPathChar, NULL );
			default :
				return;
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );
	
	ofSetColor( 255, 0, 0 );
	ofDrawBitmapString( "PARENT APPLICATION LAUNCHED.", 20, 20 );
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
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
	
}

//--------------------------------------------------------------
void testApp::urlResponse(ofHttpResponse & response){
	
}
