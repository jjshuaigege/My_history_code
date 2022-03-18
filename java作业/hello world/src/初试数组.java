import java.util.Scanner;

public class 初试数组 {

	public static void main(String[] args) {
		int x,cnt,sum,n;
		double average;
			Scanner in=new Scanner(System.in);
			System.out.print("请输入要输入的个数:");
			n=in.nextInt();
			int[] numbers=new int[n];
			cnt=0;
			sum=0;
			if(n>0)
			{
				System.out.print("请输入一串数字:");
				while(cnt<n)
				{
					x=in.nextInt();
					sum+=x;
					numbers[cnt]=x;
					cnt++;
				}
			}
			if(cnt>0)
			{
				average=sum*1.0/cnt;
				for(int i=0;i<numbers.length;i++)
				{
					if(numbers[i]>average)
					{
						System.out.print(numbers[i]+" ");
					}
				}
				System.out.println();
			}
			in.close();
		}

}
