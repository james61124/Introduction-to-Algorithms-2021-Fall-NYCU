#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
vector<vector<pair<int, int>>>table;

int min_number(int a, int b) {
    if (a >= b) {
        return b;
    }
    else {
        return a;
    }
}

int BFS() {

    queue<int>q;
    vector<int>visit(table.size(), 0);
    vector<int>path(table.size(), 0);
    vector<int>flow(table.size(), 0);
    visit[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        visit[i] = 1;
        if (i == table.size() - 1) {
            int current = flow[i];
            int temp = i;
            while (temp != 0) {
                int boss = path[temp];
                int flag = 0;
                for (int k = 0; k < table[boss].size(); k++) {
                    if (table[boss][k].first == temp) {
                        table[boss][k].second = table[boss][k].second - current;
                        break;
                    }
                }
                for (int k = 0; k < table[temp].size(); k++) {
                    if (table[temp][k].first == boss) {
                        flag = 1;
                        table[temp][k].second = table[temp][k].second + current;
                        break;
                    }
                }
                if (flag == 0) {
                    table[temp].push_back(make_pair(boss, current));
                }
                temp = boss;
            }
            return current;
        }
        for (int j = 0; j < table[i].size(); j++) {
            if (visit[table[i][j].first] == 0 && table[i][j].second > 0) {
                if (i == 0) {
                    q.push(table[i][j].first);
                    visit[table[i][j].first] = 1;
                    path[table[i][j].first] = i;
                    flow[table[i][j].first] = table[i][j].second;
                    continue;
                }
                q.push(table[i][j].first);
                visit[table[i][j].first] = 1;
                path[table[i][j].first] = i;
                flow[table[i][j].first] = min_number(table[i][j].second, flow[i]);
            }
        }
    }
    return 0;
}

void printtable(vector<vector<pair<int, int>>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << "(" << vec[i][j].first << " , " << vec[i][j].second << ")" << " ";
        }
        cout << endl;
    }
    cout << endl;
}

signed main()
{
    
    int n;
    cin >> n;
    table.resize(n+2);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        table[0].push_back(make_pair(i, a));
    }
    
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        table[i].push_back(make_pair(n+1, a));
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int one, two, weight;
        cin >> one >> two >> weight;
        table[one].push_back(make_pair(two, weight));
        table[two].push_back(make_pair(one, weight));
    }
    while (BFS() != 0) {

    }
    int sum = 0;
    for (int i = 0; i < table[n+1].size(); i++) {
        if (table[n + 1][i].second > 0) {
            sum = sum + table[n + 1][i].second;
        }
    }
    cout << sum << '\n';
}