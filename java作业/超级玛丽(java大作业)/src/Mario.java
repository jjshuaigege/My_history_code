import java.awt.image.BufferedImage;

public class Mario implements Runnable{
    //记录马里奥当前状态（左跑，右跳等）
    private String status=null;
    //left_jump,right_jump,left_run,right_run,left_stand,right_stand
    //用以表示横纵坐标
    private int x;
    private int y;
    //当前状态所对应的图像
    private BufferedImage show=null;
    //当前所处的场景，来获取障碍物信息
    private Scene ma_sc=null;
    //用以实现马里奥的动作
    private Thread thread=new Thread(this);
    //马里奥的水平移动速度
    private int xSpeed;
    //马里奥的跳跃速度（垂直速度）
    private int ySpeed;
    //取得马里奥的运动图像
    private int index;
    //马里奥跳跃的上升时间
    private int uptime=0;
    //判断马里奥是否已经走到城堡门口
    boolean Tower_Arrived=false;
    //判断马里奥是否死亡
    boolean isdead=false;
    //马里奥获得的分数
    private int goal=0;
    public class Thread2 extends Thread
    {
        @Override
        public void run() {
            while (true) {
                //判断赢的条件
                if (ma_sc.isIsfinal() && x > 500) {
                    ma_sc.setHasArrived(true);

                    //判断旗子是否下落完成
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

                //判断杀死敌人与被敌人杀死
                for(int i=0;i<ma_sc.getEnemies().size();i++)
                {
                    Enemy ene=ma_sc.getEnemies().get(i);
                    //首先判断是否能杀死蘑菇敌人
                    if (ene.getType() == 1)    //判断蘑菇敌人
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
                    } else   //判断食人花敌人
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
    //线程2
    private Thread2 thread2=new Thread2();



    //马里奥向左移动（改变status）
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
    //马里奥向右移动
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
    //马里奥向左停止
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

    //马里奥向右停止
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
    //马里奥向上跳跃
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
    //马里奥向下下落
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
            //调试代码
//            System.out.print("mario的x:"+x+"\t");
//            System.out.print("mario的y:"+y+"\t");
//            System.out.println("flagtoground："+ma_sc.isFlag_To_Ground());
            //判断是否处于障碍物体上面
            boolean On_Ob=false;
            //判断是否可以向左走
            boolean Can_Left=true;
            //判断是否可以向右走
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
            //下落和上升处理
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
            //判断是否顶到砖块以及是否可以左右走
            for(int i=0;i<ma_sc.obstacles.size();i++)
            {
                Obstacle ob=ma_sc.obstacles.get(i);
                //判断是否顶到砖块
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
                //判断是否可以向左走
                if(this.x==ob.getX()+30&&this.y> ob.getY()-25&&this.y< ob.getY()+30)
                {
                    Can_Left=false;
                }
                //判断是否可以向右走
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
            //判断是向左移动
            if(status.equals("right_run")) {
                index=index==0?1:0;
                show = LoadImage.RUN_R.get(index);
            }
            //判断是否向右移动
            else if(status.equals("left_run"))
            {
                index=index==0?1:0;
                show = LoadImage.RUN_L.get(index);
            }
            //判断是否向左停止
            else if(status.equals("left_stand"))
            {
                show=LoadImage.stand_L;
            }
            //判断是否向右停止
            else if(status.equals("right_stand"))
            {
                show=LoadImage.stand_R;
            }
            //判断是否为向左跳
            else if(status.equals("left_jump"))
            {
                show=LoadImage.jump_L;
            }
            //判断是否为向右跳
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

    //马里奥死亡或者踩死蘑菇敌人
//    public int Alive_Eliminate()     //返回0代表无事发生，返回-1代表马里奥死亡，返回1代表低人死亡
//    {
//        for(Enemy ene:ma_sc.getEnemies())
//        {
//            //首先判断是否能杀死蘑菇敌人
//            if(ene.getType()=1)
//            {
//                if (this.x > ene.getX() - 25 && this.x < ene.getX() + 35&&this.y==ene.getY()-25)
//                {
//
//                }
//            }
//        }
//    }

    //构造函数
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
        System.out.println("这是一个带void的构造函数");
    }
    //更新马里奥所在的场景
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
