#include <iostream>
#include <time.h>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <string>

const int SIZE = 7;
char choice;
int randomRow = rand() % 7;
int randomCol = rand() % 7;

struct NPC {
	int xCoord, yCoord;
};

class Maze {

public:
	Maze();
	void set_room();
	void print_maze();
	void move(char input);
	bool notgameover();

private:
	char mazeArray[SIZE][SIZE];  // Main array
	NPC Player;
	NPC Wumpus;
	NPC Bat1;
	NPC Bat2;
	NPC Hole1;
	NPC Hole2;
	NPC Arrow1;
	NPC Arrow2;
	int arrowsInv;
	bool debug;  //False for Normal play, true for debug mode
};


Maze::Maze() {  // Main maze object
	debug = false;
	set_room();
	arrowsInv = 5;
}

bool Maze::notgameover() {
	if ((Player.xCoord == Wumpus.xCoord) && (Player.yCoord == Wumpus.yCoord) || (Player.xCoord == Hole1.xCoord) && (Player.yCoord == Hole1.yCoord)
		|| (Player.xCoord == Hole2.xCoord) && (Player.yCoord == Hole2.yCoord)) {
		std::cout << "";
		return false;
	}
	else {
		return true;
	}
}

void Maze::set_room() {  // Initialization of the rooms
	int arrowCap = 5;

	Player.xCoord = std::rand() % 7;
	Player.yCoord = std::rand() % 7;
	Wumpus.xCoord = std::rand() % 7;
	Wumpus.yCoord = std::rand() % 7;
	Bat1.xCoord = std::rand() % 7;
	Bat1.yCoord = std::rand() % 7;
	Bat2.xCoord = std::rand() % 7;
	Bat2.yCoord = std::rand() % 7;
	Hole1.xCoord = std::rand() % 7;
	Hole1.yCoord = std::rand() % 7;
	Hole2.xCoord = std::rand() % 7;
	Hole2.yCoord = std::rand() % 7;
	Arrow1.xCoord = std::rand() % 7;
	Arrow1.yCoord = std::rand() % 7;
	Arrow2.xCoord = std::rand() % 7;
	Arrow2.yCoord = std::rand() % 7;

	NPC ar1[8] = { Player, Wumpus, Bat1, Bat2, Hole1, Hole2, Arrow1, Arrow2 };

	int sameRoom = 0;   // If two things are in the same room at the same time
	for (int i = 1; i < 8; i++) {
		for (int j = i; j > 0; j--) {
			if (ar1[i - j].xCoord == ar1[i].xCoord && ar1[i - j].yCoord == ar1[i].yCoord) {
				ar1[i].xCoord = std::rand() % 7;
				ar1[i].yCoord = std::rand() % 7;
				sameRoom++;
			}
			if (sameRoom > 0) {  // Continues on
				j = i;
				sameRoom = 0;
			}
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			mazeArray[i][j] = '-';
		}
	}

	Player.xCoord = ar1[0].xCoord;
	Player.yCoord = ar1[0].yCoord;
	Wumpus.xCoord = ar1[1].xCoord;
	Wumpus.yCoord = ar1[1].yCoord;
	Bat1.xCoord = ar1[2].xCoord;
	Bat1.yCoord = ar1[2].yCoord;
	Bat2.xCoord = ar1[3].xCoord;
	Bat2.yCoord = ar1[3].yCoord;
	Hole1.xCoord = ar1[4].xCoord;
	Hole1.yCoord = ar1[4].yCoord;
	Hole2.xCoord = ar1[5].xCoord;
	Hole2.yCoord = ar1[5].yCoord;
	Arrow1.xCoord = ar1[6].xCoord;
	Arrow1.yCoord = ar1[6].yCoord;
	Arrow2.xCoord = ar1[7].xCoord;
	Arrow2.yCoord = ar1[7].yCoord;

	if (debug) {  // Debug mode to show all icons
		mazeArray[Wumpus.xCoord][Wumpus.yCoord] = 'w';
		mazeArray[Bat1.xCoord][Bat1.yCoord] = 'b';
		mazeArray[Bat2.xCoord][Bat2.yCoord] = 'b';
		mazeArray[Hole1.xCoord][Hole1.yCoord] = 'h';
		mazeArray[Hole2.xCoord][Hole2.yCoord] = 'h';
		mazeArray[Arrow1.xCoord][Arrow1.yCoord] = 'a';
		mazeArray[Arrow2.xCoord][Arrow2.yCoord] = 'a';

	}
	mazeArray[Player.xCoord][Player.yCoord] = 'o';


}


void Maze::move(char input) {  // Player movement
							   //std::srand(time(NULL));
	if ((input == 'N') || (input == 'n')) {
		if (Player.xCoord == 0) {
			std::cout << "You cannot make that movement. \n";
		}
		else {
			mazeArray[Player.xCoord][Player.yCoord] = '*';
			Player.xCoord = Player.xCoord - 1;
			mazeArray[Player.xCoord][Player.yCoord] = 'o';
		}
	}
	if ((input == 'S') || (input == 's')) {
		if (Player.xCoord == 6) {
			std::cout << "You cannot make that movement. \n";
		}
		else {
			mazeArray[Player.xCoord][Player.yCoord] = '*';
			Player.xCoord = Player.xCoord + 1;
			mazeArray[Player.xCoord][Player.yCoord] = 'o';
		}
	}
	if ((input == 'W') || (input == 'w')) {
		if (Player.yCoord == 0) {
			std::cout << "You cannot make that movement. \n";
		}
		else {
			mazeArray[Player.xCoord][Player.yCoord] = '*';
			Player.yCoord = Player.yCoord - 1;
			mazeArray[Player.xCoord][Player.yCoord] = 'o';
		}
	}
	if ((input == 'E') || (input == 'e')) {
		if (Player.yCoord == 6) {
			std::cout << "You cannot make that movement. \n";
		}
		else {
			mazeArray[Player.xCoord][Player.yCoord] = '*';
			Player.yCoord = Player.yCoord + 1;
			mazeArray[Player.xCoord][Player.yCoord] = 'o';
		}
	}
	if ((input == 'T') || (input == 't')) {
		std::ofstream outFile;
		outFile.open("outFile.txt");
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				outFile << mazeArray[i][j];
			}
		}
	}

	if ((Player.xCoord == Wumpus.xCoord) && (Player.yCoord == Wumpus.yCoord)) {
		std::cout << "The wumpus decided that he needs your arms more than you do.  He takes them and you bleed out.\n";
		std::cout << "Game Over.\n";
	}
	if ((Player.xCoord == Bat1.xCoord) && (Player.yCoord == Bat1.yCoord)) {
		std::cout << "A bat the size of a cow thinks you are a delicious meal.  Upon further inspection you are not. \n";
		std::cout << "The bat drops you off in a random room. \n";
		Player.xCoord = randomRow;
		Player.yCoord = randomCol;

	}
	if ((Player.xCoord == Bat2.xCoord) && (Player.yCoord == Bat2.yCoord)) {
		std::cout << "A bat the size of a cow thinks you are a delicious meal.  Upon further inspection you are not. \n";
		std::cout << "The bat drops you off in a random room. \n";
		Player.xCoord = randomRow;
		Player.yCoord = randomCol;
	}
	if ((Player.xCoord == Hole1.xCoord) && (Player.yCoord == Hole1.yCoord)) {
		std::cout << "Your trip over a small rock and fall into a small hole.  You hit your head.\n";
		std::cout << "Game Over.\n";
	}
	if ((Player.xCoord == Hole2.xCoord) && (Player.yCoord == Hole2.yCoord)) {
		std::cout << "Your trip over a small rock and fall into a small hole.  You hit your head.\n";
		std::cout << "Game Over.\n";
	}
	if ((Player.xCoord == Arrow1.xCoord) && (Player.yCoord == Arrow1.yCoord)) {
		std::cout << "You found a poisoned wumpus arrow!\n";
		arrowsInv++;
	}
	if ((Player.xCoord == Arrow2.xCoord) && (Player.yCoord == Arrow2.yCoord)) {
		std::cout << "You found a poisoned wumpus arrow!\n";
		arrowsInv++;
	}


	if (arrowsInv == 0) {
		std::cout << "You ran out of arrows, you stink at aiming. \n";
	}
	else if (input == '1') {  //When arrow is shot down
		if ((Player.yCoord == Wumpus.yCoord) && 
			((Player.xCoord == Wumpus.xCoord - 1) || (Player.xCoord == Wumpus.xCoord - 2) || (Player.xCoord == Wumpus.xCoord - 3))) {
			std::cout << "Congratulations, you murdered the wumpus.  He had " << std::rand() % 20 << " children. \n";
			exit(1);
		}
		else {
			arrowsInv--;
			std::cout << "You missed the wumpus.  Are you even trying? \n";
		}
	}
	else if (input == '2') {  //When arrow is shot right
		if ((Player.xCoord == Wumpus.xCoord) && 
			((Player.yCoord == Wumpus.yCoord - 1) || (Player.yCoord == Wumpus.yCoord - 2) || (Player.yCoord == Wumpus.yCoord - 3))) {
			std::cout << "Congratulations, you murdered the wumpus.  He had " << std::rand() % 20 << " children. \n";
			exit(1);
		}
		else {
			arrowsInv--;
			std::cout << "You missed the wumpus.  Are you even trying? \n";
		}
	}
	else if (input == '3') {  //When arrow is shot left
		if ((Player.xCoord == Wumpus.xCoord) &&
			((Player.yCoord == Wumpus.yCoord + 1) || (Player.yCoord == Wumpus.yCoord + 2) || (Player.yCoord == Wumpus.yCoord + 3))) {
			std::cout << "Congratulations, you murdered the wumpus.  He had " << std::rand() % 20 << " children. \n";
			exit(1);
		}
		else {
			arrowsInv--;
			std::cout << "You missed the wumpus.  Are you even trying? \n";
		}
	}
	else if (input == '4') {  //When arrow is shot up
		if ((Player.yCoord == Wumpus.yCoord) &&
			((Player.xCoord == Wumpus.xCoord + 1) || (Player.xCoord == Wumpus.xCoord + 2) || (Player.xCoord == Wumpus.xCoord + 3))) {
			std::cout << "Congratulations, you murdered the wumpus.  He had " << std::rand() % 20 << " children. \n";
			exit(1);
		}
		else {
			arrowsInv--;
			std::rand() % 4;
			std::cout << "You missed the wumpus.  Are you even trying?  The wumpus has moved to avoid your failure. \n";

			if (Wumpus.xCoord == 0) {
				Wumpus.xCoord = 1;
			}
			if (Wumpus.xCoord == 6) {
				Wumpus.xCoord = 5;
			}
			if (Wumpus.yCoord == 0) {
				Wumpus.yCoord = 1;
			}
			if (Wumpus.yCoord == 6) {
				Wumpus.yCoord = 5;
			}	
		}
	}
	// Hearing bats
	if (((Player.xCoord >= Bat1.xCoord - 1 && Player.xCoord <= Bat1.xCoord + 1) && (Player.yCoord >= Bat1.yCoord - 1 && Player.yCoord <= Bat1.yCoord + 1) || (Player.xCoord >= Bat2.xCoord - 1 && Player.xCoord <= Bat2.xCoord + 1) && (Player.yCoord >= Bat2.yCoord - 1 && Player.yCoord <= Bat2.yCoord + 1))) {
		std::cout << "You hear flapping sounds nearby. \n" << std::endl;
	}
	// Hearing pit
	if (((Player.xCoord >= Hole1.xCoord - 1 && Player.xCoord <= Hole1.xCoord + 1) && (Player.yCoord >= Hole1.yCoord - 1 && Player.yCoord <= Hole1.yCoord + 1) || (Player.xCoord >= Hole2.xCoord - 1 && Player.xCoord <= Hole2.xCoord + 1) && (Player.yCoord >= Hole2.yCoord - 1 && Player.yCoord <= Hole2.yCoord + 1))) {
		std::cout << "The dirt beneath your feet feels uneven. \n" << std::endl;
	}
	// Hearing wumpus
	if (((Player.xCoord >= Wumpus.xCoord - 1 && Player.xCoord <= Wumpus.xCoord + 1) && (Player.yCoord >= Wumpus.yCoord - 1 && Player.yCoord <= Wumpus.yCoord + 1))) {
		std::cout << "A foul stench forces your fingers to plug your nose. \n" << std::endl;
	}


}



void Maze::print_maze() {  // Prints array
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			std::cout << mazeArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


int main() {

	srand(time(NULL));

	int choice;
	char choice1;

	std::cout << "************************************* \n";
	std::cout << "********** HUNT THE WUMPUS ********** \n";
	std::cout << "************************************* \n\n";
	std::cout << "The wumpus, a terrible legendary creature, enjoys causing bugs in computer programs and corrupting files. \n";
	std::cout << "You have one job: to find and kill the wumpus.  Who wouldn't want him dead? \n";
	std::cout << "Only a magic arrow made of good intentions, holy wood and plenty of poison may kill the creature, \n";
	std::cout << "but that is not all the hero must be wary of. \n";
	std::cout << "Evil bats pick up and drop off the hero wherever they decide, which may even include bottomless pits that \n";
	std::cout << "exist in the cave the wumpus lives in. \n";
	std::cout << "Find arrows and kill the wumpus before it finds you. \n";
	std::cout << " \n";
	std::cout << "Legend: (o) = player, (w) = wumpus, (b) = bats, (h) = holes, (a) = arrows \n";
	std::cout << " \n";

	std::cout << "Main Menu: \n";
	std::cout << "1.  New Game \n";
	std::cout << "2.  Load Game \n";
	std::cout << "3.  Instructions \n";
	std::cout << "4.  Quit \n\n";

	std::cout << " \n";
	std::cin >> choice;

	if (choice == 1) {
		Maze game;  // Instantiate game
		game.set_room();  // Sets rooms
		while (game.notgameover()) {   // While loop to continue moves
			game.print_maze();  // Prints maze after every move
			std::cout << " \n";
			std::cout << "Where would you like to move (N, S, W, or E) or T to save \n";
			std::cout << "or would you like to try to shoot the wumpus (1 for down, 2 for right, 3 for left, 4 for up)? \n";
			std::cin >> choice1;
			game.move(choice1);
		}
		std::cout << "\n";
		main();
	}
	else if (choice == 2) {
	}
	else if (choice == 3) {
		std::cout << "\nThe wumpus, a terrible legendary creature, enjoys causing bugs in computer programs and corrupting files. \n";
		std::cout << "You have one job: to find and kill the wumpus.  Who wouldn't want him dead? \n";
		std::cout << "Only a magic arrow made of good intentions, holy wood and plenty of poison may kill the creature, but that is not all the hero must be wary of. \n";
		std::cout << "Evil bats pick up and drop off the hero wherever they decide, which may even include bottomless pits that exist in the cave the wumpus lives in. \n";
		std::cout << "Find arrows and kill the wumpus before it finds you. \n";
		//main();
	}

	else if (choice == 4) {// Quit game
		exit(0);
	}
	else {  // Default for any input outside 1-4
		std::cout << "Invalid Choice.  Please try again. " << std::endl;
	}
	return 0;
}