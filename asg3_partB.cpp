#include<iostream>
#include<cstring>
using namespace std;

// Since your shitty requirements require me to *not* delete anything in the skeleton
// And the class definition of Card is not defined, and thus non-enforcable.
class Card
{
public:
	Card();
	void setColor(char* n);
	void setValue(int v);
	void setNum(int num);
	char* getColor();
	int getVal();
	int getNum();
private:
	char* color;
	int value;
	int number;
};

// Add your code here.
// You need to implement these access functions and the default constructor in order to complete the class definition of Card.
// No lol

// color is an pointer to color array, while num is an pointer to number array
// Nah fuck off with your bullshit

void initSequence(Card* cardSeq, char colorName[][10], int* color, int* num);
void printSequence(Card* cardSeq);

string coloring(int color) {
        switch (color) {
            case 1: return "Red"; break;
            case 2: return "Yellow"; break;
            case 3: return "Blue"; break;
            case 4: return "Green"; break;
            default: return ""; break;
        }
}

int sequenceInit(int seed, int cardSequence[2][6]) {
    switch (seed) {
        case 1: cardSequence[0][0] = 2; cardSequence[1][0] = 9;
                cardSequence[0][1] = 3; cardSequence[1][1] = 5;
                cardSequence[0][2] = 2; cardSequence[1][2] = 2;
                cardSequence[0][3] = 3; cardSequence[1][3] = 1;
                cardSequence[0][4] = 3; cardSequence[1][4] = 3;
                cardSequence[0][5] = 2; cardSequence[1][5] = 3;
                break;
        case 2: cardSequence[0][0] = 2; cardSequence[1][0] = 3;
                cardSequence[0][1] = 3; cardSequence[1][1] = 3;
                cardSequence[0][2] = 1; cardSequence[1][2] = 4;
                cardSequence[0][3] = 3; cardSequence[1][3] = 8;
                cardSequence[0][4] = 2; cardSequence[1][4] = 2;
                cardSequence[0][5] = 2; cardSequence[1][5] = 2;
                break;
        case 3: cardSequence[0][0] = 1; cardSequence[1][0] = 6;
                cardSequence[0][1] = 3; cardSequence[1][1] = 2;
                cardSequence[0][2] = 4; cardSequence[1][2] = 7;
                cardSequence[0][3] = 3; cardSequence[1][3] = 5;
                cardSequence[0][4] = 2; cardSequence[1][4] = 1;
                cardSequence[0][5] = 2; cardSequence[1][5] = 1;
                break;
        case 4: cardSequence[0][0] = 4; cardSequence[1][0] = 9;
                cardSequence[0][1] = 4; cardSequence[1][1] = 9;
                cardSequence[0][2] = 2; cardSequence[1][2] = 1;
                cardSequence[0][3] = 4; cardSequence[1][3] = 3;
                cardSequence[0][4] = 1; cardSequence[1][4] = 9;
                cardSequence[0][5] = 2; cardSequence[1][5] = 9;
                break;
        case 5: cardSequence[0][0] = 3; cardSequence[1][0] = 2;
                cardSequence[0][1] = 4; cardSequence[1][1] = 6;
                cardSequence[0][2] = 1; cardSequence[1][2] = 3;
                cardSequence[0][3] = 4; cardSequence[1][3] = 1;
                cardSequence[0][4] = 1; cardSequence[1][4] = 7;
                cardSequence[0][5] = 3; cardSequence[1][5] = 8;
                break;
        case 6: cardSequence[0][0] = 3; cardSequence[1][0] = 5;
                cardSequence[0][1] = 4; cardSequence[1][1] = 5;
                cardSequence[0][2] = 3; cardSequence[1][2] = 7;
                cardSequence[0][3] = 1; cardSequence[1][3] = 8;
                cardSequence[0][4] = 1; cardSequence[1][4] = 6;
                cardSequence[0][5] = 3; cardSequence[1][5] = 7;
                break;
        case 7: cardSequence[0][0] = 2; cardSequence[1][0] = 8;
                cardSequence[0][1] = 4; cardSequence[1][1] = 3;
                cardSequence[0][2] = 2; cardSequence[1][2] = 1;
                cardSequence[0][3] = 1; cardSequence[1][3] = 5;
                cardSequence[0][4] = 4; cardSequence[1][4] = 5;
                cardSequence[0][5] = 3; cardSequence[1][5] = 6;
                break;
        case 8: cardSequence[0][0] = 1; cardSequence[1][0] = 1;
                cardSequence[0][1] = 4; cardSequence[1][1] = 9;
                cardSequence[0][2] = 4; cardSequence[1][2] = 4;
                cardSequence[0][3] = 2; cardSequence[1][3] = 3;
                cardSequence[0][4] = 4; cardSequence[1][4] = 3;
                cardSequence[0][5] = 3; cardSequence[1][5] = 5;
                break;
        case 9: cardSequence[0][0] = 1; cardSequence[1][0] = 5;
                cardSequence[0][1] = 4; cardSequence[1][1] = 7;
                cardSequence[0][2] = 3; cardSequence[1][2] = 6;
                cardSequence[0][3] = 2; cardSequence[1][3] = 1;
                cardSequence[0][4] = 3; cardSequence[1][4] = 2;
                cardSequence[0][5] = 3; cardSequence[1][5] = 4;
                break;
        case 10:cardSequence[0][0] = 4; cardSequence[1][0] = 7;
                cardSequence[0][1] = 1; cardSequence[1][1] = 6;
                cardSequence[0][2] = 2; cardSequence[1][2] = 9;
                cardSequence[0][3] = 3; cardSequence[1][3] = 7;
                cardSequence[0][4] = 3; cardSequence[1][4] = 1;
                cardSequence[0][5] = 3; cardSequence[1][5] = 3;
                break;
        case 11:cardSequence[0][0] = 3; cardSequence[1][0] = 1;
                cardSequence[0][1] = 1; cardSequence[1][1] = 4;
                cardSequence[0][2] = 4; cardSequence[1][2] = 3;
                cardSequence[0][3] = 3; cardSequence[1][3] = 5;
                cardSequence[0][4] = 3; cardSequence[1][4] = 8;
                cardSequence[0][5] = 3; cardSequence[1][5] = 2;
                break;
        case 12:cardSequence[0][0] = 2; cardSequence[1][0] = 4;
                cardSequence[0][1] = 1; cardSequence[1][1] = 1;
                cardSequence[0][2] = 3; cardSequence[1][2] = 6;
                cardSequence[0][3] = 4; cardSequence[1][3] = 2;
                cardSequence[0][4] = 2; cardSequence[1][4] = 7;
                cardSequence[0][5] = 3; cardSequence[1][5] = 1;
                break;
        case 13:cardSequence[0][0] = 2; cardSequence[1][0] = 6;
                cardSequence[0][1] = 1; cardSequence[1][1] = 9;
                cardSequence[0][2] = 1; cardSequence[1][2] = 8;
                cardSequence[0][3] = 4; cardSequence[1][3] = 9;
                cardSequence[0][4] = 2; cardSequence[1][4] = 6;
                cardSequence[0][5] = 3; cardSequence[1][5] = 9;
                break;
        case 14:cardSequence[0][0] = 1; cardSequence[1][0] = 9;
                cardSequence[0][1] = 1; cardSequence[1][1] = 7;
                cardSequence[0][2] = 4; cardSequence[1][2] = 3;
                cardSequence[0][3] = 4; cardSequence[1][3] = 6;
                cardSequence[0][4] = 1; cardSequence[1][4] = 5;
                cardSequence[0][5] = 3; cardSequence[1][5] = 8;
                break;
        case 15:cardSequence[0][0] = 4; cardSequence[1][0] = 3;
                cardSequence[0][1] = 1; cardSequence[1][1] = 5;
                cardSequence[0][2] = 2; cardSequence[1][2] = 6;
                cardSequence[0][3] = 1; cardSequence[1][3] = 4;
                cardSequence[0][4] = 1; cardSequence[1][4] = 4;
                cardSequence[0][5] = 4; cardSequence[1][5] = 7;
                break;
        case 16:cardSequence[0][0] = 3; cardSequence[1][0] = 6;
                cardSequence[0][1] = 2; cardSequence[1][1] = 3;
                cardSequence[0][2] = 1; cardSequence[1][2] = 9;
                cardSequence[0][3] = 1; cardSequence[1][3] = 2;
                cardSequence[0][4] = 4; cardSequence[1][4] = 2;
                cardSequence[0][5] = 4; cardSequence[1][5] = 6;
                break;
        case 17:cardSequence[0][0] = 3; cardSequence[1][0] = 8;
                cardSequence[0][1] = 2; cardSequence[1][1] = 1;
                cardSequence[0][2] = 4; cardSequence[1][2] = 2;
                cardSequence[0][3] = 2; cardSequence[1][3] = 2;
                cardSequence[0][4] = 4; cardSequence[1][4] = 1;
                cardSequence[0][5] = 4; cardSequence[1][5] = 5;
                break;
        case 18:cardSequence[0][0] = 2; cardSequence[1][0] = 2;
                cardSequence[0][1] = 2; cardSequence[1][1] = 8;
                cardSequence[0][2] = 2; cardSequence[1][2] = 5;
                cardSequence[0][3] = 2; cardSequence[1][3] = 6;
                cardSequence[0][4] = 4; cardSequence[1][4] = 9;
                cardSequence[0][5] = 4; cardSequence[1][5] = 4;
                break;
        case 19:cardSequence[0][0] = 1; cardSequence[1][0] = 5;
                cardSequence[0][1] = 2; cardSequence[1][1] = 7;
                cardSequence[0][2] = 1; cardSequence[1][2] = 8;
                cardSequence[0][3] = 3; cardSequence[1][3] = 4;
                cardSequence[0][4] = 3; cardSequence[1][4] = 8;
                cardSequence[0][5] = 4; cardSequence[1][5] = 3;
                break;
        case 20:cardSequence[0][0] = 4; cardSequence[1][0] = 7;
                cardSequence[0][1] = 2; cardSequence[1][1] = 4;
                cardSequence[0][2] = 3; cardSequence[1][2] = 1;
                cardSequence[0][3] = 3; cardSequence[1][3] = 2;
                cardSequence[0][4] = 3; cardSequence[1][4] = 7;
                cardSequence[0][5] = 4; cardSequence[1][5] = 2;
                break;
        default:cardSequence[0][0] = 1; cardSequence[1][0] = 1;
                cardSequence[0][1] = 1; cardSequence[1][1] = 1;
                cardSequence[0][2] = 1; cardSequence[1][2] = 4;
                cardSequence[0][3] = 1; cardSequence[1][3] = 5;
                cardSequence[0][4] = 1; cardSequence[1][4] = 1;
                cardSequence[0][5] = 1; cardSequence[1][5] = 4;
                break;
    }
    return 0;
}

int printCard(int cardSequence[2][6]) {
        for (int i = 0; i < 6; i++) {
                if (cardSequence[0][i] == -1) continue; // skip if card is indicated to be used
                cout << coloring(cardSequence[0][i]) << cardSequence[1][i] << ' ';
        }
        return 0; // no additional formatting besides spaces after each remaining card
}

bool drawcheck(int self[2][6], int comp[2][6]) {
        bool draw = true;
        for (int i = 0; i < 6; i++) {
                if (self[0][i] + comp[0][i] != -2) {
                        draw = false;
                        break;}
        }
        return draw;
}

int computerLogic(int computerCardSequence[2][6], int face[2]) {
        for (int i = 0; i < 6; i++) {
                if ((face[0] == -1) && (face[1] == -1)) {
                        face[0] = computerCardSequence[0][0]; // plays the first card in the first round.
                        face[1] = computerCardSequence[1][0];
                        computerCardSequence[0][i] = -1;
                        computerCardSequence[1][i] = -1;
                        break; //mark card as used
                }
                if ((computerCardSequence[0][i] == -1) && i < 5) continue; //skip used cards.

                if ((computerCardSequence[0][i] == face[0]) || (computerCardSequence[1][i] == face[1])) {
                        face[0] = computerCardSequence[0][i];
                        face[1] = computerCardSequence[1][i];
                        computerCardSequence[0][i] = -1;
                        computerCardSequence[1][i] = -1;
                        break; //mark card as used
                }

                if (i >= 5) return 1; // this point is only reached if there are no matching cards by the computer.
        }
        return 0;
}

int main() {
	// Add your code here.

        int selfCardSequence [2][6];
        int computerCardSequence [2][6];
                                // [0] is color, [1] is value
                                // in color, Red 1, Yellow 2, Blue 3, Green 4

        int seed;

        cout << "Enter the seed for random number generation: ";
        cin >> seed;
        cout << "\n";
        sequenceInit(seed, selfCardSequence); // pass the array into the function, in case that isnt obvious
        sequenceInit(8, computerCardSequence);
        int face[2] = {-1, -1};
        int playerInput[2];
        bool haveCard;
        cout << "Your card sequence: ";
                printCard(selfCardSequence);
                cout << "\n";
                cout << "\n";
                cout << "Computer's card sequence: ";
                printCard(computerCardSequence);
                cout << "\n";
                cout << "\n";
        while (true) { // the game loop
                // computer logic:
                if (face[0] == -1 && face[1] == -1) {
                        if (computerLogic(computerCardSequence, face)) goto win;
                        }

                cout << "The computer plays " << coloring(face[0]) << face[1] << ", please input two integers to represent the card you plan to play: ";
                // player logic:
                cin >> playerInput[0];
                cin >> playerInput[1];
                cout << "\n";
                if ((playerInput[0] == 0) && (playerInput[1] == 0)) goto lose;
                haveCard = false;
                for (int i = 0; i < 6; i++) {
                        if (selfCardSequence[0][i] == -1) continue; // skip used cards
                        if ((playerInput[0] == selfCardSequence[0][i]) && (playerInput[1] == selfCardSequence[1][i])) {
                                selfCardSequence[0][i] = -1;
                                selfCardSequence[1][i] = -1; //mark card as used
                                haveCard = true;
                                break;
                                }
                }
                if (!haveCard) goto lose;
                if ((playerInput[0] == face[0]) || (playerInput[1] == face[1])) {
                        face[0] = playerInput[0];
                        face[1] = playerInput[1];
                        }
                else goto lose;
                if (drawcheck(selfCardSequence,computerCardSequence)) goto draw;
                if (computerLogic(computerCardSequence, face)) goto win; // move check here after the first round to prevent unneeded output
                cout << "Game continues. Your remaining card(s): ";
                printCard(selfCardSequence);
                cout << "\n";
                cout << "\n";
        }

        win:
                cout << "Game ends. You win";
                return 0;
        lose: 
                cout << "Game ends. you lose";
                return 0;
        draw:
                cout << "Game ends. A draw";
                return 0;
	//initSequence(cardSeq, colorName, &color, &num); <- useless shit
	//printSequence(cardSeq); <- useless shit
	return 0;
}

// Add your code here.
// You need to implement initSequence(Card* cardSeq, char colorName[][10], int* color, int* num) function.

// Add your code here.
// You need to implement printSequence(Card* cardSeq) function.