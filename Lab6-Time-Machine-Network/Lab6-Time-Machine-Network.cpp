#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
#define int long long

vector<vector<pair<int, int>>>table;
vector<int>path;
vector<int>check;
int n, m;

void printtable() {
    for (int i = 0; i < table.size(); i++) {
        for (auto iter = table[i].begin(); iter != table[i].end(); iter++) {
            cout << "(" << iter->first << " , " << iter->second << ")" << endl;
        }
        cout << endl;
    }
    cout << endl;
}
void printvector(vector<int>vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

bool isgood(int number) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (auto iter = table[i].begin(); iter != table[i].end(); iter++) {
                if (iter->first + path[i] < path[iter->second] && iter->first > number) {
                    path[iter->second] = iter->first + path[i];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto iter = table[i].begin(); iter != table[i].end(); iter++) {
            if (iter->first + path[i] < path[iter->second] && iter->first > number) {
                path[iter->second] = iter->first + path[i];
                return false;//有負環
            }
        }
    }
    return true;//沒負環
}

void initpath() {
    for (int i = 0; i < n; i++) {
        path[i] = 10000000000000;
    }
    path[0] = 0;
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int flag = 0;
    int ans = 0;
    cin >> n >> m;
    table.resize(n);
    path.resize(n);
    initpath();
    for (int i = 0; i < m; i++) {
        int one, two, weight;
        cin >> one >> two >> weight;
        table[one].push_back(make_pair(weight,two));
        if (weight < 0) {
            check.push_back(weight);
        }
    }
    sort(check.begin(), check.end());
    if (check.size() != 0) {
        if (isgood(check[0] - 1)) {
            flag = 1;
        }
    }
    else {
        flag = 1;
    }
    
    int left, middle, right, leftmiddle, rightmiddle;
    left = 0;
    right = check.size() - 1;
    middle = (left + right) / 2;
    int cycle=0,nocycle= check.size() - 1;
    if (flag != 1) {
        while (left <= right) {
            initpath();
            bool temp = isgood(check[middle]);
            if (!temp) {//有負環 表示要往右走
                cycle = middle;
                left = middle + 1;
                middle = (left + right) / 2;
                
            }
            else {//沒有負環 表示要往左走
                nocycle = middle;
                right = middle - 1;
                middle = (left + right) / 2;
            }
        }
    }
    if (flag == 1) {
        cout << "GO AHEAD" << '\n';
    }
    else {
        if (check[nocycle] == check[check.size() - 1]) {
            cout << "NO WAY BACK" << '\n';
        }
        else if (nocycle == check.size() - 1 || cycle == check.size() - 2 ) {
            cout << "NO WAY BACK" << '\n';
        }
        else {
            if(nocycle==0) cout << check[0] << '\n';
            else {
                cout << check[nocycle] << '\n';
            }
            
        }
    }

}