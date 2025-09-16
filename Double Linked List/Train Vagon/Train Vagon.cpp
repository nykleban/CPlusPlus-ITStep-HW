using namespace std;
#include <iostream>
struct Vagon {
	int number;
	int capacity;
	int passengers;
	Vagon() : number(0), capacity(0), passengers(0) {}
	Vagon(int num, int cap, int pass) : number(num), capacity(cap), passengers(pass) {}
	void Print() const {
		cout << "Vagon Number: " << number << ", Capacity: " << capacity
			<< ", Passengers: " << passengers << endl;
	}
};
ostream& operator<<(ostream& os, const Vagon& v) {
	os << "Vagon Number: " << v.number << ", Capacity: " << v.capacity
		<< ", Passengers: " << v.passengers;
	return os;
}

template<typename T>
class List
{
private:
	struct Node {
		T data;
		Node* next;
		Node* prev;
		Node() :prev(nullptr), data(T()), next(nullptr) {}
		Node(Node* prev, T value, Node* next) :prev(prev), data(value), next(next) {}
		Node(Node* prev, T value) : prev(prev), data(value), next(prev->next) {}
	};
	Node* head;
	Node* tail;

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	~List() {
		if (head != nullptr) head = nullptr; 
		if (tail != nullptr) tail = nullptr; 
	};
	void AddToTail(T item) {
		Node* newNode = new Node(head,item,nullptr);
		Node* current = tail;
		if (IsEmpty()) head = tail = newNode;
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}
	void AddToHead(T item) {
		Node* newNode = new Node(nullptr, item, head);
      
		if (IsEmpty()) {
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
	}
	void DeleteFromHead() {
		if (IsEmpty()) return;
		if (head->next == nullptr) {
			delete head;
			head = tail = nullptr;
			return;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
	}
	void DeleteFromTail() {
		if (head == nullptr) return;
		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}

	}
	int GetByPosition(int pos) {
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
		return -1;
	}

	int operator[](int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
		return -1;
	}

	void Print() const {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << endl;
			current = current->next;
		}
	}
	void AddByPosition(int pos, T item) {
		if (pos < 1) return;
		if (pos == 1) {
			AddToHead(item);
			return;
		}
		Node* current = head;
		int i = 1;
		while (current != nullptr && i < pos) {
			current = current->next;
			i++;
		}
		if (current == nullptr) {
			AddToTail(item);
			return;
		}
		Node* newNode = new Node(current->prev, item, current);

		if (current->prev != nullptr) current->prev->next = newNode;
		else head = newNode;

		current->prev = newNode;
	}
	void DeleteByPosition(int pos) {
		if (pos < 1 || IsEmpty()) return;
		if (pos == 1) {
			DeleteFromHead();
			return;
		}
		Node* current = head;
		int i = 1;
		while (current != nullptr && i < pos) {
			current = current->next;
			i++;
		}
		if (current == nullptr) return;
		if (current->prev != nullptr) current->prev->next = current->next;
		else head = current->next;
		if (current->next != nullptr) current->next->prev = current->prev;
		else tail = current->prev;
		delete current;
	}
};


class Train
{
private:
	string model;
	int countVagons;
	List<Vagon> vagons;
public:
	Train() : model(""), countVagons(0) {}
	Train(string m) : model(m), countVagons(0) {}
	Train(Train& copy) : model(copy.model), countVagons(copy.countVagons), vagons(copy.vagons) {}
	void AddVagonToTail(const Vagon& vagon) {
		vagons.AddToTail(vagon);
		countVagons++;
	}
	void AddVagonToHead(const Vagon& vagon) {
		vagons.AddToHead(vagon);
		countVagons++;
	}
	void DeleteVagonFromHead() {
		if (countVagons > 0) {
			vagons.DeleteFromHead();
			countVagons--;
		}
	}
	void DeleteVagonFromTail() {
		if (countVagons > 0) {
			vagons.DeleteFromTail();
			countVagons--;
		}
	}
	void Show() const {
		cout << "\t========= Train INFO ===========" << endl;
		cout << "Train Model: " << model << ", Count of Vagons: " << countVagons << endl
			<< "------------------------------------------------"<<endl;
		vagons.Print();
		cout << "------------------------------------------------" << endl << endl;
	}
	void AddByPosition(int pos, const Vagon& vagon) {
		vagons.AddByPosition(pos, vagon);
		countVagons++;
	}
	void DeleteByPosition(int pos) {
		if (countVagons > 0) {
			vagons.DeleteByPosition(pos);
			countVagons--;
		}
	}
};


int main()
{
	Train train("MEGATRAIN G5000");
	train.AddVagonToTail(Vagon(1, 100, 50));
	train.AddVagonToTail(Vagon(2, 120, 80));
	train.AddVagonToTail(Vagon(3, 120, 80));
	train.AddVagonToTail(Vagon(4, 120, 80));
	train.AddVagonToHead(Vagon(0, 90, 30));
	train.AddByPosition(3, Vagon(400, 13000, 7000));
	train.Show();
	train.DeleteByPosition(3);
	train.Show();

}
