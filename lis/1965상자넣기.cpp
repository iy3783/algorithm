#include <iostream>


using namespace std;



int main() {
	int n;
	cin >> n;
	int arr[1005];
	int D[1005];


	for (int i = 0; i < n;i++) {
		cin >> arr[i];
		D[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (D[i] < D[j] + 1) {
					D[i] = D[j] + 1;
				}
			}
		}
	}
	int max= -1;
	for (int i = 0; i < n; i++) {
		if (max < D[i]) {
			max = D[i];
		}
	}
	cout <<max;




	return 0;
}