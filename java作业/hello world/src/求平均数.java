import java.util.Scanner;

public class ��ƽ���� {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int cnt,sum,n;
		sum=0;
		cnt=0;
		while(true)
		{
			while(true)
			{
				n=in.nextInt();
				if(n!=-1)
				{
					sum+=n;
					cnt++;
				}
				else
				{
					break;
				}
			}
			if(cnt>0)
			{
				System.out.println("ƽ����Ϊ"+(double)sum/cnt);
			}
		}
	}

}
