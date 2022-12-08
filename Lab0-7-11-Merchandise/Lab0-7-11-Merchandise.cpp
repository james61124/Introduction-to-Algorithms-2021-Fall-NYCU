#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int type, instruction;
	cin >> type >> instruction;
	vector<vector<int>>product;
	vector<int>temp;
	for (int i = 0; i < type; i++) {
		product.push_back(temp);
	}
	for (int i = 0; i < instruction; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			product[b].push_back(c);
		}
		else if (a == 2) {
			if (c < product[b].size()) {
				cout << product[b][c] << '\n';
			}
			else cout << "-1" << '\n';
		}
		cin.tie(0);
		cin.sync_with_stdio(0);
		
	}
	
	
}