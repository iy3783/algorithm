#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


struct yx
{
	int y;
	int x;
};
struct from_to
{
	int start;
	int des;
};

int map[15][15];
int map_num[15][15];

int N;
int M;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<from_to> total_ft;

vector<from_to> ft;
int island_num;
int connect_num;

vector<yx> mapinfo[10];


int minnum = 12345678;


int checking(int start,int des) {

	int minn=12345678;

	for (int i = 0; i < mapinfo[start].size(); i++) {
		int sy = mapinfo[start][i].y;
		int sx = mapinfo[start][i].x;
		int counter;
		for (int j = 0; j < 4; j++) {
			int nexty = sy;
			int nextx = sx;
			counter = 0;
			while (1) {
				nexty = nexty + dy[j];
				nextx = nextx + dx[j];
				if (nexty <= 0 || nexty >N || nextx <= 0 || nextx >M) {
					break;
				}
				if (map_num[nexty][nextx] !=0) {
					if (map_num[nexty][nextx] == start) {
						break;
					}
					else if (map_num[nexty][nextx] == des) {
						if (counter >= 2) {
							if (counter < minn) {
								minn = counter;
							}

						}
						break;
					}
					else {
						break;

					}

				}

				counter++;

			}
		}
	}
	if (minn == 12345678) {
		return 0;

	}
	else {
		return minn;
	}


}



int BFS( int adj[][10] ) {
	int tcheck[10];
	for (int i = 1; i <= island_num; i++) {
		tcheck[i] = 0;
	}
	queue<int> Q;
	Q.push(1);
	tcheck[1] = 1;
	

	while (!Q.empty()) {

		int top = Q.front();
		Q.pop();
		for (int i = 1; i <= island_num; i++) {
			if (tcheck[i]==0 && adj[top][i] == 1  ) {
				Q.push(i);
				tcheck[i] = 1;
			}


		}


	}
	int possible = 1;
	for (int i = 1; i <= island_num; i++ ) {
		if (tcheck[i] == 0) {
			possible = 0;
		}

	}
	return possible;


}
void solve( int depth ) {
	
	if (  depth == total_ft.size()) {
		int adj[10][10];
		for (int i = 1; i <= island_num; i++) {
			for (int j = 1; j <= island_num; j++) {
				adj[i][j] = 0;
			}
		}
		for (int i = 0; i < ft.size();i++) {
			adj[ft[i].start][ft[i].des] = 1;
			adj[ft[i].des][ft[i].start] = 1;
		}

		int ps = BFS(adj);

		if (ps == 0) {
			return; 
		}
		int sum = 0;
		for (int i = 0; i < ft.size(); i++) {
			int tmpt = checking(ft[i].start, ft[i].des);
			if (tmpt == 0) {
				return;
			}
			sum += tmpt;

		}
	
		if (sum < minnum ) {
			minnum = sum;

		}
		




		return;

	}


	

	
	solve(depth + 1);


	ft.push_back(total_ft[depth]);
	solve(depth+1);
	ft.pop_back();


	return;
}








void find_island(int y, int x,int numbering) {
	int tcheck[15][15];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tcheck[i][j] = 0;
		}
	}
	queue<yx> Q;
	yx ff;
	ff.y = y;
	ff.x = x;
	Q.push(ff);
	tcheck[y][x] = 1;
	map_num[y][x] = numbering;

	while (!Q.empty()  ) {
		
		yx top = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i ++) {
			yx next;
			next.y = top.y + dy[i];
			next.x = top.x + dx[i];
			if ( next.y <=0 || next.y >N || next.x <= 0 || next.x >M ) {
				continue;
			}
			if (tcheck[next.y][next.x]==0  &&map[next.y][next.x]==1   ) {
				Q.push(next);
				tcheck[next.y][next.x] = 1;
				map_num[next.y][next.x] = numbering;
			}


		}
	
	
	}


	


}




int main() {

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N;i++) {
		for (int j = 1; j<=M;j++ ){
			map[i][j]=0;
			map_num[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	int numbering=0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] != 0 && map_num[i][j] == 0) {
				numbering++;
				find_island(i,j,numbering);
				
			}
			
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] !=0) {
				yx tmp;
				tmp.y = i;
				tmp.x = j;
			
				mapinfo[map_num[i][j]].push_back(tmp);

			}

		}
	}
	


	for (int i = 1; i <= numbering; i++) {
		for (int j = i+1; j <= numbering; j++) {
			from_to tmp;
			tmp.start = i;
			tmp.des = j;
			total_ft.push_back(tmp);
		}
	}
	island_num = numbering;
	
	solve(  0);

	if (minnum == 12345678) {
		cout << -1;
	}
	else if (minnum == 0) {
		cout << -1;
	}
	else {
		cout << minnum;

	}


	return 0;
}