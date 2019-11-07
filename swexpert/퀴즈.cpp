#include <iostream>
using namespace std;
#define MOD 1000000007
long long int D[1000005];

long long int func(long long int i , long long int k) {


	if (k == 0) {
		return 1;

	}
	
	long long int tmp = (func(i, k / 2) % MOD);

	if (k%2==0) {

		return (tmp * tmp)%MOD;
	}
	else  {
	
		return (tmp*tmp) % MOD  * i %MOD;


	}



}



int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int testcase;
	cin >> testcase;
	long long int sum = 0;
	for (int i = 1; i <= 1000000; i++) {
		long long int tmp = func(i, i);
		sum += tmp;
		sum %= MOD;
		D[i] = sum;
	}



	for (int t = 1; t <= testcase;t++) {
		int N;
		cin >> N;
	
		cout << "#" << t << " " << D[N] << "\n";
	}


	return 0;
}