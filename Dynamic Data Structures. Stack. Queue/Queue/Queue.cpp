using namespace std;  
#include <iostream>  
#include <string>  

template<typename T>  
class Queue  
{  

public:  
   enum Posada  
   {  
       guest = 1,  
       admin = 2,  
       maneger = 3,  
       director = 4  
   };  

   struct file  
   {  
       string name;
	   string posada_str;
       Posada posada_number = 0;
      
       file(const string& name = "", const string& posada = "")
           : name(name), posada_str(posada), posada_number(guest)
       { 
		   if (posada == "guest") posada_number = guest;
           else if (posada_str == "admin") posada_number = admin;
           else if (posada_str == "maneger") posada_number = maneger;
           else if (posada_str == "director") posada_number = director;
       }
   };  

private:  
   int size;  
   file* arr;  

public:  
   Queue() : arr(nullptr), size(0) {};  
   ~Queue() { if (arr != nullptr) delete[]arr; };  
   void sortByPosada()  
   {  
       for (int i = 0; i < size - 1; i++) {  
           bool swapped = false;  
           for (int j = 0; j < size - i - 1; j++) {  
               if (arr[j].posada_number < arr[j + 1].posada_number) {
                   swap(arr[j], arr[j + 1]);  
                   swapped = true;  
               }  
           }  
           if (!swapped) {  
               break;  
           }  
       }  
   }  
   void addFile(file newFile)
   {
       file* newArr = new file[size + 1];
       for (int i = 0; i < size; i++) {
           newArr[i] = arr[i];
       }
       newArr[size] = newFile; 
       delete[] arr;
       arr = newArr;
       sortByPosada();
       size++;
   };
   void printQueue()  
   {  
       if (size == 0) {  
           cout << "Queue is empty! (from printQueue())" << endl;  
           return;  
       }  
       cout << "Queue: " << endl;  
       for (int i = 0; i < size; i++)  
       {  
           switch (arr[i].posada_number)  
           {  
           case guest:  
               cout << "Guest";  
               break;  
           case admin:  
               cout << "Admin";  
               break;  
           case maneger:  
               cout << "Maneger";  
               break;  
           case director:  
               cout << "Director";  
               break;  
           default:  
               break;  
           }  
           cout << " - " << arr[i].name << endl;  
       }  
   };
   void clearQueue()
   {
	   if (arr != nullptr) {
		   delete[] arr;
		   arr = nullptr;
		   size = 0;
	   }
       cout << "Queue cleared." << endl;
   };
   void first() {
	   if (size > 0) {
		   cout << "First in queue: " << arr[0].name << endl;
	   }
	   else {
		   cout << "Queue is empty!(from printfirst())" << endl;
	   }
   }

};  

int main()  
{  
  Queue<string> queue;  
  queue.addFile({ "Alice", "guest" });
  queue.addFile({ "Bob", "admin" });
  queue.addFile({ "Charlie", "maneger" });
  queue.addFile({ "David", "director" });
  queue.addFile({ "Nazar", "STUDENT" });
  queue.addFile({ "Eve", "guest" });
  queue.addFile({ "Frank", "admin" });

  Queue<string>::file newFile("Grace", "maneger");
  queue.addFile(newFile);
  queue.addFile({ "Hannah" , "director" });

  queue.printQueue();
  queue.first();
  queue.clearQueue();

  queue.first();
  queue.printQueue(); 

}
