#include <iostream>
using namespace std;
template<typename ElementType>
struct ArrayList
{
	private:
		int length;   //ʵ�ʳ���
		int max_length;   //��󳤶� 
		ElementType* p;
	public:
	ArrayList():length(0),p(new ElementType[10]),max_length(10)
	{
	}
	//���ݣ�5����λ��
	void space_enlarge()
	{
		cout<<"void space_enlarge()"<<endl;
		ElementType* temp=p;
		p=new ElementType[max_length+5];
		max_length+=5;
		for(int i=0;i<length;++i)
		{
			p[i]=temp[i];	
		}
		delete[] temp;	
	} 
	void  List_Make_empty()
	{
		length=0;
	}
	ElementType FindKth(int K)
	{
		if(K>=0&&K<length)
		return p[K];
	}
	//���±�Ϊ s_index��λ�ò��ҵ�һ�γ���X��λ�ã��ҵ������±꣬δ�ҵ�����-1 
	int Find(ElementType X,int s_index=0) 
	{
		int index=-1;
		for(int i=s_index;i<length;++i)
		{
			if(p[i]==X)
			{
				index=i;
				break;
			}
		}
		return index;  //
	}
	//���±����X
	bool insert_index(ElementType X,int i)
	{
		if(i<0||i>length)    //����λ�ò��Ϸ� 
		{
			return false;
		}
		else
		{
			if(length==max_length)
			{
				space_enlarge();
			}
			//�ƶ������Ԫ�� 
			for(int k=length-1;k>=i;--k)
			{
				p[k+1]=p[k];
			}
			//���뵽��λ
			p[i]=X;
			length++;
			return true;
		}
	}
	//���±�ɾ��Ԫ��
	bool delete_index(int i)
	{
		if(i<0||i>=length)
		{
			return false;
		}
		else
		{
			for(int k=i;k<length-1;++k)
			{
				p[k]=p[k+1];
			}
			length--;
			return true;
		}
	}
	//�����Ա�ĳ��� 
	int get_length()
	{
		return length; 
	} 
	//չʾ���Ա�
	void show()
	{
		cout<<"length="<<length<<endl;
		int i;
		for(i=0;i<length;++i)
		{
			cout<<p[i];
			if((i+1)%5==0)
			{
				cout<<endl;
			}
			else if(i!=length-1)
			{
				cout<<",";
			}
		}
		if(i%5!=0)
		{
			cout<<endl;
		}
	 } 
	 ~ArrayList()
	 {
	 	delete[] p;
	 }
};
int main()
{
	ArrayList<double> s;
	s.insert_index(3.5,0);
	s.insert_index(6.6,1);
	s.insert_index(3.14,0);
	s.insert_index(3.5,0);
	s.insert_index(6.6,1);
	s.insert_index(3.14,0);
	s.insert_index(3.5,0);
	s.insert_index(6.6,1);
	s.insert_index(3.14,0);
	s.insert_index(3.5,0);
	s.insert_index(6.6,1);
	s.insert_index(3.14,0);
	s.show();
	return 0;
}

