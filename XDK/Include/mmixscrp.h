#ifndef _H_mmixscrp

#define _H_mmixscrp



/* =========================================================================



	Copyright (c) 1996-1998, Macromedia, Inc.  All rights reserved.
	
	You may utilize this source file to create and compile object code for 
	use within products you may create.  THIS CODE IS PROVIDED "AS IS", 
	WITHOUT WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED 
	WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A
	PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE 
	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES 
	ARISING OUT OF YOUR USE OR INABILITY TO USE THIS CODE.

	

	Purpose:

	

	Director/Authroware Scripting Xtra Interfaces



	This file defines the new and improved Scripting Xtra interface. It is

	incompatible with drixlngo.h.

	

	History:



	10dec96	dws	Created. Based on drixlngo.h.



============================================================================ */

#include "moaxtra.h"

#ifndef _H_mmtypes

#include "mmtypes.h"

#endif



/* Bail if drixlngo.h has been included. Shouldn't use both together. */



#ifdef _H_DrIXLngo

#error Don't include both mmixscrp.h and drixlngo.h.

#endif



#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )

	#pragma push

	#pragma pointers_in_D0

#endif





/* -------------------------------------------------------------------------

	

	Interface for IMoaMmXScript



   ------------------------------------------------------------------------- */



/* This must be the same GUID as IID_IMoaDrXLingo. */

/* IID_IMoaMmXScript: AC401FB60001F9B000000800072C6326 */

DEFINE_GUID(IID_IMoaMmXScript, 0xAC401FB6L, 0x0001, 0xF9B0, 0x00, 0x00, 0x08,

				0x00, 0x07, 0x2C, 0x63, 0x26);

				

#undef INTERFACE

#define INTERFACE IMoaMmXScript



DECLARE_INTERFACE_(IMoaMmXScript, IMoaUnknown)

/*

Description



The <tt>IMoaMmXScript</tt> interface is implemented by Scripting Xtras.

It is used by the host application to dispatch methods of the Xtra.

*/

{

	STD_IUNKNOWN_METHODS

	

	STDMETHOD(Call)  (THIS_

		PMoaMmCallInfo callPtr) /* Pointer to a <tt>MoaMmCallInfo</tt>
structure */

		PURE;


/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=247><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Method call successful
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=247><TT>kMoaMmErr_ArgOutOfRange</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Method selector out of
range
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=247><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Method call failed due
to memory error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=247><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Method call failed due
to internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=247><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Value supplied for
<TT>&quot;any&quot;</TT>-type argument not supported
</TD></TR>
</TABLE>
*/


/*Description

Performs the call specified by the Lingo Xtra.  Use the <tt>methodSelector
</tt>member of the <tt><i>callPtr </i></tt>structure to determine the Lingo
command being called.  <p>
<p>
The <tt>MoaMmCallInfo</tt> structure <tt><i>callPtr</i></tt> contains
information about the method being called and the arguments supplied with the
call.  Lingo Xtras implement this method with a case statement based on the
<tt>methodSelector</tt> field of the call info structure, each case being the
C-enumeration name of one of the handlers implemented.  The code within the
case represents the Xtras response to that particular handler.  <p>

On entry

the fields of the callPtr argument are:

<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=247><TT>xinst</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343> Reserved (instance of Xtra,
host-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=247><TT>methodFlags</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Reserved
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=247><TT>methodSelector</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Method index. Zero is first
method in message table.
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=247><TT>resultValue</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Method result
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=247><TT>nargs</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343> Number of arguments passed to
method including the first argument which is reserved (nargs always >= 1)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=247><TT>pArgs</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343> Pointer to array of
arguments. The first argument is reserved. The caller owns the argument
values. The Xtra must not modify or release them.
</TABLE>

On exit the resultValue field is set to the result, if any.
*/

};



typedef IMoaMmXScript FAR * PIMoaMmXScript;





/* Old names for compatability with Dir 5.0 xtras. */



#define IMoaDrXLingo		IMoaMmXScript

#define IID_IMoaDrXLingo	IID_IMoaMmXScript

#define PIMoaDrXLingo		PIMoaMmXScript





#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )

	#pragma pop

#endif



/*---------------------------------------------------------------------------

Convienence macros.



These all assume callPtr is the PMoaMmCallInfo passed to the main entry point

	Call()



 	Access user parameters to the instance, n is the arg count which is

	1-based.

	

	By using this macro, you are getting direct access to the argument

	value, so you should not release this value.  It's owned by the calling

	application.

/--------------------------------------------------------------------------*/





#define AccessArgByIndex(n, pValue) pciGetArgByIndex( callPtr, n, pValue )







/* Don't use this one; exists for backward compatibility with older samples

*/

#define GetArgByIndex(n, pValue)	AccessArgByIndex(n, pValue)



#endif	/* _H_mmixscrp */









