package �¼���������;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Textlistener_and_Itemlistener {
    public static void main(String[] args) {
        Frame frame=new Frame();
        TextField tf=new TextField(20);
        Choice stars=new Choice();

        //containerlistener ����frame������ı仯
        frame.addContainerListener(new ContainerListener() {
            @Override
            public void componentAdded(ContainerEvent e) {
                Component child=e.getChild();
                System.out.println(child+"\n");
            }

            @Override
            public void componentRemoved(ContainerEvent e) {
                String name=e.getChild().getName();
                System.out.println("�Ƴ������:"+name+"\n");
            }
        });


        //Itemlistener  ������Ŀѡ��ı仯
        stars.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                String s=stars.getSelectedItem();
                tf.setText(s);
            }
        });
        stars.add("����");
        stars.add("����");
        stars.add("���");

        //Textlistener   �����ı����ݵı仯
        tf.addTextListener(new TextListener() {
            @Override
            public void textValueChanged(TextEvent e) {
                System.out.println(tf.getText());
            }
        });

        Box box=new Box(BoxLayout.X_AXIS);
        box.add(stars);
        box.add(tf);
        frame.add(box);

        frame.pack();
        frame.setVisible(true);




    }
}
