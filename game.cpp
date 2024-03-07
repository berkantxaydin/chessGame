#include <iostream>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <cctype>
#include "bridge.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::min;
using std::max;

const int boardSize = 8;

void printBoard(string** board) {
    setTextColor(33);
    cout << "#########################################################" << endl;
    setTextColor(35);
    cout << "###AA#####BB#####CC#####DD#####EE#####FF#####GG#####HH###";
    resetColor();
    cout << endl << "#" << setw(7) << "#"<< setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << endl;
    for (int i = 0; i < boardSize; i++) {
        setTextColor(33);
        cout << i+1;
        for (int j = 0; j < boardSize; j++) {
            cout << setw(4) << board[i][j] << setw(3) << "#";
        }
        resetColor();
        cout << endl << "#" << setw(7) << "#"<< setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << setw(7) << "#" << endl;
    }
    setTextColor(35);
    cout << "###AA#####BB#####CC#####DD#####EE#####FF#####GG#####HH###" << endl;
    setTextColor(33);
    cout << "#########################################################" << endl;
    resetColor();
}

int initializeGame(){ 
    system("cls");
    string** board = new string*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        board[i] = new string[boardSize];
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = "  ";
        }
    }
    board[0][0] = "RK";board[0][1] = "KN";board[0][2] = "BP";board[0][3] = "QN";board[0][4] = "KG";board[0][5] = "BP";board[0][6] = "KN";board[0][7] = "RK"; 
    board[1][0] = "PN";board[1][1] = "PN";board[1][2] = "PN";board[1][3] = "PN";board[1][4] = "PN";board[1][5] = "PN";board[1][6] = "PN";board[1][7] = "PN";

    board[6][0] = "pn";board[6][1] = "pn";board[6][2] = "pn";board[6][3] = "pn";board[6][4] = "pn";board[6][5] = "pn";board[6][6] = "pn";board[6][7] = "pn";
    board[7][0] = "rk";board[7][1] = "kn";board[7][2] = "bp";board[7][3] = "qn";board[7][4] = "kg";board[7][5] = "bp";board[7][6] = "kn";board[7][7] = "rk";


    int currentPlayer = 1;
    while(true) {
        system("cls");
        printBoard(board);
        cout << endl << "Enter your move PLAYER "<< currentPlayer << "(A2B4): ";
        string move;
        cin >> move;
        if (move.length() != 4 && move.length() != 7) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        } else if (move.length() == 7){
            return false;
        }
        int fromX = move[0] - 'A';
        int fromY = move[1] - '1';
        int toX = move[2] - 'A';
        int toY = move[3] - '1';
        if (fromX < 0 || fromX >= boardSize || fromY < 0 || fromY >= boardSize || toX < 0 || toX >= boardSize || toY < 0 || toY >= boardSize) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }
        if (board[fromY][fromX] == "  ") {
            cout << "No piece at that location." << endl;
            getch();
            continue;
        }


        if(currentPlayer == 2){
            goto skipPlayer1;
        }
        //knight(KN)
        if ((board[fromY][fromX] == "KN") &&
            ((abs(fromX - toX) != 1 || abs(fromY - toY) != 2) && (abs(fromX - toX) != 2 || abs(fromY - toY) != 1))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(isupper(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "OK KNIGHT" << endl;
            getch();
        }
        //bishop(BP)
        if ((board[fromY][fromX] == "BP") &&
            ((abs(fromX - toX) != abs(fromY - toY)))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(isupper(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "OK BISHOP" << endl;
            getch();
        }
        //rook(RK)
        if ((board[fromY][fromX] == "RK") &&
            ((fromX != toX && fromY != toY))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(isupper(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "OK ROOK" << endl;
            getch();
        }
        //queen(QN)
        if ((board[fromY][fromX] == "QN") &&
            (((fromX != toX && fromY != toY)) && ((abs(fromX - toX) != abs(fromY - toY))))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(isupper(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "YES" << endl;
            getch();
        }
        //king(KG)
        if ((board[fromY][fromX] == "KG") &&
            ((abs(fromX - toX) > 1 || abs(fromY - toY) > 1))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(isupper(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "OK KING" << endl;
            getch();
        } 
        // PLAYER 1 END
        skipPlayer1:;
        if(currentPlayer == 1){
            goto skipPlayer2;
        }
        //knight(kn)
        if ((board[fromY][fromX] == "kn") &&
            ((abs(fromX - toX) != 1 || abs(fromY - toY) != 2) && (abs(fromX - toX) != 2 || abs(fromY - toY) != 1))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(islower(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "OK KNIGHT" << endl;
            getch();
        }
        //bishop(bp)
        if ((board[fromY][fromX] == "bp") &&
            ((abs(fromX - toX) != abs(fromY - toY)))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(islower(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "OK BISHOP" << endl;
            getch();
        }
        //rook(rk)
        if ((board[fromY][fromX] == "rk") &&
            ((fromX != toX && fromY != toY))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(islower(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "OK ROOK" << endl;
            getch();
        }
        //queen(qn)
        if ((board[fromY][fromX] == "qn") &&
            (((fromX != toX && fromY != toY)) && ((abs(fromX - toX) != abs(fromY - toY))))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(islower(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "YES" << endl;
            getch();
        }
        //king(kg)
        if ((board[fromY][fromX] == "kg") &&
            ((abs(fromX - toX) > 1 || abs(fromY - toY) > 1))) {
            cout << "Invalid move." << endl;
            getch();
            continue;
        }else if(islower(board[toY][toX][1])) {
            cout << "Invalid move. Path Blocked by Ally" << endl;
            getch();
            continue;
        }else{
            cout << "OK KING" << endl;
            getch();
        }
        //PLAYER 2 END


        skipPlayer2:;
        currentPlayer = (currentPlayer == 1) ? 2 : 1;


        if (board[toY][toX] == "KG" && "kg"){
        cout << "Game Over!";
        getch();
        return false;
        }   
           
        if (board[toY][toX] != "  ") {
        cout << "You ate " << board[toY][toX] << endl;
        getch();
        }

        board[toY][toX] = board[fromY][fromX];
        board[fromY][fromX] = "  ";
    }


    for (int i = 0; i < boardSize; i++) {
        delete[] board[i];
    }
    delete[] board;

    getch();
    return false;
}
