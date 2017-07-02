#include <iostream>
#include <memory>
using namespace std;

template<typename T>
struct ListNode {
	T data;
	shared_ptr<ListNode<T> > next;
	shared_ptr<ListNode<T> > prev;
	ListNode<T>(T t) {
		data = t;
	}
	ListNode<T>() {
 
	}
};
 
typedef shared_ptr<ListNode<int> > p_list_int;

p_list_int build_list(p_list_int l, int n) {
	p_list_int result = NULL;
	for(int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		p_list_int pt(new ListNode<int>());
		pt->data = t;
		if(l) {
			l->next = pt;
			pt->prev = l;
		} else {
			l = pt;
			result = l;
		}
		l = pt;
	}
	return result;
}

p_list_int reverse(p_list_int head) {
	p_list_int p1 = NULL;
	p_list_int p2 = head;
	p_list_int result = p2;
	while(p2) {
		result = p2;
		p_list_int p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	return result;
}

p_list_int get_middle(p_list_int head) {
	p_list_int slow = head;
	p_list_int fast = head;
	while(fast) {
		fast = fast->next;
		if(fast) {
			fast = fast->next;
		}
		if(fast)
			slow = slow->next;
	}
	return slow;
}

bool is_palindrome(p_list_int head) {
	auto middle = get_middle(head);
	auto r_list = reverse(middle?middle->next:NULL);
	middle->next = NULL;
	bool result = true;
	while(head && r_list && result) {
		result = (head->data == r_list->data);
		head = head->next;
		r_list = r_list->next;
	}
	return result;
}

int main() {
	// your code goes here
	p_list_int l = NULL;
	int m, n;
	cin >> m;
	l = build_list(l, m);
	cout << is_palindrome(l) << "\n";
	return 0;
}
