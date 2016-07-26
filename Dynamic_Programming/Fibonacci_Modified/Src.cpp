#include <iostream>
#include <string>
using namespace std;

string BigIntegerAdd(string, string);
string BigIntegerMul(string, string);

int main(){
  // TLE
  // I'm still trying to solve this problem in c++
	int t1, t2, n, i;
	cin >> t1 >> t2 >> n;

	string DP[21];
	DP[1] = to_string(t1);
	DP[2] = to_string(t2);

	for (i = 3; i <= n; i++){
		DP[i] = BigIntegerAdd(DP[i - 2], BigIntegerMul(DP[i - 1], DP[i - 1]));
	}

	cout << DP[n];

	return 0;
}

string BigIntegerAdd(string a, string b){
	string answer = "";
	int digitA, digitB, digit, carry = 0, temp;

	digitA = a.length();
	digitB = b.length();
	digit = digitA > digitB ? digitA : digitB;

	while (digit--){
		temp = carry;
		if (--digitA >= 0){
			temp += (a[digitA] - '0');
		}
		if (--digitB >= 0){
			temp += (b[digitB] - '0');
		}
		carry = temp / 10;
		temp %= 10;
		answer.insert(answer.begin(), temp + '0'); // if answer's length is 1000
		                                           // it will cause O(1000-1) time
												   // to complete it's operation
	}
	if (carry){
		answer.insert(answer.begin(), carry + '0');
	}

	return answer;
}

string BigIntegerMul(string a, string b){
	string answer = "";
	string partialresult;
	int carry = 0, temp, i, j, k;

	for (i = b.length() - 1, k = 0; i >= 0; i--, k++){
		partialresult = "";
		for (j = k; j>0; j--){
			partialresult.insert(partialresult.begin(), '0');
		}
		temp = carry = 0;
		for (j = a.length() - 1; j >= 0; j--){
			temp = carry + (b[i] - '0')*(a[j] - '0');
			carry = temp / 10;
			temp %= 10;
			partialresult.insert(partialresult.begin(), temp + '0');
		}
		if (carry){
			partialresult.insert(partialresult.begin(), carry + '0');
		}

		answer = BigIntegerAdd(answer, partialresult);
	}

	return answer;
}
