package castle;

public class HandlerGo extends Handler {
	public void doCmd(Game game,String word) {
		game.goRoom(word);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
