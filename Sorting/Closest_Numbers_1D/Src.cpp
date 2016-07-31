#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

struct Pair {
	int value, index;
	Pair(int first, int second): value(first), index(second) {}
};

int main() {
	//fstream read("input.txt", ios::in);

	// Be Careful The Runtime Error
	// (the size of your array)

	int N;
	cin >> N;
	vector<int> arr;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	//read.close();

	sort(arr.begin(), arr.end()); // O(NlogN)

	vector<int> diff;
	diff.resize(N - 1);
	for (int i = 0; i < N - 1; i++) { // O(N)
		diff[i] = abs(arr[i + 1] - arr[i]);
	}

	// Record the pairs of elements with the smallest difference
	vector<Pair> answer;
	answer.reserve(N - 1);
	answer.push_back({ diff[0],0 });
	for (int i = 1; i < diff.size(); i++) { // O(N)
		if (answer[0].value < diff[i]) {
			continue;
		}
		else if (answer[0].value == diff[i]) {
			answer.push_back({ diff[i],i });
		}
		else {
			answer.clear();
			answer.push_back({ diff[i],i });
		}
	}

	//fstream write("output.txt", ios::out);
	for (int i = 0; i < answer.size(); i++) {
		cout << arr[answer[i].index] << " " << arr[answer[i].index + 1] << " ";
	}
	//write.close();

	return 0;
}
