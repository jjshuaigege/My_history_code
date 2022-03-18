import java.util.Scanner;
public class 猜数游戏 {

	public static void main(String[] args)
	{
		int n;
		int x;
		Scanner in=new Scanner(System.in);
		while(true)
		{
			n=(int)(Math.random()*100+1);
			System.out.println("我已经想好了一个0到99的整数");
			do
			{
				System.out.print("请输入你猜的数字：");
				x=in.nextInt();
				if(x>n)
				{
					System.out.println("你猜的数大了");
				}
				else if(x<n)
				{
					System.out.println("你猜的数小了");
				}
				else
				{
					System.out.println("恭喜你猜对了");
				}
			}while(x!=n);
			System.out.println("游戏结束");
		}

	}

}
