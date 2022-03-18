import java.util.Scanner;

public class 计算倒数的前n项和 {

	public static void main(String[] args) {
		double sum=0;
		int n;
		Scanner in=new Scanner(System.in);
		n=in.nextInt();
		int sign=1;
		for(int i=1;i<=n;i++)
		{
			sum+=sign*1.0/i;
			sign=-sign;
		}
		System.out.printf("%.2f",sum);
	}

}
