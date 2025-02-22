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
 *	Name: TWReg.cpp
 *	
 * 	Purpose: Definitions of Register class interface(s) and methods for the
 *           TallWide Transition Xtra.
 *	
 ****************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .cpp file should automatically include all the support files needed
 *	for this particular class. In addition, this file may include other .h
 *	files defining additional callback interfaces for use by a third party. 
 *  Test of localized high-ascii comments:    �  �  �  �  
 ****************************************************************************/ 
#ifndef INITGUID        /* INITGUID causes the actual GUIDs to be declared, */ 
	#define INITGUID      /* not just references to them. Must be declared in */
#endif                  /* only one file. */          

#include "TWReg.h"
#include "TWAsset.h"
#include "TWTrans.h"

#ifdef MACINTOSH
	#include <Resources.h>
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
BEGIN_DEFINE_CLASS_INTERFACE(CTallWideRegister, IMoaRegister) 
END_DEFINE_CLASS_INTERFACE

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
STDMETHODIMP MoaCreate_CTallWideRegister(CTallWideRegister FAR * This)
{
	UNUSED(This);
	X_ENTER

	MoaError		err = kMoaErr_NoErr;

	X_RETURN(MoaError, err);
	X_EXIT
}

/* --------------------------------------------------- MoaDestroy_CRegister */
STDMETHODIMP_(void) MoaDestroy_CTallWideRegister(CTallWideRegister FAR * This)
{
	UNUSED(This);
	X_ENTER

	X_RETURN_VOID;
	X_EXIT
}

/* ---------------------------------- CRegister_IMoaRegister Create/Destroy */
CTallWideRegister_IMoaRegister::CTallWideRegister_IMoaRegister(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CTallWideRegister_IMoaRegister::~CTallWideRegister_IMoaRegister() {}

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

#define kMyAssetTypeCount	1
/* This transitionCaps has the following meaning:

	- Supports either changeArea or fullStage (transition area control enabled)
	- Does not support chunkSize control 			  (chunksize control disabled)
	- Does *not* support duration control	  		  (duration control disabled)
	- Can interleave with palette changes
	- Doesn't do any direct screen access
*/

/* ------------------------------------ CRegister_IMoaRegister::Register */
STDMETHODIMP_(MoaError) CTallWideRegister_IMoaRegister::Register(PIMoaCache pCache,
    PIMoaDict pXtraDict)
{
	X_ENTER
	
	MoaError 		err = kMoaErr_NoErr;
	PIMoaDict 	pRegDict;
	long				count;
	
	/* Standard asset entries */
	/* Cast member TYPE string	 */
	PMoaChar 			symStr[kMyAssetTypeCount] 		= {"tallWideTrans"};
	/* Trasition name as it will appear in transition dialog */
	PMoaChar 			nameStr[kMyAssetTypeCount] 		= {"Tall then Wide Transition"};
	/* Transition grouping name (NOT IMP 10/15) */
	PMoaChar 			catStr[kMyAssetTypeCount]		= {"Transition Examples"};
	/* Actor type--transition for us */
	MoaMmActorType 		actorType[kMyAssetTypeCount] 	= { kMoaMmActorType_Transition };
	/* list of capabilities */
	MoaMmAssetCaps		assetCaps[kMyAssetTypeCount] 	= { (kMoaMmAssetCaps_CanImageStaticThumb |
															 kMoaMmAssetCaps_CanImageAnimThumb |
															 kMoaMmAssetCaps_HasAboutBox |
															 kMoaMmAssetCaps_HasPropsEditor)};
	/* Register the small cast icons */
	char*				colorIconResName[kMyAssetTypeCount]	= { PICON };
	char*				bwIconResName[kMyAssetTypeCount]	= { PICON_BW };

	/* transition caps list: which standard default transition caps */
	/* of chunksize, duration and changearea are supported */
	MoaMmTransCaps		transCaps[kMyAssetTypeCount]	= { kMoaMmTransCaps_ChangeArea /*|
															kMoaMmTransCaps_ChunkSize |
															kMoaMmTransCaps_Duration */};

	/* Default for the changearea cap that I do support */
	MoaLong				area[kMyAssetTypeCount]			= { kMoaMmTransArea_FullStage };
	

	/* Register all of our asset types */
	
	for (count = 0; count < kMyAssetTypeCount; count ++)
	{
		if ((err = pCache->AddRegistryEntry(pXtraDict,
			&CLSID_CTallWideAsset,
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
			&assetCaps[count], sizeof ( MoaMmAssetCaps ), kMoaMmDictKey_AssetCaps)) 
			!= kMoaErr_NoErr) break;
			
		/* Mark this Xtra "Safe for Shockwave" */
		
		MoaBool bItsSafe = TRUE;
		
		if ((err = pRegDict->Put(kMoaMmDictType_SafeForShockwave,
			&bItsSafe, 	sizeof( bItsSafe ), kMoaMmDictKey_SafeForShockwave))
			!= kMoaErr_NoErr) break;
			
			
		/* Register icons */
		RegisterIcon(pRegDict, colorIconResName[count], TRUE /* bColor */);
		RegisterIcon(pRegDict, bwIconResName[count], FALSE /* bColor */);


		/* Register transition capabilities */
		
		if ((err = pRegDict->Put(kMoaMmDictType_TransitionCaps, 
			&transCaps[count], sizeof(MoaMmTransCaps), kMoaMmDictKey_TransitionCaps)) 
			!= kMoaErr_NoErr) break;
						
		/* Register default values for transition "area" */

		if ((err = pRegDict->Put(kMoaMmDictType_TransDefaultArea, 
			&area[count], 0, kMoaMmDictKey_TransDefaultArea)) 
			!= kMoaErr_NoErr) break;
		
	}

	X_STD_RETURN(err);
	X_EXIT
}

/* ------------------------------------ CRegister_IMoaRegister::Register */
/* Convert C to Pascal string (for Mac code) */

STDMETHODIMP_(void) CTallWideRegister_IMoaRegister::CToPas(ConstPMoaChar pCStr, PMoaChar pPasStr)
{	
	PMoaChar pOrigPasStr = pPasStr;
	while (*pCStr)
		*(++pPasStr) = *(pCStr++);
	pOrigPasStr[0] = pPasStr - pOrigPasStr;
}

/* -------------------------------- CRegister_IMoaRegister::RegisterIcon */
/* Pulls an icon out of a Mac PICT or Windows BITMAP resource
   and registers it as a custom asset type icon.  This scheme
   can be used for both sprite and transition xtras.
*/

STDMETHODIMP_(MoaError) CTallWideRegister_IMoaRegister::RegisterIcon(PIMoaDict pDict, ConstPMoaChar pResName, MoaBoolParam bColor)
{
	XtraResourceCookie 	myCookie, saveCookie;
	MoaError	err = kMoaErr_NoErr;
	
	myCookie = pObj->pCallback->MoaBeginUsingResources(gXtraFileRef, &saveCookie);

#ifdef MACINTOSH
	/**** Macintosh Implementation ****/
	Handle hPic;
	Str255 pasResName;
		
	CToPas(pResName, (PMoaChar) pasResName);
	hPic = GetNamedResource('PICT', pasResName);
	if (hPic) {
		LoadResource(hPic);
		HLock(hPic);
		
		/* Stuff the icon picture data into the registry */
		err = pDict->Put(
				bColor ? kMoaMmDictType_ColorIcon : kMoaMmDictType_BWIcon, 
				*hPic, 
				GetHandleSize(hPic), 
				bColor ? kMoaMmDictKey_ColorIcon : kMoaMmDictKey_BWIcon);

		HUnlock(hPic);
		ReleaseResource(hPic);
	} else err = kMoaErr_BadParam;
#endif /* MACINTOSH */
#ifdef WINDOWS
	/**** Windows Implementation ****/
	HGLOBAL hBitmap;
	LPVOID	pBitmap;
	DWORD	size;
	HRSRC hRsrc = FindResource((HINSTANCE) myCookie, pResName, MAKEINTRESOURCE(RT_BITMAP));
	if (hRsrc) {
		hBitmap = LoadResource((HINSTANCE) myCookie, hRsrc);
		if (hBitmap) {
			pBitmap = LockResource(hBitmap);
			size = SizeofResource((HINSTANCE) myCookie, hRsrc);
			err = pDict->Put(
					bColor ? kMoaMmDictType_ColorIcon : kMoaMmDictType_BWIcon, 
					pBitmap, 
					size, 
					bColor ? kMoaMmDictKey_ColorIcon : kMoaMmDictKey_BWIcon);
			UnlockResource(hBitmap);
			FreeResource(hBitmap);
		}
	} else err = kMoaErr_BadParam;
#endif /* WINDOWS */

	pObj->pCallback->MoaEndUsingResources(gXtraFileRef, saveCookie);

	return err;
}

