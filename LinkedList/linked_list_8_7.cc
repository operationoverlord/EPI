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

void delete_k_node(p_list_int* head, int k) {
	p_list_int p1 = *head, p2 = *head;
	for(int i = 1; i < k; ++i) {
		p2 = p2->next;
	}
	p_list_int prev = NULL;
	while(p2 && p2->next) {
		prev = p1;
		p1 = p1->next;
		p2 = p2->next;
	}
	if(prev) {
		prev->next = p1->next;
	} else if(*head) {
		*head = (*head)->next;
	}
}


int main() {
	// your code goes here
	p_list_int l = NULL;
	int m, n;
	cin >> m;
	l = build_list(l, m);
	delete_k_node(&l, 1);
	while(l) {
		cout << l->data << " ";
		l = l->next;
	}
	return 0;
}
