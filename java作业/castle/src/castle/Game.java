package castle;

import java.util.HashMap;
import java.util.Scanner;

public class Game {
    private Room currentRoom;
    private HashMap<String,Handler> handlers=new HashMap<String,Handler>();
    public Game() 
    {
    	handlers.put("bye", new HandlerBye());
    	handlers.put("help", new HandlerHelp());
    	handlers.put("go", new HandlerGo());
        createRooms();
    }

    public void showprompt()
    {
    	System.out.println(currentRoom.Room_Exit_Desc());
    }
    private void createRooms()
    {
        Room outside, lobby, pub, study, bedroom;
      
        //	制造房间
        outside = new Room("城堡外");
        lobby = new Room("大堂");
        pub = new Room("小酒吧");
        study = new Room("书房");
        bedroom = new Room("卧室");
        
        //	初始化房间的出口
        outside.setExits("east",lobby);
        outside.setExits("south",study);
        outside.setExits("west",pub);
        lobby.setExits("west",outside);
        pub.setExits("east",outside);
        study.setExits("north",outside);
        study.setExits("east",bedroom);
        study.setExits("down", lobby);
        bedroom.setExits("west",study);
//      outside.setExits(null, lobby, study, pub);
//      lobby.setExits(null, null, null, outside);
//      pub.setExits(null, outside, null, null);
//      study.setExits(outside, bedroom, null, null);
//      bedroom.setExits(null, null, null, study);

        currentRoom = outside;  //	从城堡门外开始
    }

    private void printWelcome() {
        System.out.println();
        System.out.println("欢迎来到城堡！");
        System.out.println("这是一个超级无聊的游戏。");
        System.out.println("如果需要帮助，请输入 'help' 。");
        System.out.println();
        System.out.println("现在你在" + currentRoom);
        System.out.print("出口有：");
        showprompt();
    }

    // 以下为用户命令

//    public void printHelp() 
//    {
//        System.out.print("迷路了吗？你可以做的命令有：go bye help");
//        System.out.println("如：\tgo east");
//    }

    public void goRoom(String direction) 
    {
        Room nextRoom = currentRoom.Go_Other_Room(direction);

        if (nextRoom == null) {
            System.out.println("那里没有门！");
        }
        else {
            currentRoom = nextRoom;
            System.out.println("你在" + currentRoom);
            System.out.print("出口有: ");
            showprompt();
        }
    }
	public void play()
	{
		Scanner in = new Scanner(System.in);
		while ( true ) { 
    		String line = in.nextLine();
    		String[] words = line.split(" ");
    		Handler handler=handlers.get(words[0]);
    		String value="";
    		if(words.length>1)
    		{
    			value=words[1];
    		}
    		
    		if(handler!=null)
    		{
    			handler.doCmd(this,value);
    			if(handler.isbye())
    			{
    				break;
    			}
    		}
//    		if ( words[0].equals("help") ) {
//    			printHelp();
//    		} else if (words[0].equals("go") ) {
//    			goRoom(words[1]);
//    		} else if ( words[0].equals("bye") ) {
//    			break;
//    		}
    }
		in.close();
	}
	public static void main(String[] args) {
		Game game = new Game();
		game.printWelcome();
		game.play();
		System.out.println("感谢您的光临。再见！");
        }
        

}
