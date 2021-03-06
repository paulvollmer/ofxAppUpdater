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



#pragma once

#include "ofMain.h"
#include "ofxXmlDefaultSettings.h"
#include "ofxXmlSettings.h"

#include "ofxGui.h"

#include "ofxAppUpdater.h"
#include "ofxUpdateManager.h"

using namespace wng;





class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void exit();
	void urlResponse(ofHttpResponse & response);
	
	void displayAppcast();
	
	
private:
	ofxXmlDefaultSettings defXML;
	ofxXmlSettings XML;
	
	string workingDir;
	
	// Fonts we use
	ofTrueTypeFont vera9;
	ofTrueTypeFont veraBold12;
	
	// Gui objects
	int leftControlWidth;
	int leftControlBackgroundX;
	ofxToggle autoUpdateToggle;
	ofxToggle LogUpdateToggle;
	ofxToggle userInformationToggle;
	//ofxToggle debugInformationToggle;
	
	// Network connection to get messages from other application.
	ofxUpdateManager updateManager;
	
	// Added ofxAppUpdater addon to testApp
	ofxAppUpdater updater;
	
	// Appcast class and string variables to sore content
	ofxAppcast appcast;
	string chTitle, chDate, chDescription;
	string acVersion, acAuthor, acDoclink, acSourcelink;

};
