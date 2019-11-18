#include <iostream>
using namespace std;
//segment tree
long long int number[100005];
long long int tree[400005];

long long int init(int index , int start, int end ) {
	if (start == end) {
		tree[index] = number[start];
	}
	else {
		int mid = (start + end) / 2;
		tree[index] = init(index * 2, start, mid) + init(index * 2 + 1, mid + 1, end);
	}

	return tree[index];
}
long long int pprint(int index, int start,int end, int first,int last) {
	//범위의 합을 출력
	if (start > last || end < first) {
		return 0;

	}
	else if ( first <=  start&& end <= last) {
		return tree[index];

	}
	else {
		int mid = (start + end) / 2;
		return pprint(index*2 , start,mid,first,last  )+pprint(index*2+1,mid+1,end,first,last );
	}

}

void changee(int index , int start,int end,int change,int changevalue) {
	int mid = (start + end) /2 ;
	if (start == end) {
		if (start == change) {
			tree[index] += changevalue - number[change];
			return;
		}
		else {

			return;
		}

	}
	if (start <= change && change <= end) {
		tree[index] += changevalue - number[change];
		changee(index*2,start,mid,change,changevalue);
		changee(index * 2+1, mid+1, end, change, changevalue);

	}
	else {
		return;
	}


}




int main() {



	return 0;
}