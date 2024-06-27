/*==========================================================================\
|                                                                           |
|                     Copyright 1999-1999, Macromedia, Inc.                 |
|                                                                           |
|      This material is the confidential trade secret and proprietary       |
|      information of Macromedia, Inc.  It may not be reproduced, used,     |
|      sold or transferred to any third party without the prior written     |
|      consent of Macromedia, Inc.  All rights reserved.                    |
|                                                                           |
\==========================================================================*/

#ifndef	NO_PRAGMA_ONCE
#pragma	once
#endif

/****************************************************************************
/ Filename
/   $Workfile: xclassver.h $
/
/ Version:
/   $Revision: 4 $
/
/ Purpose
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/xclassver.h $
/   
/   4     11/30/99 4:46p Grandma
/   Merging from Stone Source Safe.
/   
/   3     11/09/99 1:06p Swbuildw
/   remove hardcoded version numbers
/   
/   2     6/11/99 5:57 PM Jcorbett
/   changed to Codewarrior DOS format
/   
/   1     4/28/99 23:48 Dan
/   internal xtra version updated
/   
****************************************************************************/


#ifndef	XCLASSVER_H
#define	XCLASSVER_H

#include "dversion.h"

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

#define MAKE_VERSION(major, minor, sub, releaseVersion, releaseType) \
	                  (unsigned long)(((unsigned long)(major & 0x0ff) << 24) + \
	                  ((unsigned long)(minor & 0x0ff) << 16) + \
	                  ((unsigned long)(sub & 0x0ff) << 8) + \
	                  ((unsigned long)(releaseType & 0x003) << 6) + \
	                  (unsigned long)(releaseVersion & 0x03f) )

/*****************************************************************************
 *	VERSION DEFINITION
 *	------------------
 *	Fill in your version numbers below.
 ****************************************************************************/ 
#define XTRA_CLASS_MAJOR_VERSION    VER_MAJORVERSION
#define XTRA_CLASS_MINOR_VERSION    VER_MINORVERSION
#define XTRA_CLASS_SUB_VERSION      VER_BUGFIXVERSION
#define XTRA_CLASS_RELEASE_TYPE     VERSION_RELEASE
#ifndef XTRA_CLASS_RELEASE_VERSION
#define XTRA_CLASS_RELEASE_VERSION  0
#endif


#define XTRA_CLASS_VERSION MAKE_VERSION(XTRA_CLASS_MAJOR_VERSION, \
                                         XTRA_CLASS_MINOR_VERSION, \
                                         XTRA_CLASS_SUB_VERSION, \
                                         XTRA_CLASS_RELEASE_VERSION, \
                                         XTRA_CLASS_RELEASE_TYPE)
                                    

#endif	/* XCLASSVER_H */
