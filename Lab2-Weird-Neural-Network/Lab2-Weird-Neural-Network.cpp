#include <iostream>

using namespace std;

#define int long long 
int m = 1000000007;
struct node {
    int number;
   // node* next;
    node* one;
    node* two;
};

int Postorder(node* current) {
    if (current->one == NULL && current->two == NULL) {
        //cout << current->number << endl;
        return current->number % m;
    }
    else if (current->one != NULL && current->two == NULL) { 
        int sum = (current->number % m)*(Postorder(current->one));
        sum = sum % m;
        //cout << sum << endl;
        return sum ;
    }
    else if (current->one == NULL && current->two != NULL) {
        int sum = (current->number % m) * (Postorder(current->two));
        sum = sum % m;
        //cout << sum << endl;
        return sum ;
    }
    else   {
        //return 1;
        //cout << current->number << endl;
        int a = Postorder(current->one);
        //cout << current->number << endl;
        int b = Postorder(current->two);
        int sum = (current->number % m) * (a+b);
        sum = sum % m;
        //cout << sum << endl;
        return sum ;
    }
}

signed main()
{
    struct node *network;
    int n;
    cin >> n;
    network = new struct node[n+1];
    network[0].number = 0;
    for (int i = 0; i <= n; i++) {
        //network[i].number = 0;
        network[i].one = NULL;
        network[i].two = NULL;
    }
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        network[i].number = a;
    }
    for (int i = 2; i <= n ; i++) {
        int a;
        cin >> a;
        if (network[a].one == NULL) {
            network[a].one = network +  i;
        }
        else {
            network[a].two = network + i;
        }
    }
    struct node* temp=network+1;
    cout << Postorder(temp) ;

}