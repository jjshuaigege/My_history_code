package ��Ŷ���CD�����Ͽ�;
import java.util.ArrayList;
import ��Ŷ���CD�����Ͽ�.Item;
public class DVD extends Item{
	private String title;
//	private String comment;
	private String director;
	private int playingTime;
	private boolean gotIt=false;
	
//���������˳��:����Ķ��壬����Ĺ��죬����Ķ��壬����Ĺ���
	public DVD(String title, String comment, String director, int playingTime) {
		super(comment,title);
		this.title = title;
		this.comment = comment;
		this.director = director;
		this.playingTime = playingTime;
	}
	public void print() {
		System.out.println("DVD:"+title+":"+director);
		print();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<DVD> xk=new ArrayList<DVD>();
		Item i1=new Item("itemx","titlex");
		xk.add(i1);
		DVD d=new DVD("a","b","c",10);
		d.print();

	}

}
