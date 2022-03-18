package 自动售货机;

public class VendingMachine {
	private int price=15;       //商品的价格
	private int balance;     //找零数目
	private int total;       //售货机里的钱有多少
	//先写一个构造函数
	VendingMachine(int price,int balance,int total)
	{
		this.price=price;
		this.balance=balance;
		this.total=total;
	}
	public void set_price(int price)
	{
		this.price=price;
	}
	public void showprompt() //打印欢迎信息
	{
		System.out.println("欢迎使用自动售货机,"+"每瓶酸奶"+price+"块");
	}
	public void return_balance() //找零
	{
		System.out.println("找您："+balance+"元");
		balance=0;
	}
	public void insert_money(int amount)
	{
		balance+=amount;
		System.out.println("已收到"+amount+"元");
	}
	public void sell_food()
	{
		while(balance>=price)
		{
			System.out.println("售出一瓶酸奶，请查收");
			balance=balance-price;
			total=total+price;
		}
	}

	public static void main(String[] args) {
		VendingMachine vm=new VendingMachine(18,0,1200);
		vm.showprompt();
		vm.insert_money(100);
		vm.sell_food();
		vm.return_balance();
		
	}

}
