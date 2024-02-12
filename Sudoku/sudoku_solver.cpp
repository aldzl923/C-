#include <iostream>
#include <vector>



// 스도쿠 SOLVER

using namespace std;

const int BOARD_SIZE = 9; // 스도쿠 보드의 크기

// 스도쿠 보드를 출력하는 함수
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}



// 사용자로부터 스도쿠 보드를 초기화하는 함수
void initializeBoard(vector<vector<int>>& board) {
    
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << "행 " << i + 1 << ": ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cin >> board[i][j];
        }
    }
}

// 특정 위치에 숫자를 입력할 수 있는지 확인하는 함수
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {

    // 같은 행에 중복된 숫자가 있는지 확인
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == num) {
            return false;
        }
    }
    // 같은 열에 중복된 숫자가 있는지 확인
    for (int i = 0; i < BOARD_SIZE; ++i) {

        if (board[i][col] == num) {
            return false;
        }
    }
    // 3x3 서브그리드에 중복된 숫자가 있는지 확인
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

// 스도쿠 보드를 해결하는 함수
bool solveSudoku(vector<vector<int>>& board) {
    int row, col;

    // 빈 칸 찾기
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

    // 빈 칸이 없으면 스도쿠가 완성됐음을 의미
    if (!isEmpty) {
        return true;
    }

    // 빈 칸에 1부터 9까지의 숫자를 시도하며 유효한지 확인
    for (int num = 1; num <= 9; ++num) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            // 현재 숫자로 스도쿠를 해결할 수 없으면 다시 0으로 초기화
            board[row][col] = 0;
        }
    }
    return false; // 현재 스도쿠 상태에서는 해결할 수 없음
}

int main() {
    vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0)); // 초기 스도쿠 보드 생성
    cout << endl;
    
    initializeBoard(board); // 사용자로부터 스도쿠 보드 초기화
    cout << "스도쿠 게임 STAGE 1 : " << endl;
    printBoard(board); // 초기화된 스도쿠 보드 출력

    if (solveSudoku(board)) {
        cout << "해결된 스도쿠 보드:" << endl;
        printBoard(board); // 해결된 스도쿠 보드 출력
    }
    else {
        cout << "해결할 수 없는 스도쿠입니다." << endl;
    }

    return 0;
}