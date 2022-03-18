import java.util.Scanner;

public class 自动售票机简化版 {

	public static void main(String[] args)
	{
		while(true)
		{
		System.out.print("请输入金额：");
		Scanner in=new Scanner(System.in);
		int amount=in.nextInt();
		System.out.println("****************");
		System.out.println("*Java城国际铁路专线*");
		System.out.println("*   无指定座位票   *");
		System.out.println("*     票价10元     *");
		System.out.println("****************");
		if(amount>=10)
		System.out.println("找零："+(amount-10)+"元");
		else 
		System.out.println("金额不足");
		}

	}
}
