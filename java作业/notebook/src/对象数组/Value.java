package ��������;

import java.util.ArrayList;

public class Value {
	private int value;
	public static ArrayList<String> notes=new ArrayList<String>();
	public void set_value(int value)
	{
		this.value=value;
	}
	public int get_value()
	{
		return value;
	}

	public static void main(String[] args) {
		System.out.println("����int����");
		int[] b=new int[10];
		for(int i=0;i<b.length;i++)
		{
			b[i]=i;
		}
		for(int i:b)
		{
			System.out.println(i);
		}
		for(int i:b)
		{
			i=0;
		}
		for(int i:b)
		{
			System.out.println(i);
		}
		System.out.println("���ڶ�������");
		Value[] a=new Value[10];
		for(int i=0;i<a.length;i++)
		{
			a[i]=new Value();
			a[i].set_value(i);
		}
		for(Value v:a)
		{
			System.out.println(v.get_value());
		}
		for(Value v:a)
		{
			v.set_value(0);
		}
		for(Value v:a)
		{
			System.out.println(v.get_value());
		}
		//˳��������for eachѭ����Ӧ��
		System.out.println("����˳������");
		notes.add("hello");
		notes.add("first");
		notes.add("two");
		notes.add("third");
		for(String s:notes)
		{
			System.out.println(s);
		}
		for(String s:notes)
		{
			s="hi!";
		}
		for(String s:notes)
		{
			System.out.println(s);
		}
	}

}
