package 基本组件的研究;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class DialogueDemo {
    public static void main(String[] args) {
        Frame frame=new Frame();
        Button B1=new Button("打开模式对话框");
        Button B2=new Button("打开非模式对话框");

        Dialog D1=new Dialog(frame,"模式对话框",true);
        Dialog D2=new Dialog(frame,"非模式对话框",false);
        D1.add(new TextArea("Hello world!",20,60),BorderLayout.CENTER);
        D1.add(new Button("确认"),BorderLayout.SOUTH);


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

        //设置对话框位置和大小
        D1.setBounds(300,300,200,100);
        D2.setBounds(350,350,200,100);

        ActionListener al=new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String command=e.getActionCommand();
                switch(command)
                {
                    case "打开模式对话框":D1.setVisible(true);System.out.println("B1被按下");break;
                    case "打开非模式对话框":D2.setVisible(true);System.out.println("B2被按下");break;
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
