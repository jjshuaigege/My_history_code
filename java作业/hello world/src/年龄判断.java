import java.util.Scanner;

public class 年龄判断 {

	public static void main(String[] args) {
		final int limit=35;
		Scanner in=new Scanner(System.in);
		System.out.print("请输入你的年龄:");
		int age=in.nextInt();
		if(age<=limit)
		{
			System.out.println("年轻是美好的");
		}
		System.out.println("年龄决定了你的精神世界，好好珍惜吧");
	}

}
