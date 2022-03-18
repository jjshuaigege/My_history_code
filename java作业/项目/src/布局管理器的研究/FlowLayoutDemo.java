package 布局管理器的研究;
import java.awt.*;

public class FlowLayoutDemo {
    public static void main(String[] args)
    {
        Frame frame=new Frame("这里测试FlowLayOut");
        frame.setLayout(new FlowLayout(FlowLayout.CENTER,20,20));
        for(int i=1;i<=99;i++)
        {
            frame.add(new Button("按钮"+i));
        }
        frame.pack();
        frame.setVisible(true);

    }
}
