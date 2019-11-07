#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct ab {
	long long int a;
	long long int b;
};
ab D[96];

void D_init( int d) {
	if (d >90) {
		return;
	}
	D[d].a = D[d - 1].a + D[d - 1].b;
	D[d].b = D[d - 1].a;
	D_init(d + 1);



	return;
}

int main() {
	int testcase;
	cin >> testcase;

	ab ab1;
	ab1.a = 2;
	ab1.b = 1;
	D[1] = ab1;
	D_init(2);


	for (int t = 1; t <= testcase; t++) {
		int K;
		cin >> K;



		cout << "#" << t << " " << D[K].a<<" "<<D[K].b<< endl;
	}
	return 0;
}