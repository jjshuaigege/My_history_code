public class ThreadTest {
    public static void rest()
    {
        for(int i=0;i<10;i++) {
            System.out.println("��ǰ�̣߳�"+Thread.currentThread().getName());
            System.out.println("��Ϣ");
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    public static void work()
    {
        for(int i=0;i<10;i++) {
            System.out.println("��ǰ�̣߳�"+Thread.currentThread().getName());
            System.out.println("����");
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        //��ʵ�ֽӿ�Runnable�������̶߳���,ʵ�ַ���������һ��ʵ��Runnable�ӿڵ���,������ഴ��һ������x�������ù��캯��-Thread(Runnable x)
        class nthread implements Runnable{
            @Override
            public void run()
            {
                System.out.println("���߳̿�ʼִ��");
                for(int i=0;i<10;i++)
                {
                    System.out.println("��ǰ�߳�:"+Thread.currentThread().getName());
                    System.out.println("Hi,����һ�����߳�");
                    try
                    {
                        Thread.sleep(100);
                    }catch (InterruptedException e)
                    {
                        e.printStackTrace();
                    }
                }

            }



        }
        nthread NT=new nthread();


        WorkThread WT=new WorkThread();
        RestThread RT=new RestThread();
        Thread NTRC=new Thread(NT);

        NTRC.start();
        WT.start();
        RT.start();
        System.out.println("��main�У����̶߳��Ѿ�ִ�й�start");
//        for(int i=0;i<5000;i++)
//        {
//            System.out.println(i);
//        }
//        ThreadTest.rest();
//        ThreadTest.work();


    }
}
