#include <iostream>
#include <vector>
#define int long long
#define m 1000000007
using namespace std;

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    pair<int, int>number;
    vector<int>sum;
    sum.push_back(0);
    sum.push_back(0);
    number = make_pair(0, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (a >= sum.size()) {
            int temp;
            temp = sum.size() - 1;
            number.second = (sum[temp-1]+number.first+1)%m;
            number.first = sum[temp-1]+1;
            sum.push_back((number.second + number.first + sum[temp])%m);
        }
        cout << (sum[a] * 4) % m + 1 << '\n';
    }
}