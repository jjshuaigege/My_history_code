package �˵�������;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class PopMenuDemo {
    public static void main(String[] args) {

        //�������
        MenuItem M1=new MenuItem("ע��");
        MenuItem M2=new MenuItem("ȡ��ע��");
        MenuItem M3=new MenuItem("����");
        MenuItem M4=new MenuItem("����");
        PopupMenu PM=new PopupMenu("�ҵĵ����˵�");
        Panel panel=new Panel();
        TextArea TF=new TextArea(5,30);
        Box box=new Box(BoxLayout.Y_AXIS);
        Frame frame=new Frame();

        //��װ
        PM.add(M1);
        PM.add(M2);
        PM.add(M3);
        PM.add(M4);
        panel.add(PM);
        box.add(TF);
        box.add(panel);
        frame.add(box);

        //��β
        panel.setPreferredSize(new Dimension(400,300));       //�˴�ע�⣡��
        frame.pack();
        frame.setVisible(true);

        //����¼�����
        panel.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {

            }

            @Override
            public void mousePressed(MouseEvent e) {

            }

            @Override
            public void mouseReleased(MouseEvent e) {
                if(e.isPopupTrigger())
                {
                    //��ʾpopupmenu
                    PM.show(panel,e.getX(),e.getY());
                }

            }

            @Override
            public void mouseEntered(MouseEvent e) {

            }

            @Override
            public void mouseExited(MouseEvent e) {

            }
        });


    }
}
