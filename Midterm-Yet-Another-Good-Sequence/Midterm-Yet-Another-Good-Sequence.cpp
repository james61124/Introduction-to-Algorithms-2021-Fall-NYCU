#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define MIN -1000000000
int pro(vector<int>vec) {
    if (vec.size() <= 2) {
        return 0;
    }
    int pivot = 0;
    if (vec.size() % 2 == 0) {
        pivot = vec.size() / 2;
    }
    else {
        pivot = (int)(vec.size() / 2) + 1;
    }
    vector<int>left(vec.begin(), vec.begin() + pivot);
    vector<int>right(vec.begin() + pivot, vec.end());
    int maxleft = MIN, maxright = MIN;
    int a = 0, b = 0;
    for (int i = 0; i < left.size(); i++) {
        if (maxleft < left[i]) {
            maxleft = left[i];
        }
    }
    for (int i = 0; i < left.size(); i++) {
        a = a + (maxleft - left[i]);
    }
    a = a + pro(right);
    for (int i = 0; i < right.size(); i++) {
        if (maxright < right[i]) {
            maxright = right[i];
        }
    }
    for (int i = 0; i < right.size(); i++) {
        b = b + (maxright - right[i]);
    }
    b = b + pro(left);
    if (a >= b) {
        return b;
    }
    else {
        return a;
    }

    

    
    
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int>vec;
    for (int i = 0; i < n ; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    int ans=pro(vec);
    cout << ans << '\n';

}