#include<iostream>
using namespace std;
class books
{
	private:
		int b_id;
		string b_name;
	public:
		void getdata()
		{
			b_id=201;
			b_name="abc";
		}
		void display()
		{
		    cout<<"bood id is "<<b_id<<endl;
		    cout<<"book name is "<<b_name<<endl;
	    }
};
int main()
{
	books b1;
	b1.getdata();
	b1.display();
    return 0;
}

