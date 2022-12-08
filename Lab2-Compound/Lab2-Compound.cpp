#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>

#define int long long

using namespace std;

bool isbig(char c) {
    if ((int)c >= 65 && (int)c <= 90) return true;
    else return false;
}

bool issmall(char c) {
    if ((int)c >= 97 && (int)c <= 122) return true;
    else return false;
}

bool isnumber(char c) {
    if ((int)c >= 48 && (int)c <= 57) return true;
    else return false;
}

bool isparameter(char c) {
    if ((int)c == 41) return true;
    else return false;
}

void process(stack<char>&s ,map<string, int>& ans1,map<string, int>& ans2, int i) {
    int base = 1;
    int count = 0;
    while (!s.empty()) {
        //int init = i;
        char c1 = s.top();
        //cout << c1 << endl;
        s.pop();
        if ((int)c1 == 40) {
            return ;
        }
        else if (isnumber(c1)) {
            int num = (int)c1 - 48;
            count = count + base * num;
            base = base * 10;
        }
            
        else if (isparameter(c1)) {
            if (count == 0) {
                process(s, ans1, ans2, i);
            }
            else {
                    process(s, ans1, ans2, i*count);
                }
                count = 0;
                base = 1;
            }
            else if (issmall(c1)) {
                char c2 = s.top();
                s.pop();
                char cc[3] = { c2,c1,'\0' };
                string name(cc);
                if (count == 0) {
                    ans2[name]+=i;
                }
                else {
                    ans2[name]+=count*i;
                }
                count = 0;
                base = 1;
            }
            else if (isbig(c1)) {
                char c[2] = { c1,'\0' };
                string name(c);
                if (count == 0) {
                    ans1[name]+=i;
                }
                else {
                    ans1[name]+=i*count;
                }
                count = 0;
                base = 1;
            }
       
    }
    return;
}

signed main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    stack<char>s;
    string scin;
    cin >> scin;
    for (int i = 0; i < scin.length(); i++) {
        s.push(scin[i]);
    }

    map<string, int>ans1;
    map<string, int>ans2;    

    process(s, ans1,ans2, 1);

    cout << ans1.size() << endl;
    if (ans1.size()) {
        for (map<string, int>::iterator iter = ans1.begin(); iter != ans1.end(); iter++) {
            cout << iter->first << ":" << iter->second << endl;
        }
    }
    cout << ans2.size() << endl;
    if (ans2.size()) {
        for (map<string, int>::iterator iter = ans2.begin(); iter != ans2.end(); iter++) {
            cout << iter->first << ":" << iter->second << endl;
        }
    }
    
}