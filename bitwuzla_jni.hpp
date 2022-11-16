#include <jni.h>

#ifndef _Included_bitwuzla_jni
#define _Included_bitwuzla_jni
#ifdef __cplusplus
extern "C" {
#endif

	JNIEXPORT jobject JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzla_1new
	(JNIEnv* env, jobject zhis);

	JNIEXPORT jobject JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzla_1mk_1true
	(JNIEnv* env, jobject zhis, jobject bitwuzla);

#ifdef __cplusplus
}
#endif
#endif
