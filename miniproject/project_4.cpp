#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    int count = 1;

    cout << "마방진의 창 혹은 열의 수를 자연수로 입력해주세요. : ";
    cin >> m;

    vector<vector<int>> v(m, vector<int>(m, 0));

    int row = 0;
    int col = m / 2;
   
    while (count <= m * m) {
        v[row][col] = count;
        count++;

        int next_row = (row - 1 + m) % m;  // 행의 범위가 넘어가지 않도록 % m 사용해서 순환
        int next_col = (col + 1) % m;

        if (v[next_row][next_col] != 0) {
            row = (row + 1) % m;   // 나눈 나머지 값을 입력
        }
        else {
            row = next_row;
            col = next_col;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] / 10 == 0) {       // 한자리 숫자 일 때 2칸, 두자리 숫자 일 때 1칸 띄워서 배열 정렬
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