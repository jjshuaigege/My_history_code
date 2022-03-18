import java.util.Scanner;

public class 字符串操作 {

	public static void main(String[] args) {
		String S1="shenguozhi是个帅哥,guozhishen是个帅哥";
		//遍历每一个字符
		for(int i=0;i<S1.length();i++)
		{
			System.out.println(S1.charAt(i));
		}
		//得到子串
		System.out.println(S1.substring(4));
		System.out.println(S1.lastIndexOf("zhi"));
		System.out.println(S1.replace("帅哥","靓仔"));
		
		//注意：所有的字符串都是不可变的
		
		//字符串的switch-case用法
		Scanner in=new Scanner(System.in);
		String A=in.next();
		switch(A)
		{
		case "this":System.out.println("这个");break;
		case "that":System.out.println("那个");break;
		}
		//Math库的使用
		System.out.println(Math.abs(-3.5));
		System.out.println(Math.round(-3.2));
		System.out.println(Math.random());
		System.out.println(Math.pow(4, 0.5));

	}

}
