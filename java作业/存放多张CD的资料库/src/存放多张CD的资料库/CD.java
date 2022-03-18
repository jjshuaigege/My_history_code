package 存放多张CD的资料库;

public class CD extends Item{
	private String title;
	private String comment;
	public String artist;
	private int numofTracks;
	private int playingtime;
	private boolean gotIt=false;
	public CD(String title, String comment, String artist, int numofTracks, int playingtime) {
		super(comment,title);
		this.artist = artist;
		this.numofTracks = numofTracks;
		this.playingtime = playingtime;
	}
	
	public void print() {
		System.out.println("CD:"+title+":"+artist);
	}
	public void special_print()
	{
		System.out.println("You are special");
	}
	
	@Override
	public String toString() {
		return "CD [title=" + title + ", comment=" + comment + ", artist=" + artist + ", numofTracks=" + numofTracks
				+ ", playingtime=" + playingtime + ", gotIt=" + gotIt + ", toString()=" + super.toString() + "]";
	}
	

	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		CD cc=(CD)obj;
		return this.artist.equals(cc.artist);
	}

	public static void main(String[] args) {
		CD cd1=new CD("a","b","c",10,20);
		CD cd2=new CD("a","b","c",10,20);
		System.out.println(cd1.equals(cd2));
 
	}



}
