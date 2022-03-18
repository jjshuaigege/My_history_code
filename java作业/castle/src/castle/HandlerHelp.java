package castle;

public class HandlerHelp extends Handler {
	public void doCmd(Game game,String word) {
		System.out.print("迷路了吗？你可以做的命令有：go bye help");
        System.out.println("如：\tgo east");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
