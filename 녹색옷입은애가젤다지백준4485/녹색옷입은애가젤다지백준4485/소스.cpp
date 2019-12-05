#include <iostream>
using namespace std;

struct yxr {
	int y;
	int x;
	int r_sum;
};


class myheap {
private:
	yxr newheap[80000];
	int heapnumber;
public:
	myheap();
	void mydownheap();
	void myupheap();


};

myheap::myheap() {
	this->heapnumber = 0;

}

void myheap::mydownheap() {
	int a=2;
	
	
	while (a <= this->heapnumber ) {
		if (this->newheap[a].r_sum > this->newheap[a+1].r_sum ) {
			a = a + 1;
		}
		if (this->newheap[a/2].r_sum > this->newheap[a].r_sum) {
			yxr temp = this->newheap[a];
			this->newheap[a] = this->newheap[a/2];
			this->newheap[a/2] = temp;

		}


	}




}

void myheap::myupheap() {
	int a;
	a = this->heapnumber;
	while (a/2 > 0) {
		int b = a / 2;
		if (this->newheap[b].r_sum> this->newheap[a].r_sum) {
			yxr temp= this->newheap[a];
			this->newheap[a] = this->newheap[b];
			this->newheap[b] = temp;
		}


		a = a / 2;
	}

}

int main() {
	ios::sync_with_stdio(false);

	



	return 0;
}