#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    int count = 1;

    cout << "�������� â Ȥ�� ���� ���� �ڿ����� �Է����ּ���. : ";
    cin >> m;

    vector<vector<int>> v(m, vector<int>(m, 0));

    int row = 0;
    int col = m / 2;
   
    while (count <= m * m) {
        v[row][col] = count;
        count++;

        int next_row = (row - 1 + m) % m;  // ���� ������ �Ѿ�� �ʵ��� % m ����ؼ� ��ȯ
        int next_col = (col + 1) % m;

        if (v[next_row][next_col] != 0) {
            row = (row + 1) % m;   // ���� ������ ���� �Է�
        }
        else {
            row = next_row;
            col = next_col;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] / 10 == 0) {       // ���ڸ� ���� �� �� 2ĭ, ���ڸ� ���� �� �� 1ĭ ����� �迭 ����
            cout << "  ";
            }
            else if (v[i][j] / 10 != 0) {
            cout << " ";                 
            }
            cout << v[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}