package ���ֹ��������о�;
import java.awt.*;

public class GridLayoutDemo {
    public static void main(String[] args) {
        Frame frame=new Frame();
        frame.setLayout(new GridLayout(4,5,20,20));    //ÿ������װһ������!
        for(int i=1;i<=10;i++)
        frame.add(new Button("����һ����ť"+i));
        Panel panel=new Panel();
        panel.add(new Button("����һ����ťA"));
        panel.add(new Button("����һ����ťB"));
        frame.add(panel);

        frame.pack();
        frame.setVisible(true);

    }
}
