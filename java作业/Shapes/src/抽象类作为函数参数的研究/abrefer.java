package 抽象类作为函数参数的研究;

public class abrefer {
	public void printinum(ab a)
	{
		a.print();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		abinher abi=new abinher();
		ab test=null;
		abrefer abr=new abrefer();
		abr.printinum(abi);
		abr.printinum(test);
		abr.printinum(abi);
		

	}

}
