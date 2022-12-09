#include <iostream>

#include <bitwuzla.h>
#include "bitwuzla_jni.hpp"

void abort_callback(const char* msg) {
    throw std::runtime_error(msg);
}

//Add templates around methods

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaNew
(JNIEnv* env, jobject nativeJNI_class) {
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

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaDelete
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_delete(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaReset
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla){
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_reset(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

jstring Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaCopyright
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
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


jstring Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaVersion
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
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

jstring Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaGitId
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTerminate
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
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


void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSetOption
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint bitwuzla_option, jint value) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_set_option(bw, BitwuzlaOption(bitwuzla_option), value);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}


void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSetOptionStr
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint bitwuzla_option, jstring value) {
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

jint Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaGetOption
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint bitwuzla_option) {
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

jstring Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaGetOptionStr
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint bitwuzla_option) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkArraySort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong index, jlong element) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBoolSort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvSort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint size) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpSort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint exp_size, jint sig_size) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkRmSort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkTrue
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFalse
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        return (jlong)bitwuzla_mk_true(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
        return -1;
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvZero
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvOne
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvOnes
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvMinSigned
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvMaxSigned
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpPosZero
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpNegZero
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpPosInf
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpNegInf
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpNan
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvValueUint64
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort, jlong value) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkVar
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort, jstring symbol) {
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

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaPush
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint n_levels) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_push(bw, n_levels);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaPop
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint n_levels) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_pop(bw, n_levels);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaAssert
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong term) {
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

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaAssume
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong term) {
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

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaFixateAssumptions
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_reset_assumptions(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaResetAssumptions
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla) {
    try {
        Bitwuzla* bw = (Bitwuzla*)bitwuzla;
        bitwuzla_reset_assumptions(bw);
    }
    catch (const std::exception& e) {
        jclass exception = env->FindClass("org/ksmt/solver/bitwuzla/bindings/BitwuzlaJNIException");
        env->ThrowNew(exception, e.what());
    }
}

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortHash
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jint Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortBvGetSize
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jint Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortFpGetExpSize
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jint Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortFpGetSigSize
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortArrayGetIndex
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortArrayGetElement
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsEqual
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort_1, jlong bitwuzla_sort_2) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsArray
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsBv
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsFp
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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


jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsFun
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsRm
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermHash
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsIndexed
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermGetBitwuzla
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermGetSort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermArrayGetIndexSort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermArrayGetElementSort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jlong Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermFunGetCodomainSort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jint Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermBvGetSize
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jint Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermFpGetExpSize
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jint Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermFpGetSigSize
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jint Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermFunGetArity
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jstring Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermGetSymbol
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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


void Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermSetSymbol
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term, jstring symbol) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsEqualSort
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term_1, jlong bitwuzla_term_2) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsArray
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsConst
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsFun
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsVar
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsBoundVar
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsValue
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsBvValue
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsFpValue
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsRmValue
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsBv
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsFp
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsRm
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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

jboolean Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsBvValueZero
(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term) {
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