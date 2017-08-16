package yanhan.com.mycalljava;

import android.util.Log;

/**
 * Created by Administrator on 2017/7/9.
 */
public class JNI {

    {
        System.loadLibrary("TestCJava");
    }

    //调用c中的add方法
    public native void callbackadd();
    //让c代码调用helloFromJava()
    public native void callbackFromJava();
    //打印printnf
    public native void callbackprintString();
    //执行静态方法函数
    public native void callbackSayHello();


    public int add(int x, int y) {
        Log.e("TAG", "add() x=" + x + " y=" + y);
        return x + y;
    }

    public void helloFromJava() {
        Log.e("TAG", "helloFromJava()");
    }

    public void printString(String s) {
        Log.e("TAG", "C中输入的：" + s);
    }

    public static void sayHello(String s){
        Log.e("TAG",  "我是java代码中的JNI."
                + "java中的sayHello(String s)静态方法，我被C调用了:"+ s);
    }

}
