#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void menu() {
	cout << "\nShow all books\t\t[1]\n";
	cout << "Search by author\t[2]\n";
	cout << "Search by title\t\t[3]\n";
	cout << "Search by publisher\t[4]\n";
	cout << "Search by genre\t\t[5]\n";
	cout << "Add new book\t\t[6]\n";
	cout << "Save to file\t\t[7]\n";
	cout << "Load from file\t\t[8]\n";
	cout << "Exit\t\t\t[0]\n\n";
};

struct Book {
	char title[100];
	char author[50];
	char publisher[50];
	char genre[50];
	int year;
	float price;
};

void showBook(const Book& book) {
	cout << "Title: " << book.title << "\n";
	cout << "Author: " << book.author << "\n";
	cout << "Publisher: " << book.publisher << "\n";
	cout << "Genre: " << book.genre << "\n";
	cout << "Year: " << book.year << "\n";
	cout << "Price: " << book.price << "$ \n\n";
}

void searchByAuthor(Book b[], int size, char author[]) {
	for (int i = 0; i < size; i++) {
		if (strcmp(b[i].author, author) == 0)
			showBook(b[i]);
	}
}

void searchByTitle(Book b[], int size, char title[]) {
	for (int i = 0; i < size; i++) {
		if (strcmp(b[i].title, title) == 0)
			showBook(b[i]);
	}
}

void searchByPublisher(Book b[], int size, char publisher[]) {
	for (int i = 0; i < size; i++) {
		if (strcmp(b[i].publisher, publisher) == 0)
			showBook(b[i]);
	}
}

void searchByGenre(Book b[], int size, char genre[]) {
	for (int i = 0; i < size; i++) {
		if (strcmp(b[i].genre, genre) == 0)
			showBook(b[i]);
	}
}

void addNewBook(Book b[], int& size, int maxSize) {
	if (size >= maxSize) {
		cout << "Cannot add more books. Maximum capacity reached.\n";
		return;
	}

	Book newBook;
	cin.ignore();
	cout << "Enter title: ";
	cin.getline(newBook.title, 100);
	cout << "Enter author: ";
	cin.getline(newBook.author, 50);
	cout << "Enter publisher: ";
	cin.getline(newBook.publisher, 50);
	cout << "Enter genre: ";
	cin.getline(newBook.genre, 50);
	cout << "Enter year: ";
	cin >> newBook.year;
	cout << "Enter price: ";
	cin >> newBook.price;

	b[size] = newBook;
	size++;
	cout << "New book added successfully.\n";
}

int main() {
	cout << "====== LIBRARY =====\n";
	int choice;
	const int maxSize = 10;
	Book books[maxSize]{
		{"My First Book", "John Smith", "Sunrise Press", "Children", 2020, 5.99},
		{"Bedtime Stories", "Emma White", "Star Books", "Fairy Tale", 2019, 4.50},
		{"ABC Book", "Mary Green", "Light House", "Educational", 2018, 3.75},
		{"Fun Reading", "Peter Brown", "Morning Light", "Children", 2021, 6.20},
		{"Forest Adventure", "Lucy Gray", "Sunny Books", "Adventure", 2022, 7.10},
		{"Lessons of Friendship", "Tom Black", "Spring House", "Educational", 2020, 5.00}
	};
	int size = 6;

	do {
		menu();
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: // Show all books
			system("cls");
			for (int i = 0; i < size; i++) {
				cout << "-- Book number [" << i + 1 << "] --" << endl;
				showBook(books[i]);
			}
			break;

		case 2: { // Search by author
			char author[50];
			cout << "Enter author: ";
			cin.ignore();
			cin.getline(author, 50);
			cout << endl;
			searchByAuthor(books, size, author);
			break;
		}
		case 3: { // Search by title
			char title[100];
			cout << "Enter title: ";
			cin.ignore();
			cin.getline(title, 100);
			cout << endl;
			searchByTitle(books, size, title);
			break;
		}
		case 4: { // Search by publisher
			char publisher[50];
			cout << "Enter publisher: ";
			cin.ignore();
			cin.getline(publisher, 50);
			cout << endl;
			searchByPublisher(books, size, publisher);
			break;
		}
		case 5: { // Search by genre
			char genre[50];
			cout << "Enter genre: ";
			cin.ignore();
			cin.getline(genre, 50);
			cout << endl;
			searchByGenre(books, size, genre);
			break;
		}
		case 6: // Add new book
		{
			system("cls");
			addNewBook(books, size, maxSize);
			break;
		}

		case 7: { // Save to file
			ofstream outFile("books.txt", ios::binary);
			if (!outFile.is_open()) {
				cout << "Error opening file for writing.\n";
			}
			else {
				for (int i = 0; i < size; i++) {
					outFile.write((char*)&books[i], sizeof(Book));
				}
				outFile.close();
				cout << "Books saved to file successfully.\n\n";	
			}
			break;
		}
		case 8: { // Load from file
			ifstream inFile("books.txt", ios::binary);
			if (!inFile.is_open()) {
				cout << "Error opening file for reading.\n";
			}
			else {
				size = 0;
				while (inFile.read((char*)&books[size], sizeof(Book)) && size < maxSize) {
					size++;
				}
				inFile.close();
				cout << "Books loaded from file successfully.\n";
			}
			break;
		}
		case 0:
			cout << "Good bye ... \n";
			exit(0);
			break;
		default:
			cout << "Invalid choice. Try again.\n";
			break;
		}
	} while (choice != 0);

	return 0;
}
