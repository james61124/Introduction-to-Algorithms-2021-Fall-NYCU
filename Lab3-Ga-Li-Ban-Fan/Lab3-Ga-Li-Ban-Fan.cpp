#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define int long long

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int>cointable;
    cointable.push_back(1000);
    cointable.push_back(500);
    cointable.push_back(100);
    cointable.push_back(50);
    cointable.push_back(10);
    cointable.push_back(5);
    cointable.push_back(1);
    for (int i = 0; i < n; i++) {
        vector<int>needpay;//要找的錢
        vector<int>::iterator iter=needpay.begin();
        map<int,int>coin;
        coin[1000] = 0;
        coin[500] = 0;
        coin[100] = 0;
        coin[50] = 0;
        coin[10] = 0;
        coin[5] = 0;
        coin[1] = 0;
        int people;
        cin >> people;
        int isfail = 0;
        for (int j = 0; j < people; j++) {
            int price;
            cin >> price;
            int sum = 0;
            for (int k = 0; k < 7; k++) {
                int coinnumber;
                cin >> coinnumber;
                sum = sum + coinnumber * cointable[k];
                coin[cointable[k]] = coin[cointable[k]] + coinnumber;
            }
            if (sum > price) {
                needpay.push_back(sum - price);
            }
        }
        for (int j = 0; j < needpay.size(); j++) {
            int index = 0;
            for (int k = 0; k < 7; k++) {
                if (cointable[k] <= needpay[j]) {
                    index = k;
                    break;
                }
            }
            while (1) {
                while (coin[cointable[index]] > 0 && needpay[j] >= cointable[index]) {
                    needpay[j] = needpay[j] - (cointable[index]);
                    coin[cointable[index]]--;
                }
                index++;
                if (index==7) {
                    if (needpay[j] != 0) {
                        isfail = 1;
                    }
                    break;
                }
            }
            if (isfail == 1) {
                break;
            }
        }

        if (isfail == 1) {
            cout << "No" << '\n';
        }
        else {
            cout << "Yes" << '\n';
        }

    }
}