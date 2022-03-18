public class ¼Ì³ÐµÄÑÐ¾¿ {
    public static class Father
    {
        private int value=10;

        public int getValue() {
            return value;
        }

        public Father(int value) {
            this.value = value;
        }
    }
    public static class Son extends Father
    {
        private int value=20;
        public int son_getValue()
        {
            return value;
        }

        public Son(int value, int value1) {
            super(value);
            this.value = value1;
        }
    }

    public static void main(String[] args) {
        Son s=new Son();
        System.out.println(s.son_getValue());

    }
}
