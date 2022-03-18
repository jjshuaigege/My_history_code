public class RestThread extends Thread{
    @Override
    public void run()
    {
        System.out.println("线程2开始启动！");
        ThreadTest.rest();
    }
    public static void main(String[] args) {

    }
}
