#include <iostream>
using namespace std;
struct GNode
{
	bool flag;   //为0代表使用数据，为1代表使用指针 
	union
	{
		int data;
		GNode* sublist;
	} URegion;
	int data;
	GNode* next;	
} 
int main()
{
	return 0;
}

