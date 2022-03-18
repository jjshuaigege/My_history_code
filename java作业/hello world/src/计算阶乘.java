import java.util.Scanner;

public class ¼ÆËã½×³Ë {

	public static void main(String[] args) {
		int n,i,sum;
		Scanner in=new Scanner(System.in);
		while(true)
		{
			sum=1;
			System.out.print("ÇëÊäÈën£º");
			n=in.nextInt();
			for(i=1;i<=n;i++)
			{
				sum*=i;
			}
			System.out.println(sum);
		}
	}

}
