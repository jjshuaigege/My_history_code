import java.util.Scanner;
public class ������Ϸ {

	public static void main(String[] args)
	{
		int n;
		int x;
		Scanner in=new Scanner(System.in);
		while(true)
		{
			n=(int)(Math.random()*100+1);
			System.out.println("���Ѿ������һ��0��99������");
			do
			{
				System.out.print("��������µ����֣�");
				x=in.nextInt();
				if(x>n)
				{
					System.out.println("��µ�������");
				}
				else if(x<n)
				{
					System.out.println("��µ���С��");
				}
				else
				{
					System.out.println("��ϲ��¶���");
				}
			}while(x!=n);
			System.out.println("��Ϸ����");
		}

	}

}
