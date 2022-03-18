package exception的研究;
class Myexception extends Throwable{
	
}

public class 主动设置并抛出异常 {
	static void f()  throws Exception,Myexception
	{
		int i=10;
		if(i<20)
		{
			throw new Myexception();
		}
	}

	public static void main(String[] args){
		// TODO Auto-generated method stub
		
		try {
			f();
		} catch (Exception e) {
			System.out.println("caught in first");
		} catch (Myexception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
