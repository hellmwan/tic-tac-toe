#include<iostream>
#include<ctime>
using namespace std;


void drawBoard(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces, char player, char computer);
bool checkWinner(char* spaces, char player, char computer);
bool checkTie(char* spaces);

int main() {

	char spaces[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	char player = 'X';
	char computer = 'O';
	bool running = true;

	drawBoard(spaces);

	while (running) {
		playerMove(spaces, player);
		drawBoard(spaces);

		if (checkWinner(spaces, player, computer)) {
			running = false;
			break;
		}

		else if (checkTie(spaces)) {
			running = false;
			break;
		}

		computerMove(spaces, player, computer);
		drawBoard(spaces);

		if (checkWinner(spaces, player, computer)) {
			running = false;
			break;
		}

		else if (checkTie(spaces)) {
			running = false;
			break;
		}
	}

	cout << "thanks for playing!" << endl;
	return 0;
}

void drawBoard(char* spaces) {

	cout << '\n';
	cout << "     |     |     " << endl;
	cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << endl;
	cout << '\n';


}
void playerMove(char* spaces, char player) {
	int number;
	do {
		cout << "enter a spot to place a marker (1-9)" << endl;
		cin >> number;
		number -= 1;
		if (spaces[number] == ' ') {
			spaces[number] = player;
			break;
		}
	} while (number > 0 || number < 9);
}
void computerMove(char* spaces, char player, char computer) {
	int number;
	srand(time(0));

	while (true) {
		number = rand() % 9;
		if (spaces[number] == ' ') {
			spaces[number] = computer;
			break;
		}
	}
}
bool checkWinner(char* spaces, char player, char computer) {

	if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[0] == spaces[2])) {
		spaces[0] == player ? cout << "you win!\n" : cout << "you lose!\n";
	}

	else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[3] == spaces[5])) {
		spaces[3] == player ? cout << "you win!\n" : cout << "you lose!\n";
	}

	else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[6] == spaces[8])) {
		spaces[6] == player ? cout << "you win!\n" : cout << "you lose!\n";
	}

	else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[0] == spaces[8])) {
		spaces[0] == player ? cout << "you win!\n" : cout << "you lose!\n";
	}

	else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[2] == spaces[6])) {
		spaces[2] == player ? cout << "you win!\n" : cout << "you lose!\n";
	}

	else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[0] == spaces[6])) {
		spaces[0] == player ? cout << "you win!\n" : cout << "you lose!\n";
	}

	else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[1] == spaces[7])) {
		spaces[1] == player ? cout << "you win!\n" : cout << "you lose!\n";
	}

	else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[2] == spaces[8])) {
		spaces[2] == player ? cout << "you win!\n" : cout << "you lose!\n";
	}

	else {
		return false;
	}

	return true;
}
bool checkTie(char* spaces) {

	for (int i = 0; i < 9; i++) {
		if (spaces[i] == ' ') {
			return false;
		}
	}
	cout << "it is a tie!" << endl;
	return true;

} 