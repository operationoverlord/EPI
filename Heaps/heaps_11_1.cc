#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class element {
	public:
		int val;
		int array_index;
		int index;
		element() {
		}
		element(int val_p, int array_index_p, int index_p) {
			val = val_p;
			array_index = array_index_p;
			index = index_p;
		}
};

class Compare
{
public:
	bool operator()(const element& a, const element& b) {
		return a.val < b.val;
	}	
};

vector<int> merge_sorted(vector<vector<int> >& sequences) {
	priority_queue<element, vector<element>, Compare> min_heap;
	vector<int> result;
	for(int i = 0; i < sequences.size(); ++i) {
		element current(sequences[i][0], i, 0);
		min_heap.push(current);
	}
	while(!min_heap.empty()) {
		element current = min_heap.top();
		min_heap.pop();
		result.push_back(current.val);
		++current.index;
		if(current.index < sequences[current.array_index].size()) {
			current.val = sequences[current.array_index][current.index];
			min_heap.push(current);
		}
	}
	return result;
}

int main() {
	// your code goes here
	int k, n;
	cin >> k;
	cin >> n;
	vector<vector<int> > v(k);
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
	}
	auto result = merge_sorted(v);
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
	}
	return 0;
}
