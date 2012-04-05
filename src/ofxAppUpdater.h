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
 * @modified    2012.04.04
 * @version     0.1.0
 */



#pragma once

#include <ofMain.h>

#define DEBUG





namespace wng {
	
	class ofxAppUpdater {
		
		public:
			/*
			 * Constructor
			 */
			ofxAppUpdater();
	
	
			/*
			 * Methods
			 */
			void init(float userVer, string file, string url, bool connection);
			void init(float userVer, string file, string url);
			bool checkVersion(float userVer, float newestVer);
		
			
			/*
			 * Variables
			 * Here will be listen all Variables of the ofxUpdater class.
			 *
			 * Trigger your web connection, if bool is true,
			 * your Application can check the version and
			 * download automatic if a new release is available. */
			bool internetConnection;
		
			/* Version of User Application */
			float userVersion;
		
			/* Latest Software Version */
			float latestVersion;
			
			/* Date of last modification */
			string modified;
		
			/* Name of the author/company */
			string author;
			
			/* A list of changes that will shipped with the new update.  */
			string changes;
		
			/* If the variable is true, the addon start
			 * downloading zip package. */
			//bool downloadActive;
			
		
	};

};
