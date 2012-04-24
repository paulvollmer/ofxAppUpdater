/**
 * ofxUpdateManager.cpp is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxUpdateManager.cpp is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxUpdateManager.cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxUpdateManager.cpp; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.24
 * @version     1.0.1d
 */



#include "ofxUpdateManager.h"



namespace wng {
	
	ofxUpdateManager::ofxUpdateManager(){}


	/**
	 * Create and connect the socket.
	 * Based on oF networkUdpSender-, ReceiverExample
	 */
	void ofxUpdateManager::connect(string ip, int port, bool blocking){
		udpConnection.Create();
		udpConnection.Connect(ip.c_str(), port);
		udpConnection.SetNonBlocking(blocking);
	}
	
	void ofxUpdateManager::connect(){
		connect("127.0.0.1", 11120119, true);
	}
	
	
	
	
	
	/**
	 * Create and bind the socket.
	 */
	void ofxUpdateManager::bind(int port, bool blocking){
		udpConnection.Create();
		udpConnection.Bind(port);
		udpConnection.SetNonBlocking(blocking);
	}
	
	void ofxUpdateManager::bind(){
		bind(11120119, true);
	}
	
	
	
	
	
	void ofxUpdateManager::send(string message){
		int send = udpConnection.Send(message.c_str(), message.length());
	}
	
	
	
	
	
	string ofxUpdateManager::receive(){
		// Network connection
		char udpMessage[100000];
		udpConnection.Receive(udpMessage,100000);
		/*string message = udpMessage;
		if(message!=""){
			cout << message << endl;
		}*/
		return udpMessage;
	}
	
	
	
	
	
	void ofxUpdateManager::open(string shPath){
		
		char *shPathChar;
		shPathChar = new char[ shPath.length() + 1 ];
		
		strcpy( shPathChar, shPath.c_str() );
		
		
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
