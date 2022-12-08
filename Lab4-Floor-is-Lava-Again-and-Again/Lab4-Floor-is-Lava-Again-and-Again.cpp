#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define N 10000000000000000

vector<vector<int>>table;
vector<vector<int>>ans;
int n, t;

int pro(int first,int second) {
    if (ans[first][second] != N) {
        return ans[first][second];
    }
    else {
        int max = -N;
        if (second - 1 >= 0) {
            int tmp = pro(first + 1,second - 1);
            if (tmp > max) {
                max = tmp;
            }
        }
        if (second + 1 < n) {
            int tmp = pro(first + 1,second + 1);
            if (tmp > max) {
                max = tmp;
            }
        }
        int tmp = pro(first + 1,second);
        if (tmp > max) {
            max = tmp;
        }
        ans[first][second] = table[first][second] + max;
        return ans[first][second];
    }
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < t; i++) {
        vector<int>tmp;
        for (int j = 0; j < n; j++) {
            tmp.push_back(N);
        }
        ans.push_back(tmp);
    }
    for (int i = 0; i < t; i++) {
        vector<int>tmp;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            tmp.push_back(a);
            if (i == t-1) ans[i][j] = a;
        }
        table.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        cout << pro(0, i) << " ";
    }
}