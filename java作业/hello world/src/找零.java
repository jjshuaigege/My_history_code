import java.util.Scanner;
public class ���� {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in); 
		System.out.print("������۸�");
		int price=in.nextInt();
		System.out.print("��������ֵ��");
		int amount=in.nextInt();
		in.close();
		System.out.println(amount+"-"+price+"="+(amount-price));
	}

}
