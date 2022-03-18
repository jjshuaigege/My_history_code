import java.util.Scanner;
//1.A,B��Ҫ�໥֪���Է��Ĵ��ڣ�����ĳ����ķ�����Synchronize���Σ�ֻ�������ĳ�Ա����֮������γɽ���ͬ����ϵ!
//2.A,B֮��Synchronize����ָ����һ�ι̶�ʱ����A��B֮��ֻ��һ��һֱ��ռ��cpu�������ڼ䲢��Ӱ������������ı�����ռCPU.

public class Thread_Synchronize {
    public static int cnt=0;
    ThreadA A;
    ThreadB B;
    public Thread_Synchronize()
    {
        ThreadA A=new ThreadA();
        A.setName("A");
        ThreadB B=new ThreadB();
        B.setName("B");
        A.setDaemon(true);    //��A���ó��ػ��߳�
        A.start();
        B.start();
    }

    class ThreadA extends Thread
    {
        public void run()
        {
            System.out.println(Thread.currentThread().getName()+"��ʼ����");
            unique_way();
        }
    }
    class ThreadB extends Thread
    {
        public void run()
        {
            System.out.println(Thread.currentThread().getName()+"��ʼ����");
            unique_way();

        }

    }
    public synchronized void unique_way()
    {
        Scanner in=new Scanner(System.in);
        while(true)
        {
            if (Thread.currentThread().getName().equals("A")) {
                System.out.println("������A�߳�Ҫ˵�Ļ�");
                String words = in.nextLine();
                if (words.equals("Aexit")) {
                    break;
                } else
                System.out.println(words);
                if(cnt==0) {
                    try {
                        cnt++;
                        wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            } else if (Thread.currentThread().getName().equals("B")) {
                System.out.println("������B�߳�Ҫ˵�Ļ�");
                String words = in.nextLine();
                if (words.equals("Bexit")) {
                    break;
                } else
                    System.out.println(words);
                if(cnt==0) {
                    try {
                        cnt++;
                        wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
            cnt--;
            notify();
        }
    }


    public static void main(String[] args) {
        Thread_Synchronize test=new Thread_Synchronize();

    }
}
