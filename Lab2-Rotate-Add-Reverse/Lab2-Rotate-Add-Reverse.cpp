#include <iostream>
#include <vector>
#include  <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>>ans;

void seq(int level) {
    vector<int>temp;
    if (level == 0) {
        temp.push_back(1);
        ans.push_back(temp);
        level++;
        seq(level);
    }
    if (level == 19) return;
    for (int i = 0; i < ans[level-1].size(); i++) {
        temp.push_back(ans[level-1][i]);
    }
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ans[level-1].size(); i++) {
        temp.push_back(ans[level-1][i]+pow(2,level-1));
    }
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    rotate(temp.begin(), temp.begin() + temp.size() - pow(2, level - 1), temp.end());
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    ans.push_back(temp);
    

}

int main()
{
    int n;
    cin >> n;
    vector<int>temp1;
    temp1.push_back(1);
    ans.push_back(temp1);
    for (int level = 1; level < 19; level++) {
        vector<int>temp;
        for (int i = 0; i < ans[level - 1].size(); i++) {
            temp.push_back(ans[level - 1][i]);
        }
        reverse(temp.begin(), temp.end());

        for (int i = 0; i < ans[level - 1].size(); i++) {
            temp.push_back(ans[level - 1][i] + pow(2, level - 1));
        }


        rotate(temp.begin(), temp.begin() + temp.size() - pow(2, level - 1), temp.end());
        ans.push_back(temp);
    }
    
    for (int i = 0; i < ans[n].size(); i++) {
        cout << ans[n][i] << " ";
    }
}