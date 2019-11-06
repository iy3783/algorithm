#include <iostream>
#include <vector>
using namespace std;


struct yx {
	int y;
	int x;
};
struct camerainfo {
	int y;
	int x;
	int direction;

};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int N;
int M;
int map[10][10];
vector<yx> camera;
vector<camerainfo> permu;
int camerasize;
int maxnum=-1;
int check[10][10];
void fillcheck(int y,int x,int i) {

	while (1) {
		if (y <N   && y >= 0 && x <M   && x >= 0) {
			if (map[y][x] == 6) {
				break;
			}
			else {
				check[y][x] = 1;
				y = y + dy[i];
				x = x + dx[i];
			}
		}
		else {
			break;
		}
	}

}

void checking1(int y,int x,int direction) {

	if (direction==0) {
		fillcheck(y,x,0);
	}
	if (direction == 1) {
		fillcheck(y, x, 1);

	}
	if (direction == 2) {
		fillcheck(y, x, 2);

	}
	if (direction == 3) {
		fillcheck(y, x, 3);
	}

}
void checking2(int y, int x, int direction) {
	if (direction == 0 || direction == 2) {
		fillcheck(y, x, 0);
		fillcheck(y, x, 2);
	}
	if (direction == 1 || direction == 3) {
		fillcheck(y, x, 1);
		fillcheck(y, x, 3);
	}

}
void checking3(int y, int x, int direction) {
	if (direction == 0) {
		fillcheck(y, x, 3);
		fillcheck(y, x, 0);
	}
	if (direction == 1) {
		fillcheck(y, x, 0);
		fillcheck(y, x, 1);
	}
	if (direction == 2) {
		fillcheck(y, x, 1);
		fillcheck(y, x, 2);
	}
	if (direction == 3) {
		fillcheck(y, x, 2);
		fillcheck(y, x, 3);
	}
}
void checking4(int y, int x, int direction) {
	if (direction == 0) {
		fillcheck(y, x, 0);
		fillcheck(y, x, 2);
		fillcheck(y, x, 3);
	}
	if (direction == 1) {
		fillcheck(y, x, 0);
		fillcheck(y, x, 1);
		fillcheck(y, x, 3);

	}
	if (direction == 2) {
		fillcheck(y, x, 0);
		fillcheck(y, x, 1);
		fillcheck(y, x, 2);

	}
	if (direction == 3) {
		fillcheck(y, x, 1);
		fillcheck(y, x, 2);
		fillcheck(y, x, 3);

	}
}
void checking5(int y, int x, int direction){
	

	for (int i = 0; i < 4; i++) {
		fillcheck(y, x, i);

	}


}



void rotatecamera(int depth) {
	if (depth == camerasize) {

		for (int i = 0; i < N;i ++) {
			for (int j = 0; j < M; j++) {
				check[i][j] = 0;
			}
		}
		for (int i = 0; i < permu.size(); i ++) {
			int y= permu[i].y;
			int x= permu[i].x;
			if (map[y][x] == 1) {
				checking1(y , x,permu[i].direction);

			}
			if (map[y][x] == 2) {
				checking2(y, x, permu[i].direction);

			}
			if (map[y][x] == 3) {
				checking3(y, x, permu[i].direction);

			}
			if (map[y][x] == 4) {
				checking4(y, x, permu[i].direction);

			}
			if (map[y][x] == 5) {
				checking5(y, x, permu[i].direction);

			}
		}
		int sum = 0;
		for (int i = 0; i < N; i ++) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] == 1) {
					sum++;
				}
			}
		}
		if (maxnum < sum) {
			maxnum = sum;
		}

		return;
	}

	for (int i = 0; i <4; i++) {
		camerainfo tmp;
		tmp.y = camera[depth].y;
		tmp.x = camera[depth].x;
		tmp.direction = i;

		permu.push_back(tmp);
		rotatecamera(depth + 1);
		permu.pop_back();

	}


}

void solve() {
	int depth = 0;
	for (int i = 0; i <4 ;i++) {
		camerainfo tmp;
		tmp.y= camera[depth].y;
		tmp.x = camera[depth].x;
		tmp.direction = i;

		permu.push_back(tmp);
		rotatecamera(depth + 1);
		permu.pop_back();

	}




}



int main() {
	cin >> N;
	cin >> M;
	int wallcounter = 0;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]>=1 && map[i][j]<=5  ) {
				yx tmp;
				tmp.y = i;
				tmp.x = j;
				camera.push_back(tmp);

			}
			if (map[i][j] == 6) {
				wallcounter++;

			}
		}
	}

	camerasize = camera.size();

	if (camerasize == 0)
	{
		cout << N * M - wallcounter;
	}
	else {
		solve();
		cout << N * M - wallcounter - maxnum;
	}
	

	
	




	return 0;
}