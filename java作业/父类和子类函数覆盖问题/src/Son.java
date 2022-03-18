public class Son extends Father{
    @Override
    public void print1()
    {
        System.out.println("×ÓÀàµÄprint1");
    }
    public void finalprint()
    {
        print1();
    }


    public static void main(String[] args) {
        Son S=new Son();
        S.finalprint();

    }
}
