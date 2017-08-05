#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class BinaryTree {
	public:
		bool is_symmetric(const shared_ptr<BinaryTree<T> > t1, const shared_ptr<BinaryTree<T> > t2) const;
	private:
		T data;
		shared_ptr<BinaryTree<T> > left;
		shared_ptr<BinaryTree<T> > right;
};

template<typename T>
bool BinaryTree<T>::is_symmetric(const shared_ptr<BinaryTree<T> > t1, const shared_ptr<BinaryTree<T> > t2) const {
	bool result = !(t1 == NULL ^ t2 == NULL);
	if(result && t1) {
		result = result && (t1->data == t2->data);
		result = result && is_symmetric(t1->left, t2->right);
		result = result && is_symmetric(t1->right, t2->left);
	}
	return result;
}

int main() {
	BinaryTree<int> T;
	// your code goes here
	
	return 0;
}
