#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

vector<vector<int>>graph;
vector<int>visitgraph;
vector<vector<int>>transgraph;
vector<int>initindex;
vector<int>finish;
vector<int>finishposition;
vector<int>finishindex;
vector<vector<int>>compression;
vector<int>compressiontable;
vector<int>sizecom;
vector<int>table;
vector<int>tableposition;
vector<int>visitcompression;
vector<int>child;
int sizenum;
int ans = 0;

void printvector2(vector<vector<int>>a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printvector(vector<int>a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printunordered_set(unordered_set<int>a) {
    for (auto iter = a.begin(); iter != a.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

void DFS(int index) {
    initindex[index] = 1;
        visitgraph[index] = 1;
        for (int j = 0; j < graph[index].size(); j++) {
            if (visitgraph[graph[index][j]] == 0) {
                DFS(graph[index][j]);
                finish.push_back(graph[index][j]);
                finishposition[graph[index][j]] = finish.size() - 1;
            }
        }
    return;
}

void DFS1(int index,int root) {
    finishindex[finishposition[index]] = 1;
    sizenum++;
    visitgraph[index] = 1;
    for (int j = 0; j < transgraph[index].size(); j++) {
        if (visitgraph[transgraph[index][j]] == 0) {
            compressiontable[transgraph[index][j]] = root;
            DFS1(transgraph[index][j], root);
        }
    }

}

void DFS2(int index) {
    if (child[index] != sizecom[index]) {
        return;
    }
    int maxnum = 0;
    for (int j = 0; j < compression[index].size(); j++) {
        DFS2(tableposition[compression[index][j]]);
        if (child[tableposition[compression[index][j]]] > maxnum) {
            maxnum = child[tableposition[compression[index][j]]];
        }
    }
    child[index] = child[index] + maxnum;
    if (child[index] > ans) {
        ans = child[index];
    }
    return;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    transgraph.resize(n);
    visitgraph.resize(n);
    compression.resize(n);
    initindex.resize(n);
    finishindex.resize(n);
    finishposition.resize(n);
    tableposition.resize(n);
    compressiontable.resize(n);
    for (int i = 0; i < n; i++) {
        visitgraph[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int one, two;
        cin >> one >> two;
        graph[one].push_back(two);
        transgraph[two].push_back(one);
    }
    for (int i = 0; i < n; i++) {
        initindex[i] = 0;
    }
    for (int init = 0;;) {
        while (initindex[init] == 1) {
            init++;
            if (init == n) break;
        }
        if (init < n) {
            DFS(init);
            finish.push_back(init);
            finishposition[init] = finish.size() - 1;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        visitgraph[i] = 0;
        finishindex[i] = 0;
        tableposition[i] = 0;
        compressiontable[i] = i;
    }
    for (int init = n-1;;) {
        while (finishindex[init] == 1) {
            init--;
            if (init == -1) break;
        }
        if (init >=0) {
            sizenum = 0;
            table.push_back(finish[init]);
            tableposition[finish[init]] = table.size() - 1;
            DFS1(finish[init],finish[init]);//數字
            sizecom.push_back(sizenum);
        }
        else {
            break;
        }
    }

    compression.resize(table.size());
    visitcompression.resize(table.size());
    child.resize(table.size());
    for (int i = 0; i < table.size(); i++) {
        child[i] = sizecom[i];
    }
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (compressiontable[graph[i][j]] != compressiontable[i]) {
                compression[tableposition[compressiontable[i]]].push_back(compressiontable[graph[i][j]]);
            }
        }
    }

    for (int i = 0; i < table.size(); i++) {
        DFS2(i);
    }
    cout << ans << '\n';


}