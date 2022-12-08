#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF -1000000000
#define int long long

vector<int>year;
vector<int>value;
vector<int>weight;
vector<int>table;
int n, m, limit;

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> limit;
    for (int i = 0; i <=limit; i++) {
        table.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        year.push_back(a);
    }
    sort(year.begin(), year.end());
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        auto iter = lower_bound(year.begin(),year.end(),a);
        auto iter2 = upper_bound(year.begin(), year.end(), b);
        value.push_back(iter2 - iter);
        sum = sum + (iter2 - iter);
        weight.push_back(c);
    }
    sum = n - sum;
    for (int i = 1; i <= m; i++) {
        for (int j = limit ; j >= 0; j--) {
            if (j - weight[i-1] >= 0) {
                table[j] = max(table[j], table[j - weight[i-1]] + value[i-1]);
            }
        }
    }
    int max = 0;
    for (int i = 0; i <= limit; i++) {
        if (table[i] > max) max = table[i];
    }
    cout << max+sum << '\n';

}