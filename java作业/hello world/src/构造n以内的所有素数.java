
public class ����n���ڵ��������� {

	public static void main(String[] args) {
		boolean[] judge_prime=new boolean[101];//����100���ڵ�����
		judge_prime[0]=false;
		judge_prime[1]=false;
		for(int i=2;i<judge_prime.length;i++)
		{
			judge_prime[i]=true;
		}
		for(int x=2;x<=100;x++)
		{
			if(judge_prime[x]==true)
			{
				for(int i=2;i*x<=100;i++)
				{
					judge_prime[i*x]=false;
				}
			}
		}
		for(int i=0;i<101;i++)
		{
			if(judge_prime[i]==true)
			{
				System.out.print(i+" ");
			}
		}

	}

}
