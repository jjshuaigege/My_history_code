package Window��Panel���о�;
import java.awt.*;

public class ScrollPaneDemo {

    public static void main(String[] args)
    {
        Frame frame=new Frame();
        ScrollPane SP=new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);

        SP.add(new TextField("���Ǹ������ı�"));
        SP.add(new Button("���Ǹ����԰�ť"));
        frame.add(SP);


        frame.setResizable(false);
        frame.setBounds(100,100,800,600);
        frame.setTitle("������ʾScrollPaneDemo");
        frame.setVisible(true);
    }
}
