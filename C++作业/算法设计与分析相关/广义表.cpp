#include <iostream>
using namespace std;
struct GNode
{
	bool flag;   //Ϊ0����ʹ�����ݣ�Ϊ1����ʹ��ָ�� 
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

