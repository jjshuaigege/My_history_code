
public class 内部类的研究 {

	private int i=98;
	class Newclass{
		int ii=10;
		double b=10.0;
		void print()
		{
			System.out.println(i);
		}
	}
	Newclass nc=new Newclass();
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		

		内部类的研究 nbc=new 内部类的研究();
		nbc.nc.print();
		

	}

}
