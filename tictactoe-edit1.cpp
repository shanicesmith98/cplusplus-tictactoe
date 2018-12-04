#include <iostream>
using namespace std;

char B[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' }; // board - global

class TicTac {
    public:
    void Player(); // enter players
    void Display(); // call Display to display board (array)
    void PlayerTurn(); // gives players 1 & 2 turns
    char check(); // check winner
};

const char QUIT = '0';

int main() {
    char choice;

    cout << "\t\t\tWelcome to Tic-Tac-Toe!" << endl;
    cout << "\t\tFirst player to get 3 in a row wins!\n" << endl;

    TicTac *round; // pointer for new game to call class member
    round = new TicTac(); // create object round that points to Tic Tac

    round ->Player();
    cout << "\nLet's Begin!\n\n"; 
    round ->Display();
    
    do { // do while loop for gameplay    
    round ->PlayerTurn();
    round ->Display();
    round ->check();
    } while (choice != QUIT);
        
    if (check() == 'X') {
        cout << "Player 1 wins!" << endl;
    }
    else if (check() == 'X') {
        cout << "Player 2 wins!" << endl;
    }
    else {
      cout << "It's a tie!" << endl;
    }
    
    delete round; // return round object to memory
    return 0;
}

void TicTac::Display(){ // display board and changes throughout game
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

void TicTac::PlayerTurn(){ //playmode for players
    int choice, player = 1;
    
    cout << "Make your move Player " << player << " (Enter a number from 1 - 9): ";
    cin >> choice;
    cout << endl;

    switch(choice){
            case 1:
                B[0] = 'X';
                break;
            case 2:
                B[1] = 'X';
                break;
            case 3:
                B[2] = 'X';
                break;
            case 4:
                B[3] = 'X';
                break;
            case 5:
                B[4] = 'X';
                break;
            case 6:
                B[5] = 'X';
                break;
            case 7:
                B[6] = 'X';
                break;
            case 8:
                B[7] = 'X';
                break;
            case 9:
                B[8] = 'X';
                break;
            default:
                cout << "Oops.. Try again!" << endl;
        }      
        player++;
        if (player > '2')
            player--;
}

char TicTac::check(){ // gives X or O
    if (B[0] == 'X' && B[1] == 'X' && B[2] == 'X')
        return 'X';
    else if (B[3] == 'X' && B[4] == 'X' && B[5] == 'X')
        return 'X';
    else if (B[6] == 'X' && B[7] == 'X' && B[8] == 'X')
        return 'X';
    else if (B[0] == 'X' && B[3] == 'X' && B[6] == 'X')
        return 'X';
    else if (B[1] == 'X' && B[4] == 'X' && B[7] == 'X')
        return 'X';
    else if (B[2] == 'X' && B[5] == 'X' && B[8] == 'X')
        return 'X';
    else if (B[0] == 'X' && B[4] == 'X' && B[8] == 'X')
        return 'X';
    else if (B[2] == 'X' && B[4] == 'X' && B[6] == 'X')
        return 'X';
    if (B[0] == 'O' && B[1] == 'O' && B[2] == 'O')
        return 'O';
    else if (B[3] == 'O' && B[4] == 'O' && B[5] == 'O')
        return 'O';
    else if (B[6] == 'O' && B[7] == 'O' && B[8] == 'O')
        return 'O';
    else if (B[0] == 'O'&& B[3] == 'O' && B[6] == 'O')
        return 'O';
    else if (B[1] == 'O'&& B[4] == 'O' && B[7] == 'O')
        return 'O';
    else if (B[2] == 'O' && B[5] == 'O' && B[8] == 'O')
        return 'O';
    else if (B[0] == 'O' && B[4] == 'O' && B[8] == 'O')
        return 'O';
    else if (B[2] == 'O' && B[4] == 'O' && B[6] == 'O')
        return 'O';
    else
        return '/';
}