import java.util.Scanner;

public class 判断成绩是否及格 {

	public static void main(String[] args) {
		final int standard=60;
		int grade;
		Scanner in=new Scanner(System.in);
		while(true)
		{
		System.out.print("请输入你的成绩:");
		grade=in.nextInt();
		System.out.println("你的成绩是"+grade);
		if(grade>=standard)
		{
			System.out.println("恭喜你通过了");
		}
		else
		{
			System.out.println("很遗憾你没有通过");
			System.out.println("再见");
		}
		}
	}

}
