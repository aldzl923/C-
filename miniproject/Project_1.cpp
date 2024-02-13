#include <iostream>

// 숫자 31을 먼저 입력하는 Player가 패배하는 게임

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
