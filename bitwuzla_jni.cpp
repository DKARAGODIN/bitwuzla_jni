#include <iostream>
#include <atomic>

#include <bitwuzla.h>
#include "bitwuzla_jni.hpp"
#include "bzla_proxy.h"

void abort_callback(const char* msg) {
    throw std::runtime_error(msg);
}

int32_t termination_callback(void* state) {
    return 0;
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaNew
(JNIEnv* env, jobject native_class) {
    bitwuzla_set_abort_callback(abort_callback);
    try {
        Bitwuzla* bw = bitwuzla_new();
        return (jlong)bw;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaDelete
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_delete(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaReset
(JNIEnv* env, jobject native_class, jlong bitwuzla){
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_reset(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

jstring Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaCopyright
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const char* c = bitwuzla_copyright(bw);
        jstring result = env->NewStringUTF(c);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jstring Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaVersion
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const char* c = bitwuzla_version(bw);
        jstring result = env->NewStringUTF(c);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jstring Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGitId
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const char* c = bitwuzla_git_id(bw);
        jstring result = env->NewStringUTF(c);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTerminate
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        return static_cast<jboolean>(bitwuzla_terminate(bw));
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSetTerminationCallback
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_set_termination_callback(bw, termination_callback, nullptr);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaResetTerminationCallback
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_set_termination_callback(bw, termination_callback, nullptr);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSetOption
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint bitwuzla_option, jint value) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_set_option(bw, BitwuzlaOption(bitwuzla_option), value);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}


void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSetOptionStr
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint bitwuzla_option, jstring value) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const char* nativeString = env->GetStringUTFChars(value, 0);
        bitwuzla_set_option_str(bw, BitwuzlaOption(bitwuzla_option), nativeString);
        env->ReleaseStringUTFChars(value, nativeString);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGetOption
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint bitwuzla_option) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        uint32_t value = bitwuzla_get_option(bw, BitwuzlaOption(bitwuzla_option));
        jint result = static_cast<jint>(value);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jstring Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGetOptionStr
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint bitwuzla_option) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const char* value = bitwuzla_get_option_str(bw, BitwuzlaOption(bitwuzla_option));
        jstring result = env->NewStringUTF(value);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkArraySort
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong index, jlong element) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* bw_index = (BitwuzlaSort*)index;
        BitwuzlaSort* bw_element = (BitwuzlaSort*)element;
        jlong result = (jlong)bitwuzla_mk_array_sort(bw, bw_index, bw_element);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkBoolSort
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const BitwuzlaSort* value = bitwuzla_mk_bool_sort(bw);
        return (jlong)value;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkBvSort
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint size) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const BitwuzlaSort* value = bitwuzla_mk_bv_sort(bw, size);
        return (jlong)value;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkFpSort
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint exp_size, jint sig_size) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const BitwuzlaSort* value = bitwuzla_mk_fp_sort(bw, exp_size, sig_size);
        return (jlong)value;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkFunSort
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint arity, jlongArray domain, jlong codomain) {
    jsize len = env->GetArrayLength(domain);
    jlong* body = env->GetLongArrayElements(domain, 0);
    BitwuzlaSort const** domain_ptr = new BitwuzlaSort const* [len];
    for (int i = 0; i < len; i++) {
        domain_ptr[i] = (BitwuzlaSort*)body[i];
    }
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* codomain_ptr = (BitwuzlaSort*)codomain;
        const BitwuzlaSort* value = bitwuzla_mk_fun_sort(bw, arity, domain_ptr, codomain_ptr);
        delete[] domain_ptr;
        env->ReleaseLongArrayElements(domain, body, 0);
        return (jlong)value;
    }
    catch (const std::exception& e) {
        delete[] domain_ptr;
        env->ReleaseLongArrayElements(domain, body, 0);
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkRmSort
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const BitwuzlaSort* value = bitwuzla_mk_rm_sort(bw);
        return (jlong)value;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkTrue
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        return (jlong) bitwuzla_mk_true(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkFalse
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        return (jlong)bitwuzla_mk_false(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkBvZero
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        return (jlong) bitwuzla_mk_bv_zero(bw, sort);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkBvOne
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        return (jlong)bitwuzla_mk_bv_one(bw, sort);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkBvOnes
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        return (jlong)bitwuzla_mk_bv_ones(bw, sort);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkBvMinSigned
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        return (jlong)bitwuzla_mk_bv_min_signed(bw, sort);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkBvMaxSigned
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        return (jlong)bitwuzla_mk_bv_max_signed(bw, sort);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkFpPosZero
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        const BitwuzlaTerm* result = bitwuzla_mk_fp_pos_zero(bw, sort);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkFpNegZero
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        const BitwuzlaTerm* result = bitwuzla_mk_fp_neg_zero(bw, sort);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkFpPosInf
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        const BitwuzlaTerm* result = bitwuzla_mk_fp_pos_inf(bw, sort);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkFpNegInf
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        const BitwuzlaTerm* result = bitwuzla_mk_fp_neg_inf(bw, sort);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkFpNan
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        const BitwuzlaTerm* result = bitwuzla_mk_fp_nan(bw, sort);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkBvValue
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort, jstring value, jint	base) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        const char* native_value = env->GetStringUTFChars(value, 0);
        const BitwuzlaTerm* result = bitwuzla_mk_bv_value(bw, sort, native_value, BitwuzlaBVBase(base));
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkBvValueUint64
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort, jlong value) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        const BitwuzlaTerm* result = bitwuzla_mk_bv_value_uint64(bw, sort, value);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkTerm1
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint kind, jlong arg) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term = (BitwuzlaTerm*)arg;
        const BitwuzlaTerm* result = bitwuzla_mk_term1(bw, BitwuzlaKind(kind), term);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkTerm2
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint kind, jlong arg0, jlong arg1) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term0 = (BitwuzlaTerm*)arg0;
        BitwuzlaTerm* term1 = (BitwuzlaTerm*)arg1;
        const BitwuzlaTerm* result = bitwuzla_mk_term2(bw, BitwuzlaKind(kind), term0, term1);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkTerm3
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint kind, jlong arg0, jlong arg1, jlong arg2) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term0 = (BitwuzlaTerm*)arg0;
        BitwuzlaTerm* term1 = (BitwuzlaTerm*)arg1;
        BitwuzlaTerm* term2 = (BitwuzlaTerm*)arg2;
        const BitwuzlaTerm* result = bitwuzla_mk_term3(bw, BitwuzlaKind(kind), term0, term1, term2);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkTerm
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint kind, jlongArray args) {
    jsize len = env->GetArrayLength(args);
    jlong* body = env->GetLongArrayElements(args, 0);
    BitwuzlaTerm const** args_ptr = new BitwuzlaTerm const* [len];
    for (int i = 0; i < len; i++) {
        args_ptr[i] = (BitwuzlaTerm*)body[i];
    }
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;

        const BitwuzlaTerm* result = bitwuzla_mk_term(bw, BitwuzlaKind(kind), len, args_ptr);
        delete[] args_ptr;
        env->ReleaseLongArrayElements(args, body, 0);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        delete[] args_ptr;
        env->ReleaseLongArrayElements(args, body, 0);
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkTerm1Indexed1
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint kind, jlong term, jint idx) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term_bw = (BitwuzlaTerm*)term;
        const BitwuzlaTerm* result = bitwuzla_mk_term1_indexed1(bw, BitwuzlaKind(kind), term_bw, idx);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkTerm1Indexed2
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint kind, jlong term, jint idx0, jint idx1) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term_bw = (BitwuzlaTerm*)term;
        const BitwuzlaTerm* result = bitwuzla_mk_term1_indexed2(bw, BitwuzlaKind(kind), term_bw, idx0, idx1);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkTerm2Indexed1
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint kind, jlong term0, jlong term1, jint idx0) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term0_bw = (BitwuzlaTerm*)term0;
        BitwuzlaTerm* term1_bw = (BitwuzlaTerm*)term1;
        const BitwuzlaTerm* result = bitwuzla_mk_term2_indexed1(bw, BitwuzlaKind(kind), term0_bw, term1_bw, idx0);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkTerm2Indexed2
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint kind, jlong term0, jlong term1, jint idx0, jint idx1) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term0_bw = (BitwuzlaTerm*)term0;
        BitwuzlaTerm* term1_bw = (BitwuzlaTerm*)term1;
        const BitwuzlaTerm* result = bitwuzla_mk_term2_indexed2(bw, BitwuzlaKind(kind), term0_bw, term1_bw, idx0, idx1);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}


jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkConst
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort, jstring symbol) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        const char* native_symbol = env->GetStringUTFChars(symbol, 0);
        const BitwuzlaTerm* result = bitwuzla_mk_const(bw, sort, native_symbol);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}


jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkConstArray
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort, jlong value) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        BitwuzlaTerm* term = (BitwuzlaTerm*)value;
        const BitwuzlaTerm* result = bitwuzla_mk_const_array(bw, sort, term);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkVar
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_sort, jstring symbol) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaSort* sort = (BitwuzlaSort*)bitwuzla_sort;
        const char* native_symbol = env->GetStringUTFChars(symbol, 0);
        const BitwuzlaTerm* result = bitwuzla_mk_var(bw, sort, native_symbol);
        return (jlong)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaPush
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint n_levels) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_push(bw, n_levels);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaPop
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint n_levels) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_pop(bw, n_levels);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaAssert
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong term) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)term;
        bitwuzla_assert(bw, bw_term);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaAssume
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong term) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)term;
        bitwuzla_assume(bw, bw_term);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

jlongArray Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGetUnsatAssumptions
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        size_t len;
        const BitwuzlaTerm** array = bitwuzla_get_unsat_assumptions(bw, &len);

        jsize len_size = (jsize)len;
        jlongArray result;
        result = env->NewLongArray(len_size);
        jlong* fill = new jlong[len_size];
        for (int i = 0; i < len_size; i++) {
            fill[i] = (jlong)array[i];
        }
        env->SetLongArrayRegion(result, 0, len_size, fill);
        delete[] fill;
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jlongArray Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGetUnsatCore
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        size_t len = 0;
        const BitwuzlaTerm** array = bitwuzla_get_unsat_core(bw, &len);
        
        jsize len_size = (jsize)len;
        for (int i = 0; i < len_size; i++) {
            std::cout << (& array)[i] << std::endl;
        }
        
        jlongArray result;
        result = env->NewLongArray(len_size);
        jlong* fill = new jlong[len_size];
        for (int i = 0; i < len_size; i++) {
            fill[i] = (jlong)(&array)[i];
        }
        env->SetLongArrayRegion(result, 0, len_size, fill);
        delete[] fill;
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaFixateAssumptions
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_fixate_assumptions(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaResetAssumptions
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_reset_assumptions(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaCheckSat
(JNIEnv* env, jobject native_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaResult result = bitwuzla_check_sat(bw);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGetValue
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_term) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term = (BitwuzlaTerm*)bitwuzla_term;
        return (jlong)bitwuzla_get_value(bw, term);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jstring Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGetBvValue
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_term) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term = (BitwuzlaTerm*)bitwuzla_term;
        const char* c = bitwuzla_get_bv_value(bw, term);
        jstring result = env->NewStringUTF(c);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jobject Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGetFpValue
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_term) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term = (BitwuzlaTerm*)bitwuzla_term;
        const char* sign;
        const char* exponent;
        const char* significand;
        bitwuzla_get_fp_value(bw, term, &sign, &exponent, &significand);

        jclass clazz = env->FindClass("org/ksmt/solver/bitwuzla/bindings/FpValue");
        jmethodID constructor = env->GetMethodID(clazz, "<init>", "()V");
        jfieldID sign_id = env->GetFieldID(clazz, "sign", "Ljava/lang/String;");
        jfieldID exponent_id = env->GetFieldID(clazz, "exponent", "Ljava/lang/Object;");
        jfieldID significand_id = env->GetFieldID(clazz, "significand", "Ljava/lang/Object;");

        jobject result_object = env->NewObject(clazz, constructor);
        jstring sign_string = env->NewStringUTF(sign);
        jstring exponent_string = env->NewStringUTF(exponent);
        jstring significandn_string = env->NewStringUTF(significand);
        env->SetObjectField(result_object, sign_id, sign_string);
        env->SetObjectField(result_object, exponent_id, exponent_string);
        env->SetObjectField(result_object, significand_id, significandn_string);
        return result_object;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jobject Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGetArrayValue
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_term) {
    try {
        size_t len = 0;
        BitwuzlaTerm const** indices_ptr;
        BitwuzlaTerm const** values_ptr;
        BitwuzlaTerm const* default_value_ptr;
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term = (BitwuzlaTerm*)bitwuzla_term;

        bitwuzla_get_array_value(bw, term, &indices_ptr, &values_ptr, &len, &default_value_ptr);

        jclass clazz = env->FindClass("org/ksmt/solver/bitwuzla/bindings/ArrayValue");

        jmethodID constructor = env->GetMethodID(clazz, "<init>", "()V");
        jfieldID size_id = env->GetFieldID(clazz, "size", "I");
        jfieldID indices_id = env->GetFieldID(clazz, "indices", "[J");
        jfieldID values_id = env->GetFieldID(clazz, "values", "[J");
        jfieldID defaultValue_id = env->GetFieldID(clazz, "defaultValue", "J");

        jobject result_object = env->NewObject(clazz, constructor);
        env->SetIntField(result_object, size_id, (jint)len);

        {
            jlongArray i = env->NewLongArray((jsize)len);
            jlong* fill = new jlong[len];
            for (int i = 0; i < len; i++) {
                fill[i] = (jlong)(&indices_ptr)[i];
            }
            env->SetLongArrayRegion(i, 0, (jsize)len, fill);
            delete[] fill;
            env->SetObjectField(result_object, indices_id, i);
        }
        {
            jlongArray i = env->NewLongArray((jsize)len);
            jlong* fill = new jlong[len];
            for (int i = 0; i < len; i++) {
                fill[i] = (jlong)(&values_ptr)[i];
            }
            env->SetLongArrayRegion(i, 0, (jsize)len, fill);
            delete[] fill;
            env->SetObjectField(result_object, values_id, i);
        }
        
        env->SetLongField(result_object, defaultValue_id, (jlong)default_value_ptr);
        return result_object;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jobject Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaGetFunValue
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_term) {
    try {
        size_t size = 0;
        size_t arity = 0;
        BitwuzlaTerm const*** args_ptr;
        BitwuzlaTerm const** values_ptr;

        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        BitwuzlaTerm* term = (BitwuzlaTerm*)bitwuzla_term;

        bitwuzla_get_fun_value(bw, term, &args_ptr, &arity, &values_ptr, &size);

        jclass clazz = env->FindClass("org/ksmt/solver/bitwuzla/bindings/FunValue");
        jmethodID constructor = env->GetMethodID(clazz, "<init>", "()V");
        jfieldID size_id = env->GetFieldID(clazz, "size", "I");
        jfieldID arity_id = env->GetFieldID(clazz, "arity", "I");
        jfieldID args_id = env->GetFieldID(clazz, "args", "[[J");
        jfieldID values_id = env->GetFieldID(clazz, "values", "[J");

        jobject result_object = env->NewObject(clazz, constructor);
        env->SetIntField(result_object, size_id, (jint)size);
        env->SetIntField(result_object, arity_id, (jint)arity);
        {
            jlongArray i = env->NewLongArray((jsize)size);
            jlong* fill = new jlong[size];
            for (int i = 0; i < size; i++) {
                fill[i] = (jlong)(&values_ptr)[i];
            }
            env->SetLongArrayRegion(i, 0, (jsize)size, fill);
            delete[] fill;
            env->SetObjectField(result_object, values_id, i);
        }
        {
            jclass clazz_long_array = env->FindClass("[J");
            jobjectArray a = env->NewObjectArray((jsize)size, clazz_long_array, NULL);
            for (jsize i = 0; i < (jsize)size; i++) {
                jlongArray ar = env->NewLongArray((jsize)arity);
                jlong* fill = new jlong[arity];
                for (int j = 0; j < (int)arity; j++) {
                    fill[j] = (jlong)(&args_ptr)[i][j];
                }
                env->SetLongArrayRegion(ar, 0, (jsize)arity, fill);
                delete[] fill;
                env->SetObjectArrayElement(a, i, ar);
            }
            env->SetObjectField(result_object, args_id, a);
        }

        return result_object;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortHash
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw = (BitwuzlaSort*)bitwuzla_sort;
        return bitwuzla_sort_hash(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermGetKind
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw = (BitwuzlaTerm*)bitwuzla_term;
        return bitwuzla_term_get_kind(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlongArray Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermGetChildren
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw = (BitwuzlaTerm*)bitwuzla_term;
        size_t len = 0;
        const BitwuzlaTerm** array = bitwuzla_term_get_children(bw, &len);
        jsize len_size = (jsize)len;
        jlongArray result;
        result = env->NewLongArray(len_size);
        jlong* fill = new jlong[len_size];
        for (int i = 0; i < len_size; i++) {
            fill[i] = (jlong)array[i];
        }
        env->SetLongArrayRegion(result, 0, len_size, fill);
        delete[] fill;
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jintArray Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermGetIndices
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw = (BitwuzlaTerm*)bitwuzla_term;
        size_t len = 0;
        uint32_t* array = bitwuzla_term_get_indices(bw, &len);
        jsize len_size = (jsize)len;
        jintArray result;
        result = env->NewIntArray(len_size);
        jint* fill = new jint[len_size];
        for (int i = 0; i < len_size; i++) {
            fill[i] = (jint)array[len_size];
        }
        env->SetIntArrayRegion(result, 0, len_size, fill);
        delete[] fill;
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortBvGetSize
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw = (BitwuzlaSort*)bitwuzla_sort;
        return bitwuzla_sort_bv_get_size(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortFpGetExpSize
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw = (BitwuzlaSort*)bitwuzla_sort;
        return bitwuzla_sort_fp_get_exp_size(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortFpGetSigSize
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw = (BitwuzlaSort*)bitwuzla_sort;
        return bitwuzla_sort_fp_get_sig_size(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortArrayGetIndex
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw = (BitwuzlaSort*)bitwuzla_sort;
        const BitwuzlaSort* bw_s = bitwuzla_sort_array_get_index(bw);
        return (jlong)bw_s;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortArrayGetElement
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw = (BitwuzlaSort*)bitwuzla_sort;
        const BitwuzlaSort* bw_s = bitwuzla_sort_array_get_element(bw);
        return (jlong)bw_s;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortIsEqual
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort_1, jlong bitwuzla_sort_2) {
    try {
        BitwuzlaSort* bw_1 = (BitwuzlaSort*)bitwuzla_sort_1;
        BitwuzlaSort* bw_2 = (BitwuzlaSort*)bitwuzla_sort_2;
        bool result = bitwuzla_sort_is_equal(bw_1, bw_2);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortIsArray
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw_sort = (BitwuzlaSort*)bitwuzla_sort;
        bool result = bitwuzla_sort_is_array(bw_sort);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortIsBv
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw_sort = (BitwuzlaSort*)bitwuzla_sort;
        bool result = bitwuzla_sort_is_bv(bw_sort);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortIsFp
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw_sort = (BitwuzlaSort*)bitwuzla_sort;
        bool result = bitwuzla_sort_is_fp(bw_sort);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}


jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortIsFun
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw_sort = (BitwuzlaSort*)bitwuzla_sort;
        bool result = bitwuzla_sort_is_fun(bw_sort);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaSortIsRm
(JNIEnv* env, jobject native_class, jlong bitwuzla_sort) {
    try {
        BitwuzlaSort* bw_sort = (BitwuzlaSort*)bitwuzla_sort;
        bool result = bitwuzla_sort_is_rm(bw_sort);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermHash
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        return bitwuzla_term_hash(bw_term);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsIndexed
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_indexed(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermGetBitwuzla
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        Bitwuzla* bw = bitwuzla_term_get_bitwuzla(bw_term);
        return (jlong)bw;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermGetSort
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        const BitwuzlaSort* bw_sort = bitwuzla_term_get_sort(bw_term);
        return (jlong)bw_sort;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermArrayGetIndexSort
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        const BitwuzlaSort* bw_sort = bitwuzla_term_array_get_index_sort(bw_term);
        return (jlong)bw_sort;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermArrayGetElementSort
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        const BitwuzlaSort* bw_sort = bitwuzla_term_array_get_element_sort(bw_term);
        return (jlong)bw_sort;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermFunGetCodomainSort
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        const BitwuzlaSort* bw_sort = bitwuzla_term_fun_get_codomain_sort(bw_term);
        return (jlong)bw_sort;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermBvGetSize
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        uint32_t result = bitwuzla_term_bv_get_size(bw_term);
        return (jint)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermFpGetExpSize
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        uint32_t result = bitwuzla_term_fp_get_exp_size(bw_term);
        return (jint)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermFpGetSigSize
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        uint32_t result = bitwuzla_term_fp_get_sig_size(bw_term);
        return (jint)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermFunGetArity
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        uint32_t result = bitwuzla_term_fun_get_arity(bw_term);
        return (jint)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jstring Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermGetSymbol
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        const char* c = bitwuzla_term_get_symbol(bw_term);
        jstring result = env->NewStringUTF(c);
        return result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return nullptr;
    }
}


void Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermSetSymbol
(JNIEnv* env, jobject native_class, jlong bitwuzla_term, jstring symbol) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        const char* native_symbol = env->GetStringUTFChars(symbol, 0);
        bitwuzla_term_set_symbol(bw_term, native_symbol);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsEqualSort
(JNIEnv* env, jobject native_class, jlong bitwuzla_term_1, jlong bitwuzla_term_2) {
    try {
        BitwuzlaTerm* bw_term_1 = (BitwuzlaTerm*)bitwuzla_term_1;
        BitwuzlaTerm* bw_term_2 = (BitwuzlaTerm*)bitwuzla_term_2;
        bool result = bitwuzla_term_is_equal_sort(bw_term_1, bw_term_2);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsArray
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_array(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsConst
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_const(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsFun
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_fun(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsVar
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_var(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsBoundVar
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_bound_var(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsValue
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_value(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsBvValue
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_bv_value(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsFpValue
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_fp_value(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsRmValue
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_rm_value(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsBv
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_bv(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsFp
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_fp(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsRm
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_rm(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsBvValueZero
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_bv_value_zero(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsBvValueOne
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_bv_value_one(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsBvValueOnes
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_bv_value_ones(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsBvValueMinSigned
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_bv_value_min_signed(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsBvValueMaxSigned
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_bv_value_max_signed(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsFpValuePosZero
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_fp_value_pos_zero(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsFpValueNegZero
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_fp_value_neg_zero(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsFpValuePosInf
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_fp_value_pos_inf(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsFpValueNegInf
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_fp_value_neg_inf(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsFpValueNan
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_fp_value_nan(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsRmValueRna
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_rm_value_rna(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsRmValueRne
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_rm_value_rne(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsRmValueRtn
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_rm_value_rtn(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsRmValueRtp
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_rm_value_rtp(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsRmValueRtz
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_rm_value_rtz(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jboolean Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaTermIsConstArray
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        bool result = bitwuzla_term_is_const_array(bw_term);
        return (jboolean)result;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaBvConstNodeGetBits
(JNIEnv* env, jobject native_class, jlong bitwuzla_term) {
    try {
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        const BzlaBitVector* bw_vector = bzla_node_bv_const_get_bits_proxy(bw_term);
        return (jlong)bw_vector;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaBvBitsGetWidth
(JNIEnv* env, jobject native_class, jlong bitwuzla_bit_vector) {
    try {
        const BzlaBitVector* bw_vector = (BzlaBitVector*)bitwuzla_bit_vector;
        uint32_t i = bzla_bv_get_width_proxy(bw_vector);
        return i;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaBvBitsToUInt64
(JNIEnv* env, jobject native_class, jlong bitwuzla_bit_vector) {
    try {
        const BzlaBitVector* bw_vector = (BzlaBitVector*)bitwuzla_bit_vector;
        uint64_t i = bzla_bv_to_uint64_proxy(bw_vector);
        return i;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkFpValue
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_bvSign, jlong bitwuzla_bvExponent, jlong bitwuzla_bvSignificand) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        const BitwuzlaTerm* bv_sign = (BitwuzlaTerm*)bitwuzla_bvSign;
        const BitwuzlaTerm* bv_exponent = (BitwuzlaTerm*)bitwuzla_bvExponent;
        const BitwuzlaTerm* bv_significand = (BitwuzlaTerm*)bitwuzla_bvSignificand;
        return (jlong)bitwuzla_mk_fp_value(bw, bv_sign, bv_exponent, bv_significand);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaMkRmValue
(JNIEnv* env, jobject native_class, jlong bitwuzla, jint rm) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        return (jlong)bitwuzla_mk_rm_value(bw, (BitwuzlaRoundingMode)rm);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jint Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaBvBitsGetBit
(JNIEnv* env, jobject native_class, jlong bitwuzla_bit_vector, jint pos) {
    try {
        const BzlaBitVector* bw_vector = (BzlaBitVector*)bitwuzla_bit_vector;
        uint32_t i = bzla_bv_get_bit_proxy(bw_vector, pos);
        return i;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_Native_bitwuzlaFpConstNodeGetBits
(JNIEnv* env, jobject native_class, jlong bitwuzla, jlong bitwuzla_term) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        auto bzla = bitwuzla_get_bzla_proxy(bw);
        BitwuzlaTerm* bw_term = (BitwuzlaTerm*)bitwuzla_term;
        auto fp = bzla_node_fp_const_get_fp_proxy(bw_term);
        const BzlaBitVector* bw_vector = bzla_fp_as_bv_proxy(bzla, fp);
        return (jlong)bw_vector;
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}






