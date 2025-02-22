#ifndef _H_cregster
#define _H_cregster

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
 *	Name: ITReg.h
 *	
 * 	Purpose: Declarations of the CLSID, class instance variables, and  
 *           class interface(s) for InkTest Xtra's Register class.
 *
 **********************************************************************************/ 

/*****************************************************************************
 *  XTRA SPECIFIC DEFINE(S)
 *  -----------------------
 *	Any #define's specific to this Xtra.  
 *****************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .h file should automatically include all the support files needed for 
 *  this particular class. In addition, this file may include other .h files 
 *  that define additional callback interfaces for use by a third party.   
 *****************************************************************************/ 
#ifndef _H_moaxtra
#include "moaxtra.h"
#endif

#include "ITAsset.h"
#include "ITSprite.h"

/*****************************************************************************
 *  CONFIGURATION DEFINE(S)
 *  -----------------------
 *	Uncomment the line below to activate debugging or load control code.
 ****************************************************************************/ 
//#define MOA_DEBUG
//#define USING_LOAD_CONTROL

/*****************************************************************************
 *	CLASS SPECIFIC DEFINE(S)
 *	-----------------------
 *	Any #define's specific to this class 
 ****************************************************************************/ 
#ifndef UNUSED
	#define UNUSED(x) x
#endif

/*****************************************************************************
 *	CLSID
 *	-----
 *	The CLSID is a GUID that unquely identifies your MOA class.  To generate a
 *	GUID, use the genUID.app utility (Mac) or the GUIDGEN.EXE utility (Win).
 *	The following line will produce a pre-compiler error if not replaced with
 *	a valid CLSID.
 ****************************************************************************/ 
DEFINE_GUID(CLSID(CInkTestRegister), 0x6F0AEDD0L, 0x97EA, 0x11D0, 0x95, 0x0C, 0x00, 0x05, 0x02, 0x70, 0xB2, 0x08);

/*****************************************************************************
 *  CLASS INSTANCE VARIABLES
 *  ------------------------
 *  Class instance variable are variables whose scope is exclusive to the
 *  methods implemented by your MOA class.  Variables necessary for the
 *  implementation of your MOA class should be places here.
 *****************************************************************************/ 
EXTERN_BEGIN_DEFINE_CLASS_INSTANCE_VARS(CInkTestRegister) 
	MoaLong	instData;
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
EXTERN_BEGIN_DEFINE_CLASS_INTERFACE(CInkTestRegister, IMoaRegister) 
	EXTERN_DEFINE_METHOD(MoaError, Register, (PIMoaCache, PIMoaDict))
private:
	EXTERN_DEFINE_METHOD(void, CToPas, (ConstPMoaChar, PMoaChar))
	EXTERN_DEFINE_METHOD(MoaError, RegisterIcon, (PIMoaDict, ConstPMoaChar, MoaBoolParam))
EXTERN_END_DEFINE_CLASS_INTERFACE


#endif /* _H_cregster */
