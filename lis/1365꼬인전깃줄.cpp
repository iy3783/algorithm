#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> V;
	int A[100005];
	for (int i = 0; i < N;i++) {
		cin >> A[i];

	}
	int ans=0;
	V.push_back(-1);
	for (int i = 0; i < N;i++) {
		if (V.back() < A[i]) {
			V.push_back(A[i]);
			ans++;
		}
		else {
			auto it = lower_bound(V.begin(),V.end(), A[i] );
			*it = A[i];
		}

	}

	cout << N-ans;

}