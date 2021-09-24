#pragma once
#include"ListNode.h"

using Rank = int;

template<class T>
class List {
private:
	int _size;
	ListNode<T>* header; ListNode<T>* trailer;

public:
	void init();

	T& operator[](Rank r) const;

	ListNode<T>* frist() const;
	ListNode<T>* find(T const& e, int n, ListNode<T>* p) const;
	ListNode<T>* insertAsFirst(T const& e);
};

template<class T>
void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;

	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size = 0;
}

template<class T>
T& List<T>::operator[](Rank r) const {
	ListNode<T>* p = first();
	while (0 < r--)
		p = p->succ;
	return p->data;
}

template<class T>
ListNode<T>* List<T>::frist() const {
	return header->succ;
}

template<class T>
ListNode<T>* List<T>::find(T const& e, int n, ListNode<T>* p) const {
	while (0 < r--)
		if (e == (p = p->pred)->data) return p;
	return NULL; 
}

template<class T>
ListNode<T>* List<T>::insertAsFirst(T const& e) {
	_size++;
	return header->insertAsSucc();
}