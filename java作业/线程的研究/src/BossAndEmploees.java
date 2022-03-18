public class BossAndEmploees implements Runnable{
    Thread Zhang_worker=new Thread(this);
    Thread Wang_worker=new Thread(this);
    Thread Boss=new Thread(this);
    public BossAndEmploees()
    {
        Zhang_worker.setName("张工");
        Wang_worker.setName("王工");
        Boss.setName("老板");
    }

    @Override
    public void run()
    {
        int i=0;    //搬运了多少苹果
        int j=0;    //搬运了多少香蕉
        if(Thread.currentThread()==Zhang_worker)
        {
            while(true)
            {
                i++;
                System.out.println(Zhang_worker.getName()+"搬运了"+i+"箱苹果");
                try
                {
                    Thread.sleep(10000);
                }catch(InterruptedException e) {
                    System.out.println(Boss.getName()+"让"+Zhang_worker.getName()+"继续工作");
                }
                if(i==3)
                {
                    return;
                }
            }
        }
        else if(Thread.currentThread()==Wang_worker)
        {
            while(true)
            {
                j++;
                System.out.println(Wang_worker.getName()+"搬运了"+j+"箱香蕉");
                try
                {
                    Thread.sleep(10000);
                }catch(InterruptedException e) {
                    System.out.println(Boss.getName()+"让"+Wang_worker.getName()+"继续工作");
                }
                if(j==3)
                {
                    return;
                }
            }
        }
        else
        {
            while(true)
            {
                Zhang_worker.interrupt();
                Wang_worker.interrupt();
                if (!(Zhang_worker.isAlive() || Wang_worker.isAlive())) {
                    System.out.println(Boss.getName() + "宣布可以下班了");
                    return;
                }
            }
        }
    }



    public static void main(String[] args) {
        BossAndEmploees test=new BossAndEmploees();
        test.Zhang_worker.start();
        test.Wang_worker.start();
        test.Boss.start();

    }
}
