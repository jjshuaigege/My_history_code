import java.util.Scanner;

public class �ж����� {
	static boolean judge_prime(int n)
	{
		//�ȼٶ�ĳ������������Ȼ���жϸ����ܲ��ܱ�1������֮���������
		boolean isprime=true;
		//�����ж��ǲ���2�����ż��
		if(n%2==0&&n!=2)
		{
			isprime=false;
		}
		else
		{
			//����2��������ֻ���3��ʼ��֤ĳ���������������ָ�����ѧ��ʽ��ֻ����֤��n��1/2�η�
			for(int i=3;i<=Math.sqrt(n);i+=2)
			{
				if(n%i==0)
				{
					isprime=false;
					break;
				}
			}
		}
		//��������֤��ĳ�����������������п�����
		return isprime;
	}
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n;
		while(true)
		{
			System.out.print("�����뽫Ҫ���жϵ�����");
			n=in.nextInt();
			if(judge_prime(n))
			{
				System.out.println("������");
			}
			else
			{
				System.out.println("��������");
			}
		}

	}

}
