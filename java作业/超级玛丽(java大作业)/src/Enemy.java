import java.awt.image.BufferedImage;
import java.nio.Buffer;
import java.util.ArrayList;

public class Enemy implements Runnable{
    private int x;
    private int y;
    private int type;
    private boolean direction;
    private BufferedImage show;
    private Scene Enemy_Sc;
    private boolean Can_Left=true;
    private boolean Can_Right=true;
    private int Max_Up;
    private int Max_Down;
    private int index=0;     //用以实现敌人的动态画面
    private Thread thread=new Thread(this);
    //敌人死亡的方法（蘑菇敌人）
    public void Enemy_Dead()
    {
        if(type==1)
        {
            Enemy_Sc.getEnemies().remove(this);
            show=LoadImage.FUNGUSES.get(2);
        }
    }
    public Enemy(int x,int y,int type,boolean direction,Scene Enemy_Sc)     //蘑菇
    {
        this.x = x;
        this.y = y;
        this.type = type;
        this.direction = direction;
        this.Enemy_Sc = Enemy_Sc;
        show=LoadImage.FUNGUSES.get(0);
        thread.start();
//        for (BufferedImage I : LoadImage.FUNGUSES)
//        {
//            shows.add(new BufferedImage()=I);
//        }
    }
    public Enemy(int x,int y,int type,boolean direction,int Max_Down,int Max_Up,Scene Enemy_Sc)    //食人花
    {
        this.x=x;
        this.y=y;
        this.type=type;
        this.direction=direction;
        this.Max_Down=Max_Down;
        this.Max_Up=Max_Up;
        this.Enemy_Sc=Enemy_Sc;
        show=LoadImage.FLOWERS.get(0);
        thread.start();

    }
    public void run() {
        while (true) {
            index = index == 0 ? 1 : 0;
            if (type == 0) {
                if (direction == true) {
                    if (this.y < Max_Up) {
                        this.y += 2;
                        show = LoadImage.FLOWERS.get(index);
                    } else {
                        this.direction = !this.direction;
                    }
                } else {
                    if (this.y > Max_Down) {
                        this.y -= 2;
                        show = LoadImage.FLOWERS.get(index);
                    } else {
                        this.direction = !this.direction;
                    }
                }

            } else if (type == 1)   //蘑菇敌人
            {
                if (direction == true) {
                    //先判断能不能向右运动
                    for (Obstacle ob : Enemy_Sc.obstacles) {
                        if((this.x == ob.getX() - 35 && this.y < ob.getY() + 30 && this.y > ob.getY() - 35)||this.x>765) {
                            Can_Right = false;
                            break;
                        }
                    }
                    if (Can_Right) {
                        this.x += 5;
                        show = LoadImage.FUNGUSES.get(index);
                    } else {
                        this.direction = !this.direction;
                    }
                    Can_Right = true;
                } else {
                    //先判断能不能向左运动
                    for (Obstacle ob : Enemy_Sc.obstacles) {
                        if ((this.x == ob.getX() + 30 && this.y < ob.getY() + 30 && this.y > ob.getY() - 35)||this.x<0) {
                            Can_Left = false;
                            break;
                        }
                    }
                    if (Can_Left) {
                        this.x -= 5;
                        show = LoadImage.FUNGUSES.get(index);
                    } else {
                        this.direction = !this.direction;
                    }
                    Can_Left = true;
                }
            }
            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public BufferedImage getShow() {
        return show;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getType() {
        return type;
    }

    public static void main(String[] args){

    }
}
