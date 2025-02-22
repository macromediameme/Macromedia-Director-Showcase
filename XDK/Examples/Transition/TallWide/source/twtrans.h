#ifndef _H_ctrans
#define _H_ctrans

/*****************************************************************************
 * Copyright � 1994-1999 Macromedia, Inc.  All Rights Reserved
 *
 * You may utilize this source file to create and compile object code for use 
 * within products you create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
 * WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
 * INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
 * FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
 * USE OR INABILITY TO USE THIS CODE.
 *
 *	Name: TWTrans.h
 *	
 * 	Purpose: Declarations of the CLSID, class instance variables, and  
 *           class interface(s) for TallWide Xtra's sprite actor class.
 *
 ****************************************************************************/ 

/*****************************************************************************
 *  XTRA SPECIFIC DEFINE(S)
 *  -----------------------
 *	Any #define's specific to this Xtra.  
 ****************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .h file should automatically include all the support files needed for
 *	this particular class. In addition, this file may include other .h files
 *	defining additional callback interfaces for use by a third party.   
 ****************************************************************************/ 
#ifndef _H_moaxtra
	#include "moaxtra.h"
#endif

#ifndef _H_mmixasst
	#include "mmixasst.h"
#endif

#ifndef _H_mmiutil
	#include "mmiutil.h"
#endif

/*****************************************************************************
 *	CLASS SPECIFIC DEFINE(S)
 *	-----------------------
 *	Any #define's specific to this class 
 ****************************************************************************/ 
#ifndef UNUSED
	#define UNUSED(x) x
#endif

#ifndef SHARED_DATA
#define SHARED_DATA
typedef struct {
	MoaLong			initialWidth;
	MoaLong			initialHeight;
	MoaLong			verticalSpeed;
	MoaLong			horizontalSpeed;
} SharedAssetData, FAR * PSharedAssetData;
#endif

/* Sprite notification messages */
enum {
	kSprNotifyMsg_SendProps = 1
};

/*****************************************************************************
 *  CLSID
 *  -----
 *  The CLSID is a GUID that unquely identifies your MOA class.  To generate a
 *  GUID, use the genUID.app utility (Mac) or the GUIDGEN.EXE utility (Win).
 ****************************************************************************/ 
DEFINE_GUID(CLSID(CTallWideTransition), 0x89FF73CCL, 0x8BD8, 0x11D0, 0x94, 0x7B, 0x00, 0x05, 0x02, 0x70, 0xB2, 0x08);

/*****************************************************************************
 *  CLASS INSTANCE VARIABLES
 *  ------------------------
 *  Class instance variable are variables whose scope is exclusive to the
 *  methods implemented by your MOA class.  Variables necessary for the
 *  implementation of your MOA class should be placed here.
 ****************************************************************************/ 
EXTERN_BEGIN_DEFINE_CLASS_INSTANCE_VARS(CTallWideTransition)
	PMoaVoid		windy;			/* mac window ptr */
	PMoaVoid		buffy;			/* mac gworld ptr */
	MoaRect 		trect;			/* mac rect */
	MoaRect			curRect;		/* transitions's changing rectangle */ 
	MoaLong			myPoly;
	MoaLong			chnkSize;		/* chunkSize */
	MoaLong			somevalue;
	PSharedAssetData	pSharedAssetData;	
EXTERN_END_DEFINE_CLASS_INSTANCE_VARS

/*****************************************************************************
 *  CLASS INTERFACE(S)
 *  ------------------
 *  The interface(s) implemented by your MOA class are specified here.  Note
 *	that at least one class in your Xtra should implement the IMoaRegister
 *	interface.
 *  NOTE: Because C++ does not use a lpVtbl to reference an interface's methods, 
 *  the actual method declaration is done here.
 *
 *  Syntax:
 *  EXTERN_BEGIN_DEFINE_CLASS_INTERFACE(<class-name>, <interface-name>) 
 *		EXTERN_DEFINE_METHOD(<return-type>, <method-name>,(<argument-list>)) 
 *	EXTERN_END_DEFINE_CLASS_INTERFACE
 ****************************************************************************/ 
EXTERN_BEGIN_DEFINE_CLASS_INTERFACE(CTallWideTransition, IMoaMmXTransitionActor)
	EXTERN_DEFINE_METHOD(MoaError, Notify, (MoaLong, PMoaVoid))		
	EXTERN_DEFINE_METHOD(MoaError, Cue, (PIMoaMmGC, PIMoaMmGC, ConstPMoaRect, ConstPMoaMmTransInfo))
	EXTERN_DEFINE_METHOD(MoaError, Continue, (PIMoaMmGC, PIMoaMmGC, ConstPMoaRect, ConstPMoaMmTransInfo, MoaBoolParam *))
	EXTERN_DEFINE_METHOD(MoaError, Finish, (PIMoaMmGC, PIMoaMmGC, ConstPMoaRect, ConstPMoaMmTransInfo))		
EXTERN_END_DEFINE_CLASS_INTERFACE


#endif /* _H_ctrans */
