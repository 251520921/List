#pragma once
#include"ListNode.h"

using Rank = int;

template<class T>
class List {
private:
	int _size;
	ListNode<T>* header; ListNode<T>* trailer;
private:
	void copyNodes(ListNode<T>* p, int n);
	void init();
	int clear();
public:
	List() { init(); }
	List(ListNode<T>* p, int n);
	List(List<T> const& L);
	List(List<T> const& L, Rank r, int n);
	~List();

	T& operator[](Rank r) const;

	ListNode<T>* frist() const;
	ListNode<T>* find(T const& e, int n, ListNode<T>* p) const;
	ListNode<T>* insertAsFirst(T const& e);
	ListNode<T>* insertAsLast(T const& e);
	ListNode<T>* insert(ListNode<T>* p, T const& e);
	ListNode<T>* insert(T const& e, ListNode<T>* p);
	T remove(ListNode<T>* p);
	void traverse(void (*visit)(T&));
	template<class VST> void traverse(VST& visit);
};

template<class T>
void List<T>::copyNodes(ListNode<T>* p, int n) {
	init();
	while (n--) {
		insertAsLast(p->data);
		p = p->succ;
	}
}

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
int List<T>::clear() {
	int oldSize = _size;
	while (0 < _size)
		remove(header->succ);
	return oldSize;
}

template<class T>
List<T>::List(ListNode<T>* p, int n) {
	copyNodes(p, n);
}

template<class T>
List<T>::List(List<T> const& L) {
	copyNodes(L.frist(), L._size);
}

template<class T>
List<T>::List(List<T> const& L, Rank r, int n) {
	copyNodes(L[r], n);
}

template<class T>
List<T>::~List() {
	clear();
	delete header;
	delete trailer;
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

template<class T>
ListNode<T>* List<T>::insertAsLast(T const& e) {
	_size++;
	return trailer->insertAsPred(e);
}

template<class T>
ListNode<T>* List<T>::insert(ListNode<T>* p, T const& e) {
	_size++;
	return p->insertAsSucc(e);
}

template<class T>
ListNode<T>* List<T>::insert(T const& e, ListNode<T>* p) {
	_size++;
	return p->insertAsPred(e);
}

template<class T>
T List<T>::remove(ListNode<T>* p) {
	T e = p->data;
	p->succ->pred = p->pred;
	p->pred->succ = p->succ;
	delete p;
	_size--;
	return e;
}

template<class T>
void List<T>::traverse(void (*visit)(T&)) {
	for (ListNode<T>* p = header->succ; p != trailer; p = p->succ)
		visit(p->data);
}

template<class T> template<class VST>
void List<T>::traverse(VST& visit) {
	for (ListNode<T>* p = header->succ; p != trailer; p = p->succ)
		visit(p->data);
}