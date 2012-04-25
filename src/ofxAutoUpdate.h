/**
 * ofxAutoUpdate.h is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxAutoUpdate.h is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxAutoUpdate.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxAutoUpdate.h; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.25
 * @version     1.0.1d2
 */



#pragma once

#include <ofMain.h>
#include "ofxAppUpdater.h"

#define OFXAUTOUPDATE_LOG





namespace wng {
	
	class ofxAutoUpdate {
		
	public:
		/**
		 * Constructor
		 */
		ofxAutoUpdate();
		
		
		/**
		 * Methods
		 */
		void init(string currentVersion, string appcastSrc);
		void update();
		void urlResponse(ofHttpResponse & response);
		
		
		
	private:
		ofxAppUpdater updater;
		
	};
	
};
