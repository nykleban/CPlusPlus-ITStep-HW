using namespace std;
#include <iostream>

class Stack
{
private:
	int size;
	string* arr;
public:
    Stack(int sizea) : size(sizea), arr(new string[sizea]) {
		for (int i = 0; i < size; i++)
		{
			arr[i] = "";
		}
	}
	void doubleSize() {
		string* newArr = new string[size * 2];
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		size *= 2;
	}
	bool isFull() {
		if (arr[size-1] != "") {
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
			for (int i = 0; i < size; i++) {
				if (arr[i] == "") {
					arr[i] = value;
					break;
				}
			}
		else
		{
			doubleSize();
			for (int i = 0; i < size; i++) {
				if (arr[i] == "") {
					arr[i] = value;
					break;
				}
			}
		}
	};
	void pop() {
		if (!isEmpty())
			for (int i = size-1; i >= 0; i--) {
				if (arr[i] != "") {
					arr[i] = "";
					break;
				}
			}
	};
	void count() {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] != "") {
				count++;
			}
		}
		cout << "Count: " << count << endl;
	};
	void print() {
		cout << "Stack: ";
		for (int i = 0; i < size; i++) {
			if (arr[i] != "") cout << arr[i];
			if (arr[i] == "") cout << "_";
			cout << " ";
		}
		cout << endl;
	};
	void clean() {
		for (int i = 0; i < size; i++) {
			arr[i] = "";
		}
		cout << "Stack cleaned!" << endl;
	};
	void last() {
		for (int i = size-1; i >= 0; i--) {
			if (arr[i] != "") {
				cout << "Last element: " << arr[i] << endl;
				break;
			}
		}
	};

};


int main()
{
	Stack stack(5);
	stack.push("A");
	stack.push("B");
	stack.push("C");
	stack.push("D");
	stack.print();
	stack.push("E");
	stack.push("F");
	stack.push("G");
	stack.push("H");
	stack.push("I");
	stack.push("J");
	stack.print();
	stack.push("K");
	stack.print();
	stack.count();
	stack.pop();
	stack.print();
	stack.last();
	stack.clean();
	stack.print();
	stack.push("F");
	stack.print();
	return 0;
}