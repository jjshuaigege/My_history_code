package ���ֹ��������о�;
import java.awt.*;

public class FlowLayoutDemo {
    public static void main(String[] args)
    {
        Frame frame=new Frame("�������FlowLayOut");
        frame.setLayout(new FlowLayout(FlowLayout.CENTER,20,20));
        for(int i=1;i<=99;i++)
        {
            frame.add(new Button("��ť"+i));
        }
        frame.pack();
        frame.setVisible(true);

    }
}
