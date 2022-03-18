package 布局管理器的研究;
import java.awt.*;
import javax.swing.*;

public class BoxlayoutDemo2 {
    public static void main(String[] args) {
        //创建一个有水平排列布局的容器
        Box box1=Box.createHorizontalBox();
        //往容器中加两个按钮
        box1.add(new Button("按钮1"));
        box1.add(new Button("按钮2"));
        //创建一个有垂直排列布局的容器
        Box box2=Box.createVerticalBox();
        //往容器中加两个按钮
        box2.add(new Button("按钮3"));
        box2.add(new Button("按钮4"));

        Frame frame=new Frame("这里演示BOX容器");
        frame.setLayout(new BoxLayout(frame,BoxLayout.Y_AXIS));
        frame.add(box1);
        frame.add(box2);
        frame.setVisible(true);
        frame.pack();

    }
}
