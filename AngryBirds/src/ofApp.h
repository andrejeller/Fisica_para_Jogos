#pragma once

#include "ofMain.h"
#include "Bird.h"


class ofApp : public ofBaseApp {

public:


#pragma region Of Functions

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

#pragma endregion

	ofImage background;
	vector <Bird> player1, player2;
	ofVec2f defMola, mouse, posCanhao, wind;

	bool mouseIsPressed = false;

	int Score1, Score2;
	int playerTurn = 0; // 0 - Menu; 1 - P1; 2 - P2; 3 - See Score;

	float gravidade = -1.0f;
	float p1_BirdNumber = 0;
	float p2_BirdNumber = 0;

	void OnMouseRelease() {
		//Calcula forca a ser apllicada com a deformaçao da mola
		defMola.set(posCanhao.x - mouse.x, posCanhao.y - mouse.y);
		ofVec2f forca = defMola * 2.5; //2.5 = const Elástica

		//Dependendo do turno chama a funcao de determinado player
		if(playerTurn == 1) {
			cout << " [P1 Number is ] " << p1_BirdNumber << endl;
			p1_BirdNumber++;
			checkPlayerCount();
			player1.at(p1_BirdNumber).isMoving = true;
			player1.at(p1_BirdNumber).applyForce(forca);

		}

		else if(playerTurn == 2) {
			cout << " [P2 Number is ] " << p2_BirdNumber << endl;
			p2_BirdNumber++;
			checkPlayerCount();
			player2.at(p2_BirdNumber).isMoving = true;
			player2.at(p2_BirdNumber).applyForce(forca);
		}
	}


	void checkPlayerCount() {
		//confere se o passaro a ser atirado está dentro dos limites do Vector
		if(p1_BirdNumber > 2) {
			p1_BirdNumber = 0;
			playerTurn++;
			system("cls");
			cout << " [NEXT TURN ] " << playerTurn << endl;
		}
		if(p2_BirdNumber > 2) {
			p2_BirdNumber = 0;
			//playerTurn++;
		}
	}

	void ResetGame() {
		//Reseta - Inicia o Jogo
		playerTurn = 0;
		background.load("menu.png");

		player1.clear();
		player1.push_back(Bird(100, 400, 2, true, "red.png"));
		player1.push_back(Bird(100, 400, 4, true, "white.png"));
		player1.push_back(Bird(100, 400, 6, true, "yellow.png"));
		//player1.push_back(Bird(100, 450, 6, true, "box.png"));

		player2.clear();
		player2.push_back(Bird(900, 400, 2, false, "red.png"));
		player2.push_back(Bird(900, 400, 4, false, "white.png"));
		player2.push_back(Bird(900, 400, 6, false, "yellow.png"));
	}

	

	void EndGame() {
		//Chamda ao acabar o jogo e faz calculo do score pela distancia dos passaros da base oposta
		for(int i = 0; i < player1.size(); i++) {
			Score1 += ofVec2f(900, 400).distance((player1.at(i).pos));
		}

		for(int i = 0; i < player1.size(); i++) {
			Score2 += ofVec2f(100, 400).distance((player2.at(i).pos));
		}

		system("cls");
		cout << "SCORE PLAYER 1 __ " << Score1 << endl;
		cout << "SCPRE PLAYER 2 __ " << Score2 << endl;
	}
};
