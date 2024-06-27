/*==========================================================================\
|                                                                           |
|                   Copyright (c) 1994-1998, Macromedia, Inc.               |
|                                                                           |
|	You may utilize this source file to create and compile object code for 	|
|	use within products you may create.  THIS CODE IS PROVIDED "AS IS", 	|
|	WITHOUT WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED 		|
|	WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A|
|	PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE |
|	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES 	|
|	ARISING OUT OF YOUR USE OR INABILITY TO USE THIS CODE.					|
|                                                                           |
\==========================================================================*/

#ifndef	NO_PRAGMA_ONCE
#pragma	once
#endif

/****************************************************************************
/ Filename
/   $Workfile: drtypes.h $
/
/ Version:
/   $Revision: 4 $
/
/ Purpose
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/drtypes.h $
/   
/   4     11/23/99 3:21p Jcorbett
/   Added MediaFlag class, added flag to not preserve white space.
/   
/   3     11/17/99 2:35p Wsharp
/   add image expected error message.
/   
/   2     6/23/99 11:54 AM Greggy
/   Checkin to synchronize revision numbers.
/   
/   13    11/4/98 4:17 PM Jcorbett
/   Added new MoaDrCursorID data type and cursor type #defines
/   
/   12    10/19/98 11:26 AM Mroeder
/   Changed header from "Confidential" to "You may use..." because these
/   files are in the XDK. Updated copyright notice to cover 1998. 
/   
/   11    2/03/98 10:59a Greggy
/   DP header files now conform with the IML standard. Fixed up guard tag
/   and sequence of #include w.r.t. extern "C".
/   
	25feb97 ejs moved tool definitions to mmtypes.h
	19feb97	esg	added Typesetting types
  	05feb97 esg	removed java load options :(  (moved to dxtsecrt.h)
	02feb97	esg	added java load options	
	10dec96 dws removed lingo xtra definitions including MoaDrCallInfo,
	            kMoaDrDictKey_MessageTable, etc. Now in mmtypes.h.
	21nov96	esg	added MoaDrSoundChannelPlayStatus;
	20nov96	esg	added SoundSpriteRef type
	19nov96	esg added CastLibRef and SpriteRef types
	16nov96	esg	changed id type to 16 byte sig.
	11nov96	esg	added new notification types, castmemid type
	28feb96 dac IMoaDrPropAndMediaOwner-->IMoaDrMediaOwner
	 4feb96 dac b3 changes; remove pragma options align for THINK_C 68k
	08jan95	JT	Removed MoaDrLingoXtraInst, modified MoaDrCallInfo
	10oct95 dws	Split out from generic types file.
****************************************************************************/


#ifndef	DRTYPES_H
#define	DRTYPES_H


#include "mmtypes.h"


#ifdef	__cplusplus
extern "C" {
#endif


/* ----------------------------------------------------------------------------
/
/	Set Alignment/Packing
/
/ -------------------------------------------------------------------------- */

#ifdef MACINTOSH
	#ifdef powerc
		#pragma options align=power
	#else
		#ifndef THINK_C
			#pragma options align=mac68k
		#endif /* THINK_C */
	#endif /* powerc */
#endif
#ifdef WINDOWS
	#pragma pack(2)
#endif /* WINDOWS */


/* ----------------------------------------------------------------------------
/
/	Director Cast Member Reference
/
/ -------------------------------------------------------------------------- */

typedef MoaLong	MoaDrMemberIndex, 	FAR * PMoaDrMemberIndex;
typedef const MoaDrMemberIndex FAR * ConstPMoaDrMemberIndex;

typedef MoaLong	MoaDrCastIndex, 	FAR * PMoaDrCastIndex;
typedef const MoaDrCastIndex FAR * ConstPMoaDrCastIndex;


typedef struct
{
	MoaDrCastIndex		movieCastIndex;	
	MoaDrMemberIndex	memberIndex;	
} MoaDrCMRef, FAR * PMoaDrCMRef;
typedef const MoaDrCMRef FAR * ConstPMoaDrCMRef;


/* MoaDrCMRef accessors: use these rather than directly touching fields
*/

#define	CMRef_GetMemberIndex(pCMRef) ((pCMRef)->memberIndex)

#define CMRef_GetMovieCastIndex(pCMRef) ((pCMRef)->movieCastIndex)

#define CMRef_Make(pCMRef, castInd, memberInd) 		\
			{ (pCMRef)->movieCastIndex = castInd; 	\
			  (pCMRef)->memberIndex = memberInd; 	\
			}
			
#define	CMRef_MakeNull(pCMRef) 						\
			{ (pCMRef)->movieCastIndex = 0; 		\
				(pCMRef)->memberIndex = 0; 			\
			}

/* ----------------------------------------------------------------------------
/
/	Director Unique Cast Member IDs
/
/ -------------------------------------------------------------------------- */

typedef struct {
	unsigned char id[16];
} MoaDrCMId, FAR * PMoaDrCMId;
typedef const MoaDrCMId FAR * ConstPMoaDrCMId;

/* ----------------------------------------------------------------------------
/
/	Director Sound Reference
/
/ -------------------------------------------------------------------------- */

typedef MoaShort MoaDrSoundChannelIndex, FAR * PMoaDrSoundChannelIndex;
typedef const MoaDrSoundChannelIndex FAR * ConstPMoaDrSoundChannelIndex;

typedef struct {
	MoaDrSoundChannelIndex soundChannelIndex;
} MoaDrSoundSpriteRef, FAR * PMoaDrSoundSpriteRef;
typedef const MoaDrSoundSpriteRef FAR * ConstPMoaDrSoundSpriteRef;

#define SoundSpriteRef_GetSoundChannelIndex(pSoundSpriteRef) ((pSoundSpriteRef)->soundChannelIndex)

#define SoundSpriteRef_Make(pSoundSpriteRef, soundChanInd) (pSoundSpriteRef)->soundChannelIndex = (soundChanInd)

/* ----------------------------------------------------------------------------
/
/	Director Sprite Reference
/
/ -------------------------------------------------------------------------- */

typedef MoaShort MoaDrSpriteIndex, FAR * PMoaDrSpriteIndex;
typedef const MoaDrSpriteIndex FAR * ConstPMoaDrSpriteIndex;

typedef struct {
	MoaDrSpriteIndex spriteIndex;
} MoaDrSpriteRef, FAR * PMoaDrSpriteRef;
typedef const MoaDrSpriteRef FAR * ConstPMoaDrSpriteRef;

#define SpriteRef_GetSpriteIndex(pSpriteRef) ((pSpriteRef)->spriteIndex)

#define SpriteRef_Make(pSpriteRef, spriteInd) (pSpriteRef)->spriteIndex = (spriteInd)

/* ----------------------------------------------------------------------------
/
/	Director Cast Lib Reference
/
/ -------------------------------------------------------------------------- */

typedef MoaShort MoaDrCastLibIndex, FAR * PMoaDrCastLibIndex;
typedef const MoaDrCastLibIndex FAR * ConstPMoaDrCastLibIndex;

typedef struct {
	MoaDrCastLibIndex castLibIndex;
} MoaDrCastLibRef, FAR * PMoaDrCastLibRef;
typedef const MoaDrCastLibRef FAR * ConstPMoaDrCastLibRef;

#define CastLibRef_GetCastLibIndex(pCastLibRef) ((pCastLibRef)->castLibIndex)

#define CastLibRef_Make(pCastLibRef, castLibInd) (pCastLibRef)->castLibIndex = (castLibInd)

/* ----------------------------------------------------------------------------
/
/	Score-related data types
/
/ -------------------------------------------------------------------------- */

typedef MoaLong		MoaDrSpriteChanIndex, 	FAR * PMoaDrSpriteChanIndex;
typedef MoaLong		MoaDrSoundChanIndex, 	FAR * PMoaDrSoundChanIndex;
typedef MoaLong		MoaDrFrameIndex,		FAR * PMoaDrFrameIndex;


/* ----------------------------------------------------------------------------
/
/	Cast Member Media Access
/
/ -------------------------------------------------------------------------- */

/* Media Access options - these depend on the media label being set/get.
						- ignored by labels that don't allow set/get options
*/

typedef	MoaLong			MoaDrMediaOpts;

#define kMoaDrMediaOpts_None						0

/* Image media "set" options
	- These are only valid when setting "image" label media
*/
/* the lower 16 bytes are for the Image options, the upper 16
are bit flags */
#define kMoaDrImgMediaOpts_AuthorDefined			0
#define kMoaDrImgMediaOpts_ImageDepthAndPal			1
#define kMoaDrImgMediaOpts_CastMemDepthAndPal		2
#define kMoaDrImgMediaOpts_ScreenDepthAndPal		3
#define kMoaDrImgMediaOpts_Dialog					4 /* author app only */
#define kMoaDrImgMediaOpts_AuxInfo					5

#define kMoaDrImgMediaFlags_DontTrimWhiteEdges		0x10000

/* When specifying kMoaDrImgMediaOpts_AuxInfo option for setting image
	media, the "aux" field of your MoaDrMediaInfo structure must
	be a FAR * (pointer) to a caller-owned MoaDrImageAuxInfo
	struct.  This permits explicit definition of the pixel depth,
	associated palette cast member, and resampling option (dither
	or remap) to be used.
*/

typedef struct
{
	MoaLong			pixelDepth;		/* Pixel depth: 1, 2, 4, 8, 16, 32 */
	MoaMmSymbol		paletteSymbol;	/* sym of built-in pal to use, 0 to use paletteCMRef */
	MoaDrCMRef		paletteCMRef;	/* MoaDrCMRef of cast-based palette to use */
	MoaBoolParam 	dither;			/* TRUE: dither, FALSE: remap */
} MoaDrImageAuxInfo, FAR * PMoaDrImageAuxInfo;
typedef const MoaDrImageAuxInfo FAR * ConstPMoaDrImageAuxInfo;


/* Information used by cast member and movie GetMedia() and SetMedia()
   methods.
*/

typedef struct
{
	MoaMmSymbol				labelSymbol;	/* Label of media to set/get */
	MoaMmSymbol				formatSymbol;	/* Format of media to set/get */
	PMoaVoid				mediaData;		/* Media data */
	MoaDrMediaOpts			options;		/* Get/Set options (depend on label) */
	PMoaVoid				aux;			/* Aux data */
	PMoaVoid				refCon;			/* Reserved */
} MoaDrMediaInfo, FAR * PMoaDrMediaInfo;
typedef const MoaDrMediaInfo FAR * ConstPMoaDrMediaInfo;


/* Information used by MediaAccessors.
	MediaAccessors, such as the ScoreAccessor, handle communication
	with the media owner object to provide a task-specific interface for
	accessing its media.
*/

typedef struct
{
	struct IMoaDrMediaOwner FAR * 		pOwner;			/* obj owning media */
	MoaMmSymbol							labelSymbol;	/* label of media */
	MoaMmSymbol							formatSymbol;	/* format of media */
} MoaDrAccessInfo, FAR * PMoaDrAccessInfo;
typedef const MoaDrAccessInfo FAR * ConstPMoaDrAccessInfo;

/* ----------------------------------------------------------------------------
/
/	Notification Client
/
/ -------------------------------------------------------------------------- */

/* Notification types.
	These are used in conjunction with IMoaDrUtils::RegisterNotificationClient()
	to obtain callbacks when certain events occur in the host application.
*/

typedef MoaLong	MoaDrNotifyType;

#define	kMoaDrNotifyType_DocFileIO					1



/* Notification message codes.
	These message codes are passed to your IMoaDrNotificationClient::Notify()
	method when events occur that you've registered to be notified about.
	
	The host app reserves message code space >= 65536
	
*/

/* --- Document File I/O (kMoaDrNotifType_DocFileIO) message codes --- */

#define	kMoaDrMsgCode_DocFileIO					65536	/* ## WINDOWS VERSION ONLY ##
														ConstPMoaChar for file pathname
														passed in refCon argument to
														Notify() */



/* ----------------------------------------------------------------------------
/
/	Director sound channel status info.
/
/ -------------------------------------------------------------------------- */

enum {
	kMoaDrSoundChannelStatus_Playing,
	kMoaDrSoundChannelStatus_Stopped
};

typedef MoaUlong MoaDrSoundChannelPlayStatus;


/* ----------------------------------------------------------------------------
/
/	Director cursor IDs.
/
/ -------------------------------------------------------------------------- */

/* Director built-in Cursors*/
#define kMoaDrCursor_Arrow  		-1
#define kMoaDrCursor_Default  		0
#define kMoaDrCursor_IBeam  		1
#define kMoaDrCursor_Crosshair  	2
#define kMoaDrCursor_Crossbar  		3
#define kMoaDrCursor_Watch  		4
#define kMoaDrCursor_Finger  		280


typedef MoaLong MoaDrCursorID;


/* ----------------------------------------------------------------------------
/
/	Director TypeSetting Data.
/
/ -------------------------------------------------------------------------- */

enum {
	kMoaDrStyle_normal		=0x0000,
	kMoaDrStyle_bold		=0x0001,
	kMoaDrStyle_italic		=0x0002,
	kMoaDrStyle_underline	=0x0004,
	kMoaDrStyle_outline		=0x0008,
	kMoaDrStyle_shadow		=0x0010,
	kMoaDrStyle_condense	=0x0020,
	kMoaDrStyle_extend		=0x0040
};

typedef short MoaDrCharStyle, FAR * PMoaDrCharStyle;

enum {
 kMoaDrCharApplyStyle_None				=32767,
 kMoaDrCharApplyStyle_Font				=0x0001,
 kMoaDrCharApplyStyle_Face				=0x0002,
 kMoaDrCharApplyStyle_Size				=0x0004,
 kMoaDrCharApplyStyle_Color				=0x0008,
 kMoaDrCharApplyStyle_Linespace			=0x0040,
 kMoaDrCharApplyStyle_Letterspace		=0x0080,
 kMoaDrCharApplyStyle_All				=(kMoaDrCharApplyStyle_Font + kMoaDrCharApplyStyle_Face + kMoaDrCharApplyStyle_Size + kMoaDrCharApplyStyle_Color + kMoaDrCharApplyStyle_Linespace + kMoaDrCharApplyStyle_Letterspace)
};

typedef short MoaDrCharApplyStyle, FAR * PMoaDrCharApplyStyle;

typedef struct {
	MoaMmRGBTriple		fCharForeColor;
	MoaDouble        	fCharLetterspace;
	MoaDouble			fCharLinespace;
	MoaShort			fCharSize;
	MoaShort			fCharFont;
	MoaDrCharStyle		fCharFace;
} MoaDrCharStyleData, FAR * PMoaDrCharStyleData;


/* ----------------------------------------------------------------------------
/
/	Director-specific error codes (extensions to shared Mm errors)
/
/ -------------------------------------------------------------------------- */

#define		kMoaDrErr_Base						3000


/* Property access errors */

#define		kMoaDrErr_CastMemberExpected		MAKE_MOAERR(kMoaDrErr_Base)
#define		kMoaDrErr_MediaExpected				MAKE_MOAERR(kMoaDrErr_Base + 1)
#define		kMoaDrErr_PictureExpected			MAKE_MOAERR(kMoaDrErr_Base + 2)

/* Media access errors */

#define		kMoaDrErr_MediaLabelNotSupported	MAKE_MOAERR(kMoaDrErr_Base + 3)
#define		kMoaDrErr_MediaFormatNotSupported	MAKE_MOAERR(kMoaDrErr_Base + 4)
#define		kMoaDrErr_MediaInUse				MAKE_MOAERR(kMoaDrErr_Base + 5)
#define		kMoaDrErr_MediaDataInvalid			MAKE_MOAERR(kMoaDrErr_Base + 6)
#define		kMoaDrErr_MediaDataNonexistant		MAKE_MOAERR(kMoaDrErr_Base + 7)
#define		kMoaDrErr_LabelNotFound				MAKE_MOAERR(kMoaDrErr_Base + 8)

/* Score access errors */

#define		kMoaDrErr_NotInUpdateMode			MAKE_MOAERR(kMoaDrErr_Base + 9)
#define		kMoaDrErr_OwnerNotSet				MAKE_MOAERR(kMoaDrErr_Base + 10)

/* For backward compatibility with Director 5.0, error code kMoaDrErr_Base +11 is in mmtypes,
   as kMoaMmErr_ToolDisabled.   */


/* Misc */

#define		kMoaDrErr_CastNotFound				MAKE_MOAERR(kMoaDrErr_Base + 12)
#define		kMoaDrErr_CastMemNotFound			MAKE_MOAERR(kMoaDrErr_Base + 13)
#define		kMoaDrErr_DiskIO					MAKE_MOAERR(kMoaMmErr_Base + 14)
#define		kMoaDrErr_FrameNotFound				MAKE_MOAERR(kMoaDrErr_Base + 15)
#define		kMoaDrErr_NotifyTypeUnknown			MAKE_MOAERR(kMoaDrErr_Base + 16)
#define		kMoaDrErr_HandlerNotDefined			MAKE_MOAERR(kMoaDrErr_Base + 17)
#define		kMoaDrErr_MovieNotOpen				MAKE_MOAERR(kMoaDrErr_Base + 18)


/* Director 6.0 error codes */

/* Property access errors */

#define		kMoaDrErr_SpriteExpected			MAKE_MOAERR(kMoaDrErr_Base + 19)
#define		kMoaDrErr_CastLibExpected			MAKE_MOAERR(kMoaDrErr_Base + 20)
#define		kMoaDrErr_SoundSpriteExpected		MAKE_MOAERR(kMoaDrErr_Base + 21)

/* Misc */

#define 	kMoaDrErr_SoundChannelOutOfRange	MAKE_MOAERR(kMoaDrErr_Base + 22)
#define 	kMoaDrErr_AuthorTimeOnly			MAKE_MOAERR(kMoaDrErr_Base + 28)

#define		kMoaDrErr_ImageExpected				MAKE_MOAERR(kMoaDrErr_Base + 29)
/* ----------------------------------------------------------------------------
/
/	Other constants
/
/ -------------------------------------------------------------------------- */

/* Maximum length of a cast name in bytes */

#define kMoaDrMaxCastName				255



/* ----------------------------------------------------------------------------
/
/	Reset Alignment/Packing
/
/ -------------------------------------------------------------------------- */

#ifdef MACINTOSH
	#ifdef powerc
		#pragma options align=reset
	#else
		#ifndef THINK_C
			#pragma options align=reset
		#endif /* THINK_C */
	#endif /* powerc */
#endif /* MACINTOSH */
#ifdef WINDOWS
	#pragma pack()
#endif /* WINDOWS */


#ifdef	__cplusplus
}
#endif


#endif	/* DRTYPES_H */
