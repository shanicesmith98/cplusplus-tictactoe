#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

char B[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' }; // board - global

class TicTac {
    public:
    void Display(); // call Display to display board (array)
    void giveWinner(); // winner message
    void Player(); // enter players
    int check(); // check winner
};

const char QUIT = '0';

int main() {
    
    int i = -1;
    int choice, player = 1;
    char mark;

    cout << "\t\t\tWelcome to Tic-Tac-Toe!" << endl;
    cout << "\t\tFirst player to get 3 in a row wins!\n" << endl;

    TicTac *round; // pointer for new game to call class member
    round = new TicTac(); // create object round that points to Tic Tac

    round ->Player();
    round ->Display();
    
    player = (player % 2)?1:2; // switch between players
    
    do { // do while loop for gameplay
    cout << "Make your move Player " << player << " (Enter a number from 1 - 9): ";
    cin >> choice;
    
    cout << endl;
    
    mark = (player == 1) ? 'X' : 'O';

    if (choice == '1' && B[0] == 'X') // placement of mark
			B[0] = mark;
	else if (choice == '2' && B[1] == '2')
			B[1] = mark;
	else if (choice == '3' && B[2] == '3')
			B[2] = mark;
	else if (choice == '4' && B[3] == '4')
			B[3] = mark;
	else if (choice == '5' && B[4] == '5')
			B[4] = mark;
	else if (choice == '6' && B[5] == '6')
			B[5] = mark;
	else if (choice == '7' && B[6] == '7')
			B[6] = mark;
	else if (choice == '8' && B[7] == '8')
			B[7] = mark;
	else if (choice == '9' && B[8] == '9')
			B[8] = mark;		
	else {
			cout << "Oops.. Try again!";
			player--;
			cin.ignore();
			cin.get();
        }
        
    round -> check();
    player++;
    } while (i==-1);
        
    if (i == 1 || i == 2){
        round -> giveWinner();
    }
    delete round; // return round object to memory
    return 0;
}

void TicTac::Display(){ // display board at beginning
    cout << "\nLet's Begin!\n\n"; 
    
    for (int i = 0; i < 9; i++) {
            cout << B[i] << ((i % 3 == 2)?'\n':'\t');
                if (i == 2 || i== 5 || i==8){
					cout << "\n";
                }
    }
    cout << endl;
}

void TicTac::Player(){ // enter player names
    string P1, P2;
    
    cout << "\nEnter your name Player 1: ";
    cin >> P1;
    cout << "\nWelcome " << P1 << "!\n" << "You'll play as \'X\'.\n";
    
    cout << "\nEnter your name Player 2: ";
    cin >> P2;
    cout << "\nWelcome " << P2 << "!\n" << "You'll play as \'O\'.\n";
}

int TicTac::check(){ // gives X or O
    if (B[0] == B[1] && B[1] == B[2])
        return 1;
    else if (B[3] == B[4] && B[4] == B[5])
        return 1;
    else if (B[6] == B[7] && B[7] == B[8])
        return 1;
    else if (B[0] == B[3] && B[3] == B[6])
        return 1;
    else if (B[1] == B[4] && B[4] == B[7])
        return 1;
    else if (B[2] == B[5] && B[5] == B[8])
        return 1;
 
    else if (B[0] == B[3] && B[3] == B[6])
        return 1;
    else if (B[6] == B[4] && B[4] == B[2])
        return 1;
 
    if (B[0] == B[1] && B[1] == B[2])
        return 2;
    else if (B[3] == B[4] && B[4] == B[5])
        return 2;
    else if (B[6] == B[7] && B[7] == B[8])
        return 2;
 
    else if (B[0] == B[3] && B[3] == B[6])
        return 2;
    else if (B[1] == B[4] && B[4] == B[7])
        return 'O';
    else if (B[2] == B[5] && B[5] == B[8])
        return 2;
 
    else if (B[0] == B[3] && B[3] == B[6])
        return 2;
    else if (B[6] == B[4] && B[4] == B[2])
        return 2;
    else
        return -1;
}

void TicTac::giveWinner(){ // winner message
    int result = 0;
    if (result == 1) {
        cout << "Player 1 wins!" << endl;
    }
    else if (result == 2) {
        cout << "Player 2 wins!" << endl;
    }
    else {
      cout << "It's a tie!" << endl;
    }
}