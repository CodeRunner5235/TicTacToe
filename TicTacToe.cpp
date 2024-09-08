//File written by CodeRunner


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;


struct board{
    char grid[3][3];
};

void printBoard(board Z);
int getInput(int &X, int &Y, int &M, board Z);
int winCheck(board Z);

int main(){
    int X = 0;
    int Y = 0;
    int M = 0;
    int count = 0;
    int win = 0;
    board Z;



    while(count < 9){
        Z.grid[Y][X] = ' ';

        if(X < 2){
            X++;
        }
        else{
            Y++;
            X = 0;
        }
        count++;
    }

    count = 0;

    while(win == 0){

        printBoard(Z);
        getInput( X, Y, M, Z);

        if(M == 1){
            Z.grid[Y][X] = 'X';
        }

        if(M == 0){
            Z.grid[Y][X] = 'O';
        }

        win = winCheck(Z);

    }

    printBoard(Z);

    if(win == 1){
        cout << "Player 1 wins!" << endl << endl;
    }

    if(win == 2){
        cout << "Player 2 wins!" << endl << endl;
    }
    if(win == 3){
        cout << "Draw." << endl << endl;
    }

    return 0;
}

void printBoard(board Z){

    #ifdef _WIN32

   	system("cls");

    #else

    	system("clear");
    
    #endif
    
    cout << endl << endl;
    cout << "    1    2    3" << endl;
    cout << "   ____________" << endl;
    cout << "A | " << Z.grid[0][0] << " || " << Z.grid[0][1] << " || " << Z.grid[0][2] << endl;
    cout << "  | =========== " << endl;
    cout << "B | " << Z.grid[1][0] << " || " << Z.grid[1][1] << " || " << Z.grid[1][2] << endl;
    cout << "  | =========== " << endl;
    cout << "C | " << Z.grid[2][0] << " || " << Z.grid[2][1] << " || " << Z.grid[2][2] << endl;
}

int getInput(int &X, int &Y, int &M, board Z){

    char B;

    if(M == 0){
        cout << "Enter your move player 1: ";
        cin >> B >> X;
        X--;
        M = 1;

        if(B == 'A' || B == 'a'){
            Y = 0;
        }
        if(B == 'B' || B == 'b'){
            Y = 1;
        }
        if(B == 'C' || B == 'c'){
            Y = 2;
        }

        while(Z.grid[Y][X] == 'X' || Z.grid[Y][X] == 'O'){
            cout << "This spot is already taken. Please try again." << endl << "Enter your move player 1: ";
            cin >> B >> X;
            X--;
            M = 1;

            if(B == 'A' || B == 'a'){
                Y = 0;
            }
            if(B == 'B' || B == 'b'){
                Y = 1;
            }
            if(B == 'C' || B == 'c'){
                Y = 2;
            }
        }
        return 0;
    }
    if(M == 1){
        cout << "Enter your move player 2: ";
        cin >> B >> X;
        X--;
        M = 0;

        if(B == 'A' || B == 'a'){
            Y = 0;
        }
        if(B == 'B' || B == 'b'){
            Y = 1;
        }
        if(B == 'C' || B == 'c'){
            Y = 2;
        }

        while(Z.grid[Y][X] == 'X' || Z.grid[Y][X] == 'O'){
            cout << "This spot is already taken. Please try again." << endl << "Enter your move player 2: ";
            cin >> B >> X;
            X--;
            M = 0;

            if(B == 'A' || B == 'a'){
                Y = 0;
            }
            if(B == 'B' || B == 'b'){
                Y = 1;
            }
            if(B == 'C' || B == 'c'){
                Y = 2;
            }
        }

        return 0;
    }

}
int winCheck(board Z) {

    int count = 0;
    int X = 0;
    int Y = 0;
    int W = 0;
    char B;

    for (int i = 0; i < 3; i++) {
        if (Z.grid[i][0] == Z.grid[i][1] && Z.grid[i][2] == Z.grid[i][1] && Z.grid[i][2] != ' ') {
            if(Z.grid[i][0] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (Z.grid[0][i] == Z.grid[1][i] && Z.grid[2][i] == Z.grid[1][i] && Z.grid[2][i] != ' ') {
            if(Z.grid[0][i] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
        }
    }

    if (Z.grid[0][0] == Z.grid[1][1] && Z.grid[2][2] == Z.grid[0][0] && Z.grid[0][0] != ' ') {
        if(Z.grid[0][0] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
    }

    if (Z.grid[0][2] == Z.grid[1][1] && Z.grid[2][0] == Z.grid[0][2] && Z.grid[0][2] != ' ') {
        if(Z.grid[2][0] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
    }

    while(count < 9){
        B = Z.grid[Y][X];

        if(B == 'X' || B == 'O'){
            W++;
        }

        if(X < 2){
            X++;
        }
        else{
            Y++;
            X = 0;
        }
        count++;
    }

    if(W == 9){
        return 3;
    }


    return 0;
}
