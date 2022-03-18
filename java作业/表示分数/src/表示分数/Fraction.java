package 表示分数;

import java.util.Scanner;

public class Fraction {
	private int a;
	private int b;
//	private double n;
//	double toDouble()
//	{
//		double n;
//		n=1.0*a/b;
//		return n;
//	}
//	Fraction(int a,int b,double n)
//	{
//		this.a=a;
//		this.b=b;
//	}
	Fraction(int a,int b)
	{
		this.a=a;
		this.b=b;
	}
	Fraction plus(Fraction r)
	{
		int a;int b;int cn;
		b=r.b*this.b;
		a=r.a*this.b+r.b*this.a;
		cn=common_num(a,b);
		b=b/cn;
		a=a/cn;
		return new Fraction(a,b);
	}
	Fraction multiply(Fraction r)
	{
		int a;int b;int cn;
		a=this.a*r.a;
		b=this.b*r.b;
		cn=common_num(a,b);
		a=a/cn;
		b=b/cn;
		return new Fraction(a,b);
	}
	void print()
	{
		int cn=common_num(a,b);
		a=a/cn;
		b=b/cn;
		if(a==1&&b==1)
		{
			System.out.println("1");
		}
		else
		{
			System.out.println(a+"/"+b);
		}
	}

	//找最大公约数
	int common_num(int a,int b)
	{
		int divisor=b;
		int dividend=a;
		int ret;
		do
		{
			ret=divisor%dividend;
			divisor=dividend;
			dividend=ret;
		}while(ret!=0);
		return divisor;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		Fraction a = new Fraction(in.nextInt(), in.nextInt());

		Fraction b = new Fraction(in.nextInt(),in.nextInt());

		a.print();

		b.print();

		a.plus(b).print();

		a.multiply(b).plus(new Fraction(5,6)).print();

		a.print();

		b.print();

		in.close();

	}

}
