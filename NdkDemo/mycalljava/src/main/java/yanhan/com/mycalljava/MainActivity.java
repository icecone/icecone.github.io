package yanhan.com.mycalljava;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

    {
        System.loadLibrary("TestCJava");
    }

    TextView tv_show;
    JNI jni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.content_main);
        tv_show= (TextView) findViewById(R.id.tv_show);
        jni=new JNI();

        findViewById(R.id.btn_show1).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                jni.callbackadd();
            }
        });
        findViewById(R.id.btn_show2).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                jni.callbackFromJava();
            }
        });
        findViewById(R.id.btn_show3).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                jni.callbackprintString();
            }
        });
        findViewById(R.id.btn_show4).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                jni.callbackSayHello();
                showToast();
            }
        });
    }

    public native void showToast();

    public void setTv_show(){
        System.out.println("showToast----------------");
        Toast.makeText(MainActivity.this,"sjkjsf",Toast.LENGTH_SHORT).show();
    }

}
