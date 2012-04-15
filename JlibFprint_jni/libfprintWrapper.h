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

#ifndef LIBFPRINTWRAPPER_H
#define	LIBFPRINTWRAPPER_H

#include <cstddef>

/**
 * The following code in this header file was adapted by libfprint project.
 * See the README for information about the license and the authors.
 */

extern "C"
{
    #include <libfprint/fprint.h>
    #include <bozorth.h>
    
    struct fp_minutiae {
            int alloc;
            int num;
            struct fp_minutia **list;
    };

    struct fp_img {
            int width;
            int height;
            size_t length;
            uint16_t flags;
            struct fp_minutiae *minutiae;
            unsigned char *binarized;
            unsigned char data[0];
    };

    enum fp_print_data_type {
            PRINT_DATA_RAW = 0, /* memset-imposed default */
            PRINT_DATA_NBIS_MINUTIAE,
    };

    static const int FP_PRINT_DATA_DATA_SIZE = sizeof(xyt_struct);
    static const int UNABLE_TO_LOAD_LIBFPRINT = -1;
    static const int DEVICE_NOT_FOUND = -2;
    
    struct fp_print_data {
            uint16_t driver_id;
            uint32_t devtype;
            enum fp_print_data_type type;
            size_t length;
            unsigned char data[FP_PRINT_DATA_DATA_SIZE];
    };
    
    int fpi_img_compare_print_data(struct fp_print_data *enrolled_print,
	struct fp_print_data *new_print);

}


#endif	/* LIBFPRINTWRAPPER_H */

