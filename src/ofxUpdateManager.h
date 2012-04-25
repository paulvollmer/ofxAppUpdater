/**
 * ofxUpdateManager.h is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxUpdateManager.h is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxUpdateManager.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxUpdateManager.h; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.24
 * @version     1.0.1d
 */



#pragma once

#include "ofxNetwork.h"





namespace wng {	
	
	class ofxUpdateManager {
		
	public:
		ofxUpdateManager();
		
		void start(string shPath);
		void connect(string ip, int port, bool blocking);
		void connect();
		void bind(int port, bool blocking);
		void bind();
		void send(string message);
		string receive();

		
	private:
		// Network connection to send/receive messages from
		// other application.
		ofxUDPManager udpConnection;
	
	};

};
