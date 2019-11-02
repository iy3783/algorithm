#include <iostream>

using namespace std;
#define INF 50000000
int N;
int H;
int M;
int map[13][35] = {0};
int minnum = INF;
int checkingline() {

	for (int i = 1; i <= N; i ++) {
		int cur = i;
		for (int j = 1; j <= H;j++) {
			if (map[cur][j]==1) {
				cur = cur + 1;

			}
			else if (map[cur-1][j]==1) {
				cur = cur - 1;

			}
		
		}
		if (cur != i ) {
			
			return 0;
		}

	}
	return 1;

}


void solve(int add_row, int depth  ,int y,int x ) {
	if (minnum != INF) {
		return;

	}
	if (add_row == depth) {
		if(checkingline()==1) {
			if (minnum >  add_row) {
				minnum = add_row;

			}
		}

		return;


	}
	for (int i = x; i <= N - 1; i++){
		for (int j = y; j <= y; j++){
			if (map[i][j] == 1) {
				continue;
			}
			if (map[i - 1][j] == 1 || map[i + 1][j] == 1) {
				continue;
			}


			map[i][j] = 1;
			solve(add_row, depth + 1,j,i);
			map[i][j] = 0;



		}
	}


	for (int i = 1; i <= N-1; i++) {
		for (int j =y+1; j <= H; j++) {
			if (map[i][j]==1) {
				continue;
			}
			if (map[i-1][j]==1 || map[i+1][j] ==1   ) {
				continue;
			}


			map[i][j]=1;
			solve(add_row,depth+1,j,i);
			map[i][j]=0;

		}
	}






}

int main() {
	cin >> N >> M >> H;
	for (int i = 1; i <= M; i++) {
		int a;
		int b;
		cin >> a >> b;
		map[b][a] = 1;


	}


	int add_row = 0;
	for (int i = M; i <= (N - 1)*H;i++) {
		if (add_row >= 4) {
			break;

		}
		solve(add_row, 0 ,1 ,1 );
		if (minnum != INF ) {
			break;
		}
		

		

		add_row++;
		
	}

	if (minnum>3 ) {
		cout << -1;

	}
	else {

		cout << minnum;
	}



	return 0;
}