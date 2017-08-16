//
// Created by Administrator on 2017/7/9.
//
#include <yanhan_com_mycalljava_JNI.h>
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>

#include <android/log.h>
#define LOG_TAG "System.outokkk"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

JNIEXPORT void JNICALL Java_yanhan_com_mycalljava_JNI_callbackadd(JNIEnv* env,jobject jobject1){
    //GetSuperclass1.得到字节码
    jclass  jclass1=(*env)->FindClass(env,"yanhan/com/mycalljava/JNI");
    //获取里面的方法,(*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //2.得到方法
    jmethodID jmethodID1=(*env)->GetMethodID(env,jclass1,"add","(II)I");
    //实例化类
    jobject jobject2=(*env)->AllocObject(env,jclass1);
    //执行方法
    jint result=(*env)->CallIntMethod(env,jobject2,jmethodID1,230,809);
    printf("vaule=:>>%d\n",result);
    LOGE("vaule=:>>%d\n",result);
};
/**
 * 让C代码调用
     * public void helloFromJava()
 */
JNIEXPORT void JNICALL Java_yanhan_com_mycalljava_JNI_callbackFromJava
        (JNIEnv * env, jobject jobject1){
    jclass jclass1=(*env)->FindClass(env,"yanhan/com/mycalljava/JNI");
    jmethodID jmethodID1=(*env)->GetMethodID(env,jclass1,"helloFromJava","()V");
    jobject  jobject2=(*env)->AllocObject(env,jclass1);
    (*env)->CallVoidMethod(env,jobject2,jmethodID1);
};


JNIEXPORT void JNICALL Java_yanhan_com_mycalljava_JNI_callbackprintString
        (JNIEnv * env, jobject jobject1){
    jclass jclass1=(*env)->FindClass(env,"yanhan/com/mycalljava/JNI");
    jmethodID jmethodID1=(*env)->GetMethodID(env,jclass1,"printString","(Ljava/lang/String;)V");
    jobject  jobject2=(*env)->AllocObject(env,jclass1);
    jstring  jstring1=(*env)->NewStringUTF(env,"i have a apple");
    (*env)->CallVoidMethod(env,jobject2,jmethodID1,jstring1);
};

JNIEXPORT void JNICALL Java_yanhan_com_mycalljava_JNI_callbackSayHello
        (JNIEnv * env, jobject jobject1){
    jclass jclass1=(*env)->FindClass(env,"yanhan/com/mycalljava/JNI");
    jmethodID jmethodID1=(*env)->GetStaticMethodID(env,jclass1,"sayHello","(Ljava/lang/String;)V");
    jstring  jstring1=(*env)->NewStringUTF(env,"i have a apple");
    (*env)->CallStaticVoidMethod(env,jclass1,jmethodID1,jstring1);

};

void Java_yanhan_com_mycalljava_MainActivity_showToast
        (JNIEnv * env, jobject jobject1){
    jclass jclass1=(*env)->FindClass(env,"yanhan/com/mycalljava/MainActivity");
    jmethodID jmethodID1=(*env)->GetMethodID(env,jclass1,"setTv_show","()V");
    (*env)->CallVoidMethod(env,jobject1,jmethodID1);

};