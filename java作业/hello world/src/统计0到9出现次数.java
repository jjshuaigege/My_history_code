import java.util.Scanner;

public class 统计0到9出现次数 {

	public static void main(String[] args) {
		int[] numbers=new int[10];
		int x;
		for(int i=0;i<numbers.length;i++)
		{
			System.out.print(numbers[i]+" ");
		}
		System.out.println();
		System.out.print("请输入一串数字，输入-1表示结束：");
		Scanner in=new Scanner(System.in);
		x=in.nextInt();
		while(x!=-1)
		{
			if(x<=9&&x>=0)
			{
				numbers[x]++;
			}
			x=in.nextInt();
		}
		for(int i=0;i<numbers.length;i++)
		{
			System.out.println(i+":"+numbers[i]);
		}
	}

}
