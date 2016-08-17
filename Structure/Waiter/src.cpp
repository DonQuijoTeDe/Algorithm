#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX 10001

std::vector<int> prime;

void LinearSieve();

int main() {
    int N, Q, P, i, j;
    std::cin >> N >> Q;

    std::vector<int> input;
    input.resize(N);

    for (i = 0; i < N; i++)
        std::cin >> input[i];

    LinearSieve(); // Construct the prime number table
                   // in linear time

    std::vector<int> tmp;
    tmp.reserve(N);
    for (i = 0; i < Q; i++) {
        P = prime[i];
        for (j = 0; j < input.size(); j++) {
            if (input[j] % P == 0)
                std::cout << input[j] << "\n";
            else
                tmp.push_back(input[j]);
        }

        input.clear();
        reverse(tmp.begin(), tmp.end());
        input = tmp;
        tmp.clear();
    }

    for (i = input.size() - 1; i >= 0; i--)
        std::cout << input[i] << "\n";

    return 0;
}

void LinearSieve() {
    int i, j;
    bool sieve[MAX];

    memset(sieve, false, sizeof(sieve));
    prime.reserve(MAX / 5);

    for (i = 2; i < MAX; i++) {
        // i is a prime number
        if (!sieve[i])
            prime.push_back(i);

        for (j = 0; i*prime[j] < MAX; j++) {
            // i*prime[j] is not a prime number
            sieve[i*prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }

}
