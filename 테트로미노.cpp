#include <iostream>
using namespace std;

int map[510][510];
int maxnum = -1;
int N;
int M;
void tet1() {
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < M; j++) {
			int dy[4] = {0,0,0,0};
			int dx[4] = {0,1,2,3};
			for (int k = 0; k < 4;k++) {//회전4번
				int sum=0;
				int sum2=0;
				int iscontinued=0;

				for (int q = 0; q < 4;q++) { // 위치 4개
					int tmpy;
					int tmpx;
					tmpy = dy[q];
					tmpx = dx[q];
					dy[q] =-tmpx  ;
					dx[q] = tmpy;

				}
				if (i+dy[1] >= N || i + dy[1] < 0 || j+dx[1] >= M || j + dx[1]<0) {
					iscontinued = 1;
				}
				if (i + dy[2] >= N || i + dy[2] < 0 || j + dx[2] >= M || j + dx[2]<0) {
					iscontinued = 1;
				}
				if (i + dy[3] >= N || i + dy[3] < 0 || j + dx[3] >= M || j + dx[3]<0) {
					iscontinued = 1;
				}


				if (iscontinued == 0) {
					for (int q = 0; q < 4; q++) { // 위치 4개
						sum += map[i + dy[q]][j + dx[q]];

					}
					if (maxnum < sum) {
						maxnum = sum;
					}
				}
		

				int ddy[4];
				int ddx[4];
				for (int q = 0; q < 4; q++) { // 위치 4개
					ddy[q] = dy[q];
					ddx[q] = dx[q];
					int tmpy;
					int tmpx;
					tmpy = ddy[q];
					tmpx = ddx[q];
					ddy[q] = -tmpy;
					ddx[q] = tmpx;

				}
				if (i + ddy[1] >= N || i + ddy[1] < 0 || j + ddx[1] >= M || j + ddx[1]<0) {
					continue;
				}
				if (i + ddy[2] >= N || i + ddy[2] < 0 || j + ddx[2] >= M || j + ddx[2]<0) {
					continue;
				}
				if (i + ddy[3] >= N || i + ddy[3] < 0 || j + ddx[3] >= M || j + ddx[3]<0) {
					continue;
				}

				for (int q = 0; q < 4; q++) { // 위치 4개
					sum2 += map[i + ddy[q]][j + ddx[q]];

				}
				if (maxnum < sum2) {
					maxnum = sum2;
				}


			}




		}
	}


}
void tet2() {
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < M; j++) {
			int dy[4] = { 0,0,1,1 };
			int dx[4] = { 0,1,0,1 };
			for (int k = 0; k < 4; k++) {//회전4번
				int sum = 0;
				int sum2 = 0;
				int iscontinued = 0;


				for (int q = 0; q < 4; q++) { // 위치 4개
					int tmpy;
					int tmpx;
					tmpy = dy[q];
					tmpx = dx[q];
					dy[q] = -tmpx;
					dx[q] = tmpy;

				}
				if (i + dy[1] >= N || i + dy[1] < 0 || j + dx[1] >= M || j + dx[1]<0) {
					iscontinued = 1;
				}
				if (i + dy[2] >= N || i + dy[2] < 0 || j + dx[2] >= M || j + dx[2]<0) {
					iscontinued = 1;
				}
				if (i + dy[3] >= N || i + dy[3] < 0 || j + dx[3] >= M || j + dx[3]<0) {
					iscontinued = 1;
				}
				if (iscontinued == 0) {
					for (int q = 0; q < 4; q++) { // 위치 4개
						sum += map[i + dy[q]][j + dx[q]];

					}
					if (maxnum < sum) {
						maxnum = sum;
					}
				}
				int ddy[4];
				int ddx[4];
				for (int q = 0; q < 4; q++) { // 위치 4개
					ddy[q] = dy[q];
					ddx[q] = dx[q];
					int tmpy;
					int tmpx;
					tmpy = ddy[q];
					tmpx = ddx[q];
					ddy[q] = -tmpy;
					ddx[q] = tmpx;

				}
				if (i + ddy[1] >= N || i + ddy[1] < 0 || j + ddx[1] >= M || j + ddx[1]<0) {
					continue;
				}
				if (i + ddy[2] >= N || i + ddy[2] < 0 || j + ddx[2] >= M || j + ddx[2]<0) {
					continue;
				}
				if (i + ddy[3] >= N || i + ddy[3] < 0 || j + ddx[3] >= M || j + ddx[3]<0) {
					continue;
				}

				for (int q = 0; q < 4; q++) { // 위치 4개
					sum2 += map[i + ddy[q]][j + ddx[q]];

				}
				if (maxnum < sum2) {
					maxnum = sum2;
				}


			}




		}
	}



}

void tet3() {
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < M; j++) {
			int dy[4] = { 0,1,2,2 };
			int dx[4] = { 0,0,0,1 };
			for (int k = 0; k < 4; k++) {//회전4번
				int sum = 0;
				int sum2 = 0;
				int iscontinued = 0;
				for (int q = 0; q < 4; q++) { // 위치 4개
					int tmpy;
					int tmpx;
					tmpy = dy[q];
					tmpx = dx[q];
					dy[q] = -tmpx;
					dx[q] = tmpy;

				}
				if (i + dy[1] >= N || i + dy[1] < 0 || j + dx[1] >= M || j + dx[1]<0) {
					iscontinued = 1;
				}
				if (i + dy[2] >= N || i + dy[2] < 0 || j + dx[2] >= M || j + dx[2]<0) {
					iscontinued = 1;
				}
				if (i + dy[3] >= N || i + dy[3] < 0 || j + dx[3] >= M || j + dx[3]<0) {
					iscontinued = 1;
				}
				if (iscontinued == 0) {
					for (int q = 0; q < 4; q++) { // 위치 4개
						sum += map[i + dy[q]][j + dx[q]];

					}
					if (maxnum < sum) {
						maxnum = sum;
					}
				}
				int ddy[4];
				int ddx[4];
				for (int q = 0; q < 4; q++) { // 위치 4개
					ddy[q] = dy[q];
					ddx[q] = dx[q];
					int tmpy;
					int tmpx;
					tmpy = ddy[q];
					tmpx = ddx[q];
					ddy[q] = -tmpy;
					ddx[q] = tmpx;

				}
				if (i + ddy[1] >= N || i + ddy[1] < 0 || j + ddx[1] >= M || j + ddx[1]<0) {
					continue;
				}
				if (i + ddy[2] >= N || i + ddy[2] < 0 || j + ddx[2] >= M || j + ddx[2]<0) {
					continue;
				}
				if (i + ddy[3] >= N || i + ddy[3] < 0 || j + ddx[3] >= M || j + ddx[3]<0) {
					continue;
				}

				for (int q = 0; q < 4; q++) { // 위치 4개
					sum2 += map[i + ddy[q]][j + ddx[q]];

				}
				if (maxnum < sum2) {
					maxnum = sum2;
				}


			}




		}
	}



}

void tet4() {
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < M; j++) {
			int dy[4] = { 0,1,1,2 };
			int dx[4] = { 0,0,1,1 };
			for (int k = 0; k < 4; k++) {//회전4번
				int sum = 0;
				int sum2 = 0;
				int iscontinued = 0;
				for (int q = 0; q < 4; q++) { // 위치 4개
					int tmpy;
					int tmpx;
					tmpy = dy[q];
					tmpx = dx[q];
					dy[q] = -tmpx;
					dx[q] = tmpy;

				}
				if (i + dy[1] >= N || i + dy[1] < 0 || j + dx[1] >= M || j + dx[1]<0) {
					iscontinued = 1;
				}
				if (i + dy[2] >= N || i + dy[2] < 0 || j + dx[2] >= M || j + dx[2]<0) {
					iscontinued = 1;
				}
				if (i + dy[3] >= N || i + dy[3] < 0 || j + dx[3] >= M || j + dx[3]<0) {
					iscontinued = 1;
				}
				if (iscontinued == 0) {
					for (int q = 0; q < 4; q++) { // 위치 4개
						sum += map[i + dy[q]][j + dx[q]];

					}
					if (maxnum < sum) {
						maxnum = sum;
					}
				}
				int ddy[4];
				int ddx[4];
				for (int q = 0; q < 4; q++) { // 위치 4개
					ddy[q] = dy[q];
					ddx[q] = dx[q];
					int tmpy;
					int tmpx;
					tmpy = ddy[q];
					tmpx = ddx[q];
					ddy[q] = -tmpy;
					ddx[q] = tmpx;

				}
				if (i + ddy[1] >= N || i + ddy[1] < 0 || j + ddx[1] >= M || j + ddx[1]<0) {
					continue;
				}
				if (i + ddy[2] >= N || i + ddy[2] < 0 || j + ddx[2] >= M || j + ddx[2]<0) {
					continue;
				}
				if (i + ddy[3] >= N || i + ddy[3] < 0 || j + ddx[3] >= M || j + ddx[3]<0) {
					continue;
				}

				for (int q = 0; q < 4; q++) { // 위치 4개
					sum2 += map[i + ddy[q]][j + ddx[q]];

				}
				if (maxnum < sum2) {
					maxnum = sum2;
				}


			}




		}
	}



}

void tet5() {
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < M; j++) {
			int dy[4] = { 0,0,0,1 };
			int dx[4] = { 0,1,2,1 };
			for (int k = 0; k < 4; k++) {//회전4번
				int sum = 0;
				int sum2 = 0;
				int iscontinued = 0;
				for (int q = 0; q < 4; q++) { // 위치 4개
					int tmpy;
					int tmpx;
					tmpy = dy[q];
					tmpx = dx[q];
					dy[q] = -tmpx;
					dx[q] = tmpy;

				}
				if (i + dy[1] >= N || i + dy[1] < 0 || j + dx[1] >= M || j + dx[1]<0) {
					iscontinued = 1;
				}
				if (i + dy[2] >= N || i + dy[2] < 0 || j + dx[2] >= M || j + dx[2]<0) {
					iscontinued = 1;
				}
				if (i + dy[3] >= N || i + dy[3] < 0 || j + dx[3] >= M || j + dx[3]<0) {
					iscontinued = 1;
				}
				if (iscontinued == 0) {
					for (int q = 0; q < 4; q++) { // 위치 4개
						sum += map[i + dy[q]][j + dx[q]];

					}
					if (maxnum < sum) {
						maxnum = sum;
					}
				}

				int ddy[4];
				int ddx[4];
				for (int q = 0; q < 4; q++) { // 위치 4개
					ddy[q] = dy[q];
					ddx[q] = dx[q];
					int tmpy;
					int tmpx;
					tmpy = ddy[q];
					tmpx = ddx[q];
					ddy[q] = -tmpy;
					ddx[q] = tmpx;

				}
				if (i + ddy[1] >= N || i + ddy[1] < 0 || j + ddx[1] >= M || j + ddx[1]<0) {
					continue;
				}
				if (i + ddy[2] >= N || i + ddy[2] < 0 || j + ddx[2] >= M || j + ddx[2]<0) {
					continue;
				}
				if (i + ddy[3] >= N || i + ddy[3] < 0 || j + ddx[3] >= M || j + ddx[3]<0) {
					continue;
				}

				for (int q = 0; q < 4; q++) { // 위치 4개
					sum2 += map[i + ddy[q]][j + ddx[q]];

				}
				if (maxnum < sum2) {
					maxnum = sum2;
				}


			}




		}
	}



}






int main() {

	cin >> N;
	cin >> M;

	for (int i = 0; i <N ;i++) {
		for (int j = 0; j < M;j++) {
			cin >> map[i][j];
		}
	}

	tet1();
	tet2();
	tet3();
	tet4();
	tet5();



	cout << maxnum;

	return 0;
}