#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int map[25][25];
vector<int> dir_map[25][4];


//���� 0:���� 1:���� 2:�Ʒ� 3:����

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}





	return 0;
}