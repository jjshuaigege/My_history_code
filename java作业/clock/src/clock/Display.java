package clock;

public class Display {
	private int limit=0;
	private int value=0;
	static int step=1;
	public Display(int limit,int value)
	{
		this.limit=limit;
		this.value=value;
	}
	public void increase()
	{
		value++;
		if(value==limit)
		{
			value=0;
		}
	}
	int get_value()
	{
		return value;
	}

	public static void main(String[] args) {
		System.out.println((Display.step));
		Display a=new Display(24,22);
		Display b=new Display(48,22);
//		for(;;)
//		{
////			hour.show_value();
//			hour.increase();
//		}
		//类中的变量加上static会变成类变量
		System.out.println(a.value);
		System.out.println(b.value);
		a.increase();
		System.out.println(a.value);
		System.out.println(b.value);
		System.out.println(a.step);
		System.out.println(b.step);
		b.step++;
		System.out.println(a.step);
		System.out.println(b.step);
		Display.step++;
		System.out.println(a.step);
		System.out.println(b.step);
		

	}

}
