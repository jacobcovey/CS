#include <iostream>

namespace KW {
	class list {
	private:
		#include "DNode.h"

	public:
		#include "list_iterator.h"

		friend class iterator;

		#include "list_const_iterator.h"

		friend class const_iterator;

	private:
		DNode* Head;
		DNode* tail;
		int num_items;
	};
}

int main() {


	return 0;
}
