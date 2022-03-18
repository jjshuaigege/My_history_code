package ����������о�;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class DialogueDemo {
    public static void main(String[] args) {
        Frame frame=new Frame();
        Button B1=new Button("��ģʽ�Ի���");
        Button B2=new Button("�򿪷�ģʽ�Ի���");

        Dialog D1=new Dialog(frame,"ģʽ�Ի���",true);
        Dialog D2=new Dialog(frame,"��ģʽ�Ի���",false);
        D1.add(new TextArea("Hello world!",20,60),BorderLayout.CENTER);
        D1.add(new Button("ȷ��"),BorderLayout.SOUTH);


        D1.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {

            }

            @Override
            public void windowClosing(WindowEvent e) {
                D1.setVisible(false);
            }

            @Override
            public void windowClosed(WindowEvent e) {

            }

            @Override
            public void windowIconified(WindowEvent e) {

            }

            @Override
            public void windowDeiconified(WindowEvent e) {

            }

            @Override
            public void windowActivated(WindowEvent e) {

            }

            @Override
            public void windowDeactivated(WindowEvent e) {

            }
        });
        D2.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {

            }

            @Override
            public void windowClosing(WindowEvent e) {
                D2.setVisible(false);
            }

            @Override
            public void windowClosed(WindowEvent e) {

            }

            @Override
            public void windowIconified(WindowEvent e) {

            }

            @Override
            public void windowDeiconified(WindowEvent e) {

            }

            @Override
            public void windowActivated(WindowEvent e) {

            }

            @Override
            public void windowDeactivated(WindowEvent e) {

            }
        });

        //���öԻ���λ�úʹ�С
        D1.setBounds(300,300,200,100);
        D2.setBounds(350,350,200,100);

        ActionListener al=new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String command=e.getActionCommand();
                switch(command)
                {
                    case "��ģʽ�Ի���":D1.setVisible(true);System.out.println("B1������");break;
                    case "�򿪷�ģʽ�Ի���":D2.setVisible(true);System.out.println("B2������");break;
                }
            }
        };
        B1.addActionListener(al);
        B2.addActionListener(al);

        frame.setLayout(new BoxLayout (frame,BoxLayout.Y_AXIS));
        frame.add(B1);
        frame.add(B2);
        frame.pack();
        frame.setVisible(true);


    }
}
