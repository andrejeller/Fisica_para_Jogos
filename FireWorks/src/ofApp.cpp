#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Define cor de fundo como preta
	ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update() {
	//Atualiza todos os fogos
	for(int i = 0; i < fireWorks.size(); i++) {		
		fireWorks.at(i).update();

		//Caso seu tempo de vida seja maior que 5000 milisegundos ele exclui do array
		if(fireWorks.at(i).lifeTime > 5000)
			fireWorks.erase(fireWorks.begin() + i);
		 
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	//Desenha tudo
	for(int i = 0; i < fireWorks.size(); i++)
		fireWorks.at(i).draw();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//Cria um novo foguetão, com X inicial aleatorio, y no fim da tela, velocidade definida por voce, e a posição final send oa do mouse
	fireWorks.push_back(fireWork(ofVec2f(ofRandom(0, ofGetWidth()), ofGetHeight()), 500, ofVec2f(x, y)));
}

#pragma region NaoUtilizados
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

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
#pragma endregion
