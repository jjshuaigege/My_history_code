import java.util.Scanner;

public class 凑钱 {

	public static void main(String[] args) {
		int one,five,ten,twenty;
		int amount;
		Scanner in=new Scanner(System.in);
		amount=in.nextInt();
		int isbreak=0;
		out:
		for(one=0;one<=amount;one++)
		{
			for(five=0;five<=amount/5;five++)
			{
				for(ten=0;ten<=amount/10;ten++)
				{
					for(twenty=0;twenty<=amount/20;twenty++)                      
					{
						if(one+five*5+ten*10+twenty*20==amount)
						{
							System.out.println(one+"个1元"+five+"个5元"+ten+"个10元"+twenty+"个20元"+"可组成"+amount+"元");
							break;
						}
					}
					
				}
			}
		}
		System.out.println("结束");
	}

}
