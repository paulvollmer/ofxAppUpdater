/**
 *  ofxAutoUpdater.h
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

#pragma once

#include <ofMain.h>
#include "ofxXmlSettings.h"
#include "ofxAppUpdater.h"

// If "OFXAUTOUPDATE_LOG" is defined, the addon prints out ofLog messages.
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
		ofxXmlSettings xml;
		ofxAppUpdater updater;
		
	};
	
};
