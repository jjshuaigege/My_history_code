package 布局管理器的研究;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CardLayoutDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("这里演示CardLayout");
        Panel panel1=new Panel();
        CardLayout CL=new CardLayout(5,5);//距离frame的左右边界
        panel1.setLayout(CL);

        panel1.add(new Button("第一张"));
        panel1.add(new Button("第二张"));
        panel1.add("第三张",new Button("第三张"));
        panel1.add(new Button("第四张"));
        panel1.add(new Button("第五张"));
        Panel panel2=new Panel();

        //加入五个按钮
        panel2.setLayout(new GridLayout(1,5,5,5));
        Button B1=new Button("上一张");
        Button B2=new Button("下一张");
        Button B3=new Button("第一张");
        Button B4=new Button("最后一张");
        Button B5=new Button("第三张");
        panel2.add(B1);
        panel2.add(B2);
        panel2.add(B3);
        panel2.add(B4);
        panel2.add(B5);

        //定义五个按钮按下去后应该做的事

        //第一种写法
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
//                CL.show(panel1,"第三张");
//            }
//        });

        //第二种写法
        ActionListener al=new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String command=e.getActionCommand();
                switch (command)
                {
                    case "上一张":CL.previous(panel1);System.out.println("B1被按下");break;
                    case "下一张":CL.next(panel1);break;
                    case "第一张":CL.first(panel1);break;
                    case "最后一张":CL.last(panel1);break;
                    case "第三张":CL.show(panel1,"第三张");break;
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
