#include "Week8.h"

#include <cmath>

JNIEXPORT jdouble JNICALL Java_Week8_calculateStdDev
(JNIEnv* env, jobject caller, jintArray sampleArr) 
{
	const jsize arrSize = env->GetArrayLength(sampleArr);
	const jint* elements = (env)->GetIntArrayElements(sampleArr, NULL);

	jdouble mean = Java_Week8_calculateMean(env, caller, sampleArr);

	jint sum = 0;
	for (int i = 0; i < arrSize; i++) {
		jdouble diff = (jdouble)(elements[i]) - mean;	// Calculate distance to the mean
		sum += (diff * diff);							// Square the differences

	}

	jdouble stdDev = sqrt(sum / arrSize);
	return stdDev;
}

JNIEXPORT jdouble JNICALL Java_Week8_calculateMean
(JNIEnv* env, jobject caller, jintArray sampleArr)
{
	const jsize arrSize = env->GetArrayLength(sampleArr);

	jint* elements = (env)->GetIntArrayElements(sampleArr, NULL);

	int sum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sum += elements[i];
	}

	env->ReleaseIntArrayElements(sampleArr, elements, 0);
		
	return static_cast<jdouble>(sum) / arrSize;
}