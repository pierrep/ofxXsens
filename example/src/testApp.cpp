#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    text.loadFont("verdana.ttf", 16, true, true);
    sensor.setup();
    sensor.connect();
}

//--------------------------------------------------------------
void testApp::update(){
    sensor.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0);
    text.drawString("Device Connected:"+ofToString(sensor.isConnected()?"On":"Off"),20,30);
    text.drawString("Latitude:"+ofToString(sensor.getLatitude()), 20, 60);
    text.drawString("Longitude:"+ofToString(sensor.getLongitude()), 20, 90);
    text.drawString("Pitch:"+ofToString(sensor.getPitch()), 20, 120);
    text.drawString("Roll:"+ofToString(sensor.getRoll()), 20, 150);
    text.drawString("Yaw:"+ofToString(sensor.getYaw()), 20, 180);
}

//--------------------------------------------------------------
void testApp::exit()
{
    cout <<"exiting app..." << endl;
    sensor.close();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
