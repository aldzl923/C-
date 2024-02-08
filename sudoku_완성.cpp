#include <cstdlib>  // srand, rand 함수를 사용하기 위해 추가
#include <algorithm>  // random_shuffle 함수를 사용하기 위해 추가
#include <iostream>  // cout을 사용하기 위해 추가
#include <vector>    // vector를 사용하기 위해 추가
#include <chrono>  // 시간 측정을 위해 추가

using namespace std;
using namespace std::chrono;

const int BOARD_SIZE = 9; // 스도쿠 보드의 크기

// 스도쿠 보드를 출력하는 함수
void printBoard(const vector<vector<int>>& board);

// 스도쿠 보드 상태가 유효한지 확인하는 함수
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // 행과 열을 검사
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // 3x3 그리드를 검사
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// 스도쿠 보드를 출력하는 함수
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// 스도쿠 보드를 채우는 함수
bool fillSudoku(vector<vector<int>>& board) {
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

    // 빈 칸에 1부터 9까지의 숫자를 랜덤한 순서로 시도하며 유효한지 확인
    vector<int> numbers({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    random_shuffle(numbers.begin(), numbers.end());  // 숫자를 랜덤한 순서로 섞음

    for (int num : numbers) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (fillSudoku(board)) {
                return true;
            }
            // 현재 숫자로 스도쿠를 채울 수 없으면 다시 0으로 초기화
            board[row][col] = 0;
        }
    }
    return false; // 현재 스도쿠 상태에서는 채울 수 없음
}

// 스도쿠 보드가 스도쿠의 규칙을 모두 만족하는지 확인하는 함수
bool isSudokuValid(const vector<vector<int>>& board) {
    // 각 행에 중복된 숫자가 있는지 확인
    for (int row = 0; row < BOARD_SIZE; ++row) {
        vector<bool> used(BOARD_SIZE + 1, false);
        for (int col = 0; col < BOARD_SIZE; ++col) {
            int num = board[row][col];
            if (num != 0 && used[num]) {
                return false; // 중복된 숫자가 발견됨
            }
            used[num] = true;
        }
    }

    // 각 열에 중복된 숫자가 있는지 확인
    for (int col = 0; col < BOARD_SIZE; ++col) {
        vector<bool> used(BOARD_SIZE + 1, false);
        for (int row = 0; row < BOARD_SIZE; ++row) {
            int num = board[row][col];
            if (num != 0 && used[num]) {
                return false; // 중복된 숫자가 발견됨
            }
            used[num] = true;
        }
    }

    // 각 3x3 그리드에 중복된 숫자가 있는지 확인
    for (int startRow = 0; startRow < BOARD_SIZE; startRow += 3) {
        for (int startCol = 0; startCol < BOARD_SIZE; startCol += 3) {
            vector<bool> used(BOARD_SIZE + 1, false);
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    int num = board[startRow + row][startCol + col];
                    if (num != 0 && used[num]) {
                        return false; // 중복된 숫자가 발견됨
                    }
                    used[num] = true;
                }
            }
        }
    }

    return true; // 모든 규칙을 만족함
}

int main() {
    srand(time(NULL));  // 랜덤한 시드 설정

    int stage = 1; // 스테이지 초기화

    while (stage <= 3) { // 세 번의 스테이지까지 게임을 진행
        vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0)); // 초기 스도쿠 보드 생성

        fillSudoku(board); // 스도쿠 보드 채우기

        // 일부 숫자 제거
        for (int i = 0; i < 1; ++i) {
            int row = rand() % BOARD_SIZE;
            int col = rand() % BOARD_SIZE;
            board[row][col] = 0;
        }
        cout << "스테이지 " << stage << " 플레이어가 풀 스도쿠 보드:" << endl;
        printBoard(board); // 플레이어가 풀 스도쿠 보드 출력

        // 게임 시작 시간 기록
        auto startTime = high_resolution_clock::now();

        // 스도쿠 보드가 정답인지 확인
        cout << "정답을 입력하세요:" << endl;
        vector<vector<int>> answer(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                cin >> answer[i][j];
                // 만약 사용자가 0을 입력했을 경우 게임 종료
                if (answer[i][j] == 0) {
                    cout << "틀렸습니다. 게임을 종료합니다." << endl;
                    return 0;
                }
            }
        }

        // 게임 종료 시간 기록
        auto endTime = high_resolution_clock::now();

        // 게임 시간 계산
        auto duration = duration_cast<seconds>(endTime - startTime);

        // 스도쿠 보드가 정답인지 확인하고 스도쿠의 규칙을 모두 만족하는지 확인
        bool isCorrect = true;
        if (!isSudokuValid(answer)) {
            isCorrect = false;
        }
        else {
            for (int i = 0; i < BOARD_SIZE; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    if (board[i][j] != 0 && board[i][j] != answer[i][j]) {
                        isCorrect = false;
                        break;
                    }
                }
                if (!isCorrect) {
                    break;
                }
            }
        }

        if (isCorrect) {
            cout << "정답입니다!";
            if (stage < 3) {
                cout << " 다음 스테이지로 진행합니다." << endl;
            }
            else {
                cout << " 모든 스테이지를 클리어했습니다." << endl << "총 게임 시간: " << duration.count();

            }
            cout << "게임 시간: " << duration.count() << "초" << endl; // 게임 시간 출력
            ++stage;
        }
        else {
            cout << "오답입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}