#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

// �����ձ� ����

using namespace std;
string word;

bool end_start_match(string word1, string word2) {
    // �� �ܾ��� ������ ��ġ�ϴ��� Ȯ���ϴ� �Լ�
    return word1.back() == word2.front();
}

int main() {
    vector<string> wordList;

    // ������ �ð� ����
    auto timeout = chrono::seconds(30);
    // ���� �ð� ����
    auto start = chrono::steady_clock::now();

    string currentWord;
    bool gameover = false;

    // �ʱ� �ܾ� ����
    cout << "�����ձ� ������ �����մϴ�." << endl;
    cin >> currentWord;
    cout << "���� �ܾ �Է��ϼ��� : " << currentWord << endl;
    wordList.push_back(currentWord);

    while (true) {
        string nextWord;
        cin >> nextWord;

        // �����ձ� ��Ģ �˻�
        if (end_start_match(currentWord, nextWord)) {
            // ��Ģ�� ���� ��� ���
            wordList.push_back(nextWord);
            currentWord = nextWord;
        }
        else {
            cout << "�����ձ� ��Ģ�� ���� �ʽ��ϴ�." << endl;
        }

        // �ð� üũ
        auto end = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::seconds>(end - start);
        if (elapsed > timeout) {
            cout << "�ð� �ʰ�! ���� ����" << endl;
            
            break;
        }

        // ���� �ܾ� ��� ���
        cout << "���� �ܾ �Է��ϼ��� : " << word;
        for (const auto& word : wordList) {
            cout << word << "->";
        }
        cout << endl;
    }

    // �Ѵܾ� ���� ���
    
    cout << "�����ձ���� ����! << endl << �� �Է��� �ܾ� ���� : " << wordList.size() << " ��" << endl;
    
    return 0;
}

           