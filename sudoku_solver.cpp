#include <iostream>
#include <vector>



// ������ SOLVER

using namespace std;

const int BOARD_SIZE = 9; // ������ ������ ũ��

// ������ ���带 ����ϴ� �Լ�
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}



// ����ڷκ��� ������ ���带 �ʱ�ȭ�ϴ� �Լ�
void initializeBoard(vector<vector<int>>& board) {
    
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << "�� " << i + 1 << ": ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cin >> board[i][j];
        }
    }
}

// Ư�� ��ġ�� ���ڸ� �Է��� �� �ִ��� Ȯ���ϴ� �Լ�
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {

    // ���� �࿡ �ߺ��� ���ڰ� �ִ��� Ȯ��
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == num) {
            return false;
        }
    }
    // ���� ���� �ߺ��� ���ڰ� �ִ��� Ȯ��
    for (int i = 0; i < BOARD_SIZE; ++i) {


        if (board[i][col] == num) {
            return false;
        }
    }
    // 3x3 ����׸��忡 �ߺ��� ���ڰ� �ִ��� Ȯ��
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// ������ ���带 �ذ��ϴ� �Լ�
bool solveSudoku(vector<vector<int>>& board) {
    int row, col;

    // �� ĭ ã��
    bool isEmpty = false;
    for (row = 0; row < BOARD_SIZE; ++row) {
        for (col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // �� ĭ�� ������ ������ �ϼ������� �ǹ�
    if (!isEmpty) {
        return true;
    }

    // �� ĭ�� 1���� 9������ ���ڸ� �õ��ϸ� ��ȿ���� Ȯ��
    for (int num = 1; num <= 9; ++num) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            // ���� ���ڷ� ������ �ذ��� �� ������ �ٽ� 0���� �ʱ�ȭ
            board[row][col] = 0;
        }
    }
    return false; // ���� ������ ���¿����� �ذ��� �� ����
}

int main() {
    vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0)); // �ʱ� ������ ���� ����
    cout << endl;
    
    initializeBoard(board); // ����ڷκ��� ������ ���� �ʱ�ȭ
    cout << "������ ���� STAGE 1 : " << endl;
    printBoard(board); // �ʱ�ȭ�� ������ ���� ���

    if (solveSudoku(board)) {
        cout << "�ذ�� ������ ����:" << endl;
        printBoard(board); // �ذ�� ������ ���� ���
    }
    else {
        cout << "�ذ��� �� ���� �������Դϴ�." << endl;
    }

    return 0;
}