package Graphics����о�;

import javax.swing.*;
import java.awt.*;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GraphicsDemo {
    private final String RECT_SHAPE="rect";
    private final String OVAL_SHAPE="oval";
    private String current_shape="";
    private Button btn_rect=new Button("���ƾ���");
    private Button btn_oval=new Button("������Բ");
    private Frame frame=new Frame("�������Graphics");
    private Box box=new Box(BoxLayout.X_AXIS);
    private class MyCanvas extends Canvas{
        @Override
        public void paint(Graphics g) {
            //���ƾ���
            if(current_shape.equals(RECT_SHAPE))
            {
                g.setColor(Color.RED);
                g.drawRect(100,100,200,120);
            }
            //������Բ
            else if(current_shape.equals(OVAL_SHAPE))
            {
                g.setColor(Color.RED);
                g.drawOval(100,100,200,120);
            }

        }
    }
    MyCanvas MC=new MyCanvas();
    public GraphicsDemo()
    {
        box.add(btn_rect);
        box.add(btn_oval);
        MC.setPreferredSize(new Dimension(400,400));
        frame.add(MC,BorderLayout.CENTER);
        frame.add(box,BorderLayout.SOUTH);

        btn_rect.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                current_shape=RECT_SHAPE;
                MC.repaint();
            }
        });
        btn_oval.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                current_shape=OVAL_SHAPE;
                MC.repaint();
            }
        });

        frame.pack();
        frame.setVisible(true);

    }

    public static void main(String[] args) {
        new GraphicsDemo();

    }
}
