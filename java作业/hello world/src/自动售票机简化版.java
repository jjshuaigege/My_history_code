import java.util.Scanner;

public class �Զ���Ʊ���򻯰� {

	public static void main(String[] args)
	{
		while(true)
		{
		System.out.print("�������");
		Scanner in=new Scanner(System.in);
		int amount=in.nextInt();
		System.out.println("****************");
		System.out.println("*Java�ǹ�����·ר��*");
		System.out.println("*   ��ָ����λƱ   *");
		System.out.println("*     Ʊ��10Ԫ     *");
		System.out.println("****************");
		if(amount>=10)
		System.out.println("���㣺"+(amount-10)+"Ԫ");
		else 
		System.out.println("����");
		}

	}
}
