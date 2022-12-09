#include <jni.h>

#ifndef _Included_bitwuzla_jni
#define _Included_bitwuzla_jni
#ifdef __cplusplus
extern "C" {
#endif

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaNew
	(JNIEnv* env, jobject nativeJNI_class);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaDelete
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaReset
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT jstring JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaCopyright
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT jstring JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaVersion
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT jstring JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaGitId
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTerminate
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSetOption
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint bitwuzla_option, jint value);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSetOptionStr
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint bitwuzla_option, jstring value);

	JNIEXPORT jint JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaGetOption
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint bitwuzla_option);

	JNIEXPORT jstring JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaGetOptionStr
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint bitwuzla_option);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkArraySort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong index, jlong element);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBoolSort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvSort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint size);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpSort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint exp_size, jint sig_size);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkRmSort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkTrue
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFalse
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvZero
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvOne
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvOnes
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvMinSigned
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvMaxSigned
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpPosZero
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpNegZero
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpPosInf
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpNegInf
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkFpNan
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkBvValueUint64
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort, jlong value);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkVar
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong bitwuzla_sort, jstring symbol);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaPush
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint n_levels);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaPop
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jint n_levels);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaAssert
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong term);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaAssume
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla, jlong term);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaFixateAssumptions
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaResetAssumptions
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortHash
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jint JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortBvGetSize
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jint JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortFpGetExpSize
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jint JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortFpGetSigSize
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortArrayGetIndex
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortArrayGetElement
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsEqual
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort_1, jlong bitwuzla_sort_2);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsArray
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsBv
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsFp
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsFun
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaSortIsRm
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_sort);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermHash
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsIndexed
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermGetBitwuzla
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermGetSort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermArrayGetIndexSort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermArrayGetElementSort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jlong JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermFunGetCodomainSort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jint JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermBvGetSize
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jint JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermFpGetExpSize
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jint JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermFpGetSigSize
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jint JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermFunGetArity
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jstring JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermGetSymbol
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermSetSymbol
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term, jstring symbol);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsEqualSort
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term_1, jlong bitwuzla_term_2);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsArray
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsConst
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsFun
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsVar
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsBoundVar
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsValue
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsBvValue
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsFpValue
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsRmValue
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsBv
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsFp
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsRm
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

	JNIEXPORT jboolean JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaTermIsBvValueZero
	(JNIEnv* env, jobject nativeJNI_class, jlong bitwuzla_term);

#ifdef __cplusplus
}
#endif
#endif
