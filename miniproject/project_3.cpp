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

    cout << "���ڴ� 1 ~ 25������ ���ڸ� �Է��� �� �ֽ��ϴ�." << endl;

    // ��ǻ�Ͱ� 1���� 25������ ���� ���� ���(�ߺ�X)
    while (num.size() < 6) {
        int com_num = (rand() % 25) + 1;
        

        // �ߺ� üũ
        if (find(num.begin(), num.end(), com_num) == num.end()) {  // �ߺ��� ���ڰ� ������ �ٽ� �̱�
            num.push_back(com_num);
        }
    }
   

    // ����ڰ� 1���� 25������ �� �� ���ϴ� ���� 6�� �Է�(�ߺ�X)
    vector<int> user_nums;

    for (int i = 1; i < 7; i++) {
        int user_num;

        cout << i << "��° ��ȣ�� �Է��ϼ��� : ";
        cin >> user_num;

        // ���� üũ
        if (user_num < 1 || user_num > 25) {
            cout << "1���� 25 ������ ���ڸ� �Է��ϼ���." << endl;
            i--;  // �ٽ� �Է¹ޱ� ���� i�� ����
            continue;
        }

        // �ߺ� üũ
        while (find(user_nums.begin(), user_nums.end(), user_num) != user_nums.end()) {
            cout << "�̹� �Էµ� �����Դϴ�. " << endl << i << "��° ��ȣ�� �Է��ϼ��� : ";
            cin >> user_num;
        }

        user_nums.push_back(user_num);
    }

    cout << "---------------------------------" << endl << "��÷��ȣ ����!" << endl;
    for (auto i : num) {
        cout << i << " ";
    }
    cout << "\n" <<  "1 ~ 7����� ����� ���� �� �ֽ��ϴ�.";

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            
            if (num[i] == user_nums[j]) {
                score++;
            }
        }
    }

    cout << "��� : ";
        switch(score){
            case 0: cout << "7���Դϴ�!";
                break;
            case 1: cout << "6���Դϴ�!";
                break;
            case 2: cout << "5���Դϴ�!";
                break;
            case 3: cout << "4���Դϴ�!";
                break;
            case 4: cout << "3���Դϴ�!";
                break;
            case 5: cout << "2���Դϴ�!";
                break;
            case 6: cout << "1���Դϴ�!";
                break;
        
        }

    return 0;
}





