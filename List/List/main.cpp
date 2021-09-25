#include <iostream>
#include "List.h"

int main() {
	List<int> list;
	for (int i = 10; 0 < i; i--)
		list.insertAsLast(i);
	return 0;
}