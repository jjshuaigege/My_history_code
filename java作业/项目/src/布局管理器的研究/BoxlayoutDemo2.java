package ���ֹ��������о�;
import java.awt.*;
import javax.swing.*;

public class BoxlayoutDemo2 {
    public static void main(String[] args) {
        //����һ����ˮƽ���в��ֵ�����
        Box box1=Box.createHorizontalBox();
        //�������м�������ť
        box1.add(new Button("��ť1"));
        box1.add(new Button("��ť2"));
        //����һ���д�ֱ���в��ֵ�����
        Box box2=Box.createVerticalBox();
        //�������м�������ť
        box2.add(new Button("��ť3"));
        box2.add(new Button("��ť4"));

        Frame frame=new Frame("������ʾBOX����");
        frame.setLayout(new BoxLayout(frame,BoxLayout.Y_AXIS));
        frame.add(box1);
        frame.add(box2);
        frame.setVisible(true);
        frame.pack();

    }
}
