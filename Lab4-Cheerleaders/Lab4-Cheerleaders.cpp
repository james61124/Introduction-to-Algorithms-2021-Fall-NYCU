#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
vector<int>people;
vector<int>negpeople;
vector<int>check;
vector<pair<int, bool>>checkpoint;
vector<int>increase;
vector<int>reverseincrease;
vector<int>decrease;
vector<int>reversedecrease;

int binary_search(vector<int>& arr, int start, int end, int khey, int level) {
    if (level == 0) {
        if (khey > arr[end - 1]) return -1;
    }
    if (start > end) return start;
    level++;
    int mid = start + (end - start) / 2;    //直接平均可能會溢位，所以用此算法
    if (arr[mid] > khey)
        return binary_search(arr, start, mid - 1, khey, level);
    else if (arr[mid] < khey)
        return binary_search(arr, mid + 1, end, khey, level);
    else
        return mid;        //最後檢測相等是因為多數搜尋狀況不是大於要不就小於
}



void posLIS(int first, int second, vector<int>& people,vector<int>&increase) {
    vector<int>temp;
    int max = 0;
    temp.push_back(people[first]);
    increase.push_back(1);
    for (int index = first + 1; index <= second; index++) {
        if (people[index] > temp[temp.size() - 1]) {
            temp.push_back(people[index]);
            increase.push_back(temp.size());
        }
        else {
            int tempindex = binary_search(temp, 0, temp.size(), people[index], 0);
            temp[tempindex] = people[index];
            increase.push_back(tempindex + 1);
        }
    }

}

int negLIS(int first, int second, vector<int>& people) {
    vector<int>temp;
    int max = 0;
    temp.push_back(people[second]);
    for (int index = second - 1; index >= first; index--) {
        if (people[index] < people[second]) continue;
        if (people[index] > temp[temp.size() - 1]) {
            temp.push_back(people[index]);
            if (temp.size() - 1 > max)max = temp.size() - 1;
        }
        else {
            int tempindex = binary_search(temp, 0, temp.size(), people[index], 0);
            temp[tempindex] = people[index];
            if (tempindex > max)max = tempindex;
        }
    }
    return max + 1;

}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    int max = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        people.push_back(a);
        negpeople.push_back(-a);
    }
    posLIS(0, n - 1, people,increase);
    reverse(people.begin(), people.end());
    posLIS(0, n - 1, people, reverseincrease);
    
    reverse(reverseincrease.begin(),reverseincrease.end());

    posLIS(0, n - 1, negpeople, decrease);
    reverse(negpeople.begin(), negpeople.end());
    
    posLIS(0, n - 1, negpeople, reversedecrease);
    reverse(reversedecrease.begin(), reversedecrease.end());
    for (int i = 0; i < n; i++) {
        if (increase[i] + reverseincrease[i] - 1 > max)max = increase[i] + reverseincrease[i] - 1;
        if (decrease[i] + reversedecrease[i] - 1 > max)max = decrease[i] + reversedecrease[i] - 1;
    }
    cout << max << '\n';



}