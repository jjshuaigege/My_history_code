package 布局管理器的研究;
import java.awt.*;
public class Calculator_Interface {
    public static void main(String[] args) {
        Frame frame=new Frame();
        frame.setLayout(new BorderLayout(15,15));
        frame.add(new TextField(),BorderLayout.NORTH);
        Panel panel=new Panel();
        panel.setLayout(new GridLayout(3,5,5,5));
        for(int i=0;i<10;i++)
        panel.add(new Button(""+i));
        panel.add(new Button("+"));
        panel.add(new Button("_"));
        panel.add(new Button("*"));
        panel.add(new Button("/"));
        panel.add(new Button("."));
        frame.add(panel,BorderLayout.CENTER);

        frame.pack();
        frame.setVisible(true);


    }
}
