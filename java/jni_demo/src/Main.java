public class Main {

    static {
/*        String libTest = "D:\\kyf\\my-workspace\\jni_demo\\lib\\test.dll";
        System.load(libTest);*/
        String libTestJni = "D:\\kyf\\my-workspace\\jni_demo\\lib\\Test_Jni.dll";
        System.load(libTestJni);
    }

    public static void main(String[] args) {
        test1();
    }

    public static void test1(){

        Test_Jni t = new Test_Jni();
        long begin = System.currentTimeMillis();
        for( int i=0; i<1000000; i++) {
            t.CharJoin("abcdef","ghxi");
            //System.out.println(t.CharJoin2("abcdef","ghxi"));
       }
        long time = System.currentTimeMillis() - begin;
        System.out.println("================================="+time);
    }

    public static void test2(){
        long begin = System.currentTimeMillis();
        for( int i=0; i<1000000; i++) {
            CharJoin("abcdef","ghxi");
        }
        System.out.println(System.currentTimeMillis() - begin);
    }

    public static String CharJoin(String var1, String var2) {
        return var1 + var2;
    }
}
