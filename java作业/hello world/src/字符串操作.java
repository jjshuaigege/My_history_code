import java.util.Scanner;

public class �ַ������� {

	public static void main(String[] args) {
		String S1="shenguozhi�Ǹ�˧��,guozhishen�Ǹ�˧��";
		//����ÿһ���ַ�
		for(int i=0;i<S1.length();i++)
		{
			System.out.println(S1.charAt(i));
		}
		//�õ��Ӵ�
		System.out.println(S1.substring(4));
		System.out.println(S1.lastIndexOf("zhi"));
		System.out.println(S1.replace("˧��","����"));
		
		//ע�⣺���е��ַ������ǲ��ɱ��
		
		//�ַ�����switch-case�÷�
		Scanner in=new Scanner(System.in);
		String A=in.next();
		switch(A)
		{
		case "this":System.out.println("���");break;
		case "that":System.out.println("�Ǹ�");break;
		}
		//Math���ʹ��
		System.out.println(Math.abs(-3.5));
		System.out.println(Math.round(-3.2));
		System.out.println(Math.random());
		System.out.println(Math.pow(4, 0.5));

	}

}
