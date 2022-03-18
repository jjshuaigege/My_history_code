
public class 异常 {
	static class myThread extends Thread
	{
		@Override
		public void run()
		{
			System.out.println("Hello");
		}
	}
	static int divide (int a,int b)
	{
		myThread thread0=new myThread();
		thread0.start();
		try {
			thread0.sleep(10);
		} 
		return a/b;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try
		{
			System.out.println(divide(3,0));
		}
		catch(ArithmeticException e)
		{
			System.out.println("divisor is zero");
		}
		catch(InterruptedException e)
		{
			System.out.println("interrupted");
		}
	}

}
