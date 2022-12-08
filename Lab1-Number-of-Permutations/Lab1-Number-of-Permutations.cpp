#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    long long int n, a;
    cin >> n;
    multiset<long long int>s;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }
    long long int ans = 1,t = 0, m = 1000000007;
    for (multiset<long long int>::iterator iter = s.begin(); iter != s.end(); iter++) {
        if(*iter > n)
            ans = (ans * (n - t)) % m;
        else ans = (ans * (*iter - t)) % m;
        t++;
    }
    /*for (multiset<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }*/
    cout << ans << '\n';
}