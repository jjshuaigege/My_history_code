#include <iostream>
using namespace std;
template<typename ElementType>
struct ArrayList
{
	private:
		int length;   //实际长度
		int max_length;   //最大长度 
		ElementType* p;
	public:
	ArrayList():length(0),p(new ElementType[10]),max_length(10)
	{
	}
	//扩容（5个单位）
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
	//从下标为 s_index的位置查找第一次出现X的位置，找到返回下标，未找到返回-1 
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
	//按下标插入X
	bool insert_index(ElementType X,int i)
	{
		if(i<0||i>length)    //插入位置不合法 
		{
			return false;
		}
		else
		{
			if(length==max_length)
			{
				space_enlarge();
			}
			//移动后面的元素 
			for(int k=length-1;k>=i;--k)
			{
				p[k+1]=p[k];
			}
			//插入到空位
			p[i]=X;
			length++;
			return true;
		}
	}
	//按下标删除元素
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
	//求线性表的长度 
	int get_length()
	{
		return length; 
	} 
	//展示线性表
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

