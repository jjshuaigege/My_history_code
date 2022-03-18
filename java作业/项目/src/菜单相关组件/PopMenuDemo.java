package 菜单相关组件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class PopMenuDemo {
    public static void main(String[] args) {

        //创建组件
        MenuItem M1=new MenuItem("注释");
        MenuItem M2=new MenuItem("取向注释");
        MenuItem M3=new MenuItem("复制");
        MenuItem M4=new MenuItem("保存");
        PopupMenu PM=new PopupMenu("我的弹出菜单");
        Panel panel=new Panel();
        TextArea TF=new TextArea(5,30);
        Box box=new Box(BoxLayout.Y_AXIS);
        Frame frame=new Frame();

        //组装
        PM.add(M1);
        PM.add(M2);
        PM.add(M3);
        PM.add(M4);
        panel.add(PM);
        box.add(TF);
        box.add(panel);
        frame.add(box);

        //收尾
        panel.setPreferredSize(new Dimension(400,300));       //此处注意！！
        frame.pack();
        frame.setVisible(true);

        //添加事件监听
        panel.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {

            }

            @Override
            public void mousePressed(MouseEvent e) {

            }

            @Override
            public void mouseReleased(MouseEvent e) {
                if(e.isPopupTrigger())
                {
                    //显示popupmenu
                    PM.show(panel,e.getX(),e.getY());
                }

            }

            @Override
            public void mouseEntered(MouseEvent e) {

            }

            @Override
            public void mouseExited(MouseEvent e) {

            }
        });


    }
}
