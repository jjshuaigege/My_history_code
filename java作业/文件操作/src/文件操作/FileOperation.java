//二进制
package 文件操作;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileOperation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		byte[] buf=new byte[10];
		for(int i=0;i<buf.length;i++)
		{
			buf[i]=(byte)i;
		}
		String S="new a file";
		try
		{
			DataOutputStream out=new DataOutputStream(new BufferedOutputStream(new FileOutputStream("a.txt")));
			int i=121;
			out.writeInt(i);;
			out.close();
		}
		catch(FileNotFoundException e)
		{
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
