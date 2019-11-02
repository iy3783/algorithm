#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[15][15];
int check[15][15] = {0};

int counter[6];
int minnum=21321321;




int ispossible(int y, int x, int d) {
	for (int i = y; i < y + d;i++) {
		for (int j = x; j < x + d; j++) {
			if (map[i][j] !=1 || check[i][j]==1  ) {
				return 0;

			}

		}
	}
	return 1;

}



void checking(int y, int x, int d) {
	for (int i = y; i < y + d; i++) {
		for (int j = x; j < x + d; j++) {
			check[i][j] = 1;
		}
	}






}

void unchecking(int y, int x, int d) {
	for (int i = y; i < y + d; i++) {
		for (int j = x; j < x + d; j++) {
			check[i][j] = 0;
		}
	}






}


void solve(int s, int e,int depth) {


	int y = -1;
	int x = -1;

	int findplace=0;
	int jump = 0;
	for (int i = s; i <= s; i++) {
		if (jump == 1) {
			break;
		}
		for (int j = e; j <= 10; j++) {
			if (map[i][j] == 1 && check[i][j] == 0 ) {
				y = i;
				x = j;
				findplace = 1;
				jump = 1;
				break;
			}

		}
	}
	if (findplace ==0) {
		int jump2 = 0;

		for (int i = s + 1; i <= 10; i++) {
			if (jump2 == 1) {
				break;
			}
			for (int j = 1; j <= 10; j++) {
				if (map[i][j] == 1 && check[i][j] == 0) {
					y = i;
					x = j;
					jump2 = 1;
					break;
				}

			}
		}

	}

	if (y==-1 ||x == -1) {

		if (depth < minnum) {
			minnum = depth;
		}

		return;

	}


	for (int i = 1; i <= 5;i++ ) {
		if (counter[i]>0 ) {
			if (ispossible(y, x, i) == 1)
			{
				checking(y, x, i);
				counter[i] --;
				solve(y, x, depth + 1);
				unchecking(y, x, i);
				counter[i] ++;
			}

		}
	
	}





	return;

}



int main() {
	for (int i = 1; i <= 10;i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= 5; i++) {
		counter[i] = 5;
	}


	solve(1,1, 0);

	if (minnum == 21321321) {
		cout << -1;
	}
	else
	cout << minnum;




	return 0;
}


