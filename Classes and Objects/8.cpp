#include<iostream>
using namespace std;
class book
{
	private:
	int bid;
	string bname;
	public:
		book(int book_id,string book_name)
		{
			bid=book_id;
			bname=book_name;
		}
		book()
		{
			cout<<"enter bid";
			cin>>bid;
			cout<<"enter bname";
			cin>>bname;
		}
		void display()
		{
			cout<<"The book id is "<<bid<<endl;
			cout<<"The book name is "<<bname<<endl;
		}
		
};		
int main()
{
	book b1,b2;
	b1.display();
	b2.display();
	return 0;
}
