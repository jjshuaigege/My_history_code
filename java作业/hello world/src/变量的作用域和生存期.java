
public class 变量的作用域和生存期 {

	public static void main(String[] args) {	
		{
			int k=2;
			System.out.println(k);
		}
		System.out.println(k);

	}

}
