package ���ֹ��������о�;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CardLayoutDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("������ʾCardLayout");
        Panel panel1=new Panel();
        CardLayout CL=new CardLayout(5,5);//����frame�����ұ߽�
        panel1.setLayout(CL);

        panel1.add(new Button("��һ��"));
        panel1.add(new Button("�ڶ���"));
        panel1.add("������",new Button("������"));
        panel1.add(new Button("������"));
        panel1.add(new Button("������"));
        Panel panel2=new Panel();

        //���������ť
        panel2.setLayout(new GridLayout(1,5,5,5));
        Button B1=new Button("��һ��");
        Button B2=new Button("��һ��");
        Button B3=new Button("��һ��");
        Button B4=new Button("���һ��");
        Button B5=new Button("������");
        panel2.add(B1);
        panel2.add(B2);
        panel2.add(B3);
        panel2.add(B4);
        panel2.add(B5);

        //���������ť����ȥ��Ӧ��������

        //��һ��д��
//        B1.addActionListener(e -> CL.previous(panel1));
//        B2.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                CL.next(panel1);
//            }
//        });
//        B3.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                CL.first(panel1);
//            }
//        });
//        B4.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                CL.last(panel1);
//            }
//        });
//        B5.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                CL.show(panel1,"������");
//            }
//        });

        //�ڶ���д��
        ActionListener al=new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String command=e.getActionCommand();
                switch (command)
                {
                    case "��һ��":CL.previous(panel1);System.out.println("B1������");break;
                    case "��һ��":CL.next(panel1);break;
                    case "��һ��":CL.first(panel1);break;
                    case "���һ��":CL.last(panel1);break;
                    case "������":CL.show(panel1,"������");break;
                }

            }
        };
        B1.addActionListener(al);
        B2.addActionListener(al);
        B3.addActionListener(al);
        B4.addActionListener(al);
        B5.addActionListener(al);

        frame.add(panel1,BorderLayout.CENTER);
        frame.add(panel2,BorderLayout.SOUTH);
        frame.pack();
        frame.setVisible(true);

    }
}
