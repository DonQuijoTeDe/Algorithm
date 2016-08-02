#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Input: 1 3 5 4 2 8 10, k=3
	// Bucket[0]: 3
	// Bucket[1]: 1, 4, 10
	// Bucket[2]: 5, 2, 8

	int n, k, i;

	cin >> n >> k;

	vector<int> vec(n, 0);
	vector<int> buckets(k, 0);

	for (i = 0; i < n; i++) {
		cin >> vec[i];
		buckets[vec[i] % k]++;
	}

	int answer = 0;

	answer = buckets[0] * (buckets[0] - 1) / 2;
	for (i = 1; i <= k / 2 && i != k - i; i++) {
		answer += buckets[i] * buckets[k - i];
	}
	if (k % 2 == 0) {
		answer += buckets[i] * (buckets[i] - 1) / 2;
	}

	cout << answer;

	return 0;
}
