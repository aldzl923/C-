#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

// 끝말잇기 게임

using namespace std;
string word;

bool end_start_match(string word1, string word2) {
    // 두 단어의 끝말이 일치하는지 확인하는 함수
    return word1.back() == word2.front();
}

int main() {
    vector<string> wordList;

    // 정해진 시간 설정
    auto timeout = chrono::seconds(30);
    // 시작 시간 저장
    auto start = chrono::steady_clock::now();

    string currentWord;
    bool gameover = false;

    // 초기 단어 설정
    cout << "끝말잇기 게임을 시작합니다." << endl;
    cin >> currentWord;
    cout << "다음 단어를 입력하세요 : " << currentWord << endl;
    wordList.push_back(currentWord);

    while (true) {
        string nextWord;
        cin >> nextWord;

        // 끝말잇기 규칙 검사
        if (end_start_match(currentWord, nextWord)) {
            // 규칙에 맞을 경우 통과
            wordList.push_back(nextWord);
            currentWord = nextWord;
        }
        else {
            cout << "끝말잇기 규칙에 맞지 않습니다." << endl;
        }

        // 시간 체크
        auto end = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::seconds>(end - start);
        if (elapsed > timeout) {
            cout << "시간 초과! 게임 종료" << endl;
            
            break;
        }

        // 사용된 단어 목록 출력
        cout << "다음 단어를 입력하세요 : " << word;
        for (const auto& word : wordList) {
            cout << word << "->";
        }
        cout << endl;
    }

    // 총단어 개수 출력
    
    cout << "끝말잇기게임 종료! << endl << 총 입력한 단어 개수 : " << wordList.size() << " 개" << endl;
    
    return 0;
}

           