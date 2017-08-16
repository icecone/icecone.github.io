package yanhan.com.ndkdemo;

import android.app.Activity;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

    Button tv_show1,tv_show2,tv_show3,tv_show4;
    TextView tv_data;
    JNI jni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.content_main);

        tv_show1= (Button) findViewById(R.id.tv_show1);
        tv_show2= (Button) findViewById(R.id.tv_show2);
        tv_show3= (Button) findViewById(R.id.tv_show3);
        tv_show4= (Button) findViewById(R.id.tv_show4);
        tv_data= (TextView) findViewById(R.id.tv_data);
        jni=new JNI();

        tv_show1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_data.setText(jni.add(300, 300)+">>>");
            }
        });
        final int[] arrayint={1,232,12,312,354};
        tv_show2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                jni.increaseArrayEles(arrayint);
                String strname="";
                for (int i=0;i<arrayint.length;i++){
                    strname+=arrayint[i]+"<>";
                }
                tv_data.setText(strname+">>>");
            }
        });
        tv_show3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_data.setText(jni.sayhello("nihaoaaa")+">>>");
            }
        });
        tv_show4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv_data.setText(jni.checkpwd("nihaoaaa")+">>>");
            }
        });

    }

}
