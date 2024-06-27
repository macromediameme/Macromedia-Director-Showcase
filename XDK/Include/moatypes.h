#ifndef _H_moatypes
#define _H_moatypes

/*
	File: moatypes.h (adaptive)

	Copyright (c) 1994, 1995, 1996 Macromedia, Inc.  All Rights Reserved
	
	You may utilize this source file to create and compile object code for use within products
	you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, AND
	MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE
	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR
	USE OR INABILITY TO USE THIS CODE.

	Abstract:
	
	A utility file to include the proper types file.
	This is the only "core" file which should ever be modified
	for basing MOA on a new platform.
	
	Revision history:

	980225	LLB / Director: use moaplat.h to include platform specific
							type headers.
	960609	Release 1.6:

			added kMoaErr_NotImplemented, MoaStringRef

			(srj)

	960220	Release 1.44:
	
			Gutted; most of the contents moved to edge files.

			(srj)
*/

/* $Revision: 2 $ */


/*---------------------------------------------------------------------------
/ 1. Include other headers we depend on.
/--------------------------------------------*/
/*-------------------------------------------------------------------------*/

#ifndef _H_moaplat
	#include "moaplat.h"
#endif

/*---------------------------------------------------------------------------
/ 2. Define constants and macros.
/--------------------------------------------*/

#ifndef TRUE
	#define TRUE 1
#endif
#ifndef FALSE
	#define FALSE 0
#endif
#ifndef NULL
	#define NULL 0
#endif
#ifndef EXTERN_C
	#ifdef __cplusplus
		#define EXTERN_C	extern "C"
	#else
		#define EXTERN_C	extern
	#endif
#endif

typedef struct _MoaStringRef FAR* MoaStringRef;

/*--------------------------------------------*/
/* these are cunningly crafted to comply with the bit allocation of an HRESULT. */

#define		kMoaErr_NoErr 					((MoaError)0L)

#define 	MAKE_MOAERR(code) \
			((MoaError)((MoaUlong)(1L << 31) | (MoaUlong)(4L << 16) | (MoaUlong)(code)))

#define 	MAKE_MOASTATUS(code) \
			((MoaError)((MoaUlong)(0L << 31) | (MoaUlong)(4L << 16) | (MoaUlong)(code)))

#ifndef SUCCEEDED
	#define SUCCEEDED(s) 					((MoaLong)(s) >= 0L)
#endif
#ifndef FAILED
	#define FAILED(s) 						((MoaLong)(s) < 0L)
#endif

#define 	kMoaStatus_OK					((MoaError)0L)
#define 	kMoaStatus_False				((MoaError)1L)

#define		kMoaErr_BadParam				MAKE_MOAERR(1)	/* you passed me a bogus argument */
#define		kMoaErr_OutOfMem				MAKE_MOAERR(2)	/* core "memory full" error */
#define		kMoaErr_XtraInUse				MAKE_MOAERR(3)	/* xtra has objects in use */
#define		kMoaErr_BadInterface			MAKE_MOAERR(4)	/* don't know that interface */
#define		kMoaErr_BadClass				MAKE_MOAERR(5)	/* don't know that class */
#define		kMoaErr_FileNotFound			MAKE_MOAERR(6)	/* couldn't find or open the file */
#define		kMoaErr_XtraNotFound			MAKE_MOAERR(7)	/* couldn't find the Xtra within the file */
#define		kMoaErr_FuncNotFound			MAKE_MOAERR(8)	/* required function missing from Xtra */
#define		kMoaErr_ClassInfoNotFound		MAKE_MOAERR(9)	/* class info missing from Xtra */
#define		kMoaErr_ConnectionNotOpen		MAKE_MOAERR(10)	/* Xtra isn't properly opened (internal error) */

	/* these are standard errors that an Xtra may use
		if it finds it can't run on a given configuration. It
		should return these from DllGetClassObject/DllGetInterface
		(or the MoaCreatedProc if you are using the standard shell
		macros). */
#define		kMoaErr_NotEnoughCPU			MAKE_MOAERR(11)	/* need better CPU (e.g, >= 68020 */
#define		kMoaErr_NotEnoughFPU			MAKE_MOAERR(12)	/* FPU required for this Xtra */
#define		kMoaErr_NotEnoughHardware		MAKE_MOAERR(13)	/* extra HW needed (e.g., scanner) */
#define		kMoaErr_NotEnoughSSW			MAKE_MOAERR(14)	/* system software is too old */
#define		kMoaErr_NotEnoughExtraSSW		MAKE_MOAERR(15)	/* missing necessary inits (e.g., QuickTime */
#define		kMoaErr_NotEnoughDiskSpace		MAKE_MOAERR(16)	/* need more free space on disk */

#define 	kMoaErr_NoUnusedFreed			MAKE_MOAERR(17)	/* MoaFreeUnused didn't free anything */

#define 	kMoaErr_RequiredCallbackMissing	MAKE_MOAERR(18)	/* a required callback interface
																(e.g., IMoaHandle) was not supplied
																by your callback class */
#define 	kMoaErr_NoSuchKey				MAKE_MOAERR(19)	/* no such key */
#define 	kMoaErr_InternalError			MAKE_MOAERR(20)	/* shouldn't happen */
#define		kMoaErr_UnsupportedCodeType		MAKE_MOAERR(21)	/* Xtra doesn't have kind of code we need */
#define		kMoaErr_DupeClassesWarn			MAKE_MOAERR(22)	/* duplicate class IDs found */
#define		kMoaErr_DeadObject				MAKE_MOAERR(23)	/* object has been disposed */

#define 	kMoaErr_NotImplemented			((MoaError)0x80004001L)		/* same as E_NOTIMPL */

/*---------------------------------------------------------------------------
/ 3. Declare structures and types.
/--------------------------------------------*/
/*-------------------------------------------------------------------------*/

typedef MoaLong FAR *				PMoaLong;
typedef const MoaLong FAR *			ConstPMoaLong;
typedef MoaChar FAR *				PMoaChar;
typedef const MoaChar FAR *			ConstPMoaChar;
typedef MoaUnichar FAR *			PMoaUnichar;
typedef const MoaUnichar FAR *		ConstPMoaUnichar;
typedef MoaDouble FAR *				PMoaDouble;
typedef MoaID FAR * 				PMoaID;
typedef const MoaID FAR * 			ConstPMoaID;
typedef MoaID 						MoaClassID;
typedef const MoaClassID FAR * 		ConstPMoaClassID;
typedef MoaID 						MoaInterfaceID;
typedef const MoaInterfaceID FAR * 	ConstPMoaInterfaceID;
typedef MoaLong						MoaCoord;

typedef struct MoaPoint {
	MoaCoord y;
	MoaCoord x;
} MoaPoint;

typedef MoaPoint FAR * PMoaPoint;
typedef const MoaPoint FAR * ConstPMoaPoint;

typedef struct MoaRect {
	MoaCoord top;
	MoaCoord left;
	MoaCoord bottom;
	MoaCoord right;
} MoaRect;

typedef MoaRect FAR * PMoaRect;
typedef const MoaRect FAR * ConstPMoaRect;

#endif /* _H_moatypes */

