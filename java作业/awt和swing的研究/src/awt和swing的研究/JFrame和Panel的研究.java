package awt和swing的研究;
import java.awt.*;

public class JFrame和Panel的研究 {
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//创建一个window对象（Frame继承自window）
		Frame myframe=new Frame();
		//创建一个panel对象
		Panel panel=new Panel();
		//创建一个文本框和一个按钮，并且把他们放入到panel容器中
		panel.add(new TextF);
		panel.add(new Button("这里是一个测试按钮"));
		//把panel放入到window中
		myframe.add(panel);
		//设置window的位置及大小
		myframe.setBounds(100,100,500,300);
		//设置window可见
		myframe.setVisible(true);
		//设置Frame窗口可关闭
		System.out.println("搞什么鬼");

	}

}
