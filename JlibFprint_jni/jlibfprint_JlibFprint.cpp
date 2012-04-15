/*
 * Jlibfprint - A Java Bridge for libfprint
 * Copyright (C) 2012 Fabio Scippacercola <nonplay.programmer@gmail.com>
 *                    Agostino Savignano <savag88@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#include "jlibfprint_JlibFprint.h"
#include "libfprintWrapper.h"
#include <cstring>

/**
 * Populate a jlibfprint/JlibFprint$fp_print_data object with the data
 * stored in a fp_print_data struct.
 * 
 * @param env the Java Environment pointer.
 * @param obj the jobject of the type jlibfprint/JlibFprint$fp_print_data to be filled.
 * @param fpd a pointer to the fp_print_data to be mapped on obj.
 */
void cfp2jfp(JNIEnv* env, jobject obj, fp_print_data* fpd)
{
    /* Determines all the fields of the object */
    jclass fpClass = env->FindClass("jlibfprint/JlibFprint$fp_print_data");
    jfieldID driver_id;
    jfieldID devtype;
    jfieldID type;
    jfieldID length;
    jfieldID data;
    
    jbyteArray dataArray;
    driver_id = env->GetFieldID(fpClass, "driver_id", "I");
    devtype = env->GetFieldID(fpClass, "devtype", "I");
    type = env->GetFieldID(fpClass, "type", "I");
    length = env->GetFieldID(fpClass, "length", "I");
    data = env->GetFieldID(fpClass, "data", "[B");

    /* Starts to fill the obj */
    env->SetIntField(obj, driver_id, fpd->driver_id);
    env->SetIntField(obj, devtype, fpd->devtype);
    env->SetIntField(obj, type, (int)fpd->type);
    env->SetIntField(obj, length, fpd->length);
    
    dataArray = env->NewByteArray(FP_PRINT_DATA_DATA_SIZE);
    env->SetByteArrayRegion(dataArray, 0, FP_PRINT_DATA_DATA_SIZE, (jbyte*)fpd->data);
    
    env->SetObjectField(obj, data, dataArray);
}

/**
 * Fills a fp_print_data struct with the data obtained by 
 * a jlibfprint/JlibFprint$fp_print_data object.
 * 
 * @param env the Java Environment pointer.
 * @param obj the jobject of the type jlibfprint/JlibFprint$fp_print_data.
 * @param fpd a reference to a fp_print_data object to be filled with the data of obj.
 */
void jfp2cfp(JNIEnv* env, jobject obj, fp_print_data& fpd)
{
    /* Determines all the fields of the object */
    jclass fpClass = env->FindClass("jlibfprint/JlibFprint$fp_print_data");
    jfieldID driver_id;
    jfieldID devtype;
    jfieldID type;
    jfieldID length;
    jfieldID data;
    
    jbyteArray dataArray;
    driver_id = env->GetFieldID(fpClass, "driver_id", "I");
    devtype = env->GetFieldID(fpClass, "devtype", "I");
    type = env->GetFieldID(fpClass, "type", "I");
    length = env->GetFieldID(fpClass, "length", "I");
    data = env->GetFieldID(fpClass, "data", "[B");

     /* Starts to fill fpd */
    fpd.driver_id = (unsigned short)(env->GetIntField(obj, driver_id));
    fpd.devtype = env->GetIntField(obj, devtype);
    
    fpd.type = (((int)env->GetIntField(obj, type)) ?  PRINT_DATA_NBIS_MINUTIAE : PRINT_DATA_RAW);
    fpd.length = env->GetIntField(obj, length);
    
    dataArray = static_cast<jbyteArray>(env->GetObjectField(obj, data));
    env->GetByteArrayRegion(dataArray, 0, FP_PRINT_DATA_DATA_SIZE, (jbyte*)fpd.data);
}       

/**
 * Check if the device_id setted for obj is available.
 * 
 * @param env the Java Environment pointer. 
 * @param obj the jobject of the type jlibfprint/JlibFprint.
 * @param device output variable, it sets *device to the fp_dev specified in obj if is available.
 * @return true if the fp-device specified in obj is available and a pointer to it was setted in *device.
 */
bool get_device_id(JNIEnv* env, jobject obj, fp_dev** device)
{
    const jclass jlibClass = env->FindClass("jlibfprint/JlibFprint");
    jfieldID device_id = env->GetFieldID(jlibClass, "deviceID", "I");
    
    int devId = env->GetIntField(obj, device_id);
    bool found = (devId >= 0); // If devId < 0 => Not found
    fp_dscv_dev **fpList = fp_discover_devs();    
        
    /* devId is a list, we need to scan and check if it terminates before devId */
    for (int i = 0; i <= devId; i++) // All ids < devID must be != NULL
        if (fpList[i] == NULL) 
        {
            found = false;
            break;
        }
    
    if (found)
    {
        *device = fp_dev_open(fpList[devId]);   
        if (*device == NULL) found = false;
    }
    fp_dscv_devs_free(fpList);
    return found;
}

/**
 * Enrolls a finger and returns the associated fp-data.
 * 
 * @param env the Java Environment pointer. 
 * @param obj the jobject of the type jlibfprint/JlibFprint.
 * @return the jlibfprint/JlibFprint$fp_print_data with the data just given by the scanner.
 * @throws an enroll_exception is raised is something gone wrong.
 */
JNIEXPORT jobject JNICALL Java_jlibfprint_JlibFprint_enroll_1finger(JNIEnv* env, jobject ref)
{
    const jclass fpClass = env->FindClass("jlibfprint/JlibFprint$fp_print_data");
    const jclass eeClass = env->FindClass("jlibfprint/JlibFprint$EnrollException");
    
    /* Starts the library */
    if (fp_init())  // Se differente da 0 => Exception
    {
        jobject enrollException = env->AllocObject(eeClass);
        jfieldID eeExcp_id = env->GetFieldID(eeClass, "enroll_exception", "I");
        env->SetIntField(enrollException, eeExcp_id, UNABLE_TO_LOAD_LIBFPRINT);
        env->Throw((jthrowable)enrollException);
        return NULL;
    }
    fp_dev *device;
    fp_print_data* pdp;    
    
    /* Gets the pointer to the device */
    if (!get_device_id(env, ref, &device))
    {
        jobject enrollException = env->AllocObject(eeClass);
        jfieldID eeExcp_id = env->GetFieldID(eeClass, "enroll_exception", "I");
        env->SetIntField(enrollException, eeExcp_id, DEVICE_NOT_FOUND);
        env->Throw((jthrowable)enrollException);
        return NULL;
    }    
    
    /* Enrolls the finger */
    int ef = fp_enroll_finger(device, &pdp);
    /* Create a new obj to store the data */
    jobject obj = env->AllocObject(fpClass); 
    
    /* Raises an exception if the enrollment was not completed */
    if (ef != FP_ENROLL_COMPLETE)
    {
        jobject enrollException = env->AllocObject(eeClass);
        jfieldID eeExcp_id = env->GetFieldID(eeClass, "enroll_exception", "I");
        env->SetIntField(enrollException, eeExcp_id, ef);
        env->Throw((jthrowable)enrollException);
    }
    else
    {
        /* Fills the object with the enrollment data */
        cfp2jfp(env, obj, pdp);
        memset(pdp, 0, sizeof(fp_print_data));
        fp_print_data_free(pdp); 
    }
    fp_dev_close(device);
    fp_exit();
    
    return obj;
}


/**
 * Compares two fingerprints data and returns a matching value.
 * 
 * @param env the Java Environment pointer. 
 * @param cls a reference to the caller class.
 * @param fp1 the first fingerprint data (an jobject of type jlibfprint/JlibFprint$fp_print_data).
 * @param fp2 the second fingerprint data (an jobject of type jlibfprint/JlibFprint$fp_print_data).
 * @return a measure of the similarities between fp1 and fp2.
 */
JNIEXPORT jint JNICALL Java_jlibfprint_JlibFprint_img_1compare_1print_1data(JNIEnv *env, jclass cls, jobject fp1, jobject fp2)
{
    fp_print_data fpd1, fpd2;
    jint retVal; 
    
    jfp2cfp(env, fp1, fpd1);
    jfp2cfp(env, fp2, fpd2);
    
    retVal = static_cast<jint>(fpi_img_compare_print_data(&fpd1, &fpd2));
    
    memset(&fpd1, 0, sizeof(fp_print_data));
    memset(&fpd2, 0, sizeof(fp_print_data));
    
    return retVal;
}
