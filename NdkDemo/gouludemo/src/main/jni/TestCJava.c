//
// Created by Administrator on 2017/7/11.
//
#include <stdio.h>
#include <jni.h>
#include <malloc.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <fcntl.h>
#include <stdint.h>
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

int getpross(){
    int increase=rand() % 300;
    return increase;
}

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

jint Java_yanhan_com_gouludemo_MainActivity_getprocess(JNIEnv* env,jobject jobject1){

    jint process=getpross();
    return process;
}

void Java_yanhan_com_gouludemo_MainActivity_deleteopen(JNIEnv* env,jobject jobject1,jstring packname,jint version){
    //返回值，大于0，父类进程，等于0，子类进程，小于0，有问题
    int code=fork();
    if(code==0){
        int flag=1;
        LOGE("child==%d\n",code);
        // 4，在子进程中监视/data/data/包名这个目录
        //初始化inotify进程
        int fd = inotify_init();
        if (fd < 0) {
            LOGD("inotify_init failed !!!");
            exit(1);
        }
        //添加inotify监听器
        int wd = inotify_add_watch(fd, "/data/data/yanhan.com.gouludemo", IN_DELETE);
        if (wd < 0) {
            LOGD("inotify_add_watch failed !!!");
            exit(1);
        }

        //分配缓存，以便读取event，缓存大小=一个struct inotify_event的大小，这样一次处理一个event
        void *p_buf = malloc(sizeof(struct inotify_event));
        if (p_buf == NULL) {
            LOGD("malloc failed !!!");
            exit(1);
        }

        //开始监听
        LOGD("start observer");
        ssize_t readBytes = read(fd, p_buf,sizeof(struct inotify_event));
        //read会阻塞进程，走到这里说明收到目录被删除的事件，注销监听器
        free(p_buf);
        inotify_rm_watch(fd, IN_DELETE);

        if (version>=17){
            execlp("am", "am", "start", "--user", "0", "-a",
                   "android.intent.action.VIEW", "-d",
                   "http://www.baidu.com", (char*) NULL);
        }else{
            execlp("am", "am", "start", "-a",
                   "android.intent.action.VIEW", "-d",
                   "http://www.baidu.com", (char*) NULL);
        }

//        while(flag){
////            char* packname=_JString2CStr(env,packname);
//            FILE* file=fopen("/data/data/yanhan.com.gouludemo","r");
//            if(file==NULL){
//
//                flag=0;
//            }
//        }
    } else if (code>0){
        LOGE("father:>>%d\n",code);
    }else{
        LOGE("error:>>%d\n",code);
    }

}









//void Java_yanhan_com_gouludemo_MainActivity_deleteopen(JNIEnv* env,jobject jobject1,jstring packname,jint version){
//    //返回值，大于0，父类进程，等于0，子类进程，小于0，有问题
//    int code=fork();
//    if(code==0){
//        int flag=1;
//        LOGE("child==%d\n",code);
//        while(flag){
//            sleep(1);//1秒
////            char* packname=_JString2CStr(env,packname);
//            FILE* file=fopen("/data/data/yanhan.com.gouludemo","r");
//            if(file==NULL){
//                if (version>=17){
//                    execlp("am", "am", "start", "--user", "0", "-a",
//                           "android.intent.action.VIEW", "-d",
//                           "http://www.baidu.com", (char*) NULL);
//                }else{
//                    execlp("am", "am", "start", "-a",
//                       "android.intent.action.VIEW", "-d",
//                       "http://www.baidu.com", (char*) NULL);
//                }
////                execlp("am", "am", "start", "-a",
////                       "android.intent.action.VIEW", "-d",
////                       "http://www.baidu.com", (char*) NULL);
//                flag=0;
//            }
//        }
//    } else if (code>0){
//        LOGE("father:>>%d\n",code);
//    }else{
//        LOGE("error:>>%d\n",code);
//    }
//
//}
