#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
int main() {
	int testcase;
	cin >> testcase;

	map<string, int> Map;
	{
		Map.insert(make_pair("yotta", 24));
		Map.insert(make_pair("zetta", 21));
		Map.insert(make_pair("exa", 18));
		Map.insert(make_pair("peta", 15));
		Map.insert(make_pair("tera", 12));
		Map.insert(make_pair("giga", 9));
		Map.insert(make_pair("mega", 6));
		Map.insert(make_pair("kilo", 3));
		Map.insert(make_pair("hecto", 2));
		Map.insert(make_pair("deca", 1));
		Map.insert(make_pair("deci", -1));
		Map.insert(make_pair("centi", -2));
		Map.insert(make_pair("milli", -3));
		Map.insert(make_pair("micro", -6));
		Map.insert(make_pair("nano", -9));
		Map.insert(make_pair("pico", -12));
		Map.insert(make_pair("femto", -15));
		Map.insert(make_pair("ato", -18));
		Map.insert(make_pair("zepto", -21));
		Map.insert(make_pair("yocto", -24));
		Map.insert(make_pair("NOT", 0));
	}
	for (int t = 1; t <= testcase;t++) {
		string a, b, c;
		cin >> a >> b;

		if (Map.find(b) == Map.end()) {
			c = b;
			b = "NOT";
		}
		else {
			cin >> c;
		}
		
		


		string ta, tc;
		int tb;
		if (a[0] == '0') {
			int prefixcounter = 0;
			int startpoint = 0;
			string number = "";
			for (int i = 2; i < a.length(); i++) {
				if (a[i] != '0') {
					prefixcounter++;
					startpoint = i;
					break;


				}
				else {
					prefixcounter++;
				}
			}
			for (int i = startpoint; i < a.length(); i++) {
				number += a[i];
			}
			if (number.length() == 1) {//한자리수는 소수점 없다
				ta = number;
			}
			else {//유효숫자 만들기
				string tmps = "";
				tmps += number[0];
				tmps += '.';
				for (int i = 1; i < number.length(); i++) {
					tmps += number[i];

				}
				ta = tmps;
			}
			tb = (-1)*prefixcounter + Map[b];
		}
		else {//0아니면 소수 아님

	
			int prefixcounter = 0;
			string number = "";
			for (int i = 0; i < a.length(); i++) {//소수점 앞에 얼마나 있었는지확인
				if (a[i] != '.') {
					prefixcounter++;
				}
				else {
					break;
				}
			}

			for (int i = 0; i < a.length(); i++) {//소수점 제외 유효숫자구하기
				if (a[i] != '.') {
					number += a[i];
				}
			}

			if (number.length() == 1 ) {//한자리수는 소수점 없다
				ta = number;
			}
			else {//유효숫자 만들기
				string tmps="";
				tmps += number[0];
				tmps += '.';
				for (int i = 1; i < number.length();i++) {
					tmps += number[i];

				}
				 
				ta = tmps;
			}
			tb = prefixcounter - 1 + Map[b];
		}
		tc = c;
		cout << "#" << t << " " << ta<<" * 10^"<< tb<<" "<<tc << endl;
	}
	return 0;
}