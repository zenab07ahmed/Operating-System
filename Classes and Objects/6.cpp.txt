#include<iostream>
using namespace std;
class book
{
	public:
		int bid;
		string bname;
};
main()
{
	book b1;
	book b2;
	
	b1.bid=101;
	b1.bname="dsa";
	
	b2.bid=102;
	b2.bname="oopm";
	
	cout<<"book b1 id is\t"<<b1.bid<<endl;
	cout<<"book b1 name is\t"<<b1.bname<<endl;
	
	cout<<"book b2 id is\t"<<b2.bid;
	cout<<"\nbook b2 name is\t"<<b2.bname;
}

