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
 *	Name: casset.cpp
 *	
 * 	Purpose: Definitions of Asset class interface(s) and methods for the 
 *           Transition Xtra skeleton project.
 *
 *  HOW TO CUSTOMIZE THIS FILE
 *  --------------------------
 *  1. Save this file under a different file name.
 *  2. Use a search and replace utility (case sensitive) to replace the
 *     following:
 *
 *     Replace         With	
 *     -------         ----
 *     casset		   <this file name>
 *     CAsset          <name of the class you defined>
 *
 *  3. Add and modify source code by looking for '--> insert -->' comment
 *  4. Create a Xtra.cpp file that contains the Xtra definition.
 ****************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .cpp file should automatically include all the support files needed
 *	for this particular class. In addition, this file may include other .h
 *	files defining additional callback interfaces for use by a third party.   
 ****************************************************************************/ 
#ifndef _H_casset
	#include "casset.h"
#endif


#ifdef MACINTOSH
	#include <QuickDraw.h>
#endif

#include <String.h> 

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
BEGIN_DEFINE_CLASS_INTERFACE(CAsset, IMoaMmXAsset)
END_DEFINE_CLASS_INTERFACE

#ifdef USING_INIT_FROM_DICT
BEGIN_DEFINE_CLASS_INTERFACE(CAsset, IMoaInitFromDict)
END_DEFINE_CLASS_INTERFACE
#endif

#ifdef USING_NOTIFICATION_CLIENT
BEGIN_DEFINE_CLASS_INTERFACE(CAsset, IMoaNotificationClient)
END_DEFINE_CLASS_INTERFACE
#endif

/*
 * --> insert additional interface(s) -->
 */ 

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

/* ------------------------------------------------------- MoaCreate_CAsset */
STDMETHODIMP  		MoaCreate_CAsset(CAsset FAR * This)
{
	UNUSED(This);
	X_ENTER
	
	/* variable declarations */
	MoaError	err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
		
	X_STD_RETURN(err);
	X_EXIT
}

/* ------------------------------------------------------ MoaDestroy_CAsset */
STDMETHODIMP_(void) MoaDestroy_CAsset(CAsset FAR * This)
{
	UNUSED(This);
	X_ENTER
	
	/*
	 * --> insert additional code -->
	 */
	
	X_RETURN_VOID;
	X_EXIT
}

/* ------------------------------------- CAsset_IMoaMmXAsset Create/Destroy */
CAsset_IMoaMmXAsset::CAsset_IMoaMmXAsset(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CAsset_IMoaMmXAsset::~CAsset_IMoaMmXAsset() {}

#ifdef USING_INIT_FROM_DICT
/* ------------------------------------ CAsset_IMoaInitFromDict Create/Destroy */
CAsset_IMoaInitFromDict::CAsset_IMoaInitFromDict(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CAsset_IMoaInitFromDict::~CAsset_IMoaInitFromDict() {}
#endif

#ifdef USING_NOTIFICATION_CLIENT
/* --------------------------- CAsset_IMoaNotificationClient Create/Destroy */
CAsset_IMoaNotificationClient::CAsset_IMoaNotificationClient(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CAsset_IMoaNotificationClient::~CAsset_IMoaNotificationClient() {}
#endif

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
 ****************************************************************************/ 

/* ------------------------------------------- CAsset_IMoaMmXAsset::GetProp */
STDMETHODIMP CAsset_IMoaMmXAsset::GetProp(MoaMmSymbol symbol, PMoaMmValue	pPropValue)
{
	UNUSED(symbol);
	UNUSED(pPropValue);
	X_ENTER

	MoaError		err = kMoaMmErr_PropertyNotFound;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ------------------------------------------- CAsset_IMoaMmXAsset::SetProp */
STDMETHODIMP CAsset_IMoaMmXAsset::SetProp(MoaMmSymbol symbol, ConstPMoaMmValue pPropValue)
{
	UNUSED(symbol);
	UNUSED(pPropValue);
	X_ENTER

	MoaError		err = kMoaMmErr_PropertyNotFound;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* -------------------------------------- CAsset_IMoaMmXAsset::CallFunction */
STDMETHODIMP CAsset_IMoaMmXAsset::CallFunction(MoaMmSymbol methodName, MoaLong nArgs, ConstPMoaMmValue pArgs, PMoaMmValue pResult)
{
	UNUSED(methodName);
	UNUSED(nArgs);
	UNUSED(pArgs);
	UNUSED(pResult);
	X_ENTER
	
	MoaError		err = kMoaMmErr_FunctionNotFound;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* --------------------------------------- CAsset_IMoaMmXAsset::SetCallback */
STDMETHODIMP CAsset_IMoaMmXAsset::SetCallback(PIMoaMmAssetCallback pAssetCallback)
{
	UNUSED(pAssetCallback);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* -------------------------------------------- CAsset_IMoaMmXAsset::Notify */
/* This method is intended for communicating between the asset and its xtras.
   The developer is free to define message codes for private use.  This may be
   called directly by an actor, or through the
   IMoaMmSpriteCallback::NotifyAsset() callback.
 */
STDMETHODIMP CAsset_IMoaMmXAsset::Notify(MoaLong msgCode, PMoaVoid refCon)
{
	UNUSED(msgCode);
	UNUSED(refCon);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ------------------------------------ CAsset_IMoaMmXAsset::GetDefaultRect */
/* We return our default rectangle centered around (0,0).  (0,0) here
   corresponds to the "loc" of the sprite, whichis the point of reference for
   the sprite.  Dragging the sprite out to the stage will position the sprite
   such that the loc is at the mouse drop position.
 */
STDMETHODIMP CAsset_IMoaMmXAsset::GetDefaultRect(PMoaRect pRect)
{
	X_ENTER
	
	MoaError	err = kMoaErr_NoErr;
	
	/* 32 x 32 centered about (0,0) */
	pRect->top = -16;
	pRect->left = -16;
	pRect->bottom = 16;
	pRect->right = 16;
		
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* --------------------------------- CAsset_IMoaMmXAsset::PrepareNewContent */
/* This method is called to have the class set-up its default state when a new
   cast member is created (note that this is different from when a new
   instance of CAsset is created; instances of the XAsset are created at both
   movie-open time (for pre-existing cast members being read-in) and new cast
   member creation time.  PrepareNewContent() is only called at new cast
   member creation time, just after the XAsset instance is created. 
 */
STDMETHODIMP CAsset_IMoaMmXAsset::PrepareNewContent(MoaMmNewFlags newFlags)
{
	UNUSED(newFlags);
	X_ENTER
	
	MoaError	err = kMoaErr_NoErr;
	
	/* A new cast member is being created in memory.  Set up default media and
	   props. */

	/* Dispose of any media and props we may have currently in memory */
	CAsset_IMoaMmXAsset::FreeMedia();
	CAsset_IMoaMmXAsset::FreeProps();
	
	/* Initialize props / media to default values here. 
	   The host app assumes that both props and media are "dirty" when a new
	   cast member is created. 
	
	   We are now "loaded" in the sense that we have everything we need from 
	   disk (there isn't anything on disk yet, so we exist only in-memory 
	   at this point). */

	 /*
	  * --> insert additional code -->
	  */
	
	X_STD_RETURN(err);
	X_EXIT
}


/* ------------------------------------ CAsset_IMoaMmXAsset::StreamOutMedia */
STDMETHODIMP CAsset_IMoaMmXAsset::StreamOutMedia(PIMoaStream pOutStream)
{
	UNUSED(pOutStream);
	X_ENTER
	
	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ------------------------------------- CAsset_IMoaMmXAsset::StreamInMedia */
STDMETHODIMP CAsset_IMoaMmXAsset::StreamInMedia(PIMoaStream pInStream)
{
	UNUSED(pInStream);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ----------------------------------------- CAsset_IMoaMmXAsset::FreeMedia */
STDMETHODIMP CAsset_IMoaMmXAsset::FreeMedia()
{
	X_ENTER

	MoaError	err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* --------------------------------- CAsset_IMoaMmXAsset::GetInMemMediaSize */
STDMETHODIMP CAsset_IMoaMmXAsset::GetInMemMediaSize(MoaUlong FAR * pSizeBytes)
{
	UNUSED(pSizeBytes);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ----------------------------- CAsset_IMoaMmXAsset::GetStreamOutMediaSize */
STDMETHODIMP CAsset_IMoaMmXAsset::GetStreamOutMediaSize(MoaUlong FAR * pSizeBytes)
{
	UNUSED(pSizeBytes);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ------------------------------------ CAsset_IMoaMmXAsset::StreamOutProps */
STDMETHODIMP CAsset_IMoaMmXAsset::StreamOutProps(PIMoaStream pOutStream)
{
	UNUSED(pOutStream);
	X_ENTER
	
	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ------------------------------------- CAsset_IMoaMmXAsset::StreamInProps */
STDMETHODIMP CAsset_IMoaMmXAsset::StreamInProps(PIMoaStream pInStream)
{
	UNUSED(pInStream);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ----------------------------------------- CAsset_IMoaMmXAsset::FreeProps */
STDMETHODIMP CAsset_IMoaMmXAsset::FreeProps()
{
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* --------------------------------- CAsset_IMoaMmXAsset::GetInMemPropsSize */
STDMETHODIMP CAsset_IMoaMmXAsset::GetInMemPropsSize(MoaUlong FAR * pSizeBytes)
{
	UNUSED(pSizeBytes);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ----------------------------- CAsset_IMoaMmXAsset::GetStreamOutPropsSize */
STDMETHODIMP CAsset_IMoaMmXAsset::GetStreamOutPropsSize(MoaUlong FAR * pSizeBytes)
{
	UNUSED(pSizeBytes);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ----------------------------------------- CAsset_IMoaMmXAsset::NewXActor */
STDMETHODIMP CAsset_IMoaMmXAsset::NewXActor(PMoaVoid FAR * ppXActor) 
{
	UNUSED(ppXActor);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* --------------------------------- CAsset_IMoaMmXAsset::InvokeMediaEditor */
STDMETHODIMP CAsset_IMoaMmXAsset::InvokeMediaEditor(PMoaMmModifyFlags pModifyFlags)
{
	UNUSED(pModifyFlags);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* --------------------------------- CAsset_IMoaMmXAsset::InvokePropsEditor */
STDMETHODIMP CAsset_IMoaMmXAsset::InvokePropsEditor()
{
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* --------------------------------- CAsset_IMoaMmXAsset::FinishPropsEditor */
STDMETHODIMP CAsset_IMoaMmXAsset::FinishPropsEditor(MoaBoolParam commitChanges,					
	PMoaMmModifyFlags pModifyFlags)
{
	UNUSED(commitChanges);
	UNUSED(pModifyFlags);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ------------------------------------- CAsset_IMoaMmXAsset_InvokeAboutBox */
STDMETHODIMP CAsset_IMoaMmXAsset::InvokeAboutBox()
{
	X_ENTER

	MoaError		err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ---------------------------------- CAsset_IMoaMmXAsset::ImageStaticThumb */
STDMETHODIMP CAsset_IMoaMmXAsset::ImageStaticThumb(PIMoaMmGC pGC, ConstPMoaRect pImageRect)
{
	UNUSED(pGC);
	UNUSED(pImageRect);
	X_ENTER

	MoaError		err = kMoaMmErr_NotImplemented;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ------------------------------- CAsset_IMoaMmXAsset::BeginImageAnimThumb */
STDMETHODIMP CAsset_IMoaMmXAsset::BeginImageAnimThumb(PIMoaMmGC pGC, ConstPMoaRect pImageRect)
{
	UNUSED(pGC);
	UNUSED(pImageRect);
	X_ENTER

	MoaError		err = kMoaMmErr_NotImplemented;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* ----------------------------- CAsset_IMoaMmXAsset::ServiceImageAnimThumb */
STDMETHODIMP CAsset_IMoaMmXAsset::ServiceImageAnimThumb(PIMoaMmGC pGC, ConstPMoaRect pImageRect)
{
	UNUSED(pGC);
	UNUSED(pImageRect);
	X_ENTER

	MoaError		err = kMoaMmErr_NotImplemented;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* --------------------------------- CAsset_IMoaMmXAsset::EndImageAnimThumb */
STDMETHODIMP CAsset_IMoaMmXAsset::EndImageAnimThumb(PIMoaMmGC pGC, ConstPMoaRect pImageRect)
{
	UNUSED(pGC);
	UNUSED(pImageRect);
	X_ENTER

	MoaError		err = kMoaMmErr_NotImplemented;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

#ifdef USING_INIT_FROM_DICT
/* ---------------------------------- CAsset_IMoaInitFromDict::InitFromDict */
STDMETHODIMP CAsset_IMoaInitFromDict::InitFromDict(PIMoaRegistryEntryDict pRegistryDict)
{
	UNUSED(pRegistryDict);
	X_ENTER
	
	/* variable declarations */
	MoaError err = kMoaErr_NoErr;

	/*
	 *  --> insert additional code -->
	 */

	X_STD_RETURN(err);
	X_EXIT
}
#endif

#ifdef USING_NOTIFICATION_CLIENT
/* ---------------------------------- CAsset_IMoaNotificationClient::Notify */
STDMETHODIMP CAsset_IMoaNotificationClient::Notify(ConstPMoaNotifyID nid, PMoaVoid pNData, PMoaVoid pRefCon)
{
	UNUSED(nid);
	UNUSED(pNData);
	UNUSED(pRefCon);
	X_ENTER
	
	/* variable declarations */
	MoaError err = kMoaErr_NoErr;

	/*
	 *  --> insert additional code -->
	 */

	X_STD_RETURN(err);
	X_EXIT
}
#endif

