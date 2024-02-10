#include <cstdlib>  // srand, rand �Լ��� ����ϱ� ���� �߰�
#include <algorithm>  // random_shuffle �Լ��� ����ϱ� ���� �߰�
#include <iostream>  // cout�� ����ϱ� ���� �߰�
#include <vector>    // vector�� ����ϱ� ���� �߰�
#include <chrono>  // �ð� ������ ���� �߰�
#include <fstream> // ���� ������� ���� �߰�
#include <string> // getline ����ϱ� ���� �߰�

using namespace std;
using namespace std::chrono;

// ����� ������ ������ ���
const string RECORDS_FILE = "Sudoku_record.txt";

// �÷��̾��� ����� �����ϴ� �Լ�
void saveRecord(string playerName, int stage, int timeInSeconds) {
    ofstream file(RECORDS_FILE, ios::app); // ������ �߰� ���� ����

    if (file.is_open()) {
        file << "�÷��̾�: " << playerName << ", ��������: " << stage - 1 << ", �ҿ� �ð�: " << timeInSeconds << "��" << endl;
    }
}

const int BOARD_SIZE = 9; // ������ ������ ũ��

// ������ ���带 ����ϴ� �Լ�
void printBoard(const vector<vector<int>>& board);

bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // ��� ���� �˻� 
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
}

int main() {
   
}
