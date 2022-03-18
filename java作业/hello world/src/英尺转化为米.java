import java.util.Scanner;

public class 英尺转化为米 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int foot=in.nextInt();
//		double inch=in.nextInt();
		double inch=in.nextDouble();
		System.out.println((foot+inch/12)*0.3048+"米");
		double b=1.44;
		int c=(int)b;
		System.out.println(b);
		System.out.println(c);
	}

}
