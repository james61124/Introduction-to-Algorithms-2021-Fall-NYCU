#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;



int rootfast(int a,vector<int>&bossfast) {
    if (bossfast[a] != a) {
        bossfast[a] = rootfast(bossfast[a], bossfast);
        return bossfast[a];
    }
    else {
        return a;
    }
}

int fastmst(int n,vector<pair<int,int>>fast,vector<int>&bossfast) {
    int ans = 0;
    for (int i = 0; i < fast.size() && ans < n - 1; i++) {
        int node1, node2;
        node1 = rootfast(fast[i].first,bossfast);
        node2 = rootfast(fast[i].second,bossfast);
        if (node1 != node2) {
            bossfast[node2] = node1;
            ans++;
        }
    }
    return ans;


}

int rootslow(int a,vector<int>&bossslow) {
    if (bossslow[a] != a) {
        bossslow[a] = rootslow(bossslow[a],bossslow);
        return bossslow[a];
    }
    else {
        return a;
    }
}

int slowmst(int n,vector<pair<int,int>>&slow,vector<int>bossslow) {
    int ans = 0;
    for (int i = 0; i < slow.size() && ans < n - 1; i++) {
        int node1, node2;
        node1 = rootslow(slow[i].first,bossslow);
        node2 = rootslow(slow[i].second,bossslow);
        if (node1 != node2) {
            bossslow[node2] = node1;
            ans++;
        }
    }
    return ans;

}

int rootall(int a,vector<int>&bossall) {
    if (bossall[a] != a) {
        bossall[a] = rootall(bossall[a],bossall);
        return bossall[a];
    }
    else {
        return a;
    }
}

int allmst(int n, vector<pair<int, int>>&all, vector<int>bossall) {
    int ans = 0;
    for (int i = 0; i < all.size() && ans < n - 1; i++) {
        int node1, node2;
        node1 = rootall(all[i].first, bossall);
        node2 = rootall(all[i].second, bossall);
        if (node1 != node2) {
            bossall[node2] = node1;
            ans++;
        }
    }
    return ans;

}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    int t;
    cin >> t;
    for (int l = 0; l < t; l++) {
        vector<pair<int, int>>fast;
        vector<pair<int, int>>slow;
        vector<pair<int, int>>all;
        
        int  m, k, f, s;

        cin >> n >> m >> k >> f >> s;
        vector<int>bossfast(n);
        vector<int>bossslow(n);
        vector<int>bossall(n);
        for (int j = 0; j < n; j++) {
            bossfast[j] = j;
        }
        for (int j = 0; j < n; j++) {
            bossslow[j] = j;
        }
        for (int j = 0; j < n; j++) {
            bossall[j] = j;
        }
        for (int j = 0; j < m; j++) {
            int one, two;
            char c;
            cin >> one >> two >> c;
            if (c == 'F') {
                fast.push_back(make_pair(one, two));
                all.push_back(make_pair(one, two));
            }
            else {
                slow.push_back(make_pair(one, two));
                all.push_back(make_pair(one, two));
            }
        }
        if (allmst(n,all,bossall) != n-1) {
            cout << "No" << '\n';
            continue;
        }
        int x1 = fastmst(n,fast,bossfast);
        int y1 = slowmst(n,slow,bossslow);
        int x2 = (n - 1) - y1;
        int y2 = (n - 1) - x1;
        int flag = 0;
        if (x1 + y2 < (n - 1) || y1 + x2 < (n - 1)) {
            flag = 0;
        }
        else {
            for (int i = x2; i <= x1; i++) {
                if ((n - 1 - i) >= y2 && (n - 1 - i) <= y1) {
                    if (i * f + (n - 1 - i) * s == k) {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 1) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }
    

}