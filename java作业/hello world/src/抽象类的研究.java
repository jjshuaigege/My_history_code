public abstract class 抽象类的研究 {
	int i=30;
	//抽象类可以没有抽象函数（一般都有），有抽象函数的类一定是抽象类,抽象类的其他特性与一般的类一样
	abstract void print(String s);
	void print1()
	{
		System.out.println("hello");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		抽象类的研究 c=new 抽象类的研究() {
			@Override
			void print(String s) {
				System.out.println(s);
			}
		};
		c.print1();

	}

}