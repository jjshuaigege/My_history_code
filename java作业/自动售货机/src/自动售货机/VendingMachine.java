package �Զ��ۻ���;

public class VendingMachine {
	private int price=15;       //��Ʒ�ļ۸�
	private int balance;     //������Ŀ
	private int total;       //�ۻ������Ǯ�ж���
	//��дһ�����캯��
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
	public void showprompt() //��ӡ��ӭ��Ϣ
	{
		System.out.println("��ӭʹ���Զ��ۻ���,"+"ÿƿ����"+price+"��");
	}
	public void return_balance() //����
	{
		System.out.println("������"+balance+"Ԫ");
		balance=0;
	}
	public void insert_money(int amount)
	{
		balance+=amount;
		System.out.println("���յ�"+amount+"Ԫ");
	}
	public void sell_food()
	{
		while(balance>=price)
		{
			System.out.println("�۳�һƿ���̣������");
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
