#include <iostream>
using namespace std;

long long int tree[4000000];
long long int number[1000005];
long long init(int index , int start , int end){
	if (start == end) {
		tree[index] = number[start];

	}

	else {
		int mid= (start +end)/2;
		tree[index] = init(index * 2 , start, mid) + init(index * 2 + 1, mid + 1, end);

	}

	return tree[index];
}



long long pprint(int index, int start, int end, int first, int last) {
	if (start > last || end < first) {
		return 0;
	}

	else if (first <= start && end <= last) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		return  pprint(index * 2, start, mid, first, last) + pprint(index * 2 + 1, mid + 1, end, first, last);

	}

}

void changee(int index, int start, int end ,int change ,int changevalue) {

	int mid = (start + end)/2;
	if (start == end) {
		if (start==change) {
			tree[index] += changevalue - number[change];
			return;

		}
		else {
			return;

		}
		
	}


	if (start <=change && change <= end) {
		tree[index] += changevalue - number[change];
		changee(index*2, start, mid, change, changevalue);
		changee(index*2+1, mid + 1, end, change, changevalue);
	}

	else {
		return;
	}

}



int main() {
	ios::sync_with_stdio(false);
	int N;
	int M;
	int K;
	cin >> N;
	cin >> M;
	cin >> K;
	for (int i = 1; i <= N;i++) {
		cin >> number[i];

	}

	init( 1 , 1, 1000000);


	for (int i = 0; i < M+K; i++) {
		int a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		if (a == 1) {
			changee(1, 1, 1000000, b, c);
			number[b] = c;
		}
		else if (a == 2) {
			cout << pprint(1, 1, 1000000, b, c) << "\n";

		}

	}

	return 0;
}