#include <iostream>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	priority_queue<int, vector<int>> max_heap;
	int n;
	int k;
	cin >> k;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	for(int i = 0; i < min(k, (int)A.size()); ++i) {
		max_heap.push(A[i]);
	}
	for(int i = k; i < A.size(); ++i) {
		if(A[i] < max_heap.top()) {
			max_heap.pop();
			max_heap.push(A[i]);
		}
	}
	while(!max_heap.empty()) {
		cout << max_heap.top() << " ";
		max_heap.pop();
	}
	return 0;
}
