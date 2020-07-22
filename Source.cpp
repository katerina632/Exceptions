#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

	Stack<int>st(3);

	cout << "Pop element.." << endl;
	try {
		cout << st.Pop() << endl;
	}
	catch (IsEmptyException & ex) {
		cout << ex.what() << endl;;
	}

	cout << "Pushing some elements.." << endl;
	try {
		st.Push(1);
		cout << st.Peek() << endl;
		st.Push(2);
		cout << st.Peek() << endl;
		st.Push(3);
		cout << st.Peek() << endl;
		st.Push(4);
		cout << st.Peek() << endl;
	}
	catch (InvalidSizeException & ex) {
		ex.Message();
	}	
	catch (OverFlowException & ex) {
		cout << ex.what() << endl;
	}

	cout << "Elements in stack: " << endl;
	while (!st.IsEmpty())
		cout << st.Pop() << endl;

	system("pause");
	return 0;
}