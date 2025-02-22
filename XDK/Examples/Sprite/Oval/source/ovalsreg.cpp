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
 *	Name: ovalsreg.cpp
 *	
 * 	Purpose: Definitions of Register class interface(s) and methods for the 
 *           Sprite Oval Xtra example.
 *
 ****************************************************************************/ 

/*****************************************************************************
 *  XTRA SPECIFIC DEFINE(S)
 *  -----------------------
 *	Any #define's specific to this Xtra.  
 *****************************************************************************/ 
#ifndef INITGUID
#define INITGUID
#endif

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .cpp file should automatically include all the support files needed for 
 *  this particular class. In addition, this file may include other .h files 
 *  defining additional callback interfaces for use by a third party.   
 *****************************************************************************/ 
#ifndef _H_MMIXASST
#include "mmixasst.h"
#endif

#include "ovalsreg.h"

#include "AwiServc.h"
  
#ifdef MACINTOSH
#include <QuickDraw.h>
#endif /* /*  MACINTOSH /* */

#include <String.h>

/*****************************************************************************
 *  CLASS INTERFACE(S)
 *  ------------------
 *  The interface(s) implemented by your MOA class are specified here.  Note that
 *  at least one class in your Xtra should implement the IMoaRegister interface.
 *  NOTE: Because C++ does not use a lpVtbl to reference an interface's methods, 
 *  the actual method declaration is done in the .h file.
 *
 *  Syntax:
 *  BEGIN_DEFINE_CLASS_INTERFACE(<class-name>, <interface-name>) 
 *****************************************************************************/ 
BEGIN_DEFINE_CLASS_INTERFACE(COvalSpriteRegister, IMoaRegister) 
END_DEFINE_CLASS_INTERFACE


/*****************************************************************************
 *  CREATE AND DESTROY METHODS
 *  --------------------------
 *  Every interface and class has an associated 'Create' and 'Destroy' pair.
 *  'Create' methods are typically used to acquire interface(s), allocate 
 *  memory, and intialize variables.  'Destroy' methods are typically used to 
 *  release interfaces and free memory.  To create 'empty' create and destroy 
 *  methods for an interface, use the STD_INTERFACE_CREATE_DESTROY macro.
 *****************************************************************************/ 

/* NOTE:  In C++, the local variable 'This' is provided implicitly within 
 * a method implementation.  Thus, there is no need explicitly declare 'This' 
 * as a function parameter. However, this implementation detail doesn�t apply 
 * to the MOA class creator and destructor functions, which are standard C 
 * functions, coded exactly as in like they are in C examples.  
 *
 * Syntax:
 * STDMETHODIMP MoaCreate_<class-name>(<class-name> FAR * This)  
 * STDMETHODIMP MoaDestroy_<class-name>(<class-name> FAR * This)  
 */

/* ------------------------------------------------- MoaCreate_COvalSpriteRegister */
STDMETHODIMP  		MoaCreate_COvalSpriteRegister(COvalSpriteRegister FAR * This)
{
	
	return(kMoaErr_NoErr);
}

/* ------------------------------------------------ MoaDestroy_COvalSpriteRegister */
STDMETHODIMP_(void) MoaDestroy_COvalSpriteRegister(COvalSpriteRegister FAR * This)
{
	
	return;
	
}

/* macros that create constructors and destructors for the following interface(s) */

STD_INTERFACE_CREATE_DESTROY(COvalSpriteRegister, IMoaRegister)

/*****************************************************************************
 *  METHOD IMPLEMENTATION(S)
 *  ------------------------
 *  This is where the methods to be defined by your MOA class are implemented.
 *  The bulk of the work in implementing Xtras is done here.  NOTE: 'This' is 
 *  implemented implicitly in C++, therefore it isn't used in the argument-list.
 *
 *	Syntax:
 *  STDMETHODIMP <class-name>_<interface-name>::<method-name>(<argument-list>)
 *****************************************************************************/ 

#define kMyAssetTypeCount	1

typedef MoaLong MyData;

/* ------------------------------------ COvalSpriteRegister_IMoaRegister::Register */
STDMETHODIMP_(MoaError) COvalSpriteRegister_IMoaRegister::Register(PIMoaCache pCache,
    PIMoaDict pXtraDict)
{
	
	/* variable declaration */
	MoaError 	err = kMoaErr_NoErr;
	PIMoaDict 	pRegDict;
	long		count;
	PIMoaAwEventSender pEventSender = NULL;
	
	/* Standard asset entries */
	char* 				symStr[kMyAssetTypeCount] 		= {"oval"};
	char* 				nameStr[kMyAssetTypeCount] 		= {"Wacky Oval"};
	char* 				catStr[kMyAssetTypeCount] 		= {"Sprite Examples"};
	MoaMmActorType 		actorType[kMyAssetTypeCount] 	= { kMoaMmActorType_Sprite };
	MoaMmAssetCaps		assetCaps[kMyAssetTypeCount] 	= { kMoaMmAssetCaps_None };
	
	/* Private entries */
	MyData				myData[kMyAssetTypeCount]		= { 0L };

	/* Register all of our asset types */
	/* NOTE:  Eventhough we are only registering one Xtra we are using a loop so that 
	          it may be modified to allow the registration of multiple types of Xtras
	          in the future. */
	for (count = 0; count < kMyAssetTypeCount; count ++)
	{
		pObj->pCallback->MoaCreateInstance(&CLSID_COvalSpriteAsset,
																				&IID_IMoaAwEventSender,
																				(PPMoaVoid)&pEventSender);
		if (pEventSender)
			/* Register the event sender */
			if ((err = pCache->AddRegistryEntry(pXtraDict,
				&CLSID_COvalSpriteAsset,
				&IID_IMoaAwEventSender,
				&pRegDict))
				!= kMoaErr_NoErr) break;

		pEventSender->Release();

		if ((err = pCache->AddRegistryEntry(pXtraDict,
			&CLSID_COvalSpriteAsset,
			&IID_IMoaMmXAsset,
			&pRegDict))
			!= kMoaErr_NoErr) break;
	
		/* Register standard asset entries */
		if ((err = pRegDict->Put(kMoaMmDictType_SymbolString, 
			symStr[count], 0, kMoaMmDictKey_SymbolString)) 
			!= kMoaErr_NoErr) break;
			
		if ((err = pRegDict->Put(kMoaMmDictType_DisplayNameString, 
			nameStr[count], 0, kMoaMmDictKey_DisplayNameString)) 
			!= kMoaErr_NoErr) break;

		if ((err = pRegDict->Put(kMoaMmDictType_DisplayCategoryString, 
			catStr[count], 0, kMoaMmDictKey_DisplayCategoryString)) 
			!= kMoaErr_NoErr) break;
			
		if ((err = pRegDict->Put(kMoaMmDictType_ActorType, 
			&actorType[count], 0, kMoaMmDictKey_ActorType)) 
			!= kMoaErr_NoErr) break;
			
		if ((err = pRegDict->Put(kMoaMmDictType_AssetCaps, 
			&assetCaps[count], sizeof(MoaMmAssetCaps), kMoaMmDictKey_AssetCaps)) 
			!= kMoaErr_NoErr) break;
								
		/* Example of registering private data for init from dict */
		if ((err = pRegDict->Put(kMoaDictType_Bytes, 
			&myData[count], sizeof(MyData), "myData")) 
			!= kMoaErr_NoErr) break;
		
		/* Mark this Xtra "Safe for Shockwave" */
		MoaBool bItsSafe = TRUE;
		if ((err = pRegDict->Put(kMoaMmDictType_SafeForShockwave,
			&bItsSafe, 	sizeof( bItsSafe ), kMoaMmDictKey_SafeForShockwave))
			!= kMoaErr_NoErr) break;
			
	}
	
	return(err);
}
