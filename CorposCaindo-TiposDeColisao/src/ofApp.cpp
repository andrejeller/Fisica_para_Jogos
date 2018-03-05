#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0);

	bodies.push_back(quadrado);
	bodies.push_back(circulo);
	bodies.push_back(triangulo);
}

//--------------------------------------------------------------
void ofApp::update(){
	quadrado.update(gravity);
	circulo.update(gravity);
	triangulo.update(gravity);

	quadrado.CheckCollision(circulo);
	quadrado.CheckCollision(triangulo);

	circulo.CheckCollision(quadrado);
	circulo.CheckCollision(triangulo);

	triangulo.CheckCollision(circulo);
	triangulo.CheckCollision(quadrado);	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 125, 0);
	ofDrawRectangle(0, ofGetHeight() - 50, ofGetWidth(), 50);

	ofSetColor(255, 0, 0);
	quadrado.draw();	

	ofSetColor(255, 0, 255);
	circulo.draw();
	
	ofSetColor(255, 255, 0);
	triangulo.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	quadrado.MouseDragged(ofVec2f(x, y), true);
	circulo.MouseDragged(ofVec2f(x, y), true);
	triangulo.MouseDragged(ofVec2f(x, y), true);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	quadrado.MouseDragged(ofVec2f(x, y), true);
	circulo.MouseDragged(ofVec2f(x, y), true);
	triangulo.MouseDragged(ofVec2f(x, y), true);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	quadrado.MouseDragged(ofVec2f(x, y), false);
	circulo.MouseDragged(ofVec2f(x, y), false);
	triangulo.MouseDragged(ofVec2f(x, y), false);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	
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
