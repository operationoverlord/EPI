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

pair<p_list_int, p_list_int> reverse(p_list_int head, p_list_int next_node) {
	pair<p_list_int, p_list_int> result;
	result.second = head;
	result.first = head;
	p_list_int p1 = NULL;
	p_list_int p2 = head;
	while(p2 != next_node) {
		p_list_int p3 = p2->next;
		p2->next = p1;
		result.first = p2;
		p1 = p2;
		p2 = p3;
	}
	return result;
}

void advance_node(p_list_int* head, int p) {
	for(int i = 0; i < p && *head; ++i) {
		*head = (*head)->next;
	}
}

void reverse_sublist(p_list_int* head, int l, int h) {
	p_list_int prev = *head;
	p_list_int next_node = *head;
	advance_node(&prev, l - 2);
	advance_node(&next_node, h);
	pair<p_list_int, p_list_int> r_list = reverse(l == 1? prev:prev->next, next_node);
	if(l > 1) {
		prev->next = r_list.first;
	}
	if(r_list.second) {
		r_list.second->next = next_node;
	}
	if(l == 1) {
		*head = r_list.first;
	}
}


int main() {
	// your code goes here
	p_list_int l = NULL;
	int m, n;
	cin >> m;
	l = build_list(l, m);
	reverse_sublist(&l, 1, 3);
	while(l) {
		cout << l->data << " ";
		l = l->next;
	}
	return 0;
}
