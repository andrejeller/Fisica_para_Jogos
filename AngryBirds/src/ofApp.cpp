#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Inicializa o jogo
	ofSetBackgroundColor(211, 245, 248);
	background.load("menu.png");
	posCanhao.set(100, 400);
	mouse = posCanhao;
	wind.set(0.0f, 0.0f);
	ResetGame();
}

//--------------------------------------------------------------
void ofApp::update() {

	if(playerTurn == 1) posCanhao.set(100, 400);
	if(playerTurn == 2) posCanhao.set(900, 400);

	for(int i = 0; i < player1.size(); i++) {
		player1.at(i).update();
		if(player1.at(i).isMoving) {
			player1.at(i).applyForce(ofVec2f(0, -gravidade));
			player1.at(i).applyForce(wind);
		}
	}



	for(int i = 0; i < player2.size(); i++) {
		player2.at(i).update();
		if(player2.at(i).isMoving) {
			player2.at(i).applyForce(ofVec2f(0, -gravidade));
			player2.at(i).applyForce(wind);
		}
	}


}

//--------------------------------------------------------------
void ofApp::draw() {


	if(playerTurn == 0) {
		background.draw(0, 75);
	}
	else if(playerTurn == 1 || playerTurn == 2) {
		background.draw(0, 0);

		//Desenho Flecha Vento
		ofSetColor(255, 0, 0);
		ofDrawArrow(ofVec3f(ofGetWidth() / 2, 20, 0), ofVec3f(ofGetWidth() / 2 + wind.x, 20 + wind.y, 0), 6);

		//Desenho Linha Estilingue
		ofSetColor(0);
		ofDrawLine(posCanhao, mouse);

		//Desenho Passaros
		ofSetColor(255, 255, 255);
		for(int i = 0; i < player1.size(); i++) {
			player1.at(i).draw();
		}

		for(int i = 0; i < player2.size(); i++) {
			player2.at(i).draw();
		}

	}

	else if(playerTurn == 3) {
		background.draw(0, 75);
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//Para resetar jogo
	if(key == 'R' || key == 'r') {
		ResetGame();
		system("cls");
		cout << " ## [Jogo Reiniciado] ##" << endl;
	}

	//Para Iniciar o Jogo
	if(playerTurn == 0 && key == 13) { //Enter
		playerTurn++;
		background.load("buildings.png");
	}

	//Para Acabar jogo
	if(playerTurn == 2 && key == 13) { //Enter
		EndGame();
		playerTurn++;
		background.load("seeScore.png");
	}

	//Para mudar o vento
	switch(key) {
		case'0':
			wind.set(0.0f, 0.0f);
			break;
		case'a':
			wind.x -= 0.05;
			break;
		case'w':
			wind.y -= 0.05;
			break;
		case's':
			wind.y += 0.05;
			break;
		case'd':
			wind.x += 0.05;
			break;
		default:
			break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	//cout << x << " " << y << endl;	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	if(mouseIsPressed)
		mouse.set(x, y);
	
	//cout << "[] DefMola " << defMola << " [] Forca " << forca << endl;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	mouseIsPressed = true;
	cout << " [Mouse Is Pressed] " << endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	mouseIsPressed = false;

	OnMouseRelease();

	cout << " [Mouse Is Not Pressed] " << endl;

	if(playerTurn == 1) mouse.set(100, 400);
	if(playerTurn == 2) mouse.set(900, 400);

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
