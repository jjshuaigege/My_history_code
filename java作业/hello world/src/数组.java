import java.util.Scanner;

public class ���� {

	public static void main(String[] args) {
		int[] a= {1,2,3,4,5};
//		int[] b=a;
//		b[0]=10;
//		System.out.println(a[0]);
		int x;
		Scanner in=new Scanner(System.in);
		x=in.nextInt();
		boolean isfound=false;
		int loc=-1
//		for(int i=0;i<a.length;i++)
		for(int i:a)
		{
			if(i==x)
			{
				isfound=true;
				System.out.println("�ҵ��ˣ�"+x+"�ڵ�"+i+"��λ��");
			}
		}
		if(isfound==false)
		{
			System.out.println("û�ҵ�"+x);
		}
	}

}
