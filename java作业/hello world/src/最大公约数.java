import java.util.Scanner;

public class ���Լ�� {
	//�����Լ��
	static int find_commonfac(int n1,int n2)
	{
//		int divisor,dividend;
//		if(n1>n2)
//		{
//			divisor=n1;
//			dividend=n2;
//		}
//		else
//		{
//			divisor=n2;
//			dividend=n1;
//		}
		int temp;
		do
		{
			temp=n1%n2;
			n1=n2;
			n2=temp;
		}while(temp!=0);
		return n1;
	}

	public static void main(String[] args) {
		int n1,n2;
		Scanner in=new Scanner(System.in);
		while(true)
		{
			System.out.println("��������������");
			n1=in.nextInt();
			n2=in.nextInt();
			System.out.printf("���Լ��Ϊ%d\n",find_commonfac(n1,n2));
		}
	}

}
