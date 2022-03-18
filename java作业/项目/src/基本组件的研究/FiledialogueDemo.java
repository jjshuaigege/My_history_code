package 基本组件的研究;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FiledialogueDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("测试打开文件对话框");
        Button B1=new Button("打开文件");
        Button B2=new Button("保存文件");
        frame.setLayout(new BoxLayout(frame,BoxLayout.Y_AXIS));
        frame.add(B1);
        frame.add(B2);
        FileDialog FD1=new FileDialog(frame,"打开文件对话框",0);
        FileDialog FD2=new FileDialog(frame,"打开文件对话框",1);
        B1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("B1被按下");
                FD1.setVisible(true);
                String directory=FD1.getDirectory();
                String filename=FD1.getFile();
                System.out.println("打开的文件目录为:"+directory);
                System.out.println("打开的文件名为:"+filename);
            }
        });
        B2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("B2被按下");
                FD2.setVisible(true);
                String directory=FD2.getDirectory();
                String filename=FD2.getFile();
                System.out.println("保存的文件目录为:"+directory);
                System.out.println("保存的文件名为:"+filename);
            }
        });

        frame.pack();
        frame.setVisible(true);

    }
}
