
public class 函数的行参和实参 {
	//参数类型自动转化
	public static double add(double a,int b)
	{
		return a+b;
	}
	//形参和实参
	public static void swap1(int[] a)
	{
		int temp=a[1];
		a[1]=a[0];
		a[0]=temp;
	}
	public static void change_string(String s)
	{
		
		s="changed";
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(add(10,23));
		int[] a= {0,1};
		swap1(a);
		for(int i:a)
		{
			System.out.println(i);
		}
		String s="befor change";
		change_string(s);
		System.out.println(s);
		
	}

}
