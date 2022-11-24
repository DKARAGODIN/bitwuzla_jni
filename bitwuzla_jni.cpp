#include <iostream>

#include <bitwuzla.h>
#include "bitwuzla_jni.hpp"

void abort_callback(const char* msg) {
    throw std::runtime_error(msg);
}

jobject Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaNew
(JNIEnv* env, jobject nativeJNI_class) {
    bitwuzla_set_abort_callback(abort_callback);
    try {
        Bitwuzla* bw = bitwuzla_new();
        jobject o = env->NewDirectByteBuffer((void*)bw, sizeof(Bitwuzla*));
        return o;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return exception;
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaDelete
(JNIEnv* env, jobject nativeJNI_class, jobject bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)env->GetDirectBufferAddress(bitwuzla);
        bitwuzla_delete(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaReset
(JNIEnv* env, jobject nativeJNI_class, jobject bitwuzla){
    try {
        Bitwuzla* bw = (Bitwuzla*)env->GetDirectBufferAddress(bitwuzla);
        bitwuzla_reset(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

jstring Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaCopyright
(JNIEnv* env, jobject nativeJNI_class, jobject bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)env->GetDirectBufferAddress(bitwuzla);
        const char* c = bitwuzla_copyright(bw);
        jstring result = env->NewStringUTF(c);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        jstring s = env->NewStringUTF(""); // ?
        return s;
    }
}

jobject Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkTrue
(JNIEnv* env, jobject nativeJNI_class, jobject bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)env->GetDirectBufferAddress(bitwuzla);
        const BitwuzlaTerm* term = bitwuzla_mk_true(bw);
        jobject o = env->NewDirectByteBuffer((void*)bw, sizeof(BitwuzlaTerm*));
        return o;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return exception;
    }
}