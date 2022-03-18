#include <iostream>
using namespace std;
template<typename ElementType>
struct LNode
{
	private:
		ElementType data;
		LNode* next;
		template<typename T>
		friend class LinkList;
		template<typename T1>
		friend void clear_link_list(LNode<T1>* Head);	
	public:
		LNode()=default;
		LNode(ElementType data):data(data)
		{
			
		}
		~LNode()
		{
			cout<<"LNode "<<data<<" was deleted!"<<endl;
		}
};
template<typename T1>
void clear_link_list(LNode<T1>* Head)
{
	if(Head->next!=nullptr)
	{
		clear_link_list(Head->next);
		delete Head;
	}
	else
	{
		delete Head;
	}
}
template<typename T>
struct LinkList    //带头结点 
{
	private:
		LNode<T>* Head;
	public:
		LinkList():Head(new LNode<T>())
		{
			
		}
		void Make_Empty()
		{
			//递归删除每一个节点 
			clear_link_list(Head->next);
			Head->next=nullptr;
		}
		T Find_Kth(int K)
		{
			int cnt=0;
			LNode<T>* p=Head->next;
			while(p!=nullptr&&cnt!=K)
			{
				p=p->next;
				cnt++;
			}
			if(p!=nullptr)
			{
				return p->data;
			}
			else 
			{
				cout<<K<<"th element not found!"<<endl;
				return -1;     //返回-1表示没找到 
			}
		}
		int Find(T X)
		{
			int index=0;
			LNode<T>* p=Head->next;
			while(p!=nullptr&&p->data!=X)
			{
				p=p->next;
				index++;
			}
			if(p==nullptr)
			{
				cout<<X<<" is not found!"<<endl;
				return -1;
			}
			else
			{
				return index;
			}
		}
		bool insert_index(T X,int i)
		{
			if(i<0)
			{
				cout<<"insert failed! too small!"<<endl;
				return false;
			}
			else 
			{
				int cnt=0;
//				LNode<T>* p=Head->next;
				LNode<T>* q=Head;
				while((q->next)!=nullptr&&cnt!=i)
				{
					q=q->next;
					cnt++;
				}
				if(q->next==nullptr&&cnt<i)
				{
					cout<<"insert failed! too big!"<<endl;
					return false;   //插入位置不合法（过大 ） 
				}
				else
				{
					LNode<T>* new_node=new LNode<T>(X);
					new_node->next=q->next;
					q->next=new_node;
					return true;
				}
			}
		}
		bool delete_index(int i)
		{
			int cnt=0;
			LNode<T>* q=Head;
			while(q->next!=nullptr&&cnt!=i)
			{
				q=q->next;
				cnt++;
			}
			if(q->next==nullptr)
			{
				cout<<"delete failed!"<<endl;
				return false;
			}
			else   //q->next!=nullptr&&cnt==i
			{
				LNode<T>* temp=q->next;
				q->next=q->next->next;
				delete temp;
			}
		}
		int get_length()
		{
			int length=0;
			LNode<T>* p=Head;
			while(p->next!=nullptr)
			{
				p=p->next;
				length++;
			}
			return length;
		}
		void show()
		{
			LNode<T>* p=Head->next;
			if(!p)
			{
				cout<<"linklist is empty!";
			}
			while(p!=nullptr)
			{
				cout<<p->data<<" ";
				p=p->next;
			}
			cout<<endl;
		}
	
};
int main()
{
	LinkList<double> ll;
	ll.insert_index(1.2,1);
	ll.show();
	ll.insert_index(1.4,0);
	ll.insert_index(2.4,0);
	ll.insert_index(3.6,1);
	cout<<ll.get_length()<<endl;
	ll.insert_index(4.8,2);
	cout<<"3.6 location:"<<ll.Find(3.6)<<endl;
	cout<<"location 1 element:"<<ll.Find_Kth(1)<<endl;
	ll.show();
	ll.delete_index(1);
	ll.show();
	ll.Make_Empty();
	
	return 0;
}

