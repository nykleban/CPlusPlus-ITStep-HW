#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

class Stack
{
    enum { EMPTY = -1 };

    int* arr;
    int maxSize;
    int topIndex;
public:

    Stack() = delete;
    Stack(int size) :maxSize(size)//50
    {
        if (size <= 0) throw logic_error("Size cannot be <= 0"); //size < 0 throw 
        arr = new int[size];//50
        topIndex = EMPTY;
    }
    ~Stack()
    {
        if (arr != nullptr)
            delete[]arr;
    }

    bool IsFull()
    {
        return topIndex == maxSize - 1;
    }
    bool Push(int value)
    {
        if (!IsFull())
        {

            arr[++topIndex] = value;
            return true;
        }
        throw out_of_range("Stack is full");  //stack is full throw 
    }
    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
        {

            return arr[topIndex--];
        }
        throw range_error("Stack is empty");   //stack is empty throw 
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    int Peek()
    {
        if (!IsEmpty())
        {

            return arr[topIndex];
        }
        throw range_error("Stack is empty"); //stack is empty throw 
    }
    int GetSize()
    {
        return topIndex + 1;
    }
    void Print()
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
    void SaveToFile(const char* filename)
    {
        ofstream fout(filename, ios::binary);
        if (!fout)
            throw runtime_error("Cannot open file for writing");
        fout.write((char*)&maxSize, sizeof(maxSize));
        fout.write((char*)&topIndex, sizeof(topIndex));
        fout.write((char*)arr, sizeof(int) * (topIndex + 1));
        fout.close();
        cout << "============================" << endl;
		cout << "Stack saved to file successfully." << endl;
        cout << "============================" << endl;
	}
    void LoadFromFile(const char* filename)
    {
        ifstream fin(filename, ios::binary);
        if (!fin)
            throw runtime_error("Cannot open file for reading");
        fin.read((char*)&maxSize, sizeof(maxSize));
        fin.read((char*)&topIndex, sizeof(topIndex));
        if (arr != nullptr)
            delete[] arr;
        arr = new int[maxSize];
        fin.read((char*)arr, sizeof(int) * (topIndex + 1));
        fin.close();
		cout << "============================" << endl;
		cout << "Stack loaded from file successfully." << endl;
		cout << "Current Stack: ";
		Print();
		cout << "============================" << endl;
	}
};

int main()
{

    Stack st(9);
    try {
        Stack st2(-10); // Invalid Size
    }
    catch (const logic_error& e) {
        cout << "Logic Error: " << e.what() << endl;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    catch (...) {
        cout << "Unknown Error!" << endl;
    }

    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);
    st.Print();
	st.SaveToFile("stack_data.bin");
	st.LoadFromFile("stack_data.bin");
    while (true)
    {
        try {
            st.Push(1000);
           

        }
        catch (const out_of_range& e) {
            cout << "Out of Range Error: " << e.what() << endl;
            st.SaveToFile("stack_data.bin");
            break;
        }
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
            st.SaveToFile("stack_data.bin");
            break;
        }
        catch (...) {
            cout << "Unknown Error!" << endl;
            st.SaveToFile("stack_data.bin");
            break;
        }
        st.Print();
    
    }

    st.LoadFromFile("stack_data.bin");

    while (true)
    {
        try {
            cout << endl << st.Pop() << " was deleted..." << endl;
        }
        catch (const range_error& e) {
            cout << "Range Error: " << e.what() << endl;
            break;
        }
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
            break;
        }
        catch (...) {
            cout << "Unknown Error!" << endl;
            break;
        }
        if (st.IsEmpty()) cout << "NEXT MSG WILL BE ERROR!" << endl;
        st.Print();

    }
    return 0;

}