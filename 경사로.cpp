#include <iostream>
using namespace std;
int N;
int L;
int map[105][105];
int total_sum=0;
int impossible[105][2] = {0};
void row_road() {
	int check[105][105] = { 0 };
	for (int i = 0; i <N; i++) {

		for (int  j= 0; j < N - 1; j++) {
			if (impossible[i][0] == 1) {
				break;

			}

			if (map[i][j] == map[i][j+1]) {
				continue;

			} //밑과 같을때
			else if (map[i][j] == map[i][j+1] + 1) {
				if (j + L >= N) {
					impossible[i][0] = 1;
					continue;
				}
				int build_possible = 1;
				for (int p = j + 1; p <= j + L; p++) {
					if (map[i][j]-1 == map[i][p] && check[i][p] == 0) {

					}
					else {
						build_possible = 0;
						impossible[i][0] = 1;
					}
				}
				if (build_possible == 1) {
					for (int p = j + 1; p <= j + L; p++) {
						check[i][p] = 1;

					}
				}




			}//더 내려갈때
			else if (map[i][j] == map[i][j + 1] - 1) {
				if (j + 1 - L <0) {
					impossible[i][0] = 1;

				}

				int build_possible = 1;
				for (int p = j; p >= j + 1 - L; p--) {
					if (map[i][j+1] - 1 == map[i][p] && check[i][p] == 0) {

					}
					else {
						build_possible = 0;
						impossible[i][0] = 1;
					}
				}
				if (build_possible == 1) {
					for (int p = j; p >= j + 1 - L; p--) {
						check[i][p] = 1;

					}
				}




			}//더 올라갈때 
			else {
				impossible[i][0] = 1;

			}



		}
	}

}
void col_road() {
	int check[105][105] = { 0 };
	for (int j = 0; j <N; j++) {

		for (int i = 0; i < N-1; i++) {
			if (impossible[j][1] == 1) {
				break;

			}

			if (map[i][j]==map[i+1][j]) {
				continue;

			} //밑과 같을때
			else if(map[i][j] == map[i + 1][j] +1){
				if (i+L>=N) {
					impossible[j][1] = 1;
					continue;
				}
				int build_possible = 1;
				for (int p = i+1 ; p <=i+L ; p++) {
					if (map[i][j]-1 ==  map[p][j] && check[p][j] == 0) {
						
					}
					else {
						build_possible = 0;
						impossible[j][1] = 1;
					}
				}
				if (build_possible == 1) {
					for (int p = i + 1; p <= i + L; p++) {
						check[p][j] = 1;

					}
				}




			}//더 내려갈때
			else if (map[i][j] == map[i + 1][j] -1) {
				if (i+1 - L <0) {
					impossible[j][1] = 1;

				}

				int build_possible = 1;
				for (int p = i; p >= i +1- L; p--) {
					if (map[i+1][j]-1 == map[p][j] && check[p][j] == 0) {

					}
					else {
						build_possible = 0;
						impossible[j][1] = 1;
					}
				}
				if (build_possible == 1) {
					for (int p = i; p >= i + 1 - L; p--) {
						check[p][j] = 1;

					}
				}




			}//더 올라갈때 
			else {
				impossible[j][1] = 1;
				
			}



		}
	}

}


int main() {
	cin >> N;
	cin >> L;
	for (int i = 0; i <N ; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	row_road();
	col_road();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			if (impossible[i][j] == 0  ) {
				total_sum++;

			}

		}
	}

	cout << total_sum;


	return 0;
}