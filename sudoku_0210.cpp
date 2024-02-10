#include <cstdlib>  // srand, rand 함수를 사용하기 위해 추가
#include <algorithm>  // random_shuffle 함수를 사용하기 위해 추가
#include <iostream>  // cout을 사용하기 위해 추가
#include <vector>    // vector를 사용하기 위해 추가
#include <chrono>  // 시간 측정을 위해 추가
#include <fstream> // 파일 입출력을 위해 추가
#include <string> // getline 사용하기 위해 추가

using namespace std;
using namespace std::chrono;

// 기록을 저장할 파일의 경로
const string RECORDS_FILE = "Sudoku_record.txt";

// 플레이어의 기록을 저장하는 함수
void saveRecord(string playerName, int stage, int timeInSeconds) {
    ofstream file(RECORDS_FILE, ios::app); // 파일을 추가 모드로 열기

    if (file.is_open()) {
        file << "플레이어: " << playerName << ", 스테이지: " << stage - 1 << ", 소요 시간: " << timeInSeconds << "초" << endl;
    }
}

const int BOARD_SIZE = 9; // 스도쿠 보드의 크기

// 스도쿠 보드를 출력하는 함수
void printBoard(const vector<vector<int>>& board);

bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // 행과 열을 검사 
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
}

int main() {
   
}
