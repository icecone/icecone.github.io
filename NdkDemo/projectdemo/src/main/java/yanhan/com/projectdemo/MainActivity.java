package yanhan.com.projectdemo;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.ImageView;

import com.mt.mtxx.image.JNI;

public class MainActivity extends Activity {

    JNI jni;
    ImageView iv_show;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.content_main);
        jni=new JNI();
        iv_show= (ImageView) findViewById(R.id.iv_show);
        findViewById(R.id.btn_demo1).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(final View v) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        lomodHDK(v);
                    }
                }).start();
            }
        });
        findViewById(R.id.btn_demo2).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(final View v) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        lomoc(v);
                    }
                }).start();
            }
        });
        findViewById(R.id.btn_demo3).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(final View v) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        lomodB(v);
                    }
                }).start();
            }
        });

    }

    public  void lomodHDK(View view){
        Bitmap bitmap= BitmapFactory.decodeResource(getResources(),R.drawable.abc);
        int[] pixels=new int[bitmap.getWidth()*bitmap.getHeight()];
        bitmap.getPixels(pixels,0,bitmap.getWidth(),0,0,bitmap.getWidth(),bitmap.getHeight());
        jni.StyleLomoHDR(pixels, bitmap.getWidth(), bitmap.getHeight());
        bitmap=Bitmap.createBitmap(pixels,bitmap.getWidth(),bitmap.getHeight(), Bitmap.Config.ARGB_8888);
        iv_show.setImageBitmap(bitmap);
    }

    public void lomoc(View v){
        Bitmap bitmap=BitmapFactory.decodeResource(getResources(),R.drawable.abc);
        int[] pexils=new int[bitmap.getWidth()*bitmap.getHeight()];
        bitmap.getPixels(pexils,0,bitmap.getWidth(),0,0,bitmap.getWidth(),bitmap.getHeight());
        jni.StyleLomoC(pexils, bitmap.getWidth(), bitmap.getHeight());
        bitmap=Bitmap.createBitmap(pexils,bitmap.getWidth(),bitmap.getHeight(), Bitmap.Config.ARGB_8888);
        iv_show.setImageBitmap(bitmap);
    }

    public  void lomodB(View view){
        Bitmap bitmap= BitmapFactory.decodeResource(getResources(),R.drawable.abc);
        int[] pixels=new int[bitmap.getWidth()*bitmap.getHeight()];
        bitmap.getPixels(pixels,0,bitmap.getWidth(),0,0,bitmap.getWidth(),bitmap.getHeight());
        jni.StyleLomoB(pixels, bitmap.getWidth(), bitmap.getHeight());
        bitmap=Bitmap.createBitmap(pixels,bitmap.getWidth(),bitmap.getHeight(), Bitmap.Config.ARGB_8888);
        iv_show.setImageBitmap(bitmap);
    }

}
