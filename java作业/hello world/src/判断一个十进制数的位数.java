import java.util.Scanner;

public class �ж�һ��ʮ��������λ�� {
	static int judge_digit(int n)
	{
		int cnt=0;
		do
		{
			n=n/10;
			cnt++;
		}while(n>0);
		return cnt;
	}
	public static void main(String[] args) {
		int n;
		Scanner in=new Scanner(System.in);
		while(true)
		{
			System.out.print("������һ������");
			n=in.nextInt();
			System.out.println("������λ��Ϊ"+judge_digit(n));
			System.out.println("n="+n);
		}
	}

}
