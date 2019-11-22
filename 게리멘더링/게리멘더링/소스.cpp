#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

int N;
int people[15];
int adj[15][15];

vector<int> red;
vector<int> blue;
int minnum= 23232332;


int RBFS( int tmap[][15] , int start) {
	int check[15];

	for (int i = 1; i<=N; i++) {
		check[i] = 0;

	}

	queue<int> Q;
	Q.push(start);

	check[start] = 1;
	while (!Q.empty()) {

		int top = Q.front();
		Q.pop();

		for (int i = 1; i <= N;  i++) {
			if (tmap[top][i] == 1) {
				if (check[i] == 0) {
					check[i] = 1;
					Q.push(i);
				}
			}
		}
	}

	int possible = 1;
	for (int i = 0; i < red.size();i++) {
		if (check[red[i]] == 0) {
			possible = 0;
		}

	}
	return possible;

}


int BBFS(int tmap[][15], int start) {
	int check[15];

	for (int i = 1; i <= N; i++) {
		check[i] = 0;

	}

	queue<int> Q;
	Q.push(start);

	check[start] = 1;
	while (!Q.empty()) {

		int top = Q.front();
		Q.pop();

		for (int i = 1; i <= N; i++) {
			if (tmap[top][i] == 1) {
				if (check[i] == 0) {
					check[i] = 1;
					Q.push(i);
				}
			}
		}
	}

	int possible = 1;
	for (int i = 0; i < blue.size(); i++) {
		if (check[blue[i]] == 0) {
			possible = 0;
		}

	}
	return possible;


}


void solve( int depth) {	
	if (depth == N) {

		if (red.size() == N || blue.size() == N) {
			return;
		}
		int tmap1[15][15];
		int tmap2[15][15];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				tmap1[i][j] = 0;
			}
		}// 초기화
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				tmap2[i][j] = 0;
			}
		}// 초기화

		for (int i = 0; i < red.size();i++) {
			for (int j = 0; j < red.size();j++) {
				if (adj[red[i]][red[j]] == 1) {
					tmap1[red[i]][red[j]] = 1;
					tmap1[red[j]][red[i]] = 1;
				}
			}
		}
		for (int i = 0; i < blue.size(); i++) {
			for (int j = 0; j < blue.size(); j++) {
				if (adj[blue[i]][blue[j]] == 1) {
					tmap2[blue[i]][blue[j]] = 1;
					tmap2[blue[j]][blue[i]] = 1;
				}
			}
		}
	
		int p1 = RBFS(tmap1,red[0] );
		int p2 = BBFS(tmap2,blue[0]);

		if (p1==1 && p2 == 1) {
			int pn1=0;
			int pn2=0;
			for (int i = 0; i < red.size(); i++) {
				pn1 += people[red[i]];
			}
			for (int i = 0; i < blue.size(); i++) {
				pn2 += people[blue[i]];
			}

			int sum = 0;
			sum = abs(pn1-pn2);
			if (sum < minnum) {
				minnum = sum;
			}
		}


		return;
	}


	red.push_back(depth + 1);
	solve(depth + 1);
	red.pop_back();


	blue.push_back(depth + 1);
	solve(depth + 1);
	blue.pop_back();


	return;
}


int main() {
	
	cin >> N;
	for (int i = 1; i <= N;i++) {
		cin >> people[i];
	}


	for (int i = 1; i <= 10;i++) {
		for (int j = 1; j <= 10;j++) {
			adj[i][j] = 0;
		}
	}// 초기화

	for (int i = 1; i <= N;i++) {
		int adjnum;
		cin >> adjnum;
		for (int j = 1; j <= adjnum; j++) {
			int tmp;
			cin >> tmp;
			adj[i][tmp] = 1;
			adj[tmp][i] = 1;
		}
	}

	solve( 0);

	if (minnum == 23232332) {
		cout << -1;
	}
	else {
		cout << minnum;
	}





	return 0;
}