#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

void drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int winner() {
    // Gorizontal va vertikal tekshirish
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    // Diagonal tekshirish
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';

    if (current_player == 1)
        current_player = 2;
    else
        current_player = 1;
}

void game() {
    cout << "1-o'yinchi, X yoki O ni tanlang: ";
    cin >> current_marker;
    current_player = 1;

    drawBoard();
    int player_won = 0;

    for (int i = 0; i < 9; i++) {
        int slot;
        cout << "O'yinchi " << current_player << ", raqamni kiriting (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Noto'g'ri joy tanlandi, qayta urinib ko'ring!\n";
            i--;
            continue;
        }

        drawBoard();
        player_won = winner();
        if (player_won != 0) {
            cout << "🎉 O'yinchi " << player_won << " g'olib bo'ldi! 🎉\n";
            return;
        }

        swapPlayerAndMarker();
    }

    cout << "O'yin durrang! 😐\n";
}

int main() {
    game();
    return 0;
}
