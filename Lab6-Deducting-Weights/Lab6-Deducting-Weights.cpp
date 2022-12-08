#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define int long long
using namespace std;

struct edge {
    int one;
    int two;
    int weight;
};

void printtable(vector<vector<pair<int, int>>>& table) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            cout << "( " << table[i][j].first << " , " << table[i][j].second << ")";
        }
        cout << endl;
    }
    cout << endl;
}

void printvector(vector<int>vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    cout << endl;
}

void printans(vector<pair<int, int>>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << "( " << ans[i].first << " , " << ans[i].second << ")";
    }
    cout << endl;
}

vector<int>dijkstra(vector<vector<pair<int, int>>>& table, int number) {

    vector<int>path;
    vector<int>visit;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >q;
    path.resize(table.size());
    visit.resize(table.size());
    for (int i = 0; i < table.size(); i++) {
        path[i] = 1000000000000000000;
        visit[i] = 0;
    }
    path[number] = 0;
    q.push(make_pair(0, number));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (visit[x]) continue;
        visit[x] = 1;
        for (int j = 0; j < table[x].size(); j++) {
            if (path[table[x][j].first] > path[x] + table[x][j].second) {
                path[table[x][j].first] = path[x] + table[x][j].second;
                q.push(make_pair(path[table[x][j].first], table[x][j].first));
            }
        }
    }
    return path;

}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    vector<struct edge>ans;
    vector<vector<pair<int, int>>>table1;
    vector<vector<pair<int, int>>>table2;
    vector<int>path1;
    vector<int>path2;
    int shortest = 0;
    int n, m;
    cin >> n >> m;
    ans.resize(m);
    table1.resize(n + 1);
    table2.resize(n + 1);
    path1.resize(n + 1);
    path2.resize(n + 1);
    for (int i = 0; i < n + 1; i++) {
        path1[i] = 0;
        path2[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int one, two, weight;
        cin >> one >> two >> weight;
        table1[one].push_back(make_pair(two, weight));
        table2[two].push_back(make_pair(one, weight));
        struct edge e;
        e.one = one;
        e.two = two;
        e.weight = weight;
        ans[i] = e;
    }
    path1 = dijkstra(table1, 1);
    path2 = dijkstra(table2, n);
    shortest = path1[n];
    for (int i = 0; i < ans.size(); i++) {
        int need = shortest - (path2[ans[i].two] + path1[ans[i].one]);
        if (need <= ans[i].weight && need >= 0) {
            cout << ans[i].weight - need << '\n';
        }
        else {
            cout << "-1" << '\n';
        }
    }

}