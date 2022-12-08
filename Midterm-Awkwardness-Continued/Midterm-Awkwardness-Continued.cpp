#include <iostream>
#include <vector>
#define int long long
using namespace std;

vector<int>preorder;
vector<int>inorder;
vector<int>inorderindex;
int pre = 0;

void tree(int begin,int end) {
    if (end<begin) {
        return;
    }
    int index=inorderindex[preorder[pre]];
    int ans = inorder[index];
    pre++;
    if (begin==end) {
        cout << inorder[begin] << " ";
        return;
    }
    int leftend = index - 1;
    int rightbegin = index + 1;
    tree(begin,leftend);
    tree(rightbegin,end);
    cout << ans << " ";
    
    return;
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    
    inorderindex.resize(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        preorder.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        inorder.push_back(a);
        inorderindex[a] = i;
    }

    tree(0,n-1);

}