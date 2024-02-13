#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int ball = 0;
    int strike = 0;
    int try_num = 0;

    vector<int> v1({ 1,2,3,4,5,6,7,8,9}); // 컴퓨터의 벡터
    random_shuffle(v1.begin(), v1.end());
    v1.erase(v1.begin() + 3, v1.end());

    int user_num;

    vector<int>v2;
    while (1) {
        int ball = 0;
        int strike = 0;
        std::cout << "1 ~ 9 사이의 숫자 3개를 입력 하시오 (이외의 숫자: 종료)" << endl;
        try_num++;

        for (int i = 0; i < 3; i++) {
            cin >> user_num;
            if (user_num < 0 || user_num > 9) {
                std::cout << "게임을 종료하였습니다." << endl;
                break;
            }
            else {
                v2.push_back(user_num);
            }
        }

        // 스트라이크 일 때
        for (int i = 0; i < 3; i++) {

            if (v1[i] == v2[i])   // 자릿수와 값이 모두 같을때 strike++
                strike++;
        }

        // 볼 일 때

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j && v1[i] == v2[j]) {
                    ball++;
                }
            }
        }

        std::cout << "strike : " << strike << " " << "ball : " << ball << " " << endl;
        v2.clear();

        if (strike == 3) {
            break;
        }

    }
    std::cout << try_num << "번 만에 맞췄습니다.";
}