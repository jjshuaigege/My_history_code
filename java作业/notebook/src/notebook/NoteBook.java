package notebook;

import java.util.ArrayList;

public class NoteBook {

	//顺序容器，ArrayList是容器类型，<Sting>是元素类型
	private ArrayList<String> notes=new ArrayList<String>();
	//添加记录
	public void add(String s)
	{
		notes.add(s);
	}
	//按索引插入指定位置（后面的记录顺着后移）
	public void add(int loc,String s)
	{
		notes.add(loc, s);
	}
	
	//得到有多少条记录
	public int getSize()
	{
		return notes.size();
	}
	//按索引找到某条记录
	public String getNote(int index)
	{
		return notes.get(index);
	}
	//按索引删除某条记录
	public void removeNote(int index)
	{
		notes.remove(index);
	}
	//列举出所有记录
	public String[] list()
	{
		String[] a=new String[notes.size()];
		notes.toArray(a);
		return a;
	}
	public static void main(String[] args) {
		String[] A=new String[2];
		A[0]="first";
		A[1]="second";
		NoteBook N=new NoteBook();
		N.add("hello1");
		N.add("hello2");
		N.add(1,"goodbye");
		N.add("finish");
//		N.removeNote(2);
		System.out.println(N.getNote(2));
		String[] a=N.list();
		for(String s:a)
		{
			System.out.println(s);
		}

	}

}
