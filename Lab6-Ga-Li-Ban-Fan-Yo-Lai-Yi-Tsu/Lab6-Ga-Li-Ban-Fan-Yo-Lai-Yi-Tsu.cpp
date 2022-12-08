#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define int long long
vector<vector<pair<int,int>>>table;

void printvector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void printvector2(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printtable(vector<vector<pair<int,int>>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size();j++) {
            cout << "(" <<vec[i][j].first<<" , "<<vec[i][j].second<<")"<< " ";
        }
        cout << endl;
    }
    cout << endl;
}

void init_vector(vector<int>& vec,int size) {
    vec.resize(size);
    for (int i = 0; i < size; i++) {
        vec[i] = 0;
    }
}

void init_vector2(vector<vector<int>>& vec, int size,int size2) {
    vec.resize(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size2; j++) {
            vec[i].push_back(0);
        }
    }
}

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
    vector<int>path(table.size(),0);
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
        for (int j = 0; j < table[i].size();j++) {
            if (visit[table[i][j].first] == 0 && table[i][j].second >0) {
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
                flow[table[i][j].first] = min_number(table[i][j].second,flow[i]);
                    
            }
        }
    }
    return 0;
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int F, N, M, C, T, K;
    cin >> F >> N >> M;
    int size_table = F + 2 * N + M + 3;
    table.resize(size_table);
    for (int i = 1; i <= F; i++) {
        int a;
        cin >> a;
        table[0].push_back(make_pair(i,a));
        
    }
    for (int i = F+1; i <= F+N; i++) {
        int a;
        cin >> a;
        table[i].push_back(make_pair(i + N,a));

    }
    for (int i = F+1+2*N; i <= F+2*N+M; i++) {
        int a;
        cin >> a;
        table[i].push_back(make_pair(F + 2 * N + M + 1,a));
    }
    cin >> C;
    for (int i = 0; i < C; i++) {
        int x,y,c;
        cin >> x>>y>>c;
        int flag = 0;
        for (int j = 0; j < table[x].size(); j++) {
            if (table[x][j].first == y + F) {
                flag = 1;
                table[x][j].second = table[x][j].second + c;
                break;
            }
        }
        if (flag == 0) table[x].push_back(make_pair(y + F, c));
    }
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        int flag = 0;
        for (int j = 0; j < table[x + F + N].size(); j++) {
            if (table[x + F + N][j].first == y + F + 2*N ) {
                flag = 1;
                table[x + F + N][j].second = table[x + F + N][j].second + c;
                break;
            }

        }
        if(flag==0) table[x + F + N].push_back(make_pair(y + F + 2 * N,c));
    }
    cin >> K;
    table[size_table - 2].push_back(make_pair(size_table-1,K));
    
    while (BFS() != 0) {

    }
    int sum = table[F + 2 * N + M + 2][0].second;
    cout << sum << '\n';
}