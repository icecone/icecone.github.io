//
// Created by Administrator on 2017/7/5.
//
#include <yanhan_com_ndkdemo_JNI.h>
#include <string.h>
#include "../../../../../../ndk/androidndkbuild/platforms/android-19/arch-x86/usr/include/jni.h"

/**
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char* _JString2CStr(JNIEnv* env, jstring jstr) {
        char* rtn = NULL;
        jclass clsstring = (*env)->FindClass(env, "java/lang/String");
        jstring strencode = (*env)->NewStringUTF(env,"GB2312");
        jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
        jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
        jsize alen = (*env)->GetArrayLength(env, barr);
        jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
        if(alen > 0) {
                rtn = (char*)malloc(alen+1); //"\0"
                memcpy(rtn, ba, alen);
                rtn[alen]=0;
        }
        (*env)->ReleaseByteArrayElements(env, barr, ba,0);
        return rtn;
}



jint Java_yanhan_com_ndkdemo_JNI_add(JNIEnv* env, jobject jobject1,jint ji,jint jj){
        int ab=ji+jj;
        return ab;
};

jstring Java_yanhan_com_ndkdemo_JNI_sayhello (JNIEnv* env, jobject jobject1, jstring jstr){
        char* inputdata="add from C";
        char* fromjava=_JString2CStr(env,jstr);
        //字符串的一个拼接，后面的会到前面去
        strcat(fromjava,inputdata);
        return (*env)->NewStringUTF(env,fromjava);
};

jintArray Java_yanhan_com_ndkdemo_JNI_increaseArrayEles
        (JNIEnv* env, jobject jobject1, jintArray jintArray1){
        //1.得到数组的长度
        jsize size=(*env)->GetArrayLength(env,jintArray1);
        //2.获得数组的元素,JNI_FALSE不开辟新的内存空间，true是开辟新的内存空间
        jint* intarray=(*env)->GetIntArrayElements(env,jintArray1,JNI_FALSE);
        int i=0;
        for (i;i<size;i++){
                *(intarray+i)+=10;
        }
        return jintArray1;
};


JNIEXPORT jint JNICALL Java_yanhan_com_ndkdemo_JNI_checkpwd
        (JNIEnv * env, jobject jobject1, jstring jstring1){
        char* pwd="123456";
        char* shurudata=_JString2CStr(env,jstring1);
        int code=strcasecmp(pwd,shurudata);
        if(code==0){
                return 200;
        }else{
                return 400;
        }

};