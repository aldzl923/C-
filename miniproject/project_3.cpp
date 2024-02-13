#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;
int com_num;


int main() {

    int score = 0;
    srand(time(nullptr));
    vector<int> num;

    cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다." << endl;

    // 컴퓨터가 1부터 25까지의 랜덤 숫자 출력(중복X)
    while (num.size() < 6) {
        int com_num = (rand() % 25) + 1;
        

        // 중복 체크
        if (find(num.begin(), num.end(), com_num) == num.end()) {  // 중복된 숫자가 있으면 다시 뽑기
            num.push_back(com_num);
        }
    }
   

    // 사용자가 1부터 25까지의 수 중 원하는 숫자 6개 입력(중복X)
    vector<int> user_nums;

    for (int i = 1; i < 7; i++) {
        int user_num;

        cout << i << "번째 번호를 입력하세요 : ";
        cin >> user_num;

        // 범위 체크
        if (user_num < 1 || user_num > 25) {
            cout << "1부터 25 사이의 숫자를 입력하세요." << endl;
            i--;  // 다시 입력받기 위해 i를 감소
            continue;
        }

        // 중복 체크
        while (find(user_nums.begin(), user_nums.end(), user_num) != user_nums.end()) {
            cout << "이미 입력된 숫자입니다. " << endl << i << "번째 번호를 입력하세요 : ";
            cin >> user_num;
        }

        user_nums.push_back(user_num);
    }

    cout << "---------------------------------" << endl << "당첨번호 공개!" << endl;
    for (auto i : num) {
        cout << i << " ";
    }
    cout << "\n" <<  "1 ~ 7등까지 결과가 나올 수 있습니다.";

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            
            if (num[i] == user_nums[j]) {
                score++;
            }
        }
    }

    cout << "결과 : ";
        switch(score){
            case 0: cout << "7등입니다!";
                break;
            case 1: cout << "6등입니다!";
                break;
            case 2: cout << "5등입니다!";
                break;
            case 3: cout << "4등입니다!";
                break;
            case 4: cout << "3등입니다!";
                break;
            case 5: cout << "2등입니다!";
                break;
            case 6: cout << "1등입니다!";
                break;
        
        }

    return 0;
}





