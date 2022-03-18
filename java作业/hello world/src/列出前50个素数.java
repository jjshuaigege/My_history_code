
public class 列出前50个素数 {
	static boolean judge_prime(int n)
	{
		//先假定某个数是素数，然后判断该数能不能被1和自身之外的数整除
		boolean isprime=true;
		//首先判断是不是2以外的偶数
		if(n%2==0&&n!=2)
		{
			isprime=false;
		}
		else
		{
			//由于2是素数，只需从3开始论证某个数不是素数，又根据数学公式，只需论证到n的1/2次方
			for(int i=3;i<=Math.sqrt(n);i+=2)
			{
				if(n%i==0)
				{
					isprime=false;
					break;
				}
			}
		}
		//至此已论证完某个数不是素数的所有可能性
		return isprime;
	}
	public static void main(String[] args) {
		int n=1,cnt=0;
		while(cnt<50)
		{
			if(judge_prime(n))
			{
				System.out.print(n);
				cnt++;
				if(cnt%5==0)
				{
					System.out.println();
				}
				else
				{
					System.out.print(",");
				}
			}
			n++;
		}

	}

}
