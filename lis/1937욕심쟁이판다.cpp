#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

struct mapinfo{
	int y;
	int x;
	int BN;

};

bool compare(mapinfo a , mapinfo b) {
	return a.BN < b.BN;

}



int main() {
	int map[505][505];
	int D[505][505];
	int n;
	vector<mapinfo> V;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			D[i][j] = 1;

			mapinfo mi;
			mi.y = i;
			mi.x = j;
			mi.BN = map[i][j];
			V.push_back(mi);
		}

	}
	sort(V.begin(), V.end(), compare);



	
	for (int q = 0; q < V.size();q++) {
		int i =V[q].y;
		int j =V[q].x;

		for (int k = 0; k < 4; k++) {
			int nexty = i + dy[k];
			int nextx = j + dx[k];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= n) {
				continue;
			}
			if (map[nexty][nextx] > map[i][j]) {
				if (D[nexty][nextx] < D[i][j] + 1) {
					D[nexty][nextx] = D[i][j] + 1;

				}
			}
		}
	}
	int max = -1;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			if (max < D[i][j]) {
				max = D[i][j];

			}

		}

	}
	cout << max;

	return 0;
}