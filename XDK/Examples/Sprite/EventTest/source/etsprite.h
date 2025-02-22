#ifndef _H_csprite
#define _H_csprite

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
 *	Name: etsprite.h
 *	
 * 	Purpose: Declarations of the CLSID, class instance variables, and  
 *           class interface(s) for EventTest Xtra's sprite actor class.
 *
 ****************************************************************************/ 

/*****************************************************************************
 *  XTRA SPECIFIC DEFINE(S)
 *  -----------------------
 *	Any #define's specific to this Xtra.  
 ****************************************************************************/ 

#include "mmtypes.h"

#ifdef WINDOWS
	/* Resource ID's for Bitmaps to be drawn */
	#define THUMBNAIL			107
	#define SPIKE       		109
	#define DIRECTOR_4  		110
#endif /*WIN */

/* These correspond to the two different visual states of our */
/* actor: */
#define kMyActorState_0		0
#define kMyActorState_1		1

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

/*****************************************************************************
 *  CLSID
 *  -----
 *  The CLSID is a GUID that unquely identifies your MOA class.  To generate a
 *  GUID, use the genUID.app utility (Mac) or the GUIDGEN.EXE utility (Win).
 ****************************************************************************/ 
DEFINE_GUID(CLSID(CEventTestSprite), 0x71056052L, 0x97EA, 0x11D0, 0x95, 0x0C, 0x00, 0x05, 0x02, 0x70, 0xB2, 0x08);

/*****************************************************************************
 *  CLASS INSTANCE VARIABLES
 *  ------------------------
 *  Class instance variable are variables whose scope is exclusive to the
 *  methods implemented by your MOA class.  Variables necessary for the
 *  implementation of your MOA class should be placed here.
 ****************************************************************************/ 
EXTERN_BEGIN_DEFINE_CLASS_INSTANCE_VARS(CEventTestSprite)
	PIMoaMmXAsset 	pXAsset;
	MoaLong 			 	state;	
	MoaLong				 	stepState;
	MoaLong				 	direction;

	// MessageWrite() is a method private to the CEventTestSprite class.  It is
	//  a utility function accessed off of the pObj of an interface or This in a
	//  constructor/destructor.
	MoaError				MessageWrite(char *);

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
EXTERN_BEGIN_DEFINE_CLASS_INTERFACE(CEventTestSprite, IMoaMmXSpriteActor)
	EXTERN_DEFINE_METHOD(MoaError, GetProp, (MoaMmSymbol, PMoaMmValue))		
	EXTERN_DEFINE_METHOD(MoaError, SetProp, (MoaMmSymbol, ConstPMoaMmValue))		
	EXTERN_DEFINE_METHOD(MoaError, CallFunction, (MoaMmSymbol, MoaLong, ConstPMoaMmValue,PMoaMmValue))		
	EXTERN_DEFINE_METHOD(MoaError, SetCallback, (PIMoaMmSpriteCallback))		
	EXTERN_DEFINE_METHOD(MoaError, Notify, (MoaLong, PMoaVoid))		
	EXTERN_DEFINE_METHOD(MoaError, GetCaps, (PMoaMmXSpriteCaps))		
	EXTERN_DEFINE_METHOD(MoaError, CollectChanges, (ConstPMoaMmXSpriteInfo, PIMoaMmChangeCollector))		
	EXTERN_DEFINE_METHOD(MoaError, ContainsPoint, (ConstPMoaMmXSpriteInfo, ConstPMoaPoint,	MoaBoolParam FAR *))		
	EXTERN_DEFINE_METHOD(MoaError, Image, (ConstPMoaMmXSpriteInfo, ConstPMoaMmPlayerStateInfo, PIMoaMmGC))		
	EXTERN_DEFINE_METHOD(MoaError, Event, (ConstPMoaMmEventInfo, ConstPMoaMmPlayerStateInfo, MoaBoolParam *))		
EXTERN_END_DEFINE_CLASS_INTERFACE


#endif /* _H_csprite */
