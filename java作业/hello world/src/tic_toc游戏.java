import java.util.Scanner;

public class tic_toc��Ϸ {

	public static void main(String[] args) {
		
		Scanner in=new Scanner(System.in);
		int[][] a=new int[3][3];
		while(true)
		{
		int isx=0;
		int iso=0;
		int win=-1;
		//��������
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				a[i][j]=in.nextInt();
			}
		}
		//�����
		for(int i=0;i<3;i++)
		{
			isx=0;iso=0;
			for(int j=0;j<3;j++)
			{
				if(a[i][j]==1)
				{
					isx++;
				}
				else
				{
					iso++;
				}
			}
			if(isx==3)
			{
				win=1;
			}
			else if(iso==3)
			{
				win=0;
			}
		}
		//�����
		for(int j=0;j<3;j++)
		{
			isx=0;iso=0;
			for(int i=0;i<3;i++)
			{
				if(a[i][j]==1)
				{
					isx++;
				}
				else
				{
					iso++;
				}
			}
			if(isx==3)
			{
				win=1;
			}
			else if(iso==3)
			{
				win=0;
			}
		}
		//�����б��
		isx=0;iso=0;
		for(int i=0,j=0;i<3;i++,j++)
		{
			if(a[i][j]==1)
			{
				isx++;
			}
			else
			{
				iso++;
			}
		}
		if(isx==3)
		{
			win=1;
		}
		else if(iso==3)
		{
			win=0;
		}
		//��鷴б��
		isx=0;iso=0;
		for(int i=0,j=2;i<3;i++,j--)
		{
			if(a[i][j]==1)
			{
				isx++;
			}
			else
			{
				iso++;
			}
		}
		if(isx==3)
		{
			win=1;
		}
		else if(iso==3)
		{
			win=0;
		}
		//��ӡ���
		switch(win)
		{
		case -1:System.out.println("ƽ�֣�");break;
		case 0:System.out.println("OӮ�ˣ���");break;
		case 1:System.out.println("XӮ�ˣ�");break;
		}
		}

}
}
