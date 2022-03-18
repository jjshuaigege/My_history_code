public class ThreadTest {
    public static void rest()
    {
        for(int i=0;i<10;i++) {
            System.out.println("当前线程："+Thread.currentThread().getName());
            System.out.println("休息");
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
            System.out.println("当前线程："+Thread.currentThread().getName());
            System.out.println("工作");
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        //以实现接口Runnable来创建线程对象,实现方法：创建一个实现Runnable接口的类,用这个类创建一个对象x，最后调用构造函数-Thread(Runnable x)
        class nthread implements Runnable{
            @Override
            public void run()
            {
                System.out.println("新线程开始执行");
                for(int i=0;i<10;i++)
                {
                    System.out.println("当前线程:"+Thread.currentThread().getName());
                    System.out.println("Hi,我是一个新线程");
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
        System.out.println("在main中，两线程都已经执行过start");
//        for(int i=0;i<5000;i++)
//        {
//            System.out.println(i);
//        }
//        ThreadTest.rest();
//        ThreadTest.work();


    }
}
