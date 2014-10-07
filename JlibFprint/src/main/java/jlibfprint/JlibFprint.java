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
package jlibfprint;

/**
 *  The bridge class for the libFprint services. 
 *  This class is not designed to be thread-safe.
 */
public class JlibFprint {
  
    static {
        System.loadLibrary("JlibFprint_jni");
    }    
    
    /** 
     * Enrollment result codes returned from fp_enroll_finger().
     * Result codes with RETRY in the name suggest that the scan failed due to
     * user error. Applications will generally want to inform the user of the
     * problem and then retry the enrollment stage. For more info on the semantics
     * of interpreting these result codes and tracking enrollment process, see
     * \ref enrolling.
     */    
    static public interface fp_enroll_result {
	/** 
         * Enrollment completed successfully, the enrollment data has been
	 * returned to the caller. 
         */
	int FP_ENROLL_COMPLETE = 1,
	/**
         * Enrollment failed due to incomprehensible data; this may occur when
	 * the user scans a different finger on each enroll stage. 
         */
	FP_ENROLL_FAIL = 2,
	/** 
         * Enroll stage passed; more stages are need to complete the process. 
         */
	FP_ENROLL_PASS = 3,
	/** 
         * The enrollment scan did not succeed due to poor scan quality or
	 * other general user scanning problem. 
         */
	FP_ENROLL_RETRY = 100,
	/** 
         * The enrollment scan did not succeed because the finger swipe was
	 * too short. 
         */
	FP_ENROLL_RETRY_TOO_SHORT = 101,
	/** 
         * The enrollment scan did not succeed because the finger was not
	 * centered on the scanner. 
         */
	FP_ENROLL_RETRY_CENTER_FINGER = 102,
	/** 
         * The verification scan did not succeed due to quality or pressure
	 * problems; the user should remove their finger from the scanner before
	 * retrying. 
         */
	FP_ENROLL_RETRY_REMOVE_FINGER = 103,
        /**
         * This problem occurs when it's impossible to load the native library.
         */       
        UNABLE_TO_LOAD_LIBFPRINT = -1,
         /**
         * This code is raised when was selected an invalid Device id.
         */
        DEVICE_NOT_FOUND = -2;
        
    };
    
    static public interface fp_print_data_type {
            int PRINT_DATA_RAW = 0, 
            PRINT_DATA_NBIS_MINUTIAE = 1;
    };
    
    /**
     * The data-structure of the fingerprint-data. It can be created
     * only using the methods of the JlibFPrint.
     */
    static public class fp_print_data implements java.io.Serializable {
        private fp_print_data() {}
        
        /**
         * Clears the private data encapsulated in this object.
         * You always should clear an fp_print_data as soon you can.
         */
        public void clear() 
        {
            driver_id = 0;
            devtype = 0;
            type = 0;
            length = 0;
            for (int i = 0; i < data.length; i++) data[i] = 0;
        }

        private int driver_id;
        private int devtype;
        private int type;
        private int length;
        private byte data[];
    };
    
    /**
     * The id of this Exception follows the conventions of 
     * the fp_enroll_result interface.
     * 
     */
    static public class EnrollException extends Exception {
        public int enroll_exception;
    };

    /**
     * Specify which device use for the fingerprint enrollment.
     * @param deviceID the id of the device (starting from zero).
     */
    public void setDeviceID(int deviceID) {
        this.deviceID = deviceID;
    }
    
    /**
     * Acquires a fingerprint data. The method is synchronous, 
     * blocks the caller and is not thread-safe.
     * 
     * @return the data structure with the data associated to the finger enrolled.
     * @throws jlibfprint.JlibFprint.EnrollException raised if something is gone wrong.
     */
    public native fp_print_data enroll_finger() throws EnrollException;
    
    /**
     * Compares two fingerprint data and returns a matching 
     * value computed by the Bozorth library used in libfprint.
     * 
     * @param enrolled_print the fingerprint stored for the comparisons.
     * @param new_print the fingerprint to compare.
     * @return a matching value.
     */
    public static native int img_compare_print_data(fp_print_data enrolled_print, fp_print_data new_print);
    
    /**
     * The default BOZORTH_THRESHOLD defined in libfprint for 
     * the fingerprint comparisons.
     */
    static public final int BOZORTH_THRESHOLD=40;
    
    /**
     * The default deviceID to be used by the library.
     * Typically only one fingerprint sensor is available on a computer.
     */
    private int deviceID = 0;
}
