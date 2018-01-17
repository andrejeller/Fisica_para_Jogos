#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	Start();
}

//--------------------------------------------------------------
void ofApp::update() {
	//Chama updade do alien passando constante de gravidade
	alien.update(-0.25);


	//Se a bool do mouse pressionado estiver verdadeira, Ativa o impulso
	if(mouseIsDown)
		alien.OnMouseDown(mouse.x, mouse.y);

}

//--------------------------------------------------------------
void ofApp::draw() {
	//Desenhando Lua e Piramide
	moon.draw(200, 100, moon.getWidth(), moon.getHeight());
	piramid.draw(300, 300, piramid.getWidth(), piramid.getHeight());

	//Desenhando o Chão
	wall.draw(-10, 400, wall.getWidth() + 10, wall.getHeight());
	wall.draw(550, 400, -wall.getWidth() + 10, wall.getHeight());
	wall.draw(532, 400, wall.getWidth() + 10, wall.getHeight());
	
	//Desenhando Alien
	alien.draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//Ao apertar R, "reseta" o Jogo
	if(key == 114)
		Start();
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
