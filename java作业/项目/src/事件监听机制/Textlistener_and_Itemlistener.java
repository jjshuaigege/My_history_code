package 事件监听机制;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Textlistener_and_Itemlistener {
    public static void main(String[] args) {
        Frame frame=new Frame();
        TextField tf=new TextField(20);
        Choice stars=new Choice();

        //containerlistener 监听frame中组件的变化
        frame.addContainerListener(new ContainerListener() {
            @Override
            public void componentAdded(ContainerEvent e) {
                Component child=e.getChild();
                System.out.println(child+"\n");
            }

            @Override
            public void componentRemoved(ContainerEvent e) {
                String name=e.getChild().getName();
                System.out.println("移除了组件:"+name+"\n");
            }
        });


        //Itemlistener  监听条目选项的变化
        stars.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                String s=stars.getSelectedItem();
                tf.setText(s);
            }
        });
        stars.add("柳岩");
        stars.add("闫妮");
        stars.add("舒淇");

        //Textlistener   监听文本内容的变化
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
