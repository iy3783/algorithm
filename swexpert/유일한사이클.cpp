#include <iostream>
#include <map>
#include <vector>
#include <string.h>
using namespace std;

vector<int> adj[1005];
int check[1005];
int maxnum=0;
int cycle_location;
void findcycle( int now, int before  ) {

	
	for (int i = 0; i <adj[now].size(); i++) {
		if (check[adj[now][i]] == 1 &&adj[now][i] != before) {
			cycle_location = adj[now][i];

		}

		if (check[adj[now][i]] == 0) {
			check[adj[now][i]] = 1;
			findcycle( adj[now][i], now);
			check[adj[now][i]] = 0;
		}


	

	}


	return;

}
void DFS(int start , int now  , int before, int len) {
	check[now] = 1;

	for (int i = 0; i <adj[now].size() ; i++) {
		if (check[adj[now][i]] == 1 && adj[now][i] == start && adj[now][i] != before) {
			if (maxnum < len + 1) {
				maxnum = len + 1;

			}

		}

		if (check[adj[now][i]] ==0 ) {
			DFS(start, adj[now][i],now,len+1);

		}




	}


	return;

}



int main() {
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		int N;
		cin >> N;
		maxnum = 0;
		cycle_location = 0;
		for (int i = 1; i <= N;i++) {
			adj[i].clear();
		}
		for (int j = 1; j <= N; j++) {
			check[j] = 0;

		}
		for (int i = 1; i <= N;i++ ) {
			int a,b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);

		}
		check[1] = 1;
		findcycle(1,0);
		check[1] = 0;

		DFS( cycle_location, cycle_location,0 ,0);



		cout << "#" << t << " " << maxnum<< endl;
	}
	return 0;
}