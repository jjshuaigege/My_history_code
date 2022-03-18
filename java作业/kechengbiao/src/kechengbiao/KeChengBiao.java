package kechengbiao;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class KeChengBiao {

	public static void main(String[] args) {
		JFrame frame=new JFrame();
		JTable table=new JTable(new KCBData());    //KCBData实现了TableModel接口,它决定了JTable的规格
		frame.add(table);
		JScrollPane pane=new JScrollPane(table);    //规定：要显示标题，必须将Jtable添加进JScrollPane，再将JScrollPane添加进JFrame。
		frame.add(pane);
		frame.pack();    //设置为最佳大小
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

	}

}
