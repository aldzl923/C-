#include <iostream>

// ���� 31�� ���� �Է��ϴ� Player�� �й��ϴ� ����

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
