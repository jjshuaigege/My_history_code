package Window��Panel���о�;
import java.awt.*;

public class Window��Panel���о� {


    public static void main(String[] args) {
        // TODO Auto-generated method stub

        //����һ��window����Frame�̳���window��
        Frame my_frame=new Frame();
        Frame sec_frame=new Frame();
        //����һ��panel����
        Panel panel1=new Panel();
        Panel panel2=new Panel();
        //����һ���ı����һ����ť�����Ұ����Ƿ��뵽panel������
        panel1.add(new TextField("������һ�������ı�"));
        panel1.add(new Button("������һ�����԰�ť"));
        panel2.add(new TextField("������һ�������ı�"));
        panel2.add(new Button("������һ�����԰�ť"));
        //��panel���뵽window��
        my_frame.add(panel1);
        sec_frame.add(panel1);
        //����window��λ�ü���С
        my_frame.setBounds(100,100,500,300);
        sec_frame.setBounds(200,200,800,600);
        //����window�ɼ�
        my_frame.setVisible(true);
        sec_frame.setVisible(true);
        //����Frame���ڿɹر�

    }

}
