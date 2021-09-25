#include <iostream>
#include "List.h"

int main() {
	List<int> list;
	for (int i = 4; 0 < i; i--)
		list.insertAsLast(i);
	list.insertSort();
	return 0;
}