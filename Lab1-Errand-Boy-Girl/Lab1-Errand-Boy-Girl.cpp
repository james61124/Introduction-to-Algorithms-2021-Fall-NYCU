#include <iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main()
{
	long long int N, l, k;
	long long int TIMEING = 0;
	cin >> N >> l >> k;
	deque<long long int> weight;
	for (long long int i = 0; i < N; i++) {
		long long int number;
		cin >> number;
		weight.push_back(number);
	}
	sort(weight.begin(), weight.end());
	while (weight.size() >= 2) {
		if (weight.back() + weight.front() <= l) { 
			TIMEING = TIMEING + k;
			weight.pop_back();
			weight.pop_front();
		}
		else {
			TIMEING = TIMEING + k;
			weight.pop_back();
		}
	}
	if (weight.size() == 1) {
		TIMEING = TIMEING + k;
	}
	cout << TIMEING * 2;
}