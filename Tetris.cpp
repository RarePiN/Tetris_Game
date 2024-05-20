#include <iostream>
#include <string>
#include <random>
#include <conio.h>
#include <chrono>
#include <thread>
#include <Windows.h>
using namespace std;

class Game{
	private:
		int board[10][20];	// Grid of the game board
		int currentPiece;	// Current piece
		int nextPiece;		// Next piece
		int score;		// Current Score
		int cleared;		// Total line cleared
		int level;		// Current level
		bool gameOver;		// If the game is over
		int fps;		// Target fps
		int frame;		// Current frame
		
		void boardClear() { // Clear board
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 20; j++) board[i][j] = 0;
			}
			return;
		}
		
		void getNextPiece() {	// Generate a random next piece
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distribution(1, 7);
			
			nextPiece = distribution(gen);
		}
		
		void clearScreen() {
			system("cls");
			return;
		}

		void updatePiece(char keypress) {
		}
		
		void placePiece() {
		}
		
		bool checkGameOver() {
		}
		
		void handleInput() {
			if (_kbhit()) { // Check if a key is pressed
        		char key = _getch(); // Get the key pressed

				// Process the key press
				switch (key) {
					case 'a': // Left Movement
						
						break;
					case 'd': // Right Movement
						
						break;
					case 's': // Down Movement
						
						break;
					case 'w': // Hard Drop
						
						break;
					case 'q': // Left Spin

						break;
					case 'e': // Right Spin

						break;
					case 'p': // Pause or Exit
						gameOver = true;
						break;
				}
			}
		}
		
		void updateScore(int line, int level) {
            		if (line == 4) score += (1200 * (level + 1)); //Tetris
            		if (line == 3) score += (300 * (level + 1));  //Triple
            		if (line == 2) score += (100 * (level + 1));  //Double
            		if (line == 1) score += (40 * (level + 1));   //Single 
            		return;
		}

		void clearLine(int pos, int count) {
			for (int i = pos; i < pos + count; i++) {
				for (int j = 0; j < 10; j++) {
					board[j][i] = 0;
				}
			}	// Clear lines start from pos
			
			for (int i = pos + count; i < 20; i++) {
				for (int j = 0; j < 10; j++) {
					board[j][i - count] = board [j][i];
					board[j][i] = 0; 
				}
			}	// Move the lines down

			updateScore(count, level);
			cleared += count;
			updateLevel();

			return;
		}
		
		void updateLevel() {
			level = (cleared / 10);
		}
		
		void gameIsOver() {
			cout << "Game Over!" << endl;
			return;
		}
		
		void drawBoard() {
			string output;  // String to store the output for each row

			bool isVerticalBorder = false;

			for (int i = 0; i < 21; ++i) {
				output.clear();  // Clear the output string for each row

				isVerticalBorder = (i != 20);

				for (int j = 0; j < 12; ++j) {
					bool isInnerCell = (i != 20 && (j > 0 && j < 11));

					if (isVerticalBorder) {
						if (j == 0 || j == 11) {
							output += "|";
						} else if (isInnerCell) {
							int cellValue = board[j - 1][19 - i];
							output += (cellValue == 1) ? "[]" : "  ";
						}
					} else {  // i == 20
						if (j == 0 || j == 11) {
							output += "+";
						} else {
							output += "==";
						}
					}
				}

				// Append additional output for specific rows
				if (i == 0) {
					output += "   Score:";
				} else if (i == 1) {
					output += "   " + to_string(score);
				} else if (i == 3) {
					output += "   Level:";
				} else if (i == 4) {
					output += "   " + to_string(level);
				} else if (i == 6) {
					output += "   Next:";
				} else if (i == 18) {
					output += "   FPS: " + to_string(fps);
				} else if (i == 19) {
					output += "   " + to_string(frame);
				}

				cout << output << endl;
			}
		}
		
	public:
		Game(int s, int l, int c, bool g, int f) {
    			score = s;			// Current Score
    			level = l;			// Current level
			cleared = c;
    			gameOver = g;			// If the game is over
    			fps = f;			// Target fps		
			frame = 0;	
            		boardClear();
		}

		void start() {	// Main Game Loop

			while(gameOver == false) {
				clearScreen();
				handleInput();
				drawBoard();
				this_thread::sleep_for(chrono::milliseconds(1000 / fps));
				frame += 1;
				if (frame == fps) {
					frame = 0;
				}
			}

			gameIsOver();

		}
};

int main() {
	Game Tetris(0, 0, 0, false, 24);
	Tetris.start();
	return 0;
}
