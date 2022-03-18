package 布局管理器的研究;
import java.awt.*;

public class GridLayoutDemo {
    public static void main(String[] args) {
        Frame frame=new Frame();
        frame.setLayout(new GridLayout(4,5,20,20));    //每个网格装一个容器!
        for(int i=1;i<=10;i++)
        frame.add(new Button("这是一个按钮"+i));
        Panel panel=new Panel();
        panel.add(new Button("这是一个按钮A"));
        panel.add(new Button("这是一个按钮B"));
        frame.add(panel);

        frame.pack();
        frame.setVisible(true);

    }
}
