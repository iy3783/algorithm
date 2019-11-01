#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int map[25][25] = {0};
int N;
vector<int> v;
int check[25] = {0};
int minnum=123213212;



void solve(int depth,int p ) {
	if (depth ==N/2) {
		int sum = 0;
		int sum2 = 0;
		int differ;
		vector<int> v2;
		for (int i = 1; i <= N;i++) {
			if (check[i] == 0) {
				v2.push_back(i);
			}
		}
		for (int i = 0; i < v.size();i++) {
			for (int j = 0; j < v.size(); j++) {
				if (i==j) {
					continue;
				}
				sum += map[v[i]][v[j]];
			}
		}
		for (int i = 0; i < v2.size(); i++) {
			for (int j = 0; j < v2.size(); j++) {
				if (i == j) {
					continue;
				}
				sum2 += map[v2[i]][v2[j]];
			}
		}
		differ = abs(sum2 - sum);
		if (differ < minnum) {
			minnum = differ;
		}


		return;
	}

	for (int i = p; i <= N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			v.push_back(i);
			solve(depth+1,i);
			v.pop_back();
			check[i] = 0;
		}
	}


	return;
}


int main() {

	cin >> N;
	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++){
		if (check[i]==0) {
			check[i] = 1;
			v.push_back(i);
			solve(1, i );
			v.pop_back();
			check[i] = 0;
		}
	}
	


	cout << minnum;




	return 0;
}