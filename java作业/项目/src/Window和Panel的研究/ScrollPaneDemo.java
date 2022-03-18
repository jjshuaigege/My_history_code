package Window和Panel的研究;
import java.awt.*;

public class ScrollPaneDemo {

    public static void main(String[] args)
    {
        Frame frame=new Frame();
        ScrollPane SP=new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);

        SP.add(new TextField("这是个测试文本"));
        SP.add(new Button("这是个测试按钮"));
        frame.add(SP);


        frame.setResizable(false);
        frame.setBounds(100,100,800,600);
        frame.setTitle("这里演示ScrollPaneDemo");
        frame.setVisible(true);
    }
}
