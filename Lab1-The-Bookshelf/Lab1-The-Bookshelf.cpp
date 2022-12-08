#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    map<int,int>book;
    map<int, int>::iterator iter;
    for (int i = 0; i < a; i++) {
        int height;
        cin >> height;
        book.insert(pair<int, int>(height,i));
    }
    for (int i = 0; i < b; i++) {
        int flag = 0, check;
        cin >> check;
        iter = book.find(check);
        if (iter == book.end()) {
            cout << "-1" << '\n';
        }
        else {
            cout << iter->second << '\n';
        }
    }
}