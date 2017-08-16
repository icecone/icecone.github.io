package yanhan.com.gouludemo;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

/**
 * Created by Administrator on 2017/7/11.
 */
public class Process extends View{

    Paint paint;
    int processint;

    public Process(Context context) {
        super(context);
        paint=new Paint();
        paint.setAntiAlias(true);
        paint.setDither(true);
        paint.setTextSize(20);
    }

    public void setProcessint(int processint) {
        this.processint=processint;
        postInvalidate();
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        if (processint>200){
            paint.setColor(Color.RED);
            canvas.drawText("快点跑，有危险",30,getHeight()/4,paint);
        }else{
            paint.setColor(Color.GRAY);
            canvas.drawRect(10,10,60,300,paint);
            if (processint>100){
                paint.setColor(Color.RED);
                canvas.drawRect(10, 300 - processint, 60, 300, paint);
            }else{
                paint.setColor(Color.GREEN);
                canvas.drawRect(10,300 - processint,60,300,paint);
            }
        }
    }
}
