Jlibfprint
=========

Copyright (C) 2012 Fabio Scippacercola <nonplay.programmer@gmail.com>
Copyright (C) 2012 Agostino Savignano <savag88@gmail.com>

libfprint was developed as part of an our little project during 
our study at the University of Naples (Università degli studi di 
Napoli Federico II). It was not developed in the sight to provide
a full support to the fingerprint sensors under Linux, but just
as basic access to these peripherals under Java.

We are sharing the code in the hope that it can be enough for your 
purposes or at least can just be a good starting point to extend 
the integration of Java with the libfprint library.

This project is fully independent from our university and from 
the libfprint project. We want thank all the authors of libfprint
for their contribution to the open source world on top of which
our small software bridge is collocated.

This software is given to you without any warranty, it is licensed
under the GNU LGPL version 2.1. See the LICENSE file for the license text.

INSTALLATION
------------

The Jlibfprint is a JNI bridge to libfprint, so it is strictly dependent
from that library. We used for our testing the libfprint-0.4.0 and we will 
refer to that version in the next of these instructions.

Jlibfprint is divided in two folder: JlibFprint, JlibFprint_jni. 
The first one contains for now only the Java class used for the bridging
with the native library, the second one is the dynamic library used by JNI.

1. Download the (latest) sources of libfprint 

2. To give the ability to compare two fingerprint data in Jlibfprint 
	you probabily need to patch the library in this way:
		- in libfprint find the file img.c and open it
		- find the function 
	int fpi_img_compare_print_data(struct fp_print_data *enrolled_print,
		struct fp_print_data *new_print)
		- add the attribute "API_EXPORTED" before the definition of the function:
	API_EXPORTED int fpi_img_compare_print_data(struct fp_print_data *enrolled_print,
		struct fp_print_data *new_print)
		
3. Configure, compile and install libfprint in the library folder your system use for dynamic linking.

4. Open the jlibfprint_jni/Makefile file, search for the ADD_INCLUDE variable (near line 53),
	and specify the JDK include library and the path of the source files of the libfprint 
	you have just patched. Please take care to add also this subfolder: libfprint/nbis/include.
	
5. Compile the JNI bridge with a "make all"

6. Copy the dynamic library you just compiled from the subdirectory of the "dist" folder
	to a lib system library used for dynamic linking.
	
7. Now you can use the class jlibfprint.JlibFprint in JlibFprint for your Java applications.
	You can soon test the library running the jlibfprint.SampleRun class. 
	If you want, you can put those classes into a Jar file. It is likely that you find that Jar 
	into JlibFprint/dist.


JLibfprint Contacts
----------
If you encounter any problem or want inform us that you are using our Bridge,
feel free to contact us to our email addresses. 
See http://code.google.com/p/jlibfprint for all the things concerning the project.


Libfprint contributors
----------
Because we have built our software on the top of Libfprint we want thank all the authors
of the libfprint project. Look the Libfprint license file for more informations.
See http://www.freedesktop.org/wiki/Software/fprint/libfprint

Thanks to:
	Copyright (C) 2007 Daniel Drake <dsd@gentoo.org>
	Copyright (C) 2006-2007 Timo Hoenig <thoenig@suse.de>
	Copyright (C) 2006 Pavel Machek <pavel@suse.cz>
	Copyright (C) 1999 Erik Walthinsen <omega@cse.ogi.edu>
	Copyright (C) 2004,2006 Thomas Vander Stichele <thomas at apestaart dot org>
	Copyright (C) 2007 Cyrille Bagard
	Copyright (C) 2007 Vasily Khoruzhick
	Copyright (C) 2007 Jan-Michael Brummer <buzz2@gmx.de>
	Copyright (C) 2007 Anthony Bretaudeau <wxcover@users.sourceforge.net>
	Copyright (C) 2010 Hugo Grostabussiat <dw23.devel@gmail.com>

