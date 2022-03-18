#include <iostream>
using namespace std;
template<typename ElementType>
struct DLNode
{
	private:
		ElementType data;
		DLNode* previous;
		DLNode* next;
		template<typename T>
		friend struct Double_Circle_LinkList;
		friend int main();
	public:
		DLNode()=default;
		DLNode(ElementType data):data(data)
		{
				
		}
		~DLNode()
		{
			cout<<"DLNode "<<data<<"was deleted!"<<endl;
		}	
};
 
template<typename T>
struct Double_Circle_LinkList
{
	private: 
		DLNode<T>* Head;
	public:
		Double_Circle_LinkList():Head(new DLNode<T>())
		{
			Head->next=Head;
			Head->previous=Head;
		}
		void Make_Empty()
		{
			DLNode<T>* p,*q;
			p=Head->next;
			while(p!=Head)
			{
				q=p;
				p=q->next;
				delete q;
			}
			Head->next=Head;
			Head->previous=Head;
		}
		DLNode<T>* Find_Kth(int k)
		{
			if(k<0)
			{
				cout<<"index is too small"<<endl;
				return nullptr;
			}
			int cnt=0;
			DLNode<T>* p=Head->next;
			while(p!=Head&&cnt!=k)
			{
				p=p->next;
				cnt++;
			}
			if(p==Head)
			{
				cout<<"index is too big"<<endl;
				return nullptr;
			}
			else
			{
				return p;
			}
		}
		DLNode<T>* Find(T X)
		{
			DLNode<T>* p=Head->next;
			while(p!=Head&&p->data!=X)
			{
				p=p->next;
			}
			if(p==Head)
			{
				return nullptr;
			}
			else
			{
				return p;
			}
		}
		void DLNode_back_insert_X(DLNode<T>* q,T X)
		{
			DLNode<T>* p=new DLNode<T>(X);
			p->next=q->next;
			p->previous=q;
			q->next->previous=p;
			q->next=p;
		}
		bool insert_index(T X,int i)
		{
			bool outcome;
			DLNode<T>* p,*q;
			if(i==0)
			{
				q=Head;
				//插入操作 
				DLNode_back_insert_X(q,X);
				outcome=true;
			}
			else
			{
				q=Find_Kth(i-1);
				if(q==nullptr)
				{
					outcome=false;
				}
				else
				{
					DLNode_back_insert_X(q,X);
					outcome=true;
				}
			}
			if(outcome)
			{
				cout<<"insert successfully"<<endl; 
			}
			else
			{
				cout<<"insert failed"<<endl;
			}
			return outcome;
		}
		bool delete_index(int i)
		{
			bool outcome;
			DLNode<T>* p,*q;
			if(i==0)     //要删除第0个元素，由于找不到前置元素，故需要做特殊考虑       
			{
				q=Head;
				p=q->next;
				if(p!=Head)      
				{
					q->next=p->next;
					p->next->previous=q;
					outcome=true;
				}
				else
				{
					outcome=false;
				}
			}
			else 
			{
				q=Find_Kth(i-1);
				if(q==nullptr)
				{
					outcome=false;
				}
				else      // //此时i>=1
				{
					p=q->next;
					if(p!=Head)     //第i个元素存在 
					{
						p->next->previous=q;
						q->next=p->next;	
						delete p;
						outcome=true;
					}
					else     //第i个元素刚好在尾结点后面一个单位 
					{
						outcome=false;
					}
				}
			}
			if(outcome)
			{
				cout<<"delete successfully!"<<endl;
			}
			else
			{
				cout<<"delete failed!"<<endl;
			}
			return outcome;
		}
		int get_length()
		{
			int length=0;
			DLNode<T>* p=Head->next;
			while(p!=Head)
			{
				p=p->next;
				length++;
			}
			return length;
		}
		void show()
		{
			DLNode<T>* p=Head->next;
			if(p==Head)
			{
				cout<<"linklist is empty!";
			}
			while(p!=Head)
			{
				cout<<p->data<<" ";
				p=p->next;
			}
			cout<<endl;
		}	
};
int main()
{
	Double_Circle_LinkList<double> ll;
	ll.insert_index(1.2,1);
	ll.show();
	ll.insert_index(1.4,0);
	ll.delete_index(1);
	ll.delete_index(0);
	ll.insert_index(2.4,0);
	
	ll.insert_index(3.6,1);
	cout<<ll.get_length()<<endl;
	ll.insert_index(4.8,2);
	cout<<"3.6 location:"<<ll.Find(3.6)->data<<endl;
	cout<<"3.6 location:previous:"<<ll.Find(3.6)->previous->data<<endl;
	cout<<"location 1 element:"<<ll.Find_Kth(1)->data<<endl;
	ll.show();
	ll.delete_index(1);
	cout<<"4.8 location:previous:"<<ll.Find(4.8)->previous->data<<endl;
	ll.show();
	ll.delete_index(0);
	ll.delete_index(0);
	ll.delete_index(0);
	ll.Make_Empty();
	return 0;
}

