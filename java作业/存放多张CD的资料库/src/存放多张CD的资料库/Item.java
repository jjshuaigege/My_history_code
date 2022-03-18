package 存放多张CD的资料库;

public class Item {
	protected String title;
	protected String comment="hi";
	public Item(String comment,String title)
	{
		this.comment=comment;
		this.title=title;
	}
	public void print()
	{
		System.out.println("Item");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
