#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class BinaryTree {
	public:
		bool is_height_balanced(const shared_ptr<BinaryTree<T> > root) const;
	private:
		int is_height_balanced_helper(const shared_ptr<BinaryTree<T> > root, bool& result) const;
		T data;
		shared_ptr<BinaryTree<T> > left;
		shared_ptr<BinaryTree<T> > right;
};

template<typename T>
bool BinaryTree<T>::is_height_balanced(const shared_ptr<BinaryTree<T> > root) const {
	bool result = true;
	is_height_balanced_helper(root, result);
	return result;
}

template<typename T>
int BinaryTree<T>::is_height_balanced_helper(const shared_ptr<BinaryTree<T> > root, bool& result) const {
	int h = 0;
	if(root && result) {
		int l_h = is_height_balanced_helper(root->left, result);
		int r_h = is_height_balanced_helper(root->right, result);
		result = result && abs(l_h - r_h) <= 1;
		h = max(l_h, r_h) + 1;
	}
	return h;
}


int main() {
	BinaryTree<int> T;
	// your code goes here
	
	return 0;
}
