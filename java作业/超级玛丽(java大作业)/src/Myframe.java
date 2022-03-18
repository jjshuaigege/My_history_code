import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

public class Myframe extends JFrame implements KeyListener,Runnable{
    //马里奥对象和Myframe绑定
    Mario mario;
    //用于存放所有的场景数据
    private ArrayList<Scene> allscenes=new ArrayList<Scene>();
    //用于记录当前场景数据
    private Scene nowscene=null;
    //用于双缓存显示图像
    private Image cache_image=null;
    //用于记录当前是第几个场景
    private int sort;
    //用于实现马里奥的移动
    private Thread thread=new Thread(this);
    public Myframe()
    {
        //读入图片的数据
        LoadImage.init();
        //读入所有场景
        for(int i=0;i<=2;i++)
        {
            allscenes.add(new Scene(i));
        }
        //当前场景初始化为0场景
        setscene(0);
        //初始化马里奥
        mario=new Mario(30,395);
        mario.set_Ma_sc(nowscene);
        //设置窗口标题
        this.setTitle("超级玛丽");
        //设置窗口大小
        this.setSize(800,600);
        //设置窗口不可改变
        this.setResizable(false);
        //设置窗口居中显示
        this.setLocationRelativeTo(null);
        //设置窗口可关闭
        this.setDefaultCloseOperation(this.EXIT_ON_CLOSE);
        //添加键盘监听器
        this.addKeyListener(this);
        //设置窗口可见
        this.setVisible(true);
        //马里奥移动线程开始
        thread.start();
        //播放音乐
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
        //绘制城堡
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
        //绘制旗杆
        cacheg.drawImage(nowscene.getGan(),500,220,this);
//        if(sort==2)
//        {
//            //画出第二个场景的额外物体
//            cacheg.drawImage(LoadImage.gan,500,221,this);
//            cacheg.drawImage(LoadImage.tower,630,270,this);
//        }
        //打印分数
        cacheg.setColor(cacheg.getColor().RED);
        cacheg.setFont(new Font("黑体",Font.BOLD,15));
        cacheg.drawString("当前分数："+mario.getGoal(),350,100);
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
                JOptionPane.showMessageDialog(this,"恭喜你已通关！");
                System.exit(0);
            }
            //判断马里奥是否死亡
            if(mario.isdead)
            {
                JOptionPane.showMessageDialog(this,"很遗憾你已死亡");
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
