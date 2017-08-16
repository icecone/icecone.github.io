package yanhan.com.gouludemo;

import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.os.SystemClock;

public class MainActivity extends Activity {

    {
     System.loadLibrary("TestCJava");
    }

    Process process;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        process=new Process(this);
        setContentView(process);

        deleteopen("/data/data/"+getPackageName(), Build.VERSION.SDK_INT);

//        new Thread(new Runnable() {
//            @Override
//            public void run() {
//                while (true){
//                    SystemClock.sleep(500);
//                    int show=Math.abs(getprocess());
//                    process.setProcessint(show);
//                }
//            }
//        }).start();
    }

    public native int getprocess();

    public native int deleteopen(String packname,int version);

}
