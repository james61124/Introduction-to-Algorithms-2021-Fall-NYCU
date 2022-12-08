#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long

queue<int>people;
vector<int>cal;
vector<int>map;
vector<int>policedis;

int me;
int police;
int flagg = 0;

void printvector(vector<int>a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void BFS(queue<int>&q, vector<vector<int>>& bfs) {

    int level = 1;
    vector<int>visit(bfs.size(),0);
    while (!q.empty()) {
        int times = q.size();
        int flag = 0;
        for (int k = 0; k < times; k++) {
            int i = q.front();
            q.pop();
            visit[i] = 1;
            for (int j = 0; j < bfs[i].size(); j++) {
                if (visit[bfs[i][j]] == 0) {
                    q.push(bfs[i][j]);
                    policedis[bfs[i][j]] = level;
                }
                visit[bfs[i][j]] = 1;
            }
        }
        level++;
    }
}

void BFS1(queue<int>& q, vector<vector<int>>& bfs) {

    //q.push(hide);
    int level = 1;
    vector<int>visit(bfs.size(), 0);
    while (!q.empty()) {
        int times = q.size();
        for (int k = 0; k < times; k++) {
            int i = q.front();
            q.pop();
            visit[i] = 1;
            for (int j = 0; j < bfs[i].size(); j++) {
                if (visit[bfs[i][j]] == 0) {
                    q.push(bfs[i][j]);
                    if (map[bfs[i][j]] == 1) {
                        if (policedis[bfs[i][j]] > level) {
                            flagg = 1;
                            return;
                        }
                    }
                    visit[bfs[i][j]] = 1;
                }
            }
        }
        level++;
    }
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        flagg = 0;
        vector<int>hide;
        vector<vector<int>>bfs;
        int flag = 0;
        int n, m, s;
        cin >> n >> m >> s;
        bfs.resize(n + 1);
        map.resize(n + 1);
        policedis.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            policedis[i] = 0;
        }
        for (int i = 0; i < n + 1; i++) {
            map[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int one, two;
            cin >> one >> two;
            bfs[one].push_back(two);
            bfs[two].push_back(one);
        }
        int a;
        cin >> a;
        for (int i = 0; i < a; i++) {
            int p;
            cin >> p;
            people.push(p);
        }
        int b;
        cin >> b;
        for (int i = 0; i < b; i++) {
            int h;
            cin >> h;
            map[h] = 1; //1是藏身處
        }
        BFS(people,bfs);
        queue<int>meme;
        meme.push(s);
        BFS1(meme, bfs);
        if (flagg == 1) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }

    }
}
