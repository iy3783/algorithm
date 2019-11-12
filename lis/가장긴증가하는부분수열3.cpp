#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {

	int N;
	cin >> N;
	long long int A[1000005];
	vector<long long int> v;
	v.push_back(-1000000000);
	long long int ans=0;
	for (int i = 0; i < N;i++) {
		cin >> A[i];

	}
	for (int i = 0; i < N; i++) {
		if (v.back() <A[i]   ) {
			v.push_back(A[i]);
			ans++;
		}
		else {
			 vector<long long int>::iterator it = lower_bound(v.begin(),v.end(), A[i]);
			 *it = A[i];

		}


	}

	cout << ans;

	return 0;
}
/*
int lower_boundd(int arr[],int target,int size) {
	int mid, start, end;
	start = 0;
	end = size - 1;


	while (end > start)
	{
		mid = (start + end);
		if ( arr[mid] >=target  ) {
			end = mid;
			
		}
		else start = mid+1;


	}
	return end;

}
*/