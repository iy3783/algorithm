#include <iostream>
#include <vector>
using namespace std;
int N;
int map[15][15] = { 0 };
vector<int> diagonal1;
vector<int> diagonal2;
vector<int> diagonal3;
vector<int> diagonal4;

int maxnum = -32;
int maxnum2 = -32;

void solve(int y, int x, int depth) {
	for (int i = y; i <= y; i++) {
		for (int j = x; j <= N; j++) {
			if ((i + j)%2 !=0) {
				continue;
			}


			if (map[i][j] == 1) {
				int ispossible = 1;
				for (int k = 0; k < diagonal1.size(); k++) {
					if (i + j == diagonal1[k]) {
						ispossible = 0;
					}
				}

				for (int k = 0; k < diagonal2.size(); k++) {
					if (i - j == diagonal2[k]) {
						ispossible = 0;
					}

				}
				if (ispossible == 1) {
					diagonal1.push_back(i + j);
					diagonal2.push_back(i - j);
					solve(i, j, depth + 1);
					diagonal1.pop_back();
					diagonal2.pop_back();
				}



			}

		}
	}
	for (int i = y + 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((i+j) % 2 !=0) {
				continue;
			}
			if (map[i][j] == 1) {
				int ispossible = 1;
				for (int k = 0; k < diagonal1.size(); k++) {
					if (i + j == diagonal1[k]) {
						ispossible = 0;
					}
				}

				for (int k = 0; k < diagonal2.size(); k++) {
					if (i - j == diagonal2[k]) {
						ispossible = 0;
					}

				}
				if (ispossible == 1) {
					diagonal1.push_back(i + j);
					diagonal2.push_back(i - j);
					solve(i, j, depth + 1);
					diagonal1.pop_back();
					diagonal2.pop_back();
				}



			}
		}


	}
	if (maxnum < depth) {
		maxnum = depth;

	}


	return;
}
void solve2(int y, int x, int depth) {
	for (int i = y; i <= y; i++) {
		for (int j = x; j <= N; j++) {
			if ((i + j) % 2 == 0) {
				continue;
			}


			if (map[i][j] == 1) {
				int ispossible = 1;
				for (int k = 0; k < diagonal3.size(); k++) {
					if (i + j == diagonal3[k]) {
						ispossible = 0;
					}
				}

				for (int k = 0; k < diagonal3.size(); k++) {
					if (i - j == diagonal4[k]) {
						ispossible = 0;
					}

				}
				if (ispossible == 1) {
					diagonal3.push_back(i + j);
					diagonal4.push_back(i - j);
					solve2(i, j, depth + 1);
					diagonal3.pop_back();
					diagonal4.pop_back();
				}



			}

		}
	}
	for (int i = y + 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((i + j)% 2 == 0) {
				continue;
			}
			if (map[i][j] == 1) {
				int ispossible = 1;
				for (int k = 0; k < diagonal3.size(); k++) {
					if (i + j == diagonal3[k]) {
						ispossible = 0;
					}
				}

				for (int k = 0; k < diagonal4.size(); k++) {
					if (i - j == diagonal4[k]) {
						ispossible = 0;
					}

				}
				if (ispossible == 1) {
					diagonal3.push_back(i + j);
					diagonal4.push_back(i - j);
					solve2(i, j, depth + 1);
					diagonal3.pop_back();
					diagonal4.pop_back();
				}



			}
		}


	}
	if (maxnum2 < depth) {
		maxnum2 = depth;

	}


	return;
}





int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}


	solve(1, 1, 0);
	solve2(1,1,0);


	cout << maxnum + maxnum2;


	return 0;
}