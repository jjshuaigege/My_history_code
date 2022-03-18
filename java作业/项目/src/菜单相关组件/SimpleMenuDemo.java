package 菜单相关组件;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

public class SimpleMenuDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("这里测试菜单项组件");


        //创建菜单条
        MenuBar MB=new MenuBar();


        //创建菜单
        Menu M1=new Menu("文件");
        Menu M2=new Menu("编辑");

        //创建菜单项
        M1.add(new MenuItem("新建文件"));
        M1.add(new MenuItem("打开文件"));
        MenuItem SF=new MenuItem("保存文件",new MenuShortcut(KeyEvent.VK_S,true));
        M1.add(SF);

        M2.add(new MenuItem("自动换行"));
        M2.add(new MenuItem("复制"));
        M2.add(new MenuItem("粘贴"));
        M2.add(new MenuItem("-"));
        Menu M2_son=new Menu("格式");     //M2_son既是菜单也是菜单项
        M2.add(M2_son);

        M2_son.add(new MenuItem("注释"));
        M2_son.add(new MenuItem("取消注释"));

        //组装
        MB.add(M1);
        MB.add(M2);
        frame.setLayout(new BorderLayout(5,5));
        frame.setMenuBar(MB);     //一个frame只能有一个menubar
//        frame.add(MB,BorderLayout.NORTH);
        frame.add(new TextArea(5,40),BorderLayout.CENTER);

        SF.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("保存文件成功！");
            }
        });

        //收尾
        frame.pack();
        frame.setVisible(true);


    }
}
