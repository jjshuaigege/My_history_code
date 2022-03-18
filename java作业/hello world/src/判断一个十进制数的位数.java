import java.util.Scanner;

public class 判断一个十进制数的位数 {
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
			System.out.print("请输入一个数：");
			n=in.nextInt();
			System.out.println("该数的位数为"+judge_digit(n));
			System.out.println("n="+n);
		}
	}

}
