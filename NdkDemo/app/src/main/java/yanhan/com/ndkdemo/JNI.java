package yanhan.com.ndkdemo;

/**
 * Created by Administrator on 2017/7/4.
 */
public class JNI {
    static {
        System.loadLibrary("Hello");   //defaultConfig.ndk.moduleName
    }
    /**
     * 让c进行加法运算，之后返回
     * @return
     */
    public native int add(int ji,int ab);
    /**
     * 定义native方法
     * 调用c代码对应的方法
     * java的字符串加上c的字符串
     * @return
     */
    public native String sayhello(String datazhi);

    /**
     * 让c进行加法运算，之后返回
     * @return
     */
    public native int[] increaseArrayEles(int[] intArrays);

    /**
     * 让c进行加法运算，之后返回
     * @return
     */
    public native int checkpwd(String pwd);


}
