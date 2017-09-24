#include <iostream>
#include <queue>
using namespace std;

class comparator {
	public:
		bool operator()(int a, int b) {
			return a > b;
		}
};

int main() {
	// your code goes here
	priority_queue<int, vector<int>, comparator> min_heap;
	int n = 0;
	int k = 0;
	cin >> k;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	for(int i = 0; i < min(k + 1, (int)A.size()); ++i) {
		min_heap.push(A[i]);
	}
	for(int i = 0, j = k + 1; !min_heap.empty(); ++i, ++j) {
		A[i] = min_heap.top();
		min_heap.pop();
		if(j < A.size())
			min_heap.push(A[j]);
	}
	for(auto e: A) {
		cout << e << " ";
	}

	return 0;
}
