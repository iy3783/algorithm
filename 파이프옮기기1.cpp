#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int N;
int map[20][20];
int check[20][20];
int counter = 0;



void DFS(int y,int x ,int dir ) {//dir 1가로  2 대각선  3 세로
	if (y == N && x == N) {

		counter++;
		return;
	}

	
	if (dir ==1) {
		if (x+1 <=N) {
			if (check[y][x + 1]==0 && map[y][x+1]==0) {
				check[y][x + 1] = 1;
				DFS(y,x+1 ,1);
				check[y][x + 1] = 0;
			}
		}
		if (x +1 <= N && y+1 <= N) {
			if (check[y+1][x + 1] == 0 && map[y+1][x + 1] == 0 && check[y][x + 1] == 0 && map[y][x + 1] == 0&& check[y + 1][x] == 0 && map[y + 1][x] == 0) {
				check[y+1][x + 1] = 1;
				DFS(y+1, x + 1, 2);
				check[y+1][x + 1] =0 ;
			}
		}



	}
	else if (dir == 2) {
		if (x + 1 <= N) {
			if (check[y][x + 1] == 0 && map[y][x + 1] == 0) {
				check[y][x + 1] = 1;
				DFS(y, x + 1, 1);
				check[y][x + 1] = 0;
			}
		}
		if (x + 1 <= N && y + 1 <= N) {
			if (check[y + 1][x + 1] == 0 && map[y + 1][x + 1] == 0 && check[y][x + 1] == 0 && map[y][x + 1] == 0 && check[y + 1][x] == 0 && map[y + 1][x] == 0) {
				check[y+1][x + 1] = 1;
				DFS(y + 1, x + 1, 2);
				check[y+1][x + 1] =0;
			}
		}
		if (y + 1 <= N) {
			if (check[y+1][x] == 0 && map[y+1][x] == 0) {
				check[y+1][x] = 1;
				DFS(y+1, x , 3);
				check[y+1][x] = 0;
			}
		}
	}
	else if (dir == 3) {
		if (x + 1 <= N && y + 1 <= N) {
			if (check[y + 1][x + 1] == 0 && map[y + 1][x + 1] == 0 && check[y][x + 1] == 0 && map[y][x + 1] == 0 && check[y + 1][x] == 0 && map[y + 1][x] == 0) {
				check[y+1][x + 1] = 1;
				DFS(y + 1, x + 1, 2);
				check[y+1][x + 1] = 0;
			}
		}
		if (y + 1 <= N) {
			if (check[y + 1][x] == 0 && map[y + 1][x] == 0) {
				check[y+1][x] = 1;
				DFS(y + 1, x, 3);
				check[y+1][x] = 0;
			}
		}

	}
	

}



int main() {
	cin >> N;
	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	check[1][1] = 1;
	check[1][2] = 1;
	DFS(1,2,1);
	cout << counter;




	return 0;
}