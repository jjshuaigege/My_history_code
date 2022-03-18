import java.util.Scanner;

public class tic_toc游戏 {

	public static void main(String[] args) {
		
		Scanner in=new Scanner(System.in);
		int[][] a=new int[3][3];
		while(true)
		{
		int isx=0;
		int iso=0;
		int win=-1;
		//输入数据
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				a[i][j]=in.nextInt();
			}
		}
		//检查行
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
		//检查列
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
		//检查正斜线
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
		//检查反斜线
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
		//打印结果
		switch(win)
		{
		case -1:System.out.println("平局！");break;
		case 0:System.out.println("O赢了！！");break;
		case 1:System.out.println("X赢了！");break;
		}
		}

}
}
