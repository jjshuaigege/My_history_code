import java.awt.image.BufferedImage;

public class Obstacle implements Runnable{
    private int x;
    private int y;
    private int type;
    private Scene sc;    //属于哪一个场景
    private BufferedImage show;    //对应的图片
    Thread thread;
    Obstacle(int x,int y,int type,Scene sc)
    {
        this.x=x;
        this.y=y;
        this.type=type;
        this.sc=sc;
        show=LoadImage.OBSTACLES.get(type);
        if(type==8) {
            thread = new Thread(this);
            thread.start();
        }
    }

    public void run()
    {
        while(true)
        {
            if(this.sc.isHasArrived())
            {
                if (this.y < 374)
                {
                    this.y += 5;
                }
                else
                {
                    this.sc.setFlag_To_Ground(true);
                }
            }

            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
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

    public BufferedImage getShow() {
        return show;
    }

    public static void main(String[] args) {

    }
}
