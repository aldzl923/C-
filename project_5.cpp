#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int ball =0;
    int strike=0;
    int try_num = 0;

    vector<int> v1; // ��ǻ���� ����
    srand(time(nullptr));

    while (v1.size() < 3) {  // ���Ͱ� 3���� ���ڸ� ���� �� ���� �ݺ�
        int com_num = (rand() % 9) + 1;  // ��ǻ�� 1���� 9���� 
        v1.push_back(com_num);

        sort(v1.begin(), v1.end());  //
        v1.erase(unique(v1.begin(), v1.end()), v1.end()); // �ߺ�����
        // cout << com_num << " ";

    }
    cout << "��ǻ�Ͱ� ���� ���� : ";
    for (auto i : v1) {
        cout << i << " ";
    }
    cout << endl;
    int user_num;

    vector<int>v2;

    while (1) {

        int ball = 0;
        int strike = 0;
        cout << "1 ~ 9 ������ ���� 3���� �Է� �Ͻÿ� (�̿��� ����: ����)" << endl;
        try_num++;

        for (int i = 0; i < 3; i++) {

            cin >> user_num;
        
            if (user_num < 0 || user_num > 9) {
                cout << "������ �����Ͽ����ϴ�." << endl;
                break;
            }
            else {
                v2.push_back(user_num);
            }
        }

        // ��Ʈ����ũ �� ��

            for (int i = 0; i < 3; i++) {
            
                if (v1[i] == v2[i])   // �ڸ����� ���� ��� ������ strike++
                    strike++;
            }

        // �� �� ��
          
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i != j && v1[i] == v2[j]) {
                        ball++;
                    }
                }
            }

            cout << "strike : " << strike << " " << "ball : " << ball << " " << endl;
            v2.clear();

            if (strike == 3) {
                break;
            }
            
        }
    cout << try_num << "�� ���� ������ϴ�.";
    }