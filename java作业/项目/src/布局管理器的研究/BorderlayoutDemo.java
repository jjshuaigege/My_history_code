package ���ֹ��������о�;
import java.awt.*;

public class BorderlayoutDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("�������BorderLayout");
        frame.setLayout(new BorderLayout(30,10));
        frame.add(new Button("���ఴť"), BorderLayout.NORTH);
        frame.add(new TextField("�ϲ��ı���"),BorderLayout.SOUTH);
        frame.add(new Button("���ఴť"), BorderLayout.EAST);
        frame.add(new Button("���ఴť"), BorderLayout.WEST);
        frame.add(new Button("�м䰴ť"), BorderLayout.CENTER);

        Frame frame1=new Frame("�������BorderLayout");
        frame1.setLayout(new BorderLayout(30,10));
        frame1.add(new Button("���ఴť"), BorderLayout.NORTH);
        frame1.add(new TextField("�ϲ��ı���"),BorderLayout.SOUTH);
        frame1.add(new Button("���ఴť"), BorderLayout.EAST);
        frame1.add(new Button("���ఴť"), BorderLayout.WEST);
        Panel panel=new Panel();
        panel.add(new Button("��ť1"));
        panel.add(new TextField("�ı���1"));
        frame1.add(panel, BorderLayout.CENTER);


        frame1.pack();
        frame1.setVisible(true);
        frame.pack();
        frame.setVisible(true);

    }
}
