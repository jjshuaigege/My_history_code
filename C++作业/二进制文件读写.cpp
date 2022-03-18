#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream ofs;
	ifstream ifs;
	int x=120;
	int y;
	ofs.open("test.dat",ios::out);
	ofs.write((const char*)&x,sizeof(int));
	ofs.close();
	ifs.open("test.dat",ios::in);
	ifs.read((char*)&y,sizeof(int));
	ifs.close();
	cout<<"y="<<y<<endl;
	return 0;
}

