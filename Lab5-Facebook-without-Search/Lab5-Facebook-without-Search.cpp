#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

vector<int>table;
set<pair<int,int>>edge;
vector<int>state;
vector<pair<char,pair<int,int>>>question;
vector<int>ans;

int maxnum(int a,int b){
    if(a>b) return a;
    else return b;
}

int minnum(int a,int b){
    if(a>b) return b;
    else return a;
}

int root(int a){
    if(table[a]==a){
        return a;
    }else{
        int temp=root(table[a]);
        table[a]=temp;
        return temp;
    }
}

bool same(int a,int b){
    if(root(a)==root(b)){
        return true;
    }else{
        return false;
    }
}

void print(){
    for(int i=0;i<table.size();i++){
        cout<<table[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        table.push_back(i);
    }
    for(int i=0;i<m;i++){
        state.push_back(1);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge.insert(make_pair(minnum(a,b),maxnum(a,b)));
    }
    for(int i=0;i<q;i++){
        char c;
        cin>>c;
        int a,b;
        cin>>a>>b;
        question.push_back(make_pair(c,make_pair(minnum(a,b),maxnum(a,b))));
        if(c=='U'){
            auto first=edge.begin();
            auto it=edge.find(make_pair(minnum(a,b),maxnum(a,b)));
            edge.erase(it);
        }
    }

    for(auto iter=edge.begin();iter!=edge.end();iter++){
        int root1=root(iter->first);
        int root2=root(iter->second);
        if(root1==iter->first && root2==iter->second){
            table[iter->second]=iter->first;
        }else if(root1!=iter->first && root2==iter->second){
            table[iter->second]=root1;
        }else if(root1==iter->first && root2!=iter->second){
            table[iter->first]=root2;
        }else if(root1!=iter->first && root2!=iter->second){
            table[root1]=root2;
        }
    }
    
    for(int i=q-1;i>=0;i--){
        if(question[i].first=='A'){
            if(same(question[i].second.first,question[i].second.second)==true){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }else{
            int question1=root(question[i].second.first);
            int question2=root(question[i].second.second);
            if(question1==question[i].second.first && question2==question[i].second.second){
                table[question[i].second.second]=question[i].second.first;
            }else if(question1!=question[i].second.first && question2==question[i].second.second){
                table[question[i].second.second]=question1;
            }else if(question1==question[i].second.first && question2!=question[i].second.second){
                table[question[i].second.first]=question2;
            }else if(question1!=question[i].second.first && question2!=question[i].second.second){
                table[question1]=question2;
            }
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        if(ans[i]==1){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }

}