import java.util.Scanner;
public class 找零 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in); 
		System.out.print("请输入价格：");
		int price=in.nextInt();
		System.out.print("请输入面值：");
		int amount=in.nextInt();
		in.close();
		System.out.println(amount+"-"+price+"="+(amount-price));
	}

}
