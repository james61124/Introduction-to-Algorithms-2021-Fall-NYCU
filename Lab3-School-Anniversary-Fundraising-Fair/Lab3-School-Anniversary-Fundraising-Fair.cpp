#include <iostream>
#include <map>
#include <set>


#define int long long

using namespace std;



signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    set<pair<int, int>>mp;
    int n, cost;
    cin >> n >> cost;
    int begin, ended;
    cin >> begin >> ended;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b >= begin) mp.insert(make_pair(a, b));
    }
    int ans = 0;
    int max;
    set<pair<int, int>>::iterator iter = mp.begin();
    while (!mp.empty()) {
        if (iter->second <= begin) {
            mp.erase(iter);
            iter=mp.begin();
        }
        else if (iter->first <= begin && iter->second >= ended) {
            ans++;
            begin = ended;
            break;
        }
        else if (iter->first <= begin) {
            ans++;
            max = iter->second;
            mp.erase(iter);
            iter = mp.begin();
            while (iter->first <= begin) {
                if (iter->second > max) {
                    max = iter->second;
                }
                mp.erase(iter);
                iter = mp.begin();
            }
            begin = max;
        }
        else {
            break;
        }
    }
    if (begin < ended) {
        cout << "0";
    }
    else {
        cout << ans * cost;
    }




}