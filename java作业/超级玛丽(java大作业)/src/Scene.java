import java.awt.*;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

public class Scene{

    private int sort;//����˵���Լ��ǵڼ�������
    public ArrayList<Obstacle> obstacles=new ArrayList<Obstacle>();   //����˵���ڲ����ϰ������Ϣ
    private ArrayList<Enemy> enemies=new ArrayList<Enemy>();        //����˵���ڲ��ĵ�����Ϣ
    public BufferedImage bg;
    //����
    public BufferedImage flag=null;
    //���
    private BufferedImage gan=null;
    //�Ǳ�
    private BufferedImage tower=null;
    //�ж��Ƿ������һ��(��Ӯ)
    private boolean isfinal=false;
    //�ж�������Ƿ��Ѿ�������˵�λ��
    private boolean HasArrived=false;
    //�ж������Ƿ����
    private boolean Flag_To_Ground=false;
    public Scene(int sort)
    {
        bg=LoadImage.BG.get(sort==2?1:0);   //�õ�����ͼ
        this.sort=sort;
        if(sort==0)
        {
            //���������
            //�µײ�ש��
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<27;j++)
                {
                    obstacles.add(new Obstacle(j*30,450+30*i,6,this));
                }
            }
            //�ϵײ�ש��
            for(int j=0;j<27;j++)
            {
                obstacles.add(new Obstacle(j*30,420,7,this));
            }
            //���ƿ���ש��
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
            //����ˮ���϶�
            obstacles.add(new Obstacle(620,360,2,this));
            obstacles.add(new Obstacle(645,360,3,this));
            //����ˮ���¶�
            for(int i=1;i<=9;i++)
            {
                obstacles.add(new Obstacle(620, 360+i*25,4,this));
                obstacles.add(new Obstacle(645, 360+i*25,5,this));
            }
            //����
            enemies.add(new Enemy(580,385,1,true,this));
            enemies.add(new Enemy(635,420,0,true,328,428,this));


        }
        else if(sort==1)
        {
            //�µײ�ש��
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<27;j++)
                {
                    obstacles.add(new Obstacle(j*30,450+30*i,6,this));
                }
            }
            //�ϵײ�ש��
            for(int j=0;j<27;j++)
            {
                obstacles.add(new Obstacle(j*30,420,7,this));
            }
            //���ƿ���ש��
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
            //����ˮ��
                //ˮ��1
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
                //ˮ��2
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
            //����
            enemies.add(new Enemy(75,420,0,true,328,418,this));
            enemies.add(new Enemy(670,420,0,true,298,388,this));
            enemies.add(new Enemy(200,385,1,true,this));
            enemies.add(new Enemy(500,385,1,true,this));

        }
        else if(sort==2)
        {
            isfinal=true;
            //�µײ�ש��
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<27;j++)
                {
                    obstacles.add(new Obstacle(j*30,450+30*i,6,this));
                }
            }
            //�ϵײ�ש��
            for(int j=0;j<27;j++)
            {
                obstacles.add(new Obstacle(j*30,420,7,this));
            }
            //����ש��
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
            //����
            enemies.add(new Enemy(150,385,1,true,this));
            //����
            obstacles.add(new Obstacle(515,220,8,this));
            //�Ǳ�
            tower=LoadImage.tower;
            //���
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
