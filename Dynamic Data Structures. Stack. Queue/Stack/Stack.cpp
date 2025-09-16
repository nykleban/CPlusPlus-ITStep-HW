using namespace std;
#include <iostream>

class Stack
{
private:
	string arr[25]{""};
public:
	bool isFull() {
		if (arr[24] != "") {
			return true;
		}
		else { return false; }
	};
	bool isEmpty() {
		if (arr[0] == "") {
			return true;
		}
		else { return false; }
	};
	void push(string value) {
		if (!isFull()) 
			for (int i = 0; i < 25; i++) {
				if (arr[i] == "") {
					arr[i] = value;
					break;
				}
			}
	};
	void pop() {
		if (!isEmpty()) 
			for (int i = 24; i >= 0; i--) {
				if (arr[i] != "") {
					arr[i] = "";
					break;
				}
			}
	};
	void count() {
		int count = 0;
		for (int i = 0; i < 25; i++) {
			if (arr[i] != "") {
				count++;
			}
		}
		cout << "Count: " << count << endl;
	};
	void print() {
		cout << "Stack: ";
		for (int i = 0; i < 25; i++) {
			if (arr[i] != "") cout << arr[i];
			if (arr[i] == "") cout << "_";
			cout << " ";
		}
		cout << endl;
	};
	void clean() {
		for (int i = 0; i < 25; i++) {
			arr[i] = "";
		}
		cout << "Stack cleaned!" << endl;
	};
	void last() {
		for (int i = 24; i >= 0; i--) {
			if (arr[i] != "") {
				cout << "Last element: " << arr[i] << endl;
				break;
			}
		}
	};

};


	int main()
	{
		Stack stack;
		stack.push("A");
		stack.push("B");
		stack.push("C");
		stack.print();
		stack.count();
		stack.last();
		stack.pop();
		stack.print();
		stack.count();
		stack.clean();
		stack.print();
	}
