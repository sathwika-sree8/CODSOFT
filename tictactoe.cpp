#include <iostream>
#include <vector>
using namespace std;

void showBoard(const vector<vector<char>>& board) {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3;j++) {
            if (board[i][j] == ' ') {
                return false;  
            }
        }
    }
    return true;  
}
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    char currentPlayer = 'X';  
    int row, col;
    bool gameWon = false;

    while (!gameWon) {
        showBoard(board);  
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }
        board[row][col] = currentPlayer;
        if (checkWin(board, currentPlayer)) {
            showBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameWon = true;
        } else if (checkDraw(board)) {
            showBoard(board);
            cout << "It's a draw!\n";
            gameWon = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}
bool playAgain() {
    char choice;
    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

int main() {
    bool keepPlaying = true;

    while (keepPlaying) {
        playGame();  // Start a new game
        keepPlaying = playAgain();  // Ask if players want to play again
    }

    cout << "Thanks for playing!\n";
    return 0;
}
