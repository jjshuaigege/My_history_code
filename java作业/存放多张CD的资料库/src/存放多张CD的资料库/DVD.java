package 存放多张CD的资料库;
import java.util.ArrayList;
import 存放多张CD的资料库.Item;
public class DVD extends Item{
	private String title;
//	private String comment;
	private String director;
	private int playingTime;
	private boolean gotIt=false;
	
//构造的运行顺序:父类的定义，父类的构造，子类的定义，子类的构造
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
