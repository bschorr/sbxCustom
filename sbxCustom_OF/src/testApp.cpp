#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //add names to your SB inputs and outputs
    inVec.name = "inVec";
    outVec.name = "outVec";
    
    //load their datatypes from your json file in the data folder
    inVec.loadType("vec3.json");
    outVec.loadType("vec3.json");
    
    //Spacebrew configs and listener
    Spacebrew::Config config;
    config.clientName = "Spacebrew Vec3 example";
    
    config.addSubscribe(inVec);
    config.addPublish(outVec);
    
    sb.connect( Spacebrew::SPACEBREW_CLOUD, config );
    
    Spacebrew::addListener(this, sb);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    //draw white circle in incoming position.
    ofSetColor(255);
    ofCircle(inVec.getInt("x"), inVec.getInt("y"), 10);
    
}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    inVec.setValue(m);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    //set outgoing variable to mouse position
    outVec.setValue("x", x);
    outVec.setValue("y", y);
    outVec.setValue("z", 0);
    
    //send outgoing position
    sb.send(outVec);

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    //if you try to add a value that is not in your JSON, the program throws a warning.
    outVec.setValue("oops", "oops");

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
