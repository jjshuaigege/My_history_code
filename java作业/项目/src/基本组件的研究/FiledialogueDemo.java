package ����������о�;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FiledialogueDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("���Դ��ļ��Ի���");
        Button B1=new Button("���ļ�");
        Button B2=new Button("�����ļ�");
        frame.setLayout(new BoxLayout(frame,BoxLayout.Y_AXIS));
        frame.add(B1);
        frame.add(B2);
        FileDialog FD1=new FileDialog(frame,"���ļ��Ի���",0);
        FileDialog FD2=new FileDialog(frame,"���ļ��Ի���",1);
        B1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("B1������");
                FD1.setVisible(true);
                String directory=FD1.getDirectory();
                String filename=FD1.getFile();
                System.out.println("�򿪵��ļ�Ŀ¼Ϊ:"+directory);
                System.out.println("�򿪵��ļ���Ϊ:"+filename);
            }
        });
        B2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("B2������");
                FD2.setVisible(true);
                String directory=FD2.getDirectory();
                String filename=FD2.getFile();
                System.out.println("������ļ�Ŀ¼Ϊ:"+directory);
                System.out.println("������ļ���Ϊ:"+filename);
            }
        });

        frame.pack();
        frame.setVisible(true);

    }
}
