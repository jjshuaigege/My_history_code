import java.util.Scanner;

public class ����׳� {

	public static void main(String[] args) {
		int n,i,sum;
		Scanner in=new Scanner(System.in);
		while(true)
		{
			sum=1;
			System.out.print("������n��");
			n=in.nextInt();
			for(i=1;i<=n;i++)
			{
				sum*=i;
			}
			System.out.println(sum);
		}
	}

}
