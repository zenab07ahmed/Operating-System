#include <iostream>
using namespace std;

class books { 
public: 
	string bookname; 
	void printname() { 
	cout << "book name is:" << bookname;
	} 
}; 
int main() { 
	books obj1;  
	obj1.bookname = "Abhi"; 
	obj1.printname(); 
	return 0; 
}
