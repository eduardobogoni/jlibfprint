Jlibfprint
=========

Jlibfprint was developed as part of a small project during our studies
at the University of Naples (Università degli studi di Napoli Federico II).
It was not developed in the sight to provide a full support to 
the fingerprint sensors under Linux, but just as basic access to these 
peripherals under Java.

We are sharing the code in the hope that it can be enough for your 
purposes or at least can just be a good starting point to extend 
the integration of Java with the libfprint library.

This project is fully independent from our university and from 
the libfprint project. We want thank all the authors of libfprint
for their contribution to the open source world on top of which
our small software bridge is collocated.

This software is given to you without any warranty, it is licensed
under the GNU LGPL version 2.1. See the LICENSE file for the license text.

Installation
------------

The Jlibfprint is a JNI bridge to libfprint, so it is strictly dependent
from that library.

Jlibfprint is divided in two folder: JlibFprint, JlibFprint_jni. 
The first one contains the Java class used for the bridging
with the native library along with an example, the second one is the dynamic library used by JNI.

-  Download the (latest) sources of libfprint
   ```bash
   $ wget http://people.freedesktop.org/~hadess/libfprint-0.6.0.tar.xz
   $ tar -xvf libfprint-0.6.0.tar.xz
   $ cd libfprint-0.6.0
   ```
   
-  To give the ability to compare two fingerprint data in Jlibfprint you need to patch it.
   
	- In libfprint find the file img.c and open it
	- Find the function 
	
		```c
		int fpi_img_compare_print_data(struct fp_print_data *enrolled_print, struct fp_print_data *new_print) 
		```
	- Add the attribute "API_EXPORTED" before the definition of the function:
		
		```c
		API_EXPORTED int fpi_img_compare_print_data(struct fp_print_data *enrolled_print, struct fp_print_data *new_print) 
		```
	- Configure, compile and install libfprint in the library folder your system use for dynamic linking.
		
		```bash
		$ ./configure --prefix=/usr
		$ make
		$ sudo make install
		```

- Setup enviroment variables.
	- Edit the file ```JlibFprint_jni/src/Makefile.am```
	- search for the ADD_INCLUDE variable (near line 53), and specify the JDK include library and the path of the source files of the libfprint you have just patched. Please take care to add also this subfolder: libfprint/nbis/include.
	
		```
		#Modify the includes of the project, add you jdk include directory and libfprint includes
		ADD_INCLUDES=
		# Example
		# ADD_INCLUDES=-I/opt/jdk1.7.0_03/include -I/opt/jdk1.7.0_03/include/linux -I/home/user/Downloads/libfprint-0.4.0 -I/home/user/Downloads/libfprint-0.4.0/libfprint/nbis/include

		```

- Compile
	```bash
	$ cd JlibFprint_jni
	$ libtoolize
	$ ./autogen.sh
	$ cd build
	$ ../configure
	$ make
	$ sudo make install
	```

- Run!
	```bash
	$ export JLIBFPRINT_JNI=/usr/local/lib/libfprint_jni.so
	$ cd JlibFprint
	$ mvn install
	$ java -cp target/jlibfprint-1.0-SNAPSHOT.jar  jlibfprint.SampleRun
	```
	

Contacts
----------
If you encounter any problem or want inform us that you are using our Bridge,
feel free to contact us to our email addresses. 
See http://code.google.com/p/jlibfprint for all the things concerning the project.


Contributors
----------

- Copyright (C) 2012 Fabio Scippacercola <nonplay.programmer@gmail.com> 
- Copyright (C) 2012 Agostino Savignano <savag88@gmail.com>
- Copyright (C) 2015 Kinshuk Bairagi <me@kinshuk.in>

Because we have built our software on the top of Libfprint we want thank all the authors
of the libfprint project. Look the Libfprint license file for more informations.
See http://www.freedesktop.org/wiki/Software/fprint/libfprint

Thanks to:

- Copyright (C) 2007 Daniel Drake <dsd@gentoo.org>
- Copyright (C) 2006-2007 Timo Hoenig <thoenig@suse.de>
- Copyright (C) 2006 Pavel Machek <pavel@suse.cz>
- Copyright (C) 1999 Erik Walthinsen <omega@cse.ogi.edu>
- Copyright (C) 2004,2006 Thomas Vander Stichele <thomas at apestaart dot org>
- Copyright (C) 2007 Cyrille Bagard
- Copyright (C) 2007 Vasily Khoruzhick
- Copyright (C) 2007 Jan-Michael Brummer <buzz2@gmx.de>
- Copyright (C) 2007 Anthony Bretaudeau <wxcover@users.sourceforge.net>
- Copyright (C) 2010 Hugo Grostabussiat <dw23.devel@gmail.com>
- Copyright (C) 2015 Eduardo Bogoni <eduardobogoni@gmail.com>
