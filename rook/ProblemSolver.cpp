
#include <iostream>
using namespace std;

const int N = 8; // ������ �����

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; // �������� �� x
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // �������� �� y

int board[N][N]; // �����

bool is_valid(int x, int y) {
    return (x >= 0 && x < N&& y >= 0 && y < N&& board[x][y] == -1);
}

void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << "\t";
        cout << endl;
    }
}

bool solve(int x, int y, int move_no) {
    if (move_no == N * N) // ��� ������ ���������
        return true;

    for (int i = 0; i < 8; i++) { // ���������� ��� ��������� ����
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (is_valid(new_x, new_y)) {
            board[new_x][new_y] = move_no;
            if (solve(new_x, new_y, move_no + 1))
                return true;
            board[new_x][new_y] = -1; // �������� ���
        }
    }

    return false;
}

int main() {
    // �������������� �����
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    int start_x = 0, start_y = 0;
    board[start_x][start_y] = 0; // ��������� ������� ����

    if (solve(start_x, start_y, 1)) {
        cout << "������� �������:" << endl;
        print_board();
    }
    else {
        cout << "������� �� �������" << endl;
    }

    return 0;
}
