/**
 *  ofxUpdateManager.cpp
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

#include "ofxUpdateManager.h"



namespace wng {
	
	ofxUpdateManager::ofxUpdateManager(){}


	
	/**
	 * start
	 */
	void ofxUpdateManager::start(string shPath){
		
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
	
	
	
	
	/**
	 *
	 */
	void ofxUpdateManager::send(string message){
		int send = udpConnection.Send(message.c_str(), message.length());
	}
	
	
	
	
	/**
	 *
	 */
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
	
	
}
