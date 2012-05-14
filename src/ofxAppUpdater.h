/**
 * ofxAppUpdater.h is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxAppUpdater.h is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxAppUpdater.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxAppUpdater.h; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.25
 * @version     1.0.1e
 */



#pragma once

#include <ofMain.h>
//#include "ofxXmlSettings.h"
#include "ofxAppcast.h"

#define OFXAPPUPDATER_LOG





namespace wng {
	
	
	// The different mode-states.
	// This we use to set the mode variable after running a mode correctly. 
	// Also we will use the enum for if/else, switch case stuff.
	enum OFXAPPUPDATER_MODE {
			DEFAULT = 0,
			CHECK = 1,
			LATEST_RELEASE = 2,
			NEW_RELEASE = 3,
			DOWNLOAD = 4,
			DOWNLOADING = 41,
			RELAUNCH = 5,
			FINISHED = 6
	};
	
	
	
	class ofxAppUpdater {
		
	public:
		/**
		 * Constructor
		 */
		ofxAppUpdater();
		
		
		/**
		 * Methods
		 */
		void init(string currentVersion, string appcastPath);
		
		int checkVersion(ofxXmlSettings xml);
		void download(string downloadUrl, string src);
		
		
		// TODO check if this is deadcode?
		void loadFile(string serverSrc, string tempFilepath);
		
		
		
		void unzip(string src);
		void relaunch();
		
		int userNotificationDisplay(string header, string message, const string buttonOk, const string buttonCancle, const string buttonAlternate);
		string getAppName();
		
		
		/**
		 * Variables
		 *
		 * We only create basic variables at this class.
		 * Basic variables 
		 */
		// The update modes.
		//
		// This we use to get the current state of the update process.
		// If a process like checking() or downloading() runs correctly,
		// the mode state will be set to the next mode value (OFXAPPUPDATER_MODE enum).
		int mode;
		// Message container for the different modes.
		string message;
		
		// The current application version.
		//
		// This variables contains the version of this application and is
		// hard coded at this release.
		// We need it for checking if a new release exist. 
		string currentVersion;
		
		// The Appcast RSS file
		//
		// lastVersion, appcast filepath and ofxAppcast class will be needed by
		// This variables will be filled with the tags from our Appcast RSS file.
		// The variables will be set get.. method by ofxAppcast methods.
		string latestVersion;
		string appcastPath;
		ofxAppcast appcast;
		
		
		
	private:
		//ofxXmlSettings xml;
		
		// Todo remove this variable.
		string temporaryDownloadFilename;
		
	};

};
