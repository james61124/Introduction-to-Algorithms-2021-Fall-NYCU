#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
#define int long long
int m = 1000000007;



int Mode(int a, int b, int m)

{
    int sum = 1;
    a = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
        {   
            sum=(sum*a)%m;
            b--;
        }
        b /= 2;             
        a=(a*a)%m;
    }
    return sum;
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    int a, b;
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++) {
        int time;
        cin >> time;
        if (time == 1) cout << "1" << '\n';
        else {
            int ans = Mode(a, time - 1, m) % m + (b % m * (Mode(a, time - 1, m) % m - 1) / (a - 1) % m) % m;
            if (ans < 0) ans = ans + m;
            ans = ans % m;
            cout << ans << '\n';
        }

    }


}