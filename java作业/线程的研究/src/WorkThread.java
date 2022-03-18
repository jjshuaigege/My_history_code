public class WorkThread extends Thread{
    @Override
    public void run()
    {
        System.out.println("线程1开始启动！");
        ThreadTest.work();
    }

    public static void main(String[] args) {


    }
}
