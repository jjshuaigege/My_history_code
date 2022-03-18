
public class 求前50个素数 {

	public static void main(String[] args) {
		int[] primes=new int[50];
		primes[0]=2;
		int x,cnt;
		cnt=1;
		out:
		for(x=3;cnt<50;x+=2)
		{
			boolean isprime=true;
			for(int i=0;i<cnt;i++)
			{
				if(x%primes[i]==0)
				{
					isprime=false;
					continue out;
				}
			}
			if(isprime==true)
			{
				primes[cnt++]=x;
			}
		}
		for(int i=0;i<primes.length;i++)
		{
			System.out.print(primes[i]+" ");
			if((i+1)%10==0)
			{
				System.out.println();
			}
		}

	}

}
