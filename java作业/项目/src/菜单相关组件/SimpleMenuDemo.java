package �˵�������;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

public class SimpleMenuDemo {
    public static void main(String[] args) {
        Frame frame=new Frame("������Բ˵������");


        //�����˵���
        MenuBar MB=new MenuBar();


        //�����˵�
        Menu M1=new Menu("�ļ�");
        Menu M2=new Menu("�༭");

        //�����˵���
        M1.add(new MenuItem("�½��ļ�"));
        M1.add(new MenuItem("���ļ�"));
        MenuItem SF=new MenuItem("�����ļ�",new MenuShortcut(KeyEvent.VK_S,true));
        M1.add(SF);

        M2.add(new MenuItem("�Զ�����"));
        M2.add(new MenuItem("����"));
        M2.add(new MenuItem("ճ��"));
        M2.add(new MenuItem("-"));
        Menu M2_son=new Menu("��ʽ");     //M2_son���ǲ˵�Ҳ�ǲ˵���
        M2.add(M2_son);

        M2_son.add(new MenuItem("ע��"));
        M2_son.add(new MenuItem("ȡ��ע��"));

        //��װ
        MB.add(M1);
        MB.add(M2);
        frame.setLayout(new BorderLayout(5,5));
        frame.setMenuBar(MB);     //һ��frameֻ����һ��menubar
//        frame.add(MB,BorderLayout.NORTH);
        frame.add(new TextArea(5,40),BorderLayout.CENTER);

        SF.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("�����ļ��ɹ���");
            }
        });

        //��β
        frame.pack();
        frame.setVisible(true);


    }
}
