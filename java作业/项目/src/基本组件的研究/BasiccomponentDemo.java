package 基本组件的研究;
import java.awt.*;
import javax.swing.*;

public class BasiccomponentDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("求职简历");
        Panel panel1=new Panel();
        Panel panel2=new Panel();
        Box box=Box.createHorizontalBox();   //用来装中间四个选项

        //选择框
        CheckboxGroup gender=new CheckboxGroup();        //在同一个Group的checkbox同一时间只能有一个被选中
        Checkbox ismale=new Checkbox("男",false,gender);     //选择框
        Checkbox isfemale=new Checkbox("女",false,gender);
        Checkbox marriage=new Checkbox("已婚",false);

        //下拉框
        Choice qualification=new Choice();
        qualification.add("学士");
        qualification.add("硕士");
        qualification.add("博士");

        //文本框
        TextArea TA=new TextArea();

        //滚动条
        Scrollbar SB=new Scrollbar(Scrollbar.VERTICAL,0,1,0,255);

        //按钮
        Button B=new Button("确认");

        //列表框
        List L=new List(5,true);
        L.add("C");
        L.add("C++");
        L.add("java");
        L.add("python");
        L.add("go");

        //设置布局
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

        //显示出来
        frame.setVisible(true);
        frame.pack();


    }
}
