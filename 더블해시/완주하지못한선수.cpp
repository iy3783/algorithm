#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Hashnode {
	string element;
	int info=0;//0ºö 1Ãæµ¹
	int counter = 0;
};
Hashnode hash_table[100010];



int Hashing(string ts) {
	int digitnum = 1;
	int ti=0;
	int ts_len;
	ts_len = ts.length();

	for (int i = ts_len - 1; i >= 0;i--) {
		ti =(ti+ digitnum*(ts[i] - 'a')) % 100000;
		digitnum =(digitnum* 29)%100000;
	}
	return ti;
}

int Hashing2(int ti) {

	return 97391-(ti % 97391);


}


int findHash(string key) {
	int hash_val=Hashing(key);
	int step_hash_val = Hashing2(hash_val);
	while (hash_table[hash_val].info !=0 && hash_table[hash_val].element !=key) {
		hash_val = hash_val + step_hash_val;
		hash_val = hash_val % 100000;
	}

	return hash_val;

}
void insertHash(string key) {
	int pos = findHash(key);
	hash_table[pos].info = 1;
	hash_table[pos].element = key;
	hash_table[pos].counter++;


}
int removeHash(string key) {
	int pos = findHash(key);
	hash_table[pos].counter--;
	if (hash_table[pos].counter ==-1) {
		return 1;
	}
	else {
		return 0;
	}

}


string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	/*for (int i = 0; i < completion.size();i++) {
		insertHash(completion[i]);
	}

	for (int i = 0; i < participant.size();i++) {
		int tk=removeHash(participant[i]);
		if (tk ==1) {
			answer = participant[i];
			break;
		}
	}
	*/
	sort(participant.begin(),participant.end());
	sort(completion.begin(),completion.end());
	for (int i = 0; i < completion.size();i++) {
		if (participant[i]!= completion[i]) {
			answer = participant[i];
			break;
		}
	}
	if (answer == "") {
		answer = participant[completion.size()];
	}

	return answer;
}

int main() {
	vector<string> p;
	vector<string> c;
	p.push_back("marina");
	p.push_back("josipa");
	p.push_back("nikola");
	p.push_back("vinko");
	p.push_back("filipa");
	c.push_back("josipa");
	c.push_back("filipa");
	c.push_back("marina");
	c.push_back("nikola");
	
	cout<< solution(p, c);

	return 0;
}






