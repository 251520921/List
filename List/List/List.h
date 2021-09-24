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