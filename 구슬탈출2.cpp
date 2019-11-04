#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

char map[15][15];
int check[15][15][15][15] = {0}; //check배열은  r b순서
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};



struct ballinfo {
	int ry;
	int rx;
	int by;
	int bx;
};


int BFS(int ry, int rx, int by, int bx) {
	int counter = 1;
	queue<ballinfo> Q;
	ballinfo start_ball;
	start_ball.ry = ry;
	start_ball.rx = rx;
	start_ball.by = by;
	start_ball.bx = bx;
	Q.push(start_ball);



	while (!Q.empty()) {
		int size = Q.size();

		if (counter > 10) {
			return -1;
		}

		for (int i = 0; i<size;i++) {
			ballinfo top;
			top = Q.front();
			Q.pop();
			int p_ry = top.ry;
			int p_rx = top.rx;
			int p_by = top.by;
			int p_bx = top.bx;

			
			for (int j = 0; j < 4; j++) {//네방향으로 보내보자 
				int isR_finished = 0;
				int isB_finished = 0;
				int r_dis = 0;
				int b_dis = 0;

				int n_ry = p_ry;
				int n_rx = p_rx;
				int n_by = p_by;
				int n_bx = p_bx;

				while (map[n_ry + dy[j]][n_rx + dx[j]] != '#') {
					n_ry += dy[j];
					n_rx += dx[j];
					r_dis++;

					if (map[n_ry][n_rx] == 'O') {
						isR_finished = 1;
						break;
					}

				}


				while (map[n_by + dy[j]][n_bx + dx[j]] != '#') {
					n_by += dy[j];
					n_bx += dx[j];
					b_dis++;
					if (map[n_by][n_bx] == 'O') {
						isB_finished = 1;
						break;
					}
				}
				//여기까지 공굴리기 시뮬레이션
				if (isB_finished == 1) {
					continue;
				}
				else {
					if (isR_finished == 1) {
						return counter;

					}

				}//만약 공이 하나라도 빠지면 end 조건

				if (n_ry == n_by && n_rx == n_bx) {
					if (r_dis > b_dis) {
						n_ry -= dy[j];
						n_rx -= dx[j];
					}
					else {
						n_by -= dy[j];
						n_bx -= dx[j];

					}
				}

				if (check[n_ry][n_rx][n_by][n_bx] == 0) {
					ballinfo nextball;
					nextball.ry = n_ry;
					nextball.rx = n_rx;
					nextball.by = n_by;
					nextball.bx = n_bx;
					Q.push(nextball);
					check[n_ry][n_rx][n_by][n_bx] = 1;

				}

			}
		}

		counter++;
	}

	return -1;
}



int main() {
	int N, M;
	cin >> N;
	cin >> M;

	int ry;
	int rx;
	int by;
	int bx;


	for (int i = 0; i < N;i++) {
		string ts;
		cin >> ts;
		for (int j = 0; j < M; j++) {
			map[i][j] = ts[j];
			if (map[i][j]=='R') {
				ry = i;
				rx = j;

			}
			if (map[i][j] == 'B') {
				by = i;
				bx = j;

			}

		}
	}

	cout<<BFS(ry,rx,by,bx);





	return 0;
}