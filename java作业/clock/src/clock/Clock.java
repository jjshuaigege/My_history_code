package clock;

public class Clock {
	Display hour;
	Display minute;
	Display second;
	public Clock(int hour, int minute, int second)
	{
		this.hour=new Display(24,hour);
		this.minute=new Display(60,minute);
		this.second=new Display(60,second);
	}

//	clock(int limit1,int limit2,int value1,int value2)
//	{
//		hour=new Display(limit1,value1);
//		minute=new Display(limit2,value2);
//	}
	public void tick()
	{
		int num1,num2;
		while(true)
		{
		System.out.printf("%02d:%02d:%02d\n",hour.get_value(),minute.get_value(),second.get_value());
		num1=second.get_value();
		if(num1==59)
		{
			num2=minute.get_value();
			if(num2==59)
			{
				hour.increase();
			}
			minute.increase();
			
		}
		second.increase();
		num2=minute.get_value();
		}
	}
//	public String toString()
//	{
//		String A=String.format("%02d:%02d:%02d",hour.get_value(),minute.get_value(),second.get_value());
//		return A;
//	}
//	public void increase_h_m_connect()
//	{
//		int num;
//		for(int i=0;i<100;i++)
//		{
//			System.out.printf("%02d:%02d\n",hour.get_value(),minute.get_value());
//			num=minute.get_value();
//			if(num==59)
//			{
//				hour.increase();
//				
//			}
//			minute.increase();
//		}
//	}

	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);

		Clock clock = new Clock(in.nextInt(), in.nextInt(), in.nextInt());

		clock.tick();

//		System.out.println(clock);

		in.close();
	}

}
