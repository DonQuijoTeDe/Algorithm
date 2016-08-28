#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

#define INF 1e9

using namespace std;

struct Point {
    double x, y;
};

bool CmpX(Point, Point);
bool CmpY(Point, Point);
double closestPair(int, int);
double distance(Point, Point);

vector<Point> p;

int main() {
    int N;
    double tmp_x, tmp_y;

    while (cin >> N && N) {
        p.clear();
        p.reserve(N);

        for (int i = 0; i < N; i++) {
            cin >> tmp_x >> tmp_y;
            p.push_back({ tmp_x,tmp_y });
        }

        // preprocess: sorted according to x coordinates
        // O(NlogN)
        sort(p.begin(), p.end(), CmpX);

        if (closestPair(0, N - 1) >= 10000)
            cout << "INFINITY\n";
        else
            cout << fixed << setprecision(4) << closestPair(0, N - 1) << "\n";
    }

    return 0;
}

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool CmpX(Point a, Point b) {
    return a.x < b.x;
}

bool CmpY(Point a, Point b) {
    return a.y < b.y;
}

double closestPair(int left, int right) {
    if (left >= right)
        return INF;

    // Find the middle point
    int mid = (left + right) / 2;

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side and find the smaller of two distances
    double d = min(closestPair(left, mid), closestPair(mid + 1, right));

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    vector<Point> strip;
    strip.reserve(right - left);
    for (int i = mid; i >= left && p[mid].x - p[i].x < d; i--)
        strip.push_back(p[i]);
    for (int i = mid + 1; i <= right && p[i].x - p[mid].x < d; i++)
        strip.push_back(p[i]);

    // All points in strip[] are sorted according to y coordinate.
    // O(NlogN)
    sort(strip.begin(), strip.end(), CmpY);

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // O(N)

    double min_D = d;

    for (int i = 0; i < (int)strip.size() - 1; i++) {
        for (int j = i + 1; j < (int)strip.size()
            && strip[j].y - strip[i].y < d; j++) {
            min_D = min(min_D, distance(strip[i], strip[j]));
        }
    }

    return min_D;
}
