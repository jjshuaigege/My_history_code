import java.util.Scanner;

public class �жϳɼ��Ƿ񼰸� {

	public static void main(String[] args) {
		final int standard=60;
		int grade;
		Scanner in=new Scanner(System.in);
		while(true)
		{
		System.out.print("��������ĳɼ�:");
		grade=in.nextInt();
		System.out.println("��ĳɼ���"+grade);
		if(grade>=standard)
		{
			System.out.println("��ϲ��ͨ����");
		}
		else
		{
			System.out.println("���ź���û��ͨ��");
			System.out.println("�ټ�");
		}
		}
	}

}
