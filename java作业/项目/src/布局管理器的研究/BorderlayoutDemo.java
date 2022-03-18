package 布局管理器的研究;
import java.awt.*;

public class BorderlayoutDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("这里测试BorderLayout");
        frame.setLayout(new BorderLayout(30,10));
        frame.add(new Button("北侧按钮"), BorderLayout.NORTH);
        frame.add(new TextField("南侧文本区"),BorderLayout.SOUTH);
        frame.add(new Button("东侧按钮"), BorderLayout.EAST);
        frame.add(new Button("西侧按钮"), BorderLayout.WEST);
        frame.add(new Button("中间按钮"), BorderLayout.CENTER);

        Frame frame1=new Frame("这里测试BorderLayout");
        frame1.setLayout(new BorderLayout(30,10));
        frame1.add(new Button("北侧按钮"), BorderLayout.NORTH);
        frame1.add(new TextField("南侧文本区"),BorderLayout.SOUTH);
        frame1.add(new Button("东侧按钮"), BorderLayout.EAST);
        frame1.add(new Button("西侧按钮"), BorderLayout.WEST);
        Panel panel=new Panel();
        panel.add(new Button("按钮1"));
        panel.add(new TextField("文本区1"));
        frame1.add(panel, BorderLayout.CENTER);


        frame1.pack();
        frame1.setVisible(true);
        frame.pack();
        frame.setVisible(true);

    }
}
