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
		cout << "������ �Է��ϼ���: ";
		cin >> user_in;
		cout << "����ڰ� �θ� ����!" << endl;

		for (int i = 1; i <= user_in; i++) // i�� 1���� user_in�� ������ �� ���� i�� 1�� ����
		{

			j++;
			cout << j << endl;

			if (j == 31)
			{
				cout << "��������! ��ǻ���� �¸��Դϴ�." << endl;
				break;

			}
		}

		int computer_in = (rand() % 3) + 1;   // ��ǻ�ʹ� 1~3������ ������ �������� �Է�
		cout << "��ǻ�Ͱ� �θ� ����!" << endl;

		for (int k = 1; k <= computer_in; k++) // k�� 1���� computer_in�� ������ �� ���� k�� 1�� ����
		{

			j++;
			cout << j << endl;

			if (j == 31)
			{
				cout << "��������! ������� �¸��Դϴ�." << endl;
				break;

			}
		}
	}
};




//���� �ּ� 1������ �ִ� 3���� ���ӵ� ���ڸ� ���ϰ�
//31�̶�� ���ڸ� ���ϴ� ����� ���� ����.
//1) ����ڴ� ������ �Է��� ���ڸ�ŭ.
//2) ��ǻ�ʹ� ���� ���ڸ�ŭ.
//3) �� �����, ��ǻ�� ��� 1~3������ ������ ����!

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
//        cout << "������ �Է��ϼ���: ";
//        cin >> user_in;
//
//        if (user_in > 3) {
//            cout << "1 ~ 3 ������ ���� �Է��ϼ���." << endl;
//        }
//
//
//        else {
//            for (int k = 0; k < user_in; k++) {         // �Է� ���� ��ŭ ���� ���
//                i++;
//                cout << i << endl;
//
//                if (i == 31) {                          // ���ڰ� 31�� ���� ��� ���� ���� �� ����� ���� ���
//                    cout << "���� ����! ��ǻ���� �¸��Դϴ�!";
//                    gameover = true;
//                    break;                              // 31�� ���� for�� Ż��
//                }
//            }
//
//
//            cout << endl;
//            int com_rand_num = rand() % 3 + 1;
//
//            cout << "��ǻ�Ͱ� �θ� ����!" << endl;
//
//            for (int k = 0; k < com_rand_num; k++) {         // com ���� �� ��ŭ ���� ���
//                i++;
//                cout << i << endl;
//
//                if (i == 31) {                      // ���ڰ� 31�� ���� ��� ���� ���� �� ����� ���� ���
//                    cout << "���� ����! ������� �¸��Դϴ�!";
//                    gameover = true;
//                    break;                          // 31�� ���� for�� Ż��
//                }
//            }
//
//
//            cout << endl;
//
//        }
//
//
//        if (gameover == true) {              // ���� ���� While �� Ż��
//            break;
//        }
//
//
//    }
//};