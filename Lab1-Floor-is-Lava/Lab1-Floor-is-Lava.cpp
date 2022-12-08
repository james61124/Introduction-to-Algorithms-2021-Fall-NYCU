#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i] >> p[i];
    }
    double L = 0.0;
    double R = 1000000000.0;
    while (fabs(R - L) > 0.000001) {
        double mid = (L + R) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            long long temp = (int)(c[i] / mid) - p[i];
            if (temp <= 0)
                continue;
            sum += temp;
        }
        if (K <= sum) L = mid;
        else R = mid;
    }

    cout << setprecision(10) << (L + R) / 2;

    return 0;
}