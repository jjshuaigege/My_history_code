import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class LoadImage {

    //�õ���ǰĿ¼
    public static String path=System.getProperty("user.dir")+"\\src\\images\\";
    //����һЩ����
    //�ϰ����ͼƬ����(�����ƶ������Խ���)
    public static ArrayList<BufferedImage> OBSTACLES=new ArrayList<BufferedImage>();
    //����ͼ
    public static ArrayList<BufferedImage> BG=new ArrayList<BufferedImage>();
    //ʳ�˻�
    public static ArrayList<BufferedImage> FLOWERS=new ArrayList<BufferedImage>();
    //Ģ������
    public static ArrayList<BufferedImage> FUNGUSES=new ArrayList<BufferedImage>();
    //���
    public static BufferedImage gan=null;
    //�����������
    public static BufferedImage jump_L=null;
    //�����������
    public static BufferedImage jump_R=null;
    //�����������
    public static ArrayList<BufferedImage> RUN_L=new ArrayList<BufferedImage>();
    //��������ұ���
    public static ArrayList<BufferedImage> RUN_R=new ArrayList<BufferedImage>();
    //���������վ��
    public static BufferedImage stand_L=null;
    //���������վ��
    public static BufferedImage stand_R=null;
    //��
    public static BufferedImage tower=null;

    public static void init()
    {
        try {
            //��ȡ�ϰ���
            // ���ؿ���ש��
            OBSTACLES.add(ImageIO.read(new File(path + "brick.png")));      //0
            OBSTACLES.add(ImageIO.read(new File(path + "brick2.png")));     //1
            //����ˮ��
            for(int i=1;i<=4;i++)
            {
                OBSTACLES.add(ImageIO.read(new File(path + "pipe"+i+".png")));  //2��5
            }
            //���ص���ש��
            OBSTACLES.add(ImageIO.read(new File(path+"soil_base.png")));    //6
            OBSTACLES.add(ImageIO.read(new File(path+"soil_up.png")));      //7
            //��������
            OBSTACLES.add(ImageIO.read(new File(path+"flag.png")));
            //��ȡ����
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
