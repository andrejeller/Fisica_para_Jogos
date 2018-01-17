#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);

	ofSetBackgroundColor(0, 0, 0);


	//alien.pos.set(ofGetWidth() / 2, ofGetHeight() / 2);	
}

//--------------------------------------------------------------
void ofApp::update() {

	//Se a bool do mouse pressionado estiver verdadeira, Ativa o impulso
	if(mouseIsDown)
			alien.OnMouseDown(mouse);

	moon.update(earth);
	alien.update(earth);
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	earth.draw(0.2f);
	moon.draw(0.5f);
	//Desenhando Alien
	alien.draw();

	//ofDrawBitmapString("Teste", 10, 10);
	//ofDrawBitmapStringHighlight("Teste", 10, 10, ofColor(255, 255, 255), ofColor(0, 0, 0));
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	//cout << x << "  " << y << endl;
	//Garantindo que a posição do mouse será alterada mesmo quando ele for arrastado
	mouse.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//Altera a bool mostrando que o mouse foi pressionado.
	mouseIsDown = true;
	//Iguala a posição do vetor mouse ao mouse quando clicado
	mouse.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	//Altera a bool mostrando que o mouse foi pressionado.
	mouseIsDown = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
