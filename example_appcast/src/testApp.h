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



#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxAppcast.h"

using namespace wng;





class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);
	void urlResponse(ofHttpResponse & response);  
	void setAppcastVars(int currentAppcastItem);	
	
	
private:
	// We need a font to display our appcast content.
	ofTrueTypeFont vera9;
	ofTrueTypeFont veraBold12;
	
	// Xml to store appcast file.
	ofxXmlSettings xml;
	
	// Add ofxAppcast class
	ofxAppcast appcast;
	int currentAppcastItem;
	int totalAppcastItems;
	// This variables will be set by our appcast file.
	string channelTitle;
	string channelLink;
	string channelDate;
	string itemTitle;
	string itemDescription;
	string itemDate;
	string itemUrl;
	string appcastVersion;
	string appcastAuthor;
	string appcastLicense;
	string appcastDownloads;
	

};
