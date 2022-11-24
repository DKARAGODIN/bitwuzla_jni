#include <jni.h>

#ifndef _Included_bitwuzla_jni
#define _Included_bitwuzla_jni
#ifdef __cplusplus
extern "C" {
#endif

	JNIEXPORT jobject JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaNew
	(JNIEnv* env, jobject nativeJNI_class);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaDelete
	(JNIEnv* env, jobject nativeJNI_class, jobject bitwuzla);

	JNIEXPORT void JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaReset
	(JNIEnv* env, jobject nativeJNI_class, jobject bitwuzla);

	JNIEXPORT jstring JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaCopyright
	(JNIEnv* env, jobject nativeJNI_class, jobject bitwuzla);

	JNIEXPORT jobject JNICALL Java_org_ksmt_solver_bitwuzla_bindings_NativeJNI_bitwuzlaMkTrue
	(JNIEnv* env, jobject nativeJNI_class, jobject bitwuzla);

#ifdef __cplusplus
}
#endif
#endif
