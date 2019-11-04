#include <iostream>
#include <vector>
#define INF -10000000000
using namespace std;
long long int number[20];
char op[20];
long long int maxnum=INF;
int N;
vector<int> v;

long long int operating(long long int a, long long int b, char op) {
	if (op =='+') {
		return a + b;
	}
	if (op == '-')
	{
		return a - b;

	}
	if (op == '*') {
		return a * b;

	}
}

void solve(int n  ) {
	if (n > N / 2)
	{
		
		long long int number2[13];
		char op2[13];
		for (int i = 0; i < 12; i ++) {
			number2[i] = number[i];
			op2[i] = op[i];
		}



		for (int i = 0; i < v.size(); i++ ) {
			int tmp = v[i];


			number2[tmp - 1] = operating(number2[tmp - 1], number2[tmp], op2[tmp]);
			number2[tmp] = INF;
			op2[tmp] = 'n';

		}

		int sum = number2[0];
		for (int i = 1; i <= N / 2;i++ ) {
			if (op2[i] == 'n') {
				continue;
			}
			sum = operating(sum, number2[i], op2[i]);
		}
		if (sum > maxnum) {
			maxnum = sum;
		}


		return;
	}


	solve(n+1);

	v.push_back(n);
	solve(n + 2);
	v.pop_back();

	return;
}



int main() {
	
	cin >> N;

	cin >> number[0];
	for (int i = 1; i <= N / 2; i++) {
		cin >> op[i];
		cin >> number[i];
	

	}



	solve(1);



	cout << maxnum;




	return 0;
}