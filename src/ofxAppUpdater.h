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
 * @modified    2012.04.22
 * @version     1.0.1d
 */



#pragma once

#include <ofMain.h>
#include "ofxAppcast.h"

#define OFXAPPUPDATER_LOG





namespace wng {
	
	
	// The values of the different mode-states.
	enum OFXAPPUPDATER_MODE {
			DEFAULT,
			CHECK,
			LATEST_RELEASE,
			NEW_RELEASE,
			DOWNLOAD,
			RELAUNCH,
			FINISHED
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
		void init(string currentVersion, string appcastSrc, bool internetConnenction);
		void init(string currentVersion, string appcastSrc);
		void autoUpdate();
		void checkVersion();
		void download(string src);
		void download();
		void relaunch();
		
		int userNotificationDisplay(string header, string message, const string buttonOk, const string buttonCancle, const string buttonAlternate);
		
		
		// The update modes.
		//
		// This we use to get the current state of the update process.
		// If a process like checking() or downloading() runs correctly,
		// the mode state will be set to the next mode value (OFXAPPUPDATER_MODE enum).
		int mode;
		
		// The current application version.
		//
		// This variables contains the version of this application and is
		// hard coded at this release.
		// We need it for checking if a new release exist. 
		string currentVersion;
		
		// The Appcast RSS file
		//
		// This variables will be filled with the tags from our Appcast RSS file.
		// The variables will be set by parseAppcast method.
		string latestVersion;   // Latest Software Version (this will be set by ofxAppcast class)
		
		// internetConnection
		//
		// Trigger your web connection, if bool is true,
		// your Application can check the version and
		// download if a new release is available.
		bool internetConnection;
		
		// Message container for the ofxAppUpdater class.
		string message;
		
		
		
	private:
		ofxAppcast appcast;
		
		
		/**
		 * Methods
		 */
		void loadFile(string serverSrc, string tempFilepath);
		void parseAppcast(string filepath);
		void unzip(string src);
		string getAppName();
		
		string appcastSrc;
		string downloadUrl;
		string temporaryDownloadFilename;
		
		// If the variable is true, the addon start downloading zip package.
		//bool downloadActive;
		
	};

};
