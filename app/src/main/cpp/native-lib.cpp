#include <jni.h>
#include <string>
// 日志输出
#include <android/log.h>
#define TAG "cyh--c"
//__VA_ARGS_- 代表...的可变参数
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__);
#define LOGI(...) __android_Log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__);
extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_changeName(JNIEnv *env, jobject mainActivityThis) {
    // TODO: implement changeName()
    jclass mainActivityCls = env->FindClass("com/example/myapplication/MainActivity");
    jfieldID nameFid = env->GetFieldID(mainActivityCls, "name", "Ljava/lang/String;");
    jstring value = env->NewStringUTF("修改为beyound");
    env->SetObjectField(mainActivityThis,nameFid, value);

}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_changeAge(JNIEnv *env, jclass mainActivityCls) {
    // TODO: implement changeAge()
//    jclass mainActivityCls = env->GetObjectClass(mainActivityThis);
    jfieldID ageFid = env->GetStaticFieldID(mainActivityCls, "age", "I");
    env->SetStaticIntField(mainActivityCls,ageFid, 29);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_callMethod(JNIEnv *env, jobject mainActivitThis) {
    // TODO: implement callMethod()
    jclass mainActivitcls = env->GetObjectClass(mainActivitThis);
// jmethodID (*GetMethodID)(JNIEnv*，jclass，const char*，const char*);
    jmethodID addMid = env->GetMethodID(mainActivitcls,"add","(II)I");
// jint CallIntMethod(jobject obj，jmethodID methodID，...
    int result = env->CallIntMethod(mainActivitThis,addMid,1,1);
    LOGD("result:%d\n",result);
    //++++++++++++++++++++++ C调用 public String showString(String str,int value) 函数
    jmethodID showStringMid = env->GetMethodID(mainActivitcls, "showString", "(Ljava/lang/String;I)Ljava/lang/String;");
// jobject(*CattobjectMethod)(jobject，jmethodID，...);
    jstring value = env->NewStringUTF("李元霸");
    jstring resultStr = (jstring) env->CallObjectMethod(mainActivitThis, showStringMid, value, 9527);
    const char * resultCstr = env->GetStringUTFChars(resultStr,NULL);
    LOGD("==:%s\n", resultCstr);
}