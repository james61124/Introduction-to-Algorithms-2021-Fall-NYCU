#include <iostream>
#include <vector>
#include <queue>

#define int long long
using namespace std;

vector<int>dijkstra(vector<vector<pair<int, int>>>& table, int number) {
    vector<int>path;
    vector<int>visit;//加鄰居進queue
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
    vector<vector<pair<int, int>>>table;
    vector<vector<int>>path;
    int n, m;
    cin >> n >> m;
    table.resize(n);
    path.resize(n);
    for (int i = 0; i < m; i++) {
        int one, two, weight;
        cin >> one >> two >> weight;
        table[one].push_back(make_pair(two, weight));
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int one, two;
        cin >> one >> two;
        if (path[one].size() == 0) {
            path[one] = dijkstra(table, one);
            if (path[one][two] == 1000000000000000000) {
                cout << "-1" << '\n';
            }
            else {
                cout << path[one][two] << '\n';
            }
        }
        else {
            if (path[one][two] == 1000000000000000000) {
                cout << "-1" << '\n';
            }
            else {
                cout << path[one][two] << '\n';
            }
        }
    }
}