#include <iostream> 
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <iomanip>

//#define double long double
//#define int long long
using namespace std;

signed main()
{
    

    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<string>>ans;
    vector<pair<int, string>>vec;
    multiset<pair<int,string>> s;
    map<string, int>mp;
    map<string, int>::iterator itermp;
    map<string, int>mp2;
    map<string, vector<string>>mp3;
    for (int i = 0; i <= n; i++) {
        string str;
        getline(cin, str);
        string tmp;
        stringstream input(str);
        vector<string>temp;
        while (input >> tmp) {
            mp[tmp]++;
            temp.push_back(tmp);
        }
        ans.push_back(temp);
    }
    int mother = ceil(log2(mp.size()));
    for (itermp = mp.begin(); itermp != mp.end();itermp++) {
        pair<int,string>tmp;
        tmp.first = itermp->second;
        tmp.second = itermp->first;
        s.insert(tmp);
    }
    while (s.size() > 1) {
        multiset<pair<int, string>>::iterator itermultiset1=s.begin();
        itermultiset1++;
        multiset<pair<int, string>>::iterator itermultiset2 = itermultiset1;
        itermultiset1--;
        set<string>temp;
        temp.insert(itermultiset1->second);
        temp.insert(itermultiset2->second);
        set<string>::iterator iter = temp.begin();
        if (*iter == itermultiset1->second) {
            pair<int, string>tmp;
            tmp.first = itermultiset1->first + itermultiset2->first;
            tmp.second = itermultiset1->second;
            if (mp3[itermultiset1->second].size() == 0) {
                mp3[itermultiset1->second].push_back(itermultiset1->second);
            }
            if (mp3[itermultiset2->second].size() == 0) {
                mp3[itermultiset2->second].push_back(itermultiset2->second);
            }
            mp3[itermultiset1->second].insert(mp3[itermultiset1->second].end(), mp3[itermultiset2->second].begin(), mp3[itermultiset2->second].end());
            mp3.erase(itermultiset2->second);
            for (int i = 0; i < mp3[itermultiset1->second].size(); i++) {
                mp2[mp3[itermultiset1->second][i]]++;
            }
            s.erase(itermultiset1);
            s.erase(itermultiset2);
            s.insert(tmp);
        }
        else {
            pair<int, string>tmp;
            tmp.first = itermultiset1->first + itermultiset2->first;
            tmp.second = itermultiset2->second;
            if (mp3[itermultiset1->second].size() == 0) {
                mp3[itermultiset1->second].push_back(itermultiset1->second);
            }
            if (mp3[itermultiset2->second].size() == 0) {
                mp3[itermultiset2->second].push_back(itermultiset2->second);
            }
            mp3[itermultiset2->second].insert(mp3[itermultiset2->second].end(), mp3[itermultiset1->second].begin(), mp3[itermultiset1->second].end());
            mp3.erase(itermultiset1->second);
            for (int i = 0; i < mp3[itermultiset2->second].size(); i++) {
                mp2[mp3[itermultiset2->second][i]]++;
            }
            s.erase(itermultiset1);
            s.erase(itermultiset2);
            s.insert(tmp);
        }

        
        
    }
    for (int i = 1; i <= n; i++) {
        double son = 0.0;
        for (int j = 0; j < ans[i].size(); j++) {
            son = son + mp2[ans[i][j]];
        }
        cout << fixed << setprecision(10) << son / ((double)mother * (double)ans[i].size())<<'\n';
    }

    
}