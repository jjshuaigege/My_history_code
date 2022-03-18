import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class LoadImage {

    //得到当前目录
    public static String path=System.getProperty("user.dir")+"\\src\\images\\";
    //定义一些变量
    //障碍物的图片容器(不会移动，可以交互)
    public static ArrayList<BufferedImage> OBSTACLES=new ArrayList<BufferedImage>();
    //背景图
    public static ArrayList<BufferedImage> BG=new ArrayList<BufferedImage>();
    //食人花
    public static ArrayList<BufferedImage> FLOWERS=new ArrayList<BufferedImage>();
    //蘑菇敌人
    public static ArrayList<BufferedImage> FUNGUSES=new ArrayList<BufferedImage>();
    //旗杆
    public static BufferedImage gan=null;
    //马里奥向左跳
    public static BufferedImage jump_L=null;
    //马里奥向右跳
    public static BufferedImage jump_R=null;
    //马里奥向左奔跑
    public static ArrayList<BufferedImage> RUN_L=new ArrayList<BufferedImage>();
    //马里奥向右奔跑
    public static ArrayList<BufferedImage> RUN_R=new ArrayList<BufferedImage>();
    //马里奥向左站立
    public static BufferedImage stand_L=null;
    //马里奥向右站立
    public static BufferedImage stand_R=null;
    //塔
    public static BufferedImage tower=null;

    public static void init()
    {
        try {
            //读取障碍物
            // 加载空中砖块
            OBSTACLES.add(ImageIO.read(new File(path + "brick.png")));      //0
            OBSTACLES.add(ImageIO.read(new File(path + "brick2.png")));     //1
            //加载水管
            for(int i=1;i<=4;i++)
            {
                OBSTACLES.add(ImageIO.read(new File(path + "pipe"+i+".png")));  //2到5
            }
            //加载地面砖块
            OBSTACLES.add(ImageIO.read(new File(path+"soil_base.png")));    //6
            OBSTACLES.add(ImageIO.read(new File(path+"soil_up.png")));      //7
            //加载旗帜
            OBSTACLES.add(ImageIO.read(new File(path+"flag.png")));
            //读取其他
            BG.add(ImageIO.read(new File(path+"bg.png")));
            BG.add(ImageIO.read(new File(path+"bg2.png")));
            for(int i=1;i<=2;i++)
            FLOWERS.add(ImageIO.read(new File(path+"flower1."+i+".png")));
            for(int i=1;i<=3;i++)
            {
                FUNGUSES.add(ImageIO.read(new File(path+"fungus"+i+".png")));
            }
            gan=ImageIO.read(new File(path+"gan.png"));
            jump_L=ImageIO.read(new File(path+"s_mario_jump1_L.png"));
            jump_R=ImageIO.read(new File(path+"s_mario_jump1_R.png"));
            RUN_L.add(ImageIO.read(new File(path+"s_mario_run1_L.png")));
            RUN_L.add(ImageIO.read(new File(path+"s_mario_run2_L.png")));
            RUN_R.add(ImageIO.read(new File(path+"s_mario_run1_R.png")));
            RUN_R.add(ImageIO.read(new File(path+"s_mario_run2_R.png")));
            stand_L=ImageIO.read(new File(path+"s_mario_stand_L.png"));
            stand_R=ImageIO.read(new File(path+"s_mario_stand_R.png"));
            tower=ImageIO.read(new File(path+"tower.png"));


        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {

        System.out.println(path);
        LoadImage.init();
        System.out.println(BG.get(0));
        System.out.println(stand_R);

    }
}
