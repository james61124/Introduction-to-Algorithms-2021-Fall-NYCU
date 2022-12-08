#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;


signed main() {
    vector <int> speghetti;
    speghetti.clear();
    speghetti.resize(0);
    int N, k, m;
    cin >> N >> k;
    int l;
    for (int i = 0; i < N; i++) {
        cin >> l;
        speghetti.push_back(l);
    }
    sort(speghetti.begin(), speghetti.end());
    vector <int> ::iterator bound = std::lower_bound(speghetti.begin(), speghetti.end(), 70);
    cin >> m;
    vector <pair<int, int>> unit_maxl;
    unit_maxl.resize(0);
    for (int i = 0; i < m; i++) {
        int unit, maxl;
        cin >> unit >> maxl;
        unit_maxl.push_back({ unit,maxl });
    }
    int n = unit_maxl.size();

    vector <int> ::iterator l_bound, u_bound;
    for (int i = 0; i < n; i++) {
        int count = 0;
        int limit;
        for (int j = 1; j < k; j++) {
            limit = unit_maxl[i].first * (j + 1) - 1 < unit_maxl[i].second ? unit_maxl[i].first * (j + 1) - 1 : unit_maxl[i].second;
            l_bound = std::lower_bound(speghetti.begin(), speghetti.end(), unit_maxl[i].first * j);
            u_bound = std::upper_bound(speghetti.begin(), speghetti.end(), limit);
            if (u_bound - l_bound >= 0) count = count + (u_bound - l_bound) * j;
        }
        limit = unit_maxl[i].first * k < unit_maxl[i].second ? unit_maxl[i].first * k : unit_maxl[i].second;
        l_bound = std::lower_bound(speghetti.begin(), speghetti.end(), unit_maxl[i].first * k);
        u_bound = std::upper_bound(speghetti.begin(), speghetti.end(), limit);
        if (u_bound - l_bound >= 0) count = count + (u_bound - l_bound) * k;
        cout << count << "\n";
    }

    return 0;
}