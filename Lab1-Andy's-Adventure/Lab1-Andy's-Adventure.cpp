#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#define int long long

using namespace std;

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, sum;
    cin >> n >> sum;
    map<int,int>mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }
    auto iter1 = mp.begin();
    for (; iter1 != mp.end();iter1++) {
        if (iter1->second == 2) {
            if (mp.count(sum - iter1->first * 2) && (sum - iter1->first * 2) > iter1->first) {
                ans++;
            }
        }
        else if (iter1->second >= 3) {
            if (iter1->first * 3 == sum) {
                ans++;
            }
            if (mp.count(sum - iter1->first * 2) && (sum - iter1->first * 2) > iter1->first) {
                ans++;
            }
        }
        iter1++;
        auto iter2 = iter1;
        iter1--;
        while (iter2 != mp.end()) {
            if (iter2->second >= 2) {
                if (iter1->first + iter2->first * 2==sum) {
                    ans++;
                }
            }
            if (mp.count(sum - iter1->first - iter2->first) && (sum - iter1->first - iter2->first) > iter2->first) {
                ans++;
            }
            iter2++;
        }
    }
    if (ans == 0) {
        cout << "FeiDooDoo_Zuo_Wei_Men";
    }
    else {
        cout << ans;
    }
    
    
}