import java.util.Scanner;

public class �������һ����_���λû��0 {

	public static void main(String[] args) {
		int n,ret,cnt,digit;
		while(true)
		{
			cnt=0;ret=0;digit=0;
			Scanner in=new Scanner(System.in);
			n=in.nextInt();
			do
			{
				digit=n%10;
				n=n/10;
				cnt++;
				ret=digit+(ret*10);
			}while(n>0);
			System.out.println(ret);
		}
	}

}
