#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define nsize 9
class Queen_Problem
{
	public:
		int n;
		const char Dy[8]={-1,0,1,-1,1,-1,0,1};
		const char Dx[8]={-1,-1,-1,0,0,1,1,1};
		vector<vector<bool> > attack;
		vector<vector<string> >solve;
		vector<string> Queen;
	public:
		Queen_Problem(int n):n(n)
		{
			for(int i=0;i<n;++i)
			{
				attack.push_back(vector<bool>());
				for(int j=0;j<n;++j)
				{
					attack[i].push_back(0);
				}
				Queen.push_back("");
				Queen[i].append(n,'.');
			}
		}
		void put_Queen(int x,int y)
		{
			for(int i=1;i<n;++i)
			{
				for(int j=0;j<8;++j)
				{
					if(x+Dx[j]*i<n&&x+Dx[j]*i>=0&&y+Dy[j]*i<n&&y+Dy[j]*i>=0)
					{
						attack[x+Dx[j]*i][y+Dy[j]*i]=1;	
					}
				}
			}	
		}
		vector<vector<string> > solve_problem(int k)                      //k�����k��
		{
			if(k==n)     //�������� 
			{
				solve.push_back(Queen);
			}
			else
			{
				for(int i=0;i<n;++i)        //����ö��
				{
					if(attack[k][i]==0)
					{
						vector<vector<bool> > temp=attack;
						//�����ǳ��Բ��������Բ�ͨ�ͻ��ݣ� 
						put_Queen(k,i);
						Queen[k][i]='Q';
						//�ݹ� 
						solve_problem(k+1);
						//�����ǻ��ݲ��� 
						attack=temp;
						Queen[k][i]='.';	
					}
				}	
			}
			return solve;	
		}	
};
int main()
{
	Queen_Problem bahuanghou(nsize);
	cout<<sizeof(bahuanghou)<<endl;
	vector<vector<string> > outcome=bahuanghou.solve_problem(0);
	cout<<outcome.size()<<endl;
	for(int i=0;i<outcome.size();++i)
	{
		cout<<"�ⷨ"<<i+1<<":"<<endl; 
		for(int j=0;j<nsize;++j)
		{
			cout<<outcome[i][j]<<endl;	
		}
	}
	
	return 0;
}

