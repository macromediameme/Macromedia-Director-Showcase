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
 *	Name: PlaySoundXtra.cpp
 *	
 * 	Purpose: The Xtra definition of the Sound Sprite Xtra example.
 *
 *
 **********************************************************************************/ 
 
/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .cpp file should automatically include all the support files needed for this 
 *  particular class. In addition, this file may include other .h files defining 
 *  additional callback interfaces for use by a third party.   
 *****************************************************************************/ 
 #include "PlaySoundSprite.h"
 #include "PlaySoundAsset.h"
 #include "PlaySoundRegister.h"

/*****************************************************************************
 *  UTILITY MACROS
 *  --------------
 *	These macros calculate a precise version for your Xtra to be used in the
 *	Xtra definition below.  The first 4 #defines represent the release types
 *	you can choose when assembling your version.
 ****************************************************************************/ 
#define VERSION_DEVELOPMENT  0
#define VERSION_ALPHA        1
#define VERSION_BETA         2
#define VERSION_RELEASE      3

#define MAKE_VERSION(major, minor, sub, releaseType, releaseVersion) \
	                  (unsigned long)(((unsigned long)major << 24) + \
	                  ((unsigned long)minor << 16) + \
	                  ((unsigned long)sub << 8) + \
	                  ((unsigned long)releaseType << 6) + \
	                  (unsigned long)releaseVersion )

/*****************************************************************************
 *	VERSION DEFINITION
 *	------------------
 *	Fill in your version numbers below.
 ****************************************************************************/ 
#define XTRA_MAJOR_VERSION    1
#define XTRA_MINOR_VERSION    0
#define XTRA_SUB_VERSION      0
#define XTRA_RELEASE          VERSION_DEVELOPMENT
#define XTRA_RELEASE_VERSION  1

#define XTRA_VERSION_NUMBER MAKE_VERSION(XTRA_MAJOR_VERSION, \
                                         XTRA_MINOR_VERSION, \
                                         XTRA_SUB_VERSION, \
                                         XTRA_RELEASE_VERSION, \
                                         XTRA_RELEASE)

/*****************************************************************************
 *  XTRA DEFINITION
 *  ---------------
 *  The Xtra definition specfies the classes and interfaces defined by your
 *  MOA Xtra.
 *
 *  Syntax:
 *	BEGIN_XTRA_DEFINES_CLASS(<class-name>,<version>)
 *	CLASS_DEFINES_INTERFACE(<class-name>, <interface-name>,<version>) 
 ****************************************************************************/ 
BEGIN_XTRA
	BEGIN_XTRA_DEFINES_CLASS(CPlaySoundRegister, XTRA_VERSION_NUMBER) 
		CLASS_DEFINES_INTERFACE(CPlaySoundRegister, IMoaRegister, XTRA_VERSION_NUMBER)
	END_XTRA_DEFINES_CLASS
	BEGIN_XTRA_DEFINES_CLASS(CPlaySoundAsset, XTRA_VERSION_NUMBER)
		CLASS_DEFINES_INTERFACE(CPlaySoundAsset, IMoaMmXAsset, XTRA_VERSION_NUMBER)
		#ifdef USING_INIT_FROM_DICT
		CLASS_DEFINES_INTERFACE(CPlaySoundAsset, IMoaInitFromDict, XTRA_VERSION_NUMBER)
		#endif
		#ifdef USING_NOTIFICATION_CLIENT
		CLASS_DEFINES_INTERFACE(CPlaySoundSprite, IMoaNotificationClient, XTRA_VERSION_NUMBER)	
		#endif
	END_XTRA_DEFINES_CLASS
	BEGIN_XTRA_DEFINES_CLASS(CPlaySoundSprite, XTRA_VERSION_NUMBER)
		CLASS_DEFINES_INTERFACE(CPlaySoundSprite, IMoaMmXSpriteActor, XTRA_VERSION_NUMBER)
	END_XTRA_DEFINES_CLASS
END_XTRA
