import java.util.Scanner;
//1.A,B需要相互知道对方的存在！即若某个类的方法被Synchronize修饰，只有这个类的成员变量之间才能形成进程同步关系!
//2.A,B之间Synchronize化后，指的是一段固定时间内A，B之间只有一个一直在占用cpu，在这期间并不影响其他的类外的变量抢占CPU.

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
        A.setDaemon(true);    //将A设置成守护线程
        A.start();
        B.start();
    }

    class ThreadA extends Thread
    {
        public void run()
        {
            System.out.println(Thread.currentThread().getName()+"开始运行");
            unique_way();
        }
    }
    class ThreadB extends Thread
    {
        public void run()
        {
            System.out.println(Thread.currentThread().getName()+"开始运行");
            unique_way();

        }

    }
    public synchronized void unique_way()
    {
        Scanner in=new Scanner(System.in);
        while(true)
        {
            if (Thread.currentThread().getName().equals("A")) {
                System.out.println("请输入A线程要说的话");
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
                System.out.println("请输入B线程要说的话");
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
