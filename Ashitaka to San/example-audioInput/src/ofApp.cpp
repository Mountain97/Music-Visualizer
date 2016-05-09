#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);

	ofSetVerticalSync(true);
	ofBackground(87,232,242);
	ofSetFrameRate(60);

    int ticksPerBuffer = 8;
    bufferSize = BUFFER_SIZE; //pdBlock-64
    inChan  = 2;
	outChan = 0;
	sampleRate = SR;

    int midiMin = 45;
    int midiMax = 90;
    
    filterBank.setup(bufferSize, midiMin, midiMax, inChan, BANDWITH, sampleRate, 1.0);
    filterBank.setColor(ofColor::orange);

	soundStream.setup(this, outChan, inChan, sampleRate, bufferSize, ticksPerBuffer);	}


//--------------------------------------------------------------

void ofApp::update(){
    


}

//--------------------------------------------------------------
void ofApp::draw(){

	
	
    float chSz = bufferSize/3;
		{
        
            filterBank.draw(1024,768);
        
	}
	


}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    //Analyze Input Buffer with ofxFilterbank
    filterBank.analyze(input);
    
}


void ofApp::audioOut(float * output, int bufferSize, int nChannels){

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    switch (key){
        case 'q':
            filterBank.showAll = !filterBank.showAll;
			break;
        case 'c':
            ofBackground(0,0,0,10);
        default:
            break;
    }
}


//--------------------------------------------------------------
void ofApp::exit(){
    soundStream.stop();
    soundStream.close();
    filterBank.exit();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------

void ofApp::mouseMoved(int x, int y ){

}


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

