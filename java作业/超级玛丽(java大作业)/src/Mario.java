import java.awt.image.BufferedImage;

public class Mario implements Runnable{
    //��¼����µ�ǰ״̬�����ܣ������ȣ�
    private String status=null;
    //left_jump,right_jump,left_run,right_run,left_stand,right_stand
    //���Ա�ʾ��������
    private int x;
    private int y;
    //��ǰ״̬����Ӧ��ͼ��
    private BufferedImage show=null;
    //��ǰ�����ĳ���������ȡ�ϰ�����Ϣ
    private Scene ma_sc=null;
    //����ʵ������µĶ���
    private Thread thread=new Thread(this);
    //����µ�ˮƽ�ƶ��ٶ�
    private int xSpeed;
    //����µ���Ծ�ٶȣ���ֱ�ٶȣ�
    private int ySpeed;
    //ȡ������µ��˶�ͼ��
    private int index;
    //�������Ծ������ʱ��
    private int uptime=0;
    //�ж�������Ƿ��Ѿ��ߵ��Ǳ��ſ�
    boolean Tower_Arrived=false;
    //�ж�������Ƿ�����
    boolean isdead=false;
    //����»�õķ���
    private int goal=0;
    public class Thread2 extends Thread
    {
        @Override
        public void run() {
            while (true) {
                //�ж�Ӯ������
                if (ma_sc.isIsfinal() && x > 500) {
                    ma_sc.setHasArrived(true);

                    //�ж������Ƿ��������
                    if (ma_sc.isFlag_To_Ground()) {
                        status = "right_run";
                        if (x < 690) {
                            xSpeed = 3;
                            x += xSpeed;
                        } else {
                            Tower_Arrived = true;
                        }
                    } else {
                        if (y < 395) {
                            status = "right_jump";
                            xSpeed = 0;
                            y += 5;
                        } else {
                            status = "right_run";
                            y = 395;
                        }
                    }
                }

                //�ж�ɱ�������뱻����ɱ��
                for(int i=0;i<ma_sc.getEnemies().size();i++)
                {
                    Enemy ene=ma_sc.getEnemies().get(i);
                    //�����ж��Ƿ���ɱ��Ģ������
                    if (ene.getType() == 1)    //�ж�Ģ������
                    {
                        if (ene.getY() == y + 20 && (ene.getX() + 35 >= x && ene.getX() - 25 < x)) {
                            ene.Enemy_Dead();
                            uptime = 3;
                            ySpeed = -10;
                            goal += 2;
                            continue;
                        } else if (x > ene.getX() - 25 && x < ene.getX() + 35 && y < ene.getY() + 35 && y > ene.getY() - 25) {
                            isdead = true;
                        }
                    } else   //�ж�ʳ�˻�����
                    {
                        if (x > ene.getX() - 25 && x < ene.getX() + 30 && y < ene.getY() + 33 && y > ene.getY() - 25) {
                            isdead = true;
                        }
                    }
                }


                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    //�߳�2
    private Thread2 thread2=new Thread2();



    //����������ƶ����ı�status��
    public void lefeMove()
    {
        xSpeed=-5;
        if(status.indexOf("jump")!=-1)
        {
            status="left_jump";
        }
        else
        {
            status = "left_run";
        }
    }
    //����������ƶ�
    public void rightMove()
    {
        xSpeed=5;
        if(status.indexOf("jump")!=-1)
        {
            status="right_jump";
        }
        else
        {
            status = "right_run";
        }
    }
    //���������ֹͣ
    public void leftStop()
    {
        xSpeed=0;
        if(status.indexOf("jump")!=-1)
        {
            status="left_jump";
        }
        else
        {
            status="left_stand";
        }
    }

    //���������ֹͣ
    public void rightStop()
    {
        xSpeed=0;
        if(status.indexOf("jump")!=-1)
        {
            status="right_jump";
        }
        else
        {
            status="right_stand";
        }
    }
    //�����������Ծ
    public void jump()
    {
        if(status.indexOf("jump")==-1)
        {
            if(status.indexOf("left")!=-1)
            {
                status="left_jump";
            }
            else if(status.indexOf("right")!=-1)
            {
                status="right_jump";
            }
            ySpeed=-10;
            uptime=10;
        }
    }
    //�������������
    public void fall()
    {
        if(status.indexOf("left")!=-1)
        {
            status="left_jump";
        }
        else if(status.indexOf("right")!=-1)
        {
            status="right_jump";
        }
        ySpeed=10;
    }

    @Override
    public void run() {
        while(true)
        {
            //���Դ���
//            System.out.print("mario��x:"+x+"\t");
//            System.out.print("mario��y:"+y+"\t");
//            System.out.println("flagtoground��"+ma_sc.isFlag_To_Ground());
            //�ж��Ƿ����ϰ���������
            boolean On_Ob=false;
            //�ж��Ƿ����������
            boolean Can_Left=true;
            //�ж��Ƿ����������
            boolean Can_Right=true;


            for(int i=0;i<ma_sc.obstacles.size();i++)
            {
                Obstacle ob=ma_sc.obstacles.get(i);
                if(ob.getY()==this.y+25&&(ob.getX()+25>=this.x&&ob.getX()-25<this.x))
                {
                    On_Ob=true;
                    break;
                }
            }
            //�������������
            if(On_Ob&&uptime==0)
            {
                if(status.indexOf("left")!=-1)
                {
                    if(xSpeed!=0)
                    {
                        status="left_run";
                    }
                    else
                    {
                        status="left_stand";
                    }
                }
                else
                {
                    if(xSpeed!=0)
                    {
                        status="right_run";
                    }
                    else
                    {
                        status="right_stand";
                    }
                }
            }
            else
            {
                if(uptime!=0) {
                    uptime--;
                }
                else
                {
                    fall();
                }
                y += ySpeed;
            }
            //�ж��Ƿ񶥵�ש���Լ��Ƿ����������
            for(int i=0;i<ma_sc.obstacles.size();i++)
            {
                Obstacle ob=ma_sc.obstacles.get(i);
                //�ж��Ƿ񶥵�ש��
                if(this.y<ob.getY()+30&&this.y>ob.getY()+20&&this.x> ob.getX()-25&&this.x<ob.getX()+30)
                {
                    if(ob.getType()==0)
                    {
                        ma_sc.obstacles.remove(ob);
                        goal++;
                        continue;
                    }
                    uptime=0;
                }
                //�ж��Ƿ����������
                if(this.x==ob.getX()+30&&this.y> ob.getY()-25&&this.y< ob.getY()+30)
                {
                    Can_Left=false;
                }
                //�ж��Ƿ����������
                if(this.x==ob.getX()-25&&this.y<ob.getY()+30&&this.y> ob.getY()-25)
                {
                    Can_Right=false;
                }
            }
            if(Can_Right&&xSpeed>0) {
                x += xSpeed;

            }
            else if(Can_Left&&xSpeed<0)
            {
                x+=xSpeed;
            }
            //�ж��������ƶ�
            if(status.equals("right_run")) {
                index=index==0?1:0;
                show = LoadImage.RUN_R.get(index);
            }
            //�ж��Ƿ������ƶ�
            else if(status.equals("left_run"))
            {
                index=index==0?1:0;
                show = LoadImage.RUN_L.get(index);
            }
            //�ж��Ƿ�����ֹͣ
            else if(status.equals("left_stand"))
            {
                show=LoadImage.stand_L;
            }
            //�ж��Ƿ�����ֹͣ
            else if(status.equals("right_stand"))
            {
                show=LoadImage.stand_R;
            }
            //�ж��Ƿ�Ϊ������
            else if(status.equals("left_jump"))
            {
                show=LoadImage.jump_L;
            }
            //�ж��Ƿ�Ϊ������
            else if(status.equals("right_jump"))
            {
                show=LoadImage.jump_R;
            }



            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    //������������߲���Ģ������
//    public int Alive_Eliminate()     //����0�������·���������-1�������������������1�����������
//    {
//        for(Enemy ene:ma_sc.getEnemies())
//        {
//            //�����ж��Ƿ���ɱ��Ģ������
//            if(ene.getType()=1)
//            {
//                if (this.x > ene.getX() - 25 && this.x < ene.getX() + 35&&this.y==ene.getY()-25)
//                {
//
//                }
//            }
//        }
//    }

    //���캯��
    public Mario(int x,int y)
    {
        this.x=x;
        this.y=y;
        show=LoadImage.stand_R;
        status="Stand_Right";
        thread.start();
        thread2.start();

    }
    public void Mario()
    {
        System.out.println("����һ����void�Ĺ��캯��");
    }
    //������������ڵĳ���
    public void set_Ma_sc(Scene sc)
    {
        this.ma_sc=sc;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getGoal() {
        return goal;
    }

    public BufferedImage getShow() {
        return show;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public boolean isTower_Arrived() {
        return Tower_Arrived;
    }

    public void setTower_Arrived(boolean tower_Arrived) {
        Tower_Arrived = tower_Arrived;
    }

    public static void main(String[] args) {


    }
}
