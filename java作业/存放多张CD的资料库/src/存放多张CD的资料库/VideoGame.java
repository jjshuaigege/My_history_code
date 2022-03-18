package 存放多张CD的资料库;

public class VideoGame extends Item {
	private int numofplayers;
	
	public VideoGame(String comment, String title, int numofplayers) {
		super(comment, title);
		this.numofplayers = numofplayers;
	}

	public static void main(String[] args) {
		

	}

}
