package 文件操作;

import java.io.*;

public class 文本方式的文件操作 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//1.在流上建立文本处理
		PrintWriter pw;
		try {
			pw = new PrintWriter(
					new BufferedWriter(
							new OutputStreamWriter(
									new FileOutputStream("abc.txt"))));
			pw.write("你好！");
			pw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//2.
	}

}
