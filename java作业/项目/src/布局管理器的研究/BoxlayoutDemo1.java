package ���ֹ��������о�;
import javax.swing.*;
import java.awt.*;

public class BoxlayoutDemo1 {
    public static void main(String[] args) {
        Frame frame=new Frame();
        BoxLayout BL=new BoxLayout(frame,BoxLayout.Y_AXIS);
        frame.setLayout(BL);
        frame.add(new Button("��ť1"));
        frame.add(new Button("��ť2"));
        frame.pack();
        frame.setVisible(true);

    }
}
