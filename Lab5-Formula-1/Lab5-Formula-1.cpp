#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#define mm 1000000007
#define int long long
using namespace std;


vector<struct edge>table;
vector<int>boss;
vector<set<int>>road;//record his neighbor
vector<int>subnet;
map<pair<int,int>,int>w;

struct edge{
    int weight;
    int left;
    int right;
};

bool compare(edge a,edge b){
    if(a.weight==b.weight){
        if(a.left==b.left){
                return (a.right<=b.right);
        }else{
            return a.left<b.left;
        }
    }else{
        return a.weight<b.weight;
    }
}

int maxnum(int a,int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}

int minnum(int a,int b){
    if(a>=b){
        return b;
    }else{
        return a;
    }
}

int root(int a){
    if(boss[a]!=a){
        boss[a]=root(boss[a]);
        return boss[a];
    }else{
        return a;
    }
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    int istree=0;
    int ans=0;
    int ansleft=0;
    cin>>n>>m;
    boss.resize(n+1);
    road.resize(n+1);
    subnet.resize(n+1);
    for(int i=0;i<n+1;i++){
        boss[i]=i;
    }
    for(int i=0;i<n+1;i++){
        subnet[i]=1;
    }
    for(int i=0;i<m;i++){
        int a,b,c;//b node c distance
        struct edge e;
        cin>>a>>b>>c;
        e.left=minnum(a,b);
        e.right=maxnum(a,b);
        e.weight=c;
        table.push_back(e);
    }
    sort(table.begin(),table.end(),compare);
    for(int i=0;i<table.size() && istree<n-1;i++){
        if(root(table[i].left)==root(table[i].right)){
            continue;
        }
        if(root(table[i].left)==table[i].left && root(table[i].right)==table[i].right){
            boss[table[i].right]=table[i].left;
        }else if(root(table[i].left)==table[i].left && root(table[i].right)!=table[i].right){
            boss[root(table[i].right)]=table[i].left;
        }else if(root(table[i].left)!=table[i].left && root(table[i].right)==table[i].right){
            boss[table[i].right]=root(table[i].left);
        }else{
            boss[root(table[i].right)]=root(table[i].left);
        }
        road[table[i].left].insert(table[i].right);
        road[table[i].right].insert(table[i].left);
        w[make_pair(table[i].left,table[i].right)]=table[i].weight;
        ansleft=ansleft+table[i].weight*2%mm;
        ansleft=ansleft%mm;
        istree++;
    }
    ansleft=ansleft%mm;
    if(istree!=n-1){
        cout<<"-1"<<'\n';
    }else{
        int index=1;
        cout<<ansleft<<" ";
        while(index<n){
            for(int i=1;i<=n;i++){
                if(road[i].size()==1){
                    int temp=*(road[i].begin());
                    subnet[temp]=subnet[temp]+subnet[i];
                    road[i].erase(temp);
                    road[temp].erase(i);
                    pair<int,int>tmp;
                    tmp.first=minnum(i,temp);
                    tmp.second=maxnum(i,temp);
                    int temp1=subnet[i]*(n-subnet[i]);
                    temp1=temp1%mm;
                    ans=ans+temp1*2*(w[tmp])%mm;
                    ans=ans%mm;
                    index++;
                }
                if(index==n) break;
            }
        }
        ans=ans%mm;
        cout<<ans<<'\n';

    }

}