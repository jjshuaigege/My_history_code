package notebook;

import java.util.ArrayList;

public class NoteBook {

	//˳��������ArrayList���������ͣ�<Sting>��Ԫ������
	private ArrayList<String> notes=new ArrayList<String>();
	//��Ӽ�¼
	public void add(String s)
	{
		notes.add(s);
	}
	//����������ָ��λ�ã�����ļ�¼˳�ź��ƣ�
	public void add(int loc,String s)
	{
		notes.add(loc, s);
	}
	
	//�õ��ж�������¼
	public int getSize()
	{
		return notes.size();
	}
	//�������ҵ�ĳ����¼
	public String getNote(int index)
	{
		return notes.get(index);
	}
	//������ɾ��ĳ����¼
	public void removeNote(int index)
	{
		notes.remove(index);
	}
	//�оٳ����м�¼
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
