#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct yx {
	int y;
	int x;
};
int N;
int M;
int map[55][55];

int total_min=222222222;

vector<yx> chicken;
vector<yx> house;

vector<yx> v;
int distance(int y1,int x1,int y2,int x2) {
	return abs(y1 - y2) + abs(x1-x2);

}

void solve(int index, int ss,int depth ) {
	if (depth == M) {
		int sum=0;
		for (int i = 0; i < house.size(); i++) {
			int mindis = 300000;
			for (int j = 0; j <v.size(); j++) {
				int dist = distance(house[i].y, house[i].x, v[j].y, v[j].x);
				if (mindis > dist) {
					mindis = dist;
				}

			}
			sum += mindis;
			

		}
		if (total_min > sum) {
			total_min = sum;

		}

	}

	for (int i = index; i < ss;i++) {
	
		v.push_back(chicken[i]);
		solve(i+1,ss, depth + 1);
		v.pop_back();
	
	}

	return;

}

int main() {
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				yx tmp;
				tmp.y = i;
				tmp.x = j;
				house.push_back(tmp);
			}
			if (map[i][j]==2) {
				yx tmp;
				tmp.y = i;
				tmp.x = j;
				chicken.push_back(tmp);
			}
		}
	}

	int c_size =chicken.size();
	
	solve(0,c_size,0);

	cout << total_min;







	return 0;
}