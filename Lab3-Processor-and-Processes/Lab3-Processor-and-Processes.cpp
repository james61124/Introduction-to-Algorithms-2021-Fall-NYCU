#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#define infinity 600000
#define int long long

using namespace std;

signed main()
{


    cin.tie(0);
    cin.sync_with_stdio(0);
    int ans = 0;
    int n, c, q;
    cin >> n >> c >> q;
    vector<int>vec;
    vector<pair<vector<int>, bool>>order;//process,
    order.resize(n + 1);
    multiset<pair<int, int>>max;//process下一個index,process
    for (int i = 0; i < q; i++) {
        int process;
        cin >> process;
        vec.push_back(process);
        order[process].first.push_back(i);
        order[process].second = false;
    }
    for (int i = 0; i < vec.size(); i++) {
        if (ans < c) {
            if (order[vec[i]].second == true) {
                max.erase(make_pair(order[vec[i]].first.front(), vec[i]));
                order[vec[i]].first.erase(order[vec[i]].first.begin());
                if (order[vec[i]].first.size() == 0) {
                    max.insert(make_pair(infinity, vec[i]));
                }
                else {
                    max.insert(make_pair(order[vec[i]].first.front(), vec[i]));
                }
            }
            else {
                order[vec[i]].first.erase(order[vec[i]].first.begin());
                if (order[vec[i]].first.size() == 0) {
                    max.insert(make_pair(infinity, vec[i]));
                }
                else {
                    max.insert(make_pair(order[vec[i]].first.front(), vec[i]));
                }
                order[vec[i]].second = true;
                ans++;
            }
        }
        else {
            if (order[vec[i]].second == true) {
                set<pair<int, int>>::iterator iter;
                for (iter = max.begin(); iter != max.end(); iter++) {
                    if (iter->second == vec[i]) break;
                }
                max.erase(iter);

                order[vec[i]].first.erase(order[vec[i]].first.begin());
                if (order[vec[i]].first.size() == 0) {
                    max.insert(make_pair(infinity, vec[i]));
                }
                else {
                    max.insert(make_pair(order[vec[i]].first.front(), vec[i]));
                }
            }
            else {
                set<pair<int, int>>::iterator iter;
                iter = max.end();
                iter--;
                order[iter->second].second = false;
                max.erase(iter);
                order[vec[i]].first.erase(order[vec[i]].first.begin());
                if (order[vec[i]].first.size() == 0) {
                    max.insert(make_pair(infinity, vec[i]));
                }
                else {
                    max.insert(make_pair(order[vec[i]].first.front(), vec[i]));
                }
                order[vec[i]].second = true;
                ans++;
            }
        }
    }
    cout << ans << '\n';


}