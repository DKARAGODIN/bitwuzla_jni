#include <iostream>

#include <bitwuzla.h>
#include "bitwuzla_jni.hpp"

JNIEXPORT jobject JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzla_1new
(JNIEnv* env, jobject zhis) {
    Bitwuzla* bw = bitwuzla_new();
    jobject o = env->NewDirectByteBuffer((void*)bw, sizeof(Bitwuzla*));
    return o;
}

JNIEXPORT jobject JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzla_1mk_1true
(JNIEnv* env, jobject zhis, jobject bitwuzla) {
    Bitwuzla* bw = (Bitwuzla*) env->GetDirectBufferAddress(bitwuzla);
    const BitwuzlaTerm* term = bitwuzla_mk_true(bw);
    jobject o = env->NewDirectByteBuffer((void*)bw, sizeof(BitwuzlaTerm*));
    return o;
}