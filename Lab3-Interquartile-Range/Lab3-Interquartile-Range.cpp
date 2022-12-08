#include <iostream>
#include <map>
#include <set>
#include <iomanip>
#include <iterator>

using namespace std;



signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int size = 1;
    multiset<double> s;
    multiset<double>::iterator iter1;
    multiset<double>::iterator iter2;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        s.insert(n);
        if (size == 1) {
            cout << "0" << '\n';
        }
        else if (size == 2) {
            multiset<double>::iterator it;
            multiset<double>::iterator it2;
            it = s.begin();
            double q1 = *it;
            it++;
            double q2 = *it;
            double ans = q2 - q1;
            if (int(ans) == ans) {
                cout << int(ans) << '\n';
            }
            else {
                cout << fixed << setprecision(1) << ans << '\n';
            }
        }
        else if (size == 3) {
            iter1 = s.begin();
            iter1++;
            iter1++;
            iter2 = iter1;
            iter1--;
            iter1--;
            double ans = *iter2 - *iter1;
            if (int(ans) == ans) {
                cout << int(ans) << '\n';
            }
            else {
                cout << fixed << setprecision(1) << ans << '\n';
            }
        }
        else {
            if (size % 4 == 0) {
                if (n < *iter1) {
                    iter2--;
                }
                else if (*iter1 <= n && n < *iter2) {
                    iter1++;
                    iter2--;
                }
                else {
                    iter1++;
                }
                iter1--;
                multiset<double>::iterator it = iter1;
                iter1++;
                iter2++;
                multiset<double>::iterator it2 = iter2;
                iter2--;
                double q1 = (*it + *iter1) / 2;
                double q2 = (*it2 + *iter2) / 2;
                double ans = q2 - q1;
                if (int(ans) == ans) {
                    cout << int(ans) << '\n';
                }
                else {
                    cout << fixed << setprecision(1) << ans << '\n';
                }
            }
            else if (size % 4 == 1) {
                if (n < *iter1) {
                    iter1--;
                }
                else if (*iter1 <= n && n < *iter2) {

                }
                else {
                    iter2++;
                }
                iter1--;
                multiset<double>::iterator it = iter1;
                iter1++;
                iter2++;
                multiset<double>::iterator it2 = iter2;
                iter2--;
                double q1 = (*it + *iter1) / 2;
                double q2 = (*it2 + *iter2) / 2;
                double ans = q2 - q1;
                if (int(ans) == ans) {
                    cout << int(ans) << '\n';
                }
                else {
                    cout << fixed << setprecision(1) << ans << '\n';
                }
            }
            else if (size % 4 == 2) {
                if (n < *iter1) {
                    iter1--;
                }
                else if (*iter1 <= n && n < *iter2) {

                }
                else {
                    iter2++;
                }
                double q1 = *iter1;
                double q2 = *iter2;
                double ans = q2 - q1;
                if (int(ans) == ans) {
                    cout << int(ans) << '\n';
                }
                else {
                    cout << fixed << setprecision(1) << ans << '\n';
                }
            }
            else if (size % 4 == 3) {
                if (n < *iter1) {
                    iter1--;
                }
                else if (*iter1 <= n && n < *iter2) {

                }
                else {
                    iter2++;
                }
                double q1 = *iter1;
                double q2 = *iter2;
                double ans = q2 - q1;
                if (int(ans) == ans) {
                    cout << int(ans) << '\n';
                }
                else {
                    cout << fixed << setprecision(1) << ans << '\n';
                }
            }
        }

        size++;
    }
}