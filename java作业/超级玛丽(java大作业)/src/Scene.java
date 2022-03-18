import java.awt.*;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

public class Scene{

    private int sort;//用以说明自己是第几个场景
    public ArrayList<Obstacle> obstacles=new ArrayList<Obstacle>();   //用以说明内部的障碍物的信息
    private ArrayList<Enemy> enemies=new ArrayList<Enemy>();        //用以说明内部的敌人信息
    public BufferedImage bg;
    //旗帜
    public BufferedImage flag=null;
    //旗杆
    private BufferedImage gan=null;
    //城堡
    private BufferedImage tower=null;
    //判断是否是最后一关(判赢)
    private boolean isfinal=false;
    //判断马里奥是否已经到到旗杆的位置
    private boolean HasArrived=false;
    //判断旗子是否落地
    private boolean Flag_To_Ground=false;
    public Scene(int sort)
    {
        bg=LoadImage.BG.get(sort==2?1:0);   //得到背景图
        this.sort=sort;
        if(sort==0)
        {
            //第零幅场景
            //下底部砖块
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<27;j++)
                {
                    obstacles.add(new Obstacle(j*30,450+30*i,6,this));
                }
            }
            //上底部砖块
            for(int j=0;j<27;j++)
            {
                obstacles.add(new Obstacle(j*30,420,7,this));
            }
            //绘制空中砖块
            for(int i=0;i<2;i++)
            {
                obstacles.add(new Obstacle(120+i*30,300,1,this));
            }
            for(int i=0;i<8;i++)
            {
                if(i%2==0)
                {
                    obstacles.add(new Obstacle(300+i*30,300,1,this));
                }
                else
                {
                    obstacles.add(new Obstacle(300+i*30,300,0,this));
                }
            }
            obstacles.add(new Obstacle(300+8*30,300,0,this));
            obstacles.add(new Obstacle(420,220,0,this));
            obstacles.add(new Obstacle(450,220,0,this));
            //绘制水管上端
            obstacles.add(new Obstacle(620,360,2,this));
            obstacles.add(new Obstacle(645,360,3,this));
            //绘制水管下端
            for(int i=1;i<=9;i++)
            {
                obstacles.add(new Obstacle(620, 360+i*25,4,this));
                obstacles.add(new Obstacle(645, 360+i*25,5,this));
            }
            //敌人
            enemies.add(new Enemy(580,385,1,true,this));
            enemies.add(new Enemy(635,420,0,true,328,428,this));


        }
        else if(sort==1)
        {
            //下底部砖块
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<27;j++)
                {
                    obstacles.add(new Obstacle(j*30,450+30*i,6,this));
                }
            }
            //上底部砖块
            for(int j=0;j<27;j++)
            {
                obstacles.add(new Obstacle(j*30,420,7,this));
            }
            //绘制空中砖块
            for(int i=0;i<5;i++)
            {
                obstacles.add(new Obstacle(240+i*30,390,1,this));
            }
            for(int i=0;i<3;i++)
            {
                obstacles.add(new Obstacle(270+i*30,360,1,this));
            }
            obstacles.add(new Obstacle(300,330,1,this));
            obstacles.add(new Obstacle(240,300,0,this));
            obstacles.add(new Obstacle(360,270,0,this));
            for(int i=0;i<3;i++)
            {
                obstacles.add(new Obstacle(420+i*60,300,0,this));
            }
            //绘制水管
                //水管1
            for(int i=0;i<10;i++)
            {
                if(i==0) {
                    obstacles.add(new Obstacle(60,360+i*25,2,this));
                    obstacles.add(new Obstacle(85,360+i*25,3,this));
                }
                else
                {
                    obstacles.add(new Obstacle(60,360+i*25,4,this));
                    obstacles.add(new Obstacle(85,360+i*25,5,this));
                }
            }
                //水管2
            for(int i=0;i<11;i++)
            {
                if(i==0)
                {
                    obstacles.add(new Obstacle(655,330+i*25,2,this));
                    obstacles.add(new Obstacle(680,330+i*25,3,this));
                }
                else
                {
                    obstacles.add(new Obstacle(655,330+i*25,4,this));
                    obstacles.add(new Obstacle(680,330+i*25,5,this));
                }
            }
            //敌人
            enemies.add(new Enemy(75,420,0,true,328,418,this));
            enemies.add(new Enemy(670,420,0,true,298,388,this));
            enemies.add(new Enemy(200,385,1,true,this));
            enemies.add(new Enemy(500,385,1,true,this));

        }
        else if(sort==2)
        {
            isfinal=true;
            //下底部砖块
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<27;j++)
                {
                    obstacles.add(new Obstacle(j*30,450+30*i,6,this));
                }
            }
            //上底部砖块
            for(int j=0;j<27;j++)
            {
                obstacles.add(new Obstacle(j*30,420,7,this));
            }
            //空中砖块
            for(int i=0;i<2;i++)
            {
                for(int j=i;j<2;j++)
                {
                    obstacles.add(new Obstacle(60+j*30,390-i*30,1,this));
                }
            }
            for(int i=0;i<5;i++)
            {
                for(int j=i;j<5;j++)
                {
                    obstacles.add(new Obstacle(300+j*30,390-i*30,1,this));
                }
            }
            //敌人
            enemies.add(new Enemy(150,385,1,true,this));
            //旗帜
            obstacles.add(new Obstacle(515,220,8,this));
            //城堡
            tower=LoadImage.tower;
            //旗杆
            gan=LoadImage.gan;



        }
    }
    public boolean isIsfinal() {
        return isfinal;
    }

    public BufferedImage getGan() {
        return gan;
    }

    public BufferedImage getTower() {
        return tower;
    }

    public boolean isHasArrived() {
        return HasArrived;
    }

    public void setHasArrived(boolean hasArrived) {
        HasArrived = hasArrived;
    }

    public boolean isFlag_To_Ground() {
        return Flag_To_Ground;
    }

    public void setFlag_To_Ground(boolean flag_To_Ground) {
        Flag_To_Ground = flag_To_Ground;
    }

    public ArrayList<Enemy> getEnemies() {
        return enemies;
    }

    public static void main(String[] args) {

    }
}
