public class BossAndEmploees implements Runnable{
    Thread Zhang_worker=new Thread(this);
    Thread Wang_worker=new Thread(this);
    Thread Boss=new Thread(this);
    public BossAndEmploees()
    {
        Zhang_worker.setName("�Ź�");
        Wang_worker.setName("����");
        Boss.setName("�ϰ�");
    }

    @Override
    public void run()
    {
        int i=0;    //�����˶���ƻ��
        int j=0;    //�����˶����㽶
        if(Thread.currentThread()==Zhang_worker)
        {
            while(true)
            {
                i++;
                System.out.println(Zhang_worker.getName()+"������"+i+"��ƻ��");
                try
                {
                    Thread.sleep(10000);
                }catch(InterruptedException e) {
                    System.out.println(Boss.getName()+"��"+Zhang_worker.getName()+"��������");
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
                System.out.println(Wang_worker.getName()+"������"+j+"���㽶");
                try
                {
                    Thread.sleep(10000);
                }catch(InterruptedException e) {
                    System.out.println(Boss.getName()+"��"+Wang_worker.getName()+"��������");
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
                    System.out.println(Boss.getName() + "���������°���");
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
