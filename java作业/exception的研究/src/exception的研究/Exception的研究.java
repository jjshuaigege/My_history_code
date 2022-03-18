package exception的研究;


public class Exception的研究 {
	void f()
	{
		int[] a=new int[10];
		try {
			a[10]=98;
			System.out.println(a[10]);
			System.out.println("excuting try");
		}
		catch(NullPointerException e)
		{
			System.out.println("NPEcaught");
		}
	}
	void g()
	{
		f();
	}
	void h()
	{
		int i=10;
		if(i<100)
		{
			g();
		}
				
	}
	
	
	public static void main(String[] args) {
		Exception的研究 ey=new Exception的研究();
		try
		{
		try
		{
		ey.h();
		}
		catch(ArrayIndexOutOfBoundsException e1)
		{
			System.out.println("e1 Caught");
			e1.printStackTrace();
			System.out.println(e1.getMessage());
			System.out.println(e1);
			throw e1;   //异常被捕捉到，但是我们没有完全处理完，再次抛出这个异常
		}
		}
		catch(Exception e2)
		{
			System.out.println("e2 Caught");
		}
		System.out.println("program continue");

	}

}
