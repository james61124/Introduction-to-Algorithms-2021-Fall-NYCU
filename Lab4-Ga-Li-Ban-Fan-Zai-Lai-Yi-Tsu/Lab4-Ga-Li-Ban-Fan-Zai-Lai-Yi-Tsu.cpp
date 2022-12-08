#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define N 10000000
#define int long long

vector<int>table;
vector<int>mp;
vector<int>ans;

int pro(int coin) {
    if (coin == 0)return 0;
    if (ans[coin]!=0) {
        return ans[coin];
    }
    else {
        int min = 100000000,tmp;
        for (int i = 0; i <table.size(); i++) {
            if (table[i] <= coin) {
                tmp = pro(table[i]) + pro(coin - table[i]);
            }
            else {
                continue;
            }
            if (tmp < min) min = tmp;
        }
        ans[coin] = min;
        return min;
    }
    
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int i = 0; i <= N; i++) {
        ans.push_back(0);
    }
    int n,q;
    cin >> n;
    ans[0] = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        table.push_back(a);
        ans[a] = 1;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            sum = sum + b * table[j];
        }
        a = sum-a;
        int ans1 = pro(a);
        cout << ans1 << '\n';
    }
    

}