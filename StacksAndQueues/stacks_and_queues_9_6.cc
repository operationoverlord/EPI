#include <iostream>
#include <stack>
using namespace std;

int main() {
	// your code goes here
	stack<int> buildings_with_potential_views;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int h;
		cin >> h;
		while(!buildings_with_potential_views.empty() && buildings_with_potential_views.top() <= h) {
			buildings_with_potential_views.pop();
		}
		buildings_with_potential_views.push(h);
	}
	while(!buildings_with_potential_views.empty()) {
		cout << buildings_with_potential_views.top() << " ";
		buildings_with_potential_views.pop();
	}
	return 0;
}
