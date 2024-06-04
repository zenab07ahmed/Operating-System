#include<iostream>
using namespace std; 
class books 
{ 
	public: 
	string bname; 
	int bid; 
	void printbname(); 
	void printbid() 
	{ 
		cout <<"book id is: "<<bid; 
	} 
}; 

void books::printbname() 
{ 
	cout <<"bookname is: "<<bname; 
} 
int main() { 
	
	books obj1; 
	obj1.bname = "Maths"; 
	obj1.bid=15; 
	
	obj1.printbname(); 
	cout << endl; 
	
	// call printid() 
	obj1.printbid(); 
	return 0; 
} 
