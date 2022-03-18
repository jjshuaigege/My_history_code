package Window和Panel的研究;
import java.awt.*;

public class Window和Panel的研究 {


    public static void main(String[] args) {
        // TODO Auto-generated method stub

        //创建一个window对象（Frame继承自window）
        Frame my_frame=new Frame();
        Frame sec_frame=new Frame();
        //创建一个panel对象
        Panel panel1=new Panel();
        Panel panel2=new Panel();
        //创建一个文本框和一个按钮，并且把他们放入到panel容器中
        panel1.add(new TextField("这里是一个测试文本"));
        panel1.add(new Button("这里是一个测试按钮"));
        panel2.add(new TextField("这里是一个测试文本"));
        panel2.add(new Button("这里是一个测试按钮"));
        //把panel放入到window中
        my_frame.add(panel1);
        sec_frame.add(panel1);
        //设置window的位置及大小
        my_frame.setBounds(100,100,500,300);
        sec_frame.setBounds(200,200,800,600);
        //设置window可见
        my_frame.setVisible(true);
        sec_frame.setVisible(true);
        //设置Frame窗口可关闭

    }

}
