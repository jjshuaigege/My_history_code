package 存放多张CD的资料库;

import java.util.ArrayList;

public class Database {
//	private ArrayList<CD> listCD=new ArrayList<CD>();
//	private ArrayList<DVD> listDVD=new ArrayList<DVD>();
	private ArrayList<Item> listItem=new ArrayList<Item>();
	
//	public void add(CD cd)
//	{
//		listCD.add(cd);
//	}
//	public void add(DVD dvd)
//	{
//		listDVD.add(dvd);
//	}
	public void add(Item item)
	{
		listItem.add(item);
	}
	
//	public void list()
//	{
//		for(CD cd:listCD)
//		{
//			cd.print();
//		}
//		for(DVD dvd:listDVD )
//		{
//			dvd.print();
//		}
//	}
	public void list()
	{
		for(Item item:listItem)
		{
			item=(Item)item;
			item.print();
		}
	}
	public static void main(String[] args) {
//		Database db=new Database();
//		
//		db.add(new CD("标题1","一些评论1","作者1",10,100));
//		db.add(new CD("标题2","一些评论2","作者2",20,200));
//		db.add(new DVD("标题3","一些评论3","导演3",300));
//		db.list();
		CD cd1=new CD("d","d","d",9,4);
		Item item1=new Item("d","d");
		Item item2=new Item("d","d");
		Item item3=cd1;
		CD cd2=(CD)item3;
		System.out.println(cd2.artist);
		cd2.special_print();
		
		
	}

}
