#include<iostream>
using namespace std;
class book
{
	private:
	int bid;
	string bname;
	public:
		book()
		{
			bid=501;
			bname="maths";
			cout<<"book id is "<<bid<<endl;
			cout<<"book name is "<<bname<<endl;
			
			bid=502;
			bname="hindi";
			cout<<"book id is "<<bid<<endl;
			cout<<"book name is "<<bname<<endl;
		}
		
};		
int main()
{
	book b1;
	return 0;
}
