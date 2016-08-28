#include <iostream>
#include <cmath>
using namespace std;

#define ull unsigned long long

ull f(ull a, int b, int c) {
    return a*b + c;
}

int main() {
    int N, S, P, Q;
    cin >> N >> S >> P >> Q;

    ull modulo = static_cast<ull>(pow(2, 31)); // modulo 2^31
    int bound = 1; // bound check
    /*
    # Main phase of algorithm : finding a repetition x_i = x_2i.
    # The hare moves twice as quickly as the tortoise and
    # the distance between them increases by 1 at each step.
    # Eventually they will both be inside the cycle and then,
    # at some point, the distance between them will be
    # divisible by the period λ.
    */
    // Initial position
    ull x0 = S % modulo;
    ull tortoise = f(x0, P, Q) % modulo;
    ull hare = f(tortoise, P, Q) % modulo;

    while (tortoise != hare) {
        // If there is no cycle
        if (bound >= N) {
            cout << bound;
            return 0;
        }
        bound++;

        tortoise = f(tortoise, P, Q) % modulo;
        hare = f(f(hare, P, Q) % modulo, P, Q) % modulo;
    }
    /*
    # At this point the tortoise position, ν, which is also equal
    # to the distance between hare and tortoise, is divisible by
    # the period λ. So hare moving in circle one step at a time,
    # and tortoise (reset to x0) moving towards the circle, will
    # intersect at the beginning of the circle. Because the
    # distance between them is constant at 2ν, a multiple of λ,
    # they will agree as soon as the tortoise reaches index μ.
    */
    ull mu = 0;
    tortoise = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise, P, Q) % modulo;
        hare = f(hare, P, Q) % modulo;
        mu++;
    }
    /*
    # Find the length of the shortest cycle starting from x_μ
    # The hare moves one step at a time while tortoise is still.
    # lam is incremented until λ is found.
    */
    ull lam = 1;
    hare = f(tortoise, P, Q) % modulo;
    while (tortoise != hare) {
        hare = f(hare, P, Q) % modulo;
        lam++;
    }

    cout << lam + mu;

    return 0;
}
