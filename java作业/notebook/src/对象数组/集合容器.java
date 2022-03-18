package 对象数组;
import java.util.ArrayList;
import java.util.HashSet;
public class 集合容器 {
	static ArrayList<String> C2=new ArrayList<String>();
	static HashSet<String> C1=new HashSet<String>();
	public String toString()
	{
		return "hi";
	}
	
//		public double toDouble()
//		{
//			return 1.0;
//		}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		C1.add("hello");
//		C1.add("world");
//		C1.add("hello");
//		for(String s:C1)
//		{
//			System.out.println(s);
//		}
//		C2.add("hello");
//		C2.add("world");
//		C2.add("hello");
//		for(String s:C2)
//		{
//			System.out.println(s);
//		}
		集合容器 c3=new 集合容器();
		System.out.println(c3);  //System.out.println会主动调用每个对象的toString函数

	}

}
