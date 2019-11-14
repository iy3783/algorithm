#include <iostream>
#include <stdio.h>
#include <cstring>
#include <malloc.h>
#define NULL 0

using namespace std;

void Run(char button, char display[30 + 1]);

int T;

char CH[33] = {0};
int CHlen=0;
char q1[33] = { 0 };
char q2[33] = { 0 };
int len1 = 0;
int len2 = 0;
char oper = '=';


char CHmulti[33] = { 0 };
int CHmulti_len = 0;
char CHdivide[33] = { 0 };
int CHdivide_len = 0;


void insertq1(char c) {
	q1[len1] = c;
	len1++;
	q1[len1] = 0;
}
void insertq2(char c) {
	q2[len2] = c;
	len2++;
	q2[len2] = 0;
}
void deleteq1() {
	q1[0] = 0;
	len1 = 0;
}
void deleteq2() {
	q2[0] = 0;
	len2 = 0;
}
int my_ctoi(char c1) {
	if ('0' <=c1  &&c1 <='9' ) {
		return c1 - '0';
	}
	else if ( 'a'<=c1&& c1 <= 'f' ) {
		return c1 - 'a'+10;

	}



}
char my_itoc(int a1) {
	if ( 0  <= a1  &&a1 <= 9) {
		return a1 + '0';
	}
	else if ( 10  <= a1&& a1 <= 15) {
		return a1 + 'a' -10;

	}
}
int tc2_isbig() {
	if (CHdivide_len >CHmulti_len) {
		return 0;
	}
	else if(CHdivide_len< CHmulti_len) {
		return 1;
	}
	for (int i = 0; i < CHdivide_len; i++) {
		if (my_ctoi(CHdivide[i]) >my_ctoi(CHmulti[i])) {
			return 0;
		}
		else if (my_ctoi(CHdivide[i]) < my_ctoi(CHmulti[i])) {
			return 1;
		}
	}
	return 0;
}


void M_plus() {
	char tc[33];
	int q1_index = len1;
	int q2_index = len2;

	if (len1 > len2) {
		int carry = 0;
		tc[len1] = 0;
		for (int i = len1-1; i >=0;i--) {
			if (q2_index==0) {
				int sum = 0;
				if (carry == 1) {
					sum += 1;

				}
				sum += my_ctoi(q1[q1_index - 1]);
				if (sum >= 16) {
					carry = 1;
					sum -= 16;
				}
				else {
					carry = 0;
				}
				tc[i] = my_itoc(sum);
				q1_index--;
			}
			else {
				int sum = 0;
				if (carry == 1) {
					sum += 1;
					
				}
				int tmpint1 = my_ctoi(q1[q1_index - 1]);
				int tmpint2 = my_ctoi(q2[q2_index - 1]);
				sum += tmpint1;
				sum += tmpint2;

				if (sum >=16) {
					carry = 1;
					sum -= 16;
				}
				else {
					carry = 0;							
				}
				tc[i] =  my_itoc(sum);
				q1_index--;
				q2_index--;
			}

		}
		if (carry ==0) {
			for (int i = 0; i <= len1;i++) {
				CH[i] = tc[i];
			}
			CHlen = len1;
		}
		else {
			CH[0] =my_itoc(carry);
			for (int i = 0; i <= len1; i++) {
				CH[i+1] = tc[i];
			}
			CHlen = len1+1;
		}

	}
	else {
		int carry = 0;
		tc[len2] = 0;
		for (int i = len2 - 1; i >= 0; i--) {
			if (q1_index == 0) {
				int sum = 0;
				if (carry == 1) {
					sum += 1;

				}
				sum += my_ctoi(q2[q2_index - 1]);
				if (sum >= 16) {
					carry = 1;
					sum -= 16;
				}
				else {
					carry = 0;
				}
				tc[i] = my_itoc(sum);
				q2_index--;
			}
			else {
				int sum = 0;
				if (carry == 1) {
					sum += 1;

				}
				int tmpint1 = my_ctoi(q1[q1_index - 1]);
				int tmpint2 = my_ctoi(q2[q2_index - 1]);
				sum += tmpint1;
				sum += tmpint2;

				if (sum >= 16) {
					carry = 1;
					sum -= 16;
				}
				else {
					carry = 0;
				}
				tc[i] = my_itoc(sum);
				q1_index--;
				q2_index--;
			}

		}
		if (carry == 0) {
			for (int i = 0; i <= len2; i++) {
				CH[i] = tc[i];
			}
			CHlen = len2;
			CH[CHlen] = 0;
		}
		else {
			CH[0] = my_itoc(carry);
			for (int i = 0; i <= len2; i++) {
				CH[i + 1] = tc[i];
			}
			CHlen = len2+1;
			CH[CHlen] = 0;


		}
	}
	



}

void argu_plus(char qq[] ,int arg_len ) { //CHmulti + qq 하는 방식 ,결과 CHmulti에 저장
	char tc[33];
	int q1_index = CHmulti_len;
	int q2_index = arg_len;

	if (CHmulti_len > arg_len) {
		int carry = 0;
		tc[CHmulti_len] = 0;
		for (int i = CHmulti_len - 1; i >= 0; i--) {
			if (q2_index == 0) {
				int sum = 0;
				if (carry == 1) {
					sum += 1;

				}
				sum += my_ctoi(CHmulti[q1_index - 1]);
				if (sum >= 16) {
					carry = 1;
					sum -= 16;
				}
				else {
					carry = 0;
				}
				tc[i] = my_itoc(sum);
				q1_index--;
			}
			else {
				int sum = 0;
				if (carry == 1) {
					sum += 1;

				}
				int tmpint1 = my_ctoi(CHmulti[q1_index - 1]);
				int tmpint2 = my_ctoi(qq[q2_index - 1]);
				sum += tmpint1;
				sum += tmpint2;

				if (sum >= 16) {
					carry = 1;
					sum -= 16;
				}
				else {
					carry = 0;
				}
				tc[i] = my_itoc(sum);
				q1_index--;
				q2_index--;
			}

		}
		if (carry == 0) {
			for (int i = 0; i <= CHmulti_len; i++) {
				CHmulti[i] = tc[i];
			}
		}
		else {
			CHmulti[0] = my_itoc(carry);
			for (int i = 0; i <= CHmulti_len; i++) {
				CHmulti[i+1] = tc[i];
			}
			CHmulti_len = CHmulti_len + 1;
		}

	}
	else {
		int carry = 0;
		tc[arg_len] = 0;
		for (int i = arg_len - 1; i >= 0; i--) {
			if (q1_index == 0) {
				int sum = 0;
				if (carry == 1) {
					sum += 1;

				}
				sum += my_ctoi(qq[q2_index - 1]);
				if (sum >= 16) {
					carry = 1;
					sum -= 16;
				}
				else {
					carry = 0;
				}
				tc[i] = my_itoc(sum);
				q2_index--;
			}
			else {
				int sum = 0;
				if (carry == 1) {
					sum += 1;

				}
				int tmpint1 = my_ctoi(CHmulti[q1_index - 1]);
				int tmpint2 = my_ctoi(qq[q2_index - 1]);
				sum += tmpint1;
				sum += tmpint2;

				if (sum >= 16) {
					carry = 1;
					sum -= 16;
				}
				else {
					carry = 0;
				}
				tc[i] = my_itoc(sum);
				q1_index--;
				q2_index--;
			}

		}
		if (carry == 0) {
			for (int i = 0; i <= arg_len; i++) {
				CHmulti[i] = tc[i];
			}
			CHmulti_len = arg_len;
			CHmulti[CHmulti_len] = 0;
		}
		else {
			CHmulti[0] = my_itoc(carry);
			for (int i = 0; i <= arg_len; i++) {
				CHmulti[i + 1] = tc[i];
			}
			CHmulti_len = arg_len + 1;
			CHmulti[CHmulti_len] = 0;
		}
	}


}

void M_minus()
{
	char tc[33];
	int q1_index = len1;
	int q2_index = len2;


	int carry = 0;
	tc[len1] = 0;
	for (int i = len1 - 1; i >= 0; i--) {
		if (q2_index == 0) {
			int sum = 0;
			if (carry == 1) {
				sum -= 1;

			}
			sum += my_ctoi(q1[q1_index - 1]);
			if (sum < 0) {
				carry = 1;
				sum += 16;
			}
			else {
				carry = 0;
			}
			tc[i] = my_itoc(sum);
			q1_index--;
		}
		else {
			int sum = 0;
			if (carry == 1) {
				sum -= 1;

			}
			int tmpint1 = my_ctoi(q1[q1_index - 1]);
			int tmpint2 = my_ctoi(q2[q2_index - 1]);
			sum += tmpint1;
			sum -= tmpint2;

			if (sum <0) {
				carry = 1;
				sum += 16;
			}
			else {
				carry = 0;
			}
			tc[i] = my_itoc(sum);
			q1_index--;
			q2_index--;
		}

	}

	int front_zero_counter = 0;
	for (int i = 0; i <= len1; i++) {
		if (tc[i] == '0') {
			front_zero_counter++;
		}
		else {
			break;
		}
	}
	for (int i = front_zero_counter; i <= len1; i++) {
		CH[i - front_zero_counter] = tc[i];
	}
	CHlen = len1 - front_zero_counter;



}

void argu_minus(char qq[] ,int arg_len) {
	char tc[33];
	int q1_index = CHdivide_len;
	int q2_index = arg_len;


	int carry = 0;
	tc[CHdivide_len] = 0;
	for (int i = CHdivide_len - 1; i >= 0; i--) {
		if (q2_index == 0) {
			int sum = 0;
			if (carry == 1) {
				sum -= 1;

			}
			sum += my_ctoi(CHdivide[q1_index - 1]);
			if (sum < 0) {
				carry = 1;
				sum += 16;
			}
			else {
				carry = 0;
			}
			tc[i] = my_itoc(sum);
			q1_index--;
		}
		else {
			int sum = 0;
			if (carry == 1) {
				sum -= 1;

			}
			int tmpint1 = my_ctoi(CHdivide[q1_index - 1]);
			int tmpint2 = my_ctoi(qq[q2_index - 1]);
			sum += tmpint1;
			sum -= tmpint2;

			if (sum <0) {
				carry = 1;
				sum += 16;
			}
			else {
				carry = 0;
			}
			tc[i] = my_itoc(sum);
			q1_index--;
			q2_index--;
		}

	}
	int front_zero_counter = 0;
	for (int i = 0; i <= CHdivide_len; i++) {
		if (tc[i] == '0') {
			front_zero_counter++;
		}
		else {
			break;
		}
	}
	for (int i = front_zero_counter; i <= CHdivide_len; i++) {
		CHdivide[i - front_zero_counter] = tc[i];
	}
	CHdivide_len = CHdivide_len - front_zero_counter;


}

void argu_minus2(char qq[], int arg_len) {
	char tc[33];
	int q1_index = CHmulti_len;
	int q2_index = arg_len;


	int carry = 0;
	tc[CHmulti_len] = 0;
	for (int i = CHmulti_len - 1; i >= 0; i--) {
		if (q2_index == 0) {
			int sum = 0;
			if (carry == 1) {
				sum -= 1;

			}
			sum += my_ctoi(CHmulti[q1_index - 1]);
			if (sum < 0) {
				carry = 1;
				sum += 16;
			}
			else {
				carry = 0;
			}
			tc[i] = my_itoc(sum);
			q1_index--;
		}
		else {
			int sum = 0;
			if (carry == 1) {
				sum -= 1;

			}
			int tmpint1 = my_ctoi(CHmulti[q1_index - 1]);
			int tmpint2 = my_ctoi(qq[q2_index - 1]);
			sum += tmpint1;
			sum -= tmpint2;

			if (sum <0) {
				carry = 1;
				sum += 16;
			}
			else {
				carry = 0;
			}
			tc[i] = my_itoc(sum);
			q1_index--;
			q2_index--;
		}

	}
	int front_zero_counter = 0;
	for (int i = 0; i <= CHmulti_len; i++) {
		if (tc[i] == '0') {
			front_zero_counter++;
		}
		else {
			break;
		}
	}
	for (int i = front_zero_counter; i <= CHmulti_len; i++) {
		CHmulti[i - front_zero_counter] = tc[i];
	}
	CHmulti_len = CHmulti_len - front_zero_counter;

}

void M_multiply()
{
	char tc[33];
	char digit[33][33];//뒤는 각 자릿수 마다 더할 값 , 앞은 q2자리수
	int digitlength[33];
	int counter = 0;
	for (int i = len2 - 1; i >= 0; i--) {
		int carry = 0;
		tc[len1]=0;
		for (int j = len1 - 1; j >= 0; j--) {
			int sum = 0;
			if (carry !=0) {
				sum +=carry;

			}
			int tmpint1 = my_ctoi(q1[j]);
			int tmpint2 = my_ctoi(q2[i]);
			sum += tmpint1*tmpint2;

			carry = sum/16;
			sum = sum % 16;
			tc[j] = my_itoc(sum);
		}
		if (carry != 0) {
			digit[i][0] = my_itoc(carry);
			for (int j = 0; j <= len1; j++) {
				digit[i][j+1] = tc[j];
			}
			digitlength[i] = len1+1;
		}
		else {
			for (int j = 0; j <= len1; j++) {
				digit[i][j] = tc[j];
			}
			digitlength[i] = len1;
		}

		for (int j = 0; j < counter; j++) {
			digit[i][digitlength[i]] = '0';
			digitlength[i]++;
		}
		digit[i][digitlength[i]] = 0;
		counter++;

	}

	for (int i = 0; i <= digitlength[len2-1]; i++) {
		CHmulti[i] = digit[len2-1][i];
	}
	CHmulti_len = digitlength[len2-1];
	for (int i =len2-2 ; i>=0  ; i--) {
		argu_plus(digit[i],digitlength[i]);
	}

	int front_zero_counter = 0;
	for (int i = 0; i <= CHmulti_len; i++) {
		if (CHmulti[i] == '0') {
			front_zero_counter++;
		}
		else {
			break;
		}
	}
	for (int i = front_zero_counter; i <= CHmulti_len; i++) {
		CH[i - front_zero_counter] = CHmulti[i];
	}
	CHlen = CHmulti_len - front_zero_counter;


}

void M_divide()
{
	char tc[33];
	char tclen = 0;
	
	char tc2[33];
	int tc2len;
	int q1_index = len1;
	int q2_index = len2;

	int zero_digit_counter= len1 - len2;//나눗셈 위해 0추가

	for (int i = 0; i <= len1;i++) {
		CHdivide[i] = q1[i];
	}
	CHdivide_len = len1;
	if (len2>len1) {
		CH[0] = '0';
		CH[1] = 0;
		CHlen = 1;
	}
	else {
		while (zero_digit_counter >=0) {
			for (int i = 0; i <= len2; i++) {
				tc2[i] = q2[i];
			}
			tc2len = len2; // tc2에 q2복사
			for (int i = 0; i < zero_digit_counter; i++) {
				tc2[tc2len] = '0';
				tc2len++;
			}// q1과 같은 len으로 맞춘다.
			tc2[tc2len] = 0;
			for (int i = 0; i <= tc2len ; i++) {
				CHmulti[i] = tc2[i];
			}
			CHmulti_len = tc2len;
			int counter = 0;
			while (1) {
				if (tc2_isbig() == 1) {
					tc[tclen]= my_itoc(counter);
					tclen++;
					tc[tclen] = 0;
					argu_minus2(tc2,tc2len);
					break;
				}
				else if (tc2_isbig() ==0) {
					counter++;
					argu_plus(tc2, tc2len);

				}
			}
			char tmpp[31];
			int tmpplen = CHmulti_len;
			for (int i = 0; i <= CHmulti_len; i++) {
				tmpp[i] = CHmulti[i];
			}
			argu_minus(tmpp , tmpplen);

			zero_digit_counter--;
		}

		int front_zero_counter=0;
		for (int i = 0; i <= tclen; i++) {
			if (tc[i] =='0' ) {
				front_zero_counter++;
			}
			else {
				break;
			}
		}
		for (int i = front_zero_counter; i <= tclen; i++) {
			CH[i - front_zero_counter] = tc[i];
		}
		CHlen = tclen - front_zero_counter;

	}




}

int main()
{
	freopen("input.txt", "r", stdin);

	int totalscore = 0;
	int tc = 0;
	int score = 100;

	char res[31] = { 0 };
	char ans[31] = { 0 };
	char buf[10] = { 0 };
	cin >> T;
	scanf("%s %s", buf, ans);
	while (buf[0] != 'Z')
	{
		Run(buf[0], res);
		if (strcmp(res, ans) != 0)
		{
			if (score) score--;
		}

		scanf("%s %s", buf, ans);

		if (buf[0] == 'C')
		{
			printf("#%d %d\n", tc + 1, score);
			tc++;
			totalscore += score;
			score = 100;
		}
	}
	printf("#%d %d\n", tc + 1, score);
	tc++;
	totalscore += score;

	printf("Total Score = %d\n", totalscore / tc);

	return 0;
}



void Run(char button, char display[30 + 1])
{

	if (button =='C') {
	
		oper = '=';
		deleteq1();
		deleteq2();
		display[0] = '0';
		display[1] = 0;
	}
	else if (button =='+'|| button == '-' || button == '*' || button == '/' ) {
		if (oper =='=') {
			for (int i = 0; i <= len1; i++) {
				display[i] = q1[i];
			}
			oper = button;
			if (len1 == 0) {
				insertq1('0');
				display[0] = '0';
				display[1] = 0;
			}
		}
		else {
			switch (oper) {
			case '+':
				M_plus();
				break;
			case '-':
				M_minus();
				break;
			case '*':
				M_multiply();
				break;
			case '/':
				M_divide();
				break;

			}
			for (int i = 0; i <= CHlen; i++) {
				q1[i] = CH[i];
				display[i] = q1[i];
			}
			len1 = CHlen;
			deleteq2();
			oper = button;
			if (len1 == 0) {
				insertq1('0');
				display[0] = '0';
				display[1] = 0;
			}
		}

	}
	else if (button == '=' ) {
		if (oper =='=') {
			for (int i = 0; i <= len1; i++) {
				display[i] = q1[i];
			}
			if (len1 == 0) {
				insertq1('0');
				display[0] = '0';
				display[1] = 0;
			}
		}
		else {
			switch (oper) {
			case '+':
				M_plus();
				break;
			case '-':
				M_minus();
				break;
			case '*':
				M_multiply();
				break;
			case '/':
				M_divide();
				break;
			}

			for (int i = 0; i <= CHlen; i++) {
				q1[i] = CH[i];
				display[i] = q1[i];
			}
			len1 = CHlen;
			deleteq2();
			oper = '=';
			if (len1 == 0) {
				insertq1('0');
				display[0] = '0';
				display[1] = 0;
			}
		}
	}
	else {
		if (oper =='=') {
			insertq1(button);
			for (int i = 0; i <= len1; i++) {
				display[i] = q1[i];
			}

		}
		else if(oper == '+' || oper == '-' || oper == '*' || oper == '/'){
			insertq2(button);
			for (int i = 0; i <= len2; i++) {
				display[i] = q2[i];
			}
		}

	}





}
