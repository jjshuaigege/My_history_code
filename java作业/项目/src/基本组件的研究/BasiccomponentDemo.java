package ����������о�;
import java.awt.*;
import javax.swing.*;

public class BasiccomponentDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("��ְ����");
        Panel panel1=new Panel();
        Panel panel2=new Panel();
        Box box=Box.createHorizontalBox();   //����װ�м��ĸ�ѡ��

        //ѡ���
        CheckboxGroup gender=new CheckboxGroup();        //��ͬһ��Group��checkboxͬһʱ��ֻ����һ����ѡ��
        Checkbox ismale=new Checkbox("��",false,gender);     //ѡ���
        Checkbox isfemale=new Checkbox("Ů",false,gender);
        Checkbox marriage=new Checkbox("�ѻ�",false);

        //������
        Choice qualification=new Choice();
        qualification.add("ѧʿ");
        qualification.add("˶ʿ");
        qualification.add("��ʿ");

        //�ı���
        TextArea TA=new TextArea();

        //������
        Scrollbar SB=new Scrollbar(Scrollbar.VERTICAL,0,1,0,255);

        //��ť
        Button B=new Button("ȷ��");

        //�б��
        List L=new List(5,true);
        L.add("C");
        L.add("C++");
        L.add("java");
        L.add("python");
        L.add("go");

        //���ò���
        frame.setLayout(new BorderLayout());
        frame.add(L,BorderLayout.EAST);
        frame.add(panel1,BorderLayout.CENTER);
        frame.add(panel2,BorderLayout.SOUTH);


        box.add(qualification);
        box.add(ismale);
        box.add(isfemale);
        box.add(marriage);

        panel1.setLayout(new BorderLayout());
        panel1.add(new TextArea(),BorderLayout.CENTER);
        panel1.add(box,BorderLayout.SOUTH);

        panel2.setLayout(new BoxLayout(panel2,BoxLayout.X_AXIS));
        panel2.add(new TextField(20));
        panel2.add(B);

//        frame.setLayout(new BorderLayout());
//        frame.add(L,BorderLayout.EAST);
//        frame.add(panel1,BorderLayout.CENTER);
//        frame.add(panel2,BorderLayout.SOUTH);

        //��ʾ����
        frame.setVisible(true);
        frame.pack();


    }
}
