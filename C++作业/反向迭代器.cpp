#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
int main()
{
	vector<int> h{1,3,5,7,9,11,13,15};
	auto i=h.cbegin();     //cbeing()����һ��const��iterator 
	vector<int>::const_reverse_iterator j=h.crbegin();
	j++;
	i=j.base();    //ʹ�ó�Ա����base�����������ת��Ϊ���������(����������ڷ����������Ӧ��λ�ú���һ����λ)
	i--;
	cout<<"*i="<<*i<<endl;
	vector<int>::const_reverse_iterator k{i};    //����������������������ʼ�� 
	k++; 
	cout<<"*i="<<*i<<endl;
	j=(vector<int>::const_reverse_iterator)i;    //Ҳ��ͨ��ǿ������ת���ѷ���ת������   ���������������λ��ͬǰ�����һ����λ�� 
	cout<<*k<<endl;     
	cout<<*j<<endl;
	return 0;
}

