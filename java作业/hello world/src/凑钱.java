import java.util.Scanner;

public class ��Ǯ {

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
							System.out.println(one+"��1Ԫ"+five+"��5Ԫ"+ten+"��10Ԫ"+twenty+"��20Ԫ"+"�����"+amount+"Ԫ");
							break;
						}
					}
					
				}
			}
		}
		System.out.println("����");
	}

}
