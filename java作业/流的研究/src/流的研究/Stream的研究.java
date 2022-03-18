package 流的研究;

import java.io.IOException;
import java.io.InputStream;

public class Stream的研究 {

	public static void main(String[] args) throws IOException {
		byte[] bf=new byte[1024];
		while(true)
		{
		int len=System.in.read(bf);
		System.out.println(len);
		String S=new String(bf,0,len);
		System.out.println(S);
		System.out.printf("S的长度是%d",S.length());
		}
	}

}
