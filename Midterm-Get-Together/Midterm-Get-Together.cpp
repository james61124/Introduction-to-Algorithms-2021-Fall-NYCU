#include <iostream>
#include <map>
#include <cmath>
#include <iomanip> 
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<double, double>>road(n);
    for (int i = 0; i < n; i++) {
            double a, b;
            cin >> road[i].first >> road[i].second;
    }
    double left, right, middle;
    left = 0;
    right = 1000000000;
    middle = (left + right) / 2;
    while (abs(right - left) > 0.000001) {
        double max = road[0].first + middle * road[0].second;
        double min= road[0].first - middle * road[0].second;
        int flag = 1;
        for (int i = 1; i < n; i++) {
            double tmpmax= road[i].first + middle * road[i].second;
            double tmpmin = road[i].first - middle * road[i].second;
            if (tmpmin > max || tmpmax<min) {
                flag = 0;
                break;
            }
            if (tmpmin > min)min = tmpmin;
            if (tmpmax < max)max = tmpmax;
        }
        if (flag == 0) {
            left = middle;
            middle = (left + right) / 2;
        }
        else {
            right = middle;
            middle = (left + right) / 2;
        }
    }
    cout << fixed << setprecision(10) << middle << '\n';
    

}