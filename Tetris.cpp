#include <iostream>
#include <random>
#include <conio.h>
using namespace std;

class Game{
	private:
		int board[10][20];	// Grid of the game board
		int currentPiece;	// Current piece
		int nextPiece;		// Next piece
		int score;			// Current Score
		int cleared;		// Total line cleared
		int level;			// Current level
		bool gameOver;		// If the game is over
		int fps;			// Target fps
		
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
		
		void updatePiece(char keypress) {
		}
		
		void placePiece() {
		}
		
		bool checkGameOver() {
		}
		
		void handleInput() {
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
		}
		
		void drawBoard() {
            for (int i = 0; i < 21; i++) {
                for (int j = 0; j < 12; j++) {
                    if (i != 20 and (j == 0 or j == 11)) {
                        cout << "|";
                    }
                    else if (i != 20 and (j > 0 and j < 11)) {
                           if (board[j-1][19 - i] == 1) cout << "[]";
                           else cout << "  ";
                    }
                    if (i == 20) {
                        if (j == 0 or j == 11) cout << "+";
                        else cout << "==";
                    }
                }

            	if (i == 0) cout << "   Score:";
                if (i == 1) cout << "   " << score;
                if (i == 3) cout << "   Level:";
                if (i == 4) cout << "   " << level;
                if (i == 6) cout << "   Next:";
                cout << endl;
            }
		}
		
		void start() {	// Main Game Loop
		}
		
	public:
		Game(int s, int l, int c, bool g, int f) {
    		score = s;			// Current Score
    		level = l;			// Current level
			cleared = c;
    		gameOver = g;		// If the game is over
    		fps = f;			// Target fps			
            boardClear();
		}
};

int main() {
    Game Tetris(0, 0, 0, false, 30);

    return 0;
}

