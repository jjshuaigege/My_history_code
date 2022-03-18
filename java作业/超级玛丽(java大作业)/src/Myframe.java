import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

public class Myframe extends JFrame implements KeyListener,Runnable{
    //����¶����Myframe��
    Mario mario;
    //���ڴ�����еĳ�������
    private ArrayList<Scene> allscenes=new ArrayList<Scene>();
    //���ڼ�¼��ǰ��������
    private Scene nowscene=null;
    //����˫������ʾͼ��
    private Image cache_image=null;
    //���ڼ�¼��ǰ�ǵڼ�������
    private int sort;
    //����ʵ������µ��ƶ�
    private Thread thread=new Thread(this);
    public Myframe()
    {
        //����ͼƬ������
        LoadImage.init();
        //�������г���
        for(int i=0;i<=2;i++)
        {
            allscenes.add(new Scene(i));
        }
        //��ǰ������ʼ��Ϊ0����
        setscene(0);
        //��ʼ�������
        mario=new Mario(30,395);
        mario.set_Ma_sc(nowscene);
        //���ô��ڱ���
        this.setTitle("��������");
        //���ô��ڴ�С
        this.setSize(800,600);
        //���ô��ڲ��ɸı�
        this.setResizable(false);
        //���ô��ھ�����ʾ
        this.setLocationRelativeTo(null);
        //���ô��ڿɹر�
        this.setDefaultCloseOperation(this.EXIT_ON_CLOSE);
        //��Ӽ��̼�����
        this.addKeyListener(this);
        //���ô��ڿɼ�
        this.setVisible(true);
        //������ƶ��߳̿�ʼ
        thread.start();
        //��������
        Music music=new Music();
    }
    public void setscene(int sort)
    {
        this.sort=sort;
        nowscene=allscenes.get(sort);
    }
    @Override
    public void paint(Graphics g)
    {
        if(cache_image==null)
        {
            cache_image=createImage(800,600);
        }
        Graphics cacheg=cache_image.getGraphics();

        cacheg.drawImage(nowscene.bg,0,0,this);
        //���ƳǱ�
        cacheg.drawImage(nowscene.getTower(),620,270,this);
        for(Enemy enm:nowscene.getEnemies())
        {
            cacheg.drawImage(enm.getShow(),enm.getX(),enm.getY(),this);
        }
        for(int i=0;i<nowscene.obstacles.size();i++)
        {
            Obstacle draw_ob=nowscene.obstacles.get(i);

            cacheg.drawImage(draw_ob.getShow(),draw_ob.getX(),draw_ob.getY(),this);
        }
        //�������
        cacheg.drawImage(nowscene.getGan(),500,220,this);
//        if(sort==2)
//        {
//            //�����ڶ��������Ķ�������
//            cacheg.drawImage(LoadImage.gan,500,221,this);
//            cacheg.drawImage(LoadImage.tower,630,270,this);
//        }
        //��ӡ����
        cacheg.setColor(cacheg.getColor().RED);
        cacheg.setFont(new Font("����",Font.BOLD,15));
        cacheg.drawString("��ǰ������"+mario.getGoal(),350,100);
        cacheg.drawImage(mario.getShow(),mario.getX(),mario.getY(),this);
        g.drawImage(cache_image,0,0,this);

    }

    @Override
    public void keyTyped(KeyEvent e) {
        if((e.getKeyChar()=='a'||e.getKeyChar()=='A')&&!nowscene.isHasArrived())
        {
            mario.lefeMove();
        }
        else if((e.getKeyChar()=='d'||e.getKeyChar()=='D')&&!nowscene.isHasArrived())
        {
            mario.rightMove();
        }

    }

    @Override
    public void keyPressed(KeyEvent e) {
        if(e.getKeyChar()==' '&&!nowscene.isHasArrived())
        {
            mario.jump();
        }

    }

    @Override
    public void keyReleased(KeyEvent e) {
        if((e.getKeyChar()=='a'||e.getKeyChar()=='A')&&!nowscene.isHasArrived())
        {
            mario.leftStop();
        }
        else if((e.getKeyChar()=='d'||e.getKeyChar()=='D')&&!nowscene.isHasArrived())
        {
            mario.rightStop();
        }

    }


    public static void main(String[] adrgs) {
        Myframe mf=new Myframe();

    }


    @Override
    public void run() {
        while(true)
        {
            repaint();
            if (mario.getX() > 785) {
                if (sort == 2) {
                    mario.setX(785);
                } else {
                    nowscene = allscenes.get(++sort);
                    mario.setX(0);
                    mario.set_Ma_sc(allscenes.get(sort));
                }
            } else if (mario.getX() < 0) {
                if (sort == 0) {
                    mario.setX(0);
                } else {
                    nowscene = allscenes.get(--sort);
                    mario.setX(785);
                    mario.set_Ma_sc(allscenes.get(sort));
                }
            }
            if(mario.isTower_Arrived())
            {
                JOptionPane.showMessageDialog(this,"��ϲ����ͨ�أ�");
                System.exit(0);
            }
            //�ж�������Ƿ�����
            if(mario.isdead)
            {
                JOptionPane.showMessageDialog(this,"���ź���������");
                mario.isdead=false;
//                System.exit(0);
            }
            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
