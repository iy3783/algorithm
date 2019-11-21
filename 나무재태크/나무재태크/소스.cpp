#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int A[13][13]; // 추가로 로봇이주는 양분
int cur_A[13][13]; //현재 양분
vector<int> tree[13][13];
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};

bool compare(int a,int b) {
	return a > b;


}
struct deadtree_info {
	int y;
	int x;
	int age;


};

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int counter = 0;

	int n;
	int m;
	int k;
	cin >> n;
	cin >> m;
	cin >> k;

	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			cin >> A[i][j];
			cur_A[i][j] = 5;
		}

	}
	for (int i = 1; i <= m;i++) {
		int y;
		int x;
		int age;
		cin >> y;
		cin >> x;
		cin >> age;

		tree[y][x].push_back(age);
	}



	for (int i = 1; i <= k; i++) {
		//봄
		vector<deadtree_info> dt;

		for (int j = 1; j <= n;j++) {
			for (int p = 1; p <= n;p++ ) {
				sort(tree[j][p].begin(),tree[j][p].end(),compare );
				int treesize = tree[j][p].size();
				for (int q = treesize - 1; q >= 0;q-- ) {
					int this_tree_age = tree[j][p][q];
					if (cur_A[j][p]- this_tree_age<0  ) {
						deadtree_info tempdt;
						tempdt.y = j;
						tempdt.x = p;
						tempdt.age = this_tree_age;
						dt.push_back(tempdt);
						tree[j][p].erase(tree[j][p].begin() + q);

						continue;

					}
					else {
						cur_A[j][p] -= this_tree_age;
						tree[j][p][q] += 1;

					}
				}
			}
		}


		//여름
		for (int j = 0; j < dt.size(); j++) {
			int ty = dt[j].y;
			int tx = dt[j].x;
			cur_A[ty][tx] += dt[j].age / 2;

		}




		//가을
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= n; p++) {
				int treesize = tree[j][p].size();
				for (int q = treesize - 1; q >= 0; q--) {
					if (tree[j][p][q] %5==0 ) {
						for (int f = 0; f < 8;f++) {
							int ny = j +dy[f];
							int nx = p+dx[f];
							if (0<ny &&ny<=n && 0<nx &&ny<=n ) {
								tree[ny][nx].push_back(1);

							}

						}

					}
					
				}
			}
		}
		//겨울
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= n; p++) {
				cur_A[j][p] += A[j][p];
			}

		}




	}

	for (int j = 1; j <= n; j++) {
		for (int p = 1; p <= n; p++) {
			int treesize = tree[j][p].size();
			for (int q = treesize - 1; q >= 0; q--) {
				counter++;

			}
		}
	}
	cout << counter;
	return 0;
}