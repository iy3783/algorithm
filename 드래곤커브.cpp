#include <iostream>
#include <vector>
using namespace std;


int N;
int map[105][105];
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

int changedir(int dir) {
	if (dir==3) {
		return 0;
	}
	else {
		return dir + 1;

	}
}

void make(int y,int x , int d,int g,int depth , vector<int> v ) {
	if (g== depth) {
		int ty=y;
		int tx=x;
		map[ty][tx] = 1;
		for (int i = 0; i < v.size();i++) {
			ty = ty + dy[v[i]];
			tx = tx + dx[v[i]];
			map[ty][tx] = 1;
		}



		return;
	}
	int vsize = v.size();
	for (int i = vsize-1; i>=0;i--) {
		v.push_back(changedir(v[i]));

	}
	make(y,x,d,g,depth+1,v);


}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		int y;
		int d;
		int g;
		cin >> x >> y >> d >> g;
		vector<int> v;
		v.push_back(d);
		make(y, x, d, g,0, v);

	}

	int counter = 0;

	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (map[i][j]==1&& map[i+1][j] == 1 && map[i][j+1] == 1 && map[i+1][j+1] == 1 ) {
				counter++;

			}

		}
	}

	cout << counter;


	return 0;
}