#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#define int long long
#define float double

using namespace std;

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k;
    vector<float>ci;
    vector<float>ans;
    
    vector<float>mp;
    multiset<pair<float,float>>s;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ans.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        float c, p;
        cin >> c >> p;
        mp.push_back(p);
        ci.push_back(c);
        pair<float, float>temp;
        temp.first = (c / (p + 1));
        temp.second = i;
        s.insert(temp);
    }
    float sum = 0;
    for (int i = 0; i < k; i++) {
        
        multiset<pair<float, float>>::iterator iters = s.end();
        iters--;
        ans[iters->second]++;
        sum = sum + iters->first;
        pair<float, float>temp;
        temp.first = ci[iters->second] * (mp[iters->second] / ((mp[iters->second] + ans[iters->second] + 1) * (mp[iters->second] + ans[iters->second])));
        temp.second = iters->second;
        s.erase(iters);
        s.insert(temp);
            
        
    }
    cout << fixed << setprecision(6) << sum <<'\n';
}