/*****************************************************************************
 * Copyright � 1994-1996 Macromedia, Inc.  All Rights Reserved
 *
 * You may utilize this source file to create and compile object code for use 
 * within products you create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
 * WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
 * INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
 * FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
 * USE OR INABILITY TO USE THIS CODE.
 *
 *	Name: cregster.cpp
 *	
 * 	Purpose: Definitions of Register class interface(s) and methods for a 
 *           generic Xtra.
 *	
 *  HOW TO CUSTOMIZE THIS FILE
 *  --------------------------
 *  1. Save this file under a different file name.
 *  2. Use a search and replace utility (case sensitive) to replace the
 *     following:
 *
 *     Replace         With	
 *     -------         ----
 *     cregster        <this file name>
 *     CRegister       <name of the class you defined>
 *
 *  3. If registering any optional interfaces, replace 'CChangeMe' with the
 *     appropriate class name(s).
 *  4. Add and modify source code by looking for '--> insert -->' comment
 *  5. Create a Xtra.cpp file that contains the Xtra definition.
 ****************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .cpp file should automatically include all the support files needed
 *	for this particular class. In addition, this file may include other .h
 *	files defining additional callback interfaces for use by a third party.   
 ****************************************************************************/ 
#ifndef INITGUID        /* INITGUID causes the actual GUIDs to be declared, */ 
	#define INITGUID      /* not just references to them. Must be declared in */
#endif                  /* only one file. */          

#ifndef _H_cregster
	#include "cregster.h"
#endif

/*****************************************************************************
 *  INTERNAL PROTOTYPES(S)
 *  ----------------------
 *  Declarations for functions used specifically in this file.
 ****************************************************************************/

/*****************************************************************************
 *  INTERNAL ROUTINE(S)
 *  -------------------
 *  Definition of file-specific functions
 ****************************************************************************/

/*****************************************************************************
 *  CLASS INTERFACE(S)
 *  ------------------
 *  The interface(s) implemented by your MOA class are specified here.  Note
 *	that at least one class in your Xtra should implement the IMoaRegister
 *	interface.
 *  NOTE: Because C++ does not use a lpVtbl to reference an interface's
 *	methods, the actual method declaration is done in the .h file.
 *
 *  Syntax:
 *  BEGIN_DEFINE_CLASS_INTERFACE(<class-name>, <interface-name>) 
 ****************************************************************************/ 
BEGIN_DEFINE_CLASS_INTERFACE(CRegister, IMoaRegister) 
END_DEFINE_CLASS_INTERFACE

/*
 * --> insert additional interface(s) -->
 */

/*****************************************************************************
 *  Data needed for Registering
 *	---------------------------
 *	Specific code needed to register different types of Xtras.  The skeleton
 *	source files include minimal implementations appropriate for each Xtra
 *	type.  Current necessary actions:
 *
 *	Scripting Xtra:					Add the Scripting Xtra Message Table
 *	Sprite Asset Xtra:			Nothing
 *	Tool Xtra:							Nothing
 *	Transition Asset Xtra		Nothing
 *****************************************************************************/ 

/*****************************************************************************
 *  CREATE AND DESTROY METHODS
 *  --------------------------
 *  Every interface and class has an associated 'Create' and 'Destroy' pair.
 *  'Create' methods are typically used to acquire interface(s), allocate 
 *  memory, and intialize variables. 'Destroy' methods are typically used to 
 *  release interfaces and free memory.
 *
 * NOTE:  In C++, the local variable 'This' is provided implicitly within 
 * a method implementation.  Thus, there is no need explicitly declare 'This' 
 * as a function parameter. However, this implementation detail doesn�t apply 
 * to the MOA class creator and destructor functions, which are standard C 
 * functions, coded exactly as in like they are in C examples.  
 *
 * Class Syntax:
 * STDMETHODIMP MoaCreate_<class-name>(<class-name> FAR * This)
 * STDMETHODIMP MoaDestroy_<class-name>(<class-name> FAR * This)
 *
 * Interface Syntax:
 * <class_name>_<if_name>::<class_name>_<if_name>(MoaError FAR * pErr)
 * <class_name>_<if_name>::~<class_name>_<if_name>()
 ****************************************************************************/ 

/* ---------------------------------------------------- MoaCreate_CRegister */
STDMETHODIMP MoaCreate_CRegister(CRegister FAR * This)
{
	UNUSED(This);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;

	/*
	 * --> insert additional code -->
	 */

	X_RETURN(MoaError, err);
	X_EXIT
}

/* --------------------------------------------------- MoaDestroy_CRegister */
STDMETHODIMP_(void) MoaDestroy_CRegister(CRegister FAR * This)
{
	UNUSED(This);
	X_ENTER

	/*
	 * --> insert additional code -->
	 */

	X_RETURN_VOID;
	X_EXIT
}

/* ---------------------------------- CRegister_IMoaRegister Create/Destroy */
CRegister_IMoaRegister::CRegister_IMoaRegister(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CRegister_IMoaRegister::~CRegister_IMoaRegister() {}

/*
 * --> insert additional create/destroy method(s) -->
 */

/*****************************************************************************
 *  METHOD IMPLEMENTATION(S)
 *  ------------------------
 *  This is where the methods to be defined by your MOA class are implemented.
 *  The bulk of the work in implementing Xtras is done here.  NOTE: 'This' is 
 *  implemented implicitly in C++, therefore it isn't used in the argument-
 *	list.
 *
 *  Syntax:
 *  STDMETHODIMP <class-name>_<interface-name>::<method-name>(<argument-list>)
 *****************************************************************************/ 

/* ------------------------------------------- CRegister_IMoaRegister::Register */
STDMETHODIMP_(MoaError) CRegister_IMoaRegister::Register(PIMoaCache pCache, 
	PIMoaDict pXtraDict)
{
	X_ENTER

	/* variable declaration */
	MoaError 	err = kMoaErr_NoErr;
	PIMoaDict	pRegDict;

	err = pCache->AddRegistryEntry(pXtraDict, &CLSID_CInterrogator, &IID_IMoaMmInterrogator, &pRegDict);
	err = pCache->AddRegistryEntry(pXtraDict, &CLSID_CInterrogator, &IID_IMoaMmTerminator, &pRegDict);

	#ifdef USING_INIT_FROM_DICT
	err = pCache->AddRegistryEntry(pXtraDict, &CLSID_CChangeMe, &IID_IMoaInitFromDict, &pRegDict);
	#endif
	
	#ifdef USING_NOTIFICATION_CLIENT
	err = pCache->AddRegistryEntry(pXtraDict, &CLSID_CChangeMe, &IID_IMoaNotificationClient, &pRegDict);
	#endif
	
	#ifdef USING_LOAD_CONTROL
	MoaLong		loadOptions = (kMoaXlc_PreloadAtLaunch | kMoaXlc_NeverUnload);
	err = pCache->AddRegistryEntry(pXtraDict, &CLSID_CChangeMe, &IID_IMoaXtraLoadControl, &pRegDict);
	err = pRegDict->Put(kMoaRegType_XtraLoadControlOptions, &loadOptions, 0, kMoaRegKey_XtraLoadControlOptions);
	#endif
	
	/*
	 * --> insert additional code -->
	 */

	X_STD_RETURN(err);
	X_EXIT
}

