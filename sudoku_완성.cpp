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
void saveRecord(const string& playerName, int stage, int timeInSeconds) {
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

    // 3x3 �׸��带 �˻�
    int startRow = row - row % 3;   //0���� 8����
    int startCol = col - col % 3;   //0,1,2 >> 0,1,2 >> 3.4.5 >> 0 1 2 >> 6 7 8 >> 0 1 2
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// ������ ���带 ����ϴ� �Լ�
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// ������ ���带 ä��� �Լ�
bool fillSudoku(vector<vector<int>>& board) {
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

    // �� ĭ�� 1���� 9������ ���ڸ� ������ ������ �õ��ϸ� ��ȿ���� Ȯ��
    vector<int> numbers({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    random_shuffle(numbers.begin(), numbers.end());  // ���ڸ� ������ ������ ����

    for (int num : numbers) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (fillSudoku(board)) {
                return true;
            }
            // ���� ���ڷ� ������ ä�� �� ������ �ٽ� 0���� �ʱ�ȭ
            board[row][col] = 0;
        }
    }
    return false; // ���� ������ ���¿����� ä�� �� ����
}

// ������ ���尡 �������� ��Ģ�� ��� �����ϴ��� Ȯ���ϴ� �Լ�
bool isSudokuValid(const vector<vector<int>>& board) {
    // �� �࿡ �ߺ��� ���ڰ� �ִ��� Ȯ��
    for (int row = 0; row < BOARD_SIZE; ++row) {
        vector<bool> used(BOARD_SIZE + 1, false);      //used[num] 1���� 9������ ���ڷ� ���� >> ó������ false�� ��� ������� �ʾҴٴ� ��
        for (int col = 0; col < BOARD_SIZE; ++col) {
            int num = board[row][col];
            if (num != 0 && used[num]) {    // num�� 0�� �ƴϰ� �̹� ���� num�̶��
     
                return false; // �ߺ��� ���ڰ� �߰ߵ�
            }
            used[num] = true;
        }
    }

    // �� ���� �ߺ��� ���ڰ� �ִ��� Ȯ��
    for (int col = 0; col < BOARD_SIZE; ++col) {
        vector<bool> used(BOARD_SIZE + 1, false);    //used[num] 0���� 9������ ���ڷ� ���� >> ó������ false�� ��� ������� �ʾҴٴ� ��
        for (int row = 0; row < BOARD_SIZE; ++row) {
            int num = board[row][col];
            if (num != 0 && used[num]) {

                return false; // �ߺ��� ���ڰ� �߰ߵ�
            }
            used[num] = true;
        }
    }

    // �� 3x3 �׸��忡 �ߺ��� ���ڰ� �ִ��� Ȯ��
    for (int startRow = 0; startRow < BOARD_SIZE; startRow += 3) {
        for (int startCol = 0; startCol < BOARD_SIZE; startCol += 3) {
            vector<bool> used(BOARD_SIZE + 1, false);
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    int num = board[startRow + row][startCol + col];
                    if (num != 0 && used[num]) {
                        return false; // �ߺ��� ���ڰ� �߰ߵ�
                    }
                    used[num] = true;
                }
            }
        }
    }

    return true; // ��� ��Ģ�� ������
}

int main() {
    srand(time(NULL));  // ������ �õ� ����

    int stage = 1; // �������� �ʱ�ȭ

    // �÷��̾� �̸� �Է� �ޱ�
    string playerName;
    cout << "�÷��̾� �̸��� �Է��ϼ��� : ";
    getline(cin, playerName);  //����ĥ������ �Է¹���

    // ���� ����
    while (stage <= 3) { // �� ���� ������������ ������ ����
        vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0)); // �ʱ� ������ ���� ����

        fillSudoku(board); // ������ ���� ä���

        // �Ϻ� ���� ����
        for (int i = 0; i < 50; i++) {
            int row = rand() % BOARD_SIZE;
            int col = rand() % BOARD_SIZE;
            board[row][col] = 0;
        }
        cout << " �������� " << stage << endl;
        printBoard(board); // �÷��̾ Ǯ ������ ���� ���

        // ���� ���� �ð� ���
        auto startTime = high_resolution_clock::now();

        // ������ ���尡 �������� Ȯ��
        cout << "������ �Է��ϼ���:" << endl;
        vector<vector<int>> answer(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                cin >> answer[i][j];
                // ���� ����ڰ� 0�� �Է����� ��� ���� ����
                if (answer[i][j] == 0) {
                    cout << "Ʋ�Ƚ��ϴ�. ������ �����մϴ�." << endl;
                    return 0;
                }
            }
        }

        // ���� ���� �ð� ���
        auto endTime = high_resolution_clock::now();

        // ���� �ð� ���
        auto duration = duration_cast<seconds>(endTime - startTime);

        // ������ ���尡 �������� Ȯ���ϰ� �������� ��Ģ�� ��� �����ϴ��� Ȯ��
        bool isCorrect = true;
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

        // ���� ��� ���
        if (isCorrect) {
            cout << "�����Դϴ�!";
            if (stage < 3) {
                cout << " ���� ���������� �����մϴ�." << endl;
            }
            else {
                cout << " ��� ���������� Ŭ�����߽��ϴ�." << endl;
            }
            cout << "���� �ð�: " << duration.count() << "��" << endl; // ���� �ð� ���
            ++stage;
        }
        else {
            cout << "�����Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }



        // ���� ���� �� ��� ����
        saveRecord(playerName, stage, duration.count());
    }

    return 0; // ���α׷� ����
}