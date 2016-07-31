#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int Case, M, N, price;

	unordered_map<int, int> Id;

	cin >> Case;
	while (Case--) {
		cin >> M >> N;

		vector<int>* auxi = new vector<int>[N + 1];
		Id.clear();
		for (int i = 1; i <= N; i++) {
			cin >> price;
			auxi[i].clear();

			if (Id.find(price) == Id.end()) {
				Id.insert(make_pair(price, i));
				auxi[i].push_back(i);
			}
			else {
				auxi[Id[price]].push_back(i);
			}
		}

		int sum = 0;
		unordered_map<int, int>::iterator it;
		unordered_map<int, int>::iterator found;
		for (it = Id.begin(); it != Id.end(); it++) {
			//cout << it->first << " " << it->second << " " << M - (it->first) << "\n";
			sum = M - (it->first);
			found = Id.find(sum);

			if (found != Id.end()) {
				if (Id[sum] != it->second) {
					it->second < Id[sum] ?
						cout << it->second << " " << Id[sum] :
						cout << Id[sum] << " " << it->second;
				}
				else if (auxi[Id[sum]].size() > 1){
					it->second < auxi[Id[sum]][1] ?
						cout << it->second << " " << auxi[Id[sum]][1] :
						cout << auxi[Id[sum]][1] << " " << it->second;
				}
				else {
					continue;
				}

				cout << "\n";
				break;
			}
		}

		delete[] auxi;
	}

	return 0;
}
