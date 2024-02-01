//#include <iostream>
//
//
////
//#include <iostream>
//
//using namespace std;
//int num1, num2, num3;
//class Num
//{
//public:
//	Num()
//	{
//		int num1, num2, num3;
//	}
//};
//
//class Me : public  Num
//{
//public:
//	Me(int num1, int num2, int num3)
//	{
//		_num1 = num1;
//		_num2 = num2;
//		_num3 = num3;
//	}
//public:
//	int _num1;
//	int _num2;
//	int _num3;
//};
//
//class Computer : public Num
//{
//public:
//	Computer(int num1, int num2, int num3)
//	{
//		_num1 = num1;
//		_num2 = num2;
//		_num3 = num3;
//	}
//public:
//	int _num1;
//	int _num2;
//	int _num3;
//};
//
#include <iostream>

using namespace std;

int user_in;
int computer_in;
int j = 0;

int main()
{
	srand(time(NULL));

	while (j <= 31)
	{
		cout << "개수를 입력하세요: ";
		cin >> user_in;
		cout << "사용자가 부른 숫자!" << endl;

		for (int i = 1; i <= user_in; i++) // i가 1부터 user_in과 같아질 때 까지 i값 1씩 증가
		{

			j++;
			cout << j << endl;

			if (j == 31)
			{
				cout << "게임종료! 컴퓨터의 승리입니다." << endl;
				break;

			}
		}

		int computer_in = (rand() % 3) + 1;   // 컴퓨터는 1~3까지의 숫자중 랜덤으로 입력
		cout << "컴퓨터가 부른 숫자!" << endl;

		for (int k = 1; k <= computer_in; k++) // k가 1부터 computer_in과 같아질 때 까지 k값 1씩 증가
		{

			j++;
			cout << j << endl;

			if (j == 31)
			{
				cout << "게임종료! 사용자의 승리입니다." << endl;
				break;

			}
		}
	}
};




//서로 최소 1개에서 최대 3개의 연속된 숫자를 말하고
//31이라는 숫자를 말하는 사람이 지는 게임.
//1) 사용자는 본인이 입력한 숫자만큼.
//2) 컴퓨터는 랜덤 숫자만큼.
//3) 단 사용자, 컴퓨터 모두 1~3사이의 개수만 가능!

//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//
//
//using namespace std;
//
//
//int main()
//{
//    srand(time(NULL));
//
//    int i = 0;
//
//    while (true) {
//        int user_in;
//        bool gameover = false;
//        cout << "개수를 입력하세요: ";
//        cin >> user_in;
//
//        if (user_in > 3) {
//            cout << "1 ~ 3 사이의 수를 입력하세요." << endl;
//        }
//
//
//        else {
//            for (int k = 0; k < user_in; k++) {         // 입력 개수 만큼 숫자 출력
//                i++;
//                cout << i << endl;
//
//                if (i == 31) {                          // 숫자가 31이 나온 경우 게임 종료 및 우승자 문구 출력
//                    cout << "게임 종료! 컴퓨터의 승리입니다!";
//                    gameover = true;
//                    break;                              // 31이 나와 for문 탈출
//                }
//            }
//
//
//            cout << endl;
//            int com_rand_num = rand() % 3 + 1;
//
//            cout << "컴퓨터가 부른 숫자!" << endl;
//
//            for (int k = 0; k < com_rand_num; k++) {         // com 랜덤 수 만큼 숫자 출력
//                i++;
//                cout << i << endl;
//
//                if (i == 31) {                      // 숫자가 31이 나온 경우 게임 종료 및 우승자 문구 출력
//                    cout << "게임 종료! 사용자의 승리입니다!";
//                    gameover = true;
//                    break;                          // 31이 나와 for문 탈출
//                }
//            }
//
//
//            cout << endl;
//
//        }
//
//
//        if (gameover == true) {              // 게임 종료 While 문 탈출
//            break;
//        }
//
//
//    }
//};