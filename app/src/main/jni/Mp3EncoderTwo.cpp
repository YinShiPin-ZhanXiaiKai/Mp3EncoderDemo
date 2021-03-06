//
// Created by WuHang on 2018/9/3 0003.
//

#include "cn_yunyunhei_mp3encoderdemo_studio_Mp3EncoderTwo.h"
#include "../cpp/mp3_encoder.h"

static mp3_encoder *mp3Encoder = NULL;

JNIEXPORT int JNICALL
Java_cn_yunyunhei_mp3encoderdemo_studio_Mp3EncoderTwo_init
        (JNIEnv *env, jobject obj, jstring pcmPathParam, jint channels, jint bitRate,
         jint sampleRate, jstring mp3PathParam) {
    const char *pcmPath = env->GetStringUTFChars(pcmPathParam, NULL);
    const char *mp3Path = env->GetStringUTFChars(mp3PathParam, NULL);
    mp3Encoder = new mp3_encoder();
    mp3Encoder->Init(pcmPath, mp3Path, sampleRate, channels, bitRate);
    env->ReleaseStringUTFChars(mp3PathParam, mp3Path);
    env->ReleaseStringUTFChars(pcmPathParam, pcmPath);
    return 0;
}

JNIEXPORT void JNICALL
Java_cn_yunyunhei_mp3encoderdemo_studio_Mp3EncoderTwo_encode(JNIEnv *env, jobject obj) {
    mp3Encoder->Encode();
}

JNIEXPORT void JNICALL
Java_cn_yunyunhei_mp3encoderdemo_studio_Mp3EncoderTwo_destroy(JNIEnv *env, jobject obj) {
    mp3Encoder->Destory();
}