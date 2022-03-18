import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Music            {
    String str=System.getProperty("user.dir")+"\\src\\music\\music.wav";
    Player player= null;
    public Music()
    {
        try {
            player = new Player(new BufferedInputStream(new FileInputStream(str)));
        } catch (JavaLayerException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        try {
            player.play();
        } catch (JavaLayerException e) {
            e.printStackTrace();
        }
        System.out.println(str);
    }
    public static void main(String[] args) {


    }
}
