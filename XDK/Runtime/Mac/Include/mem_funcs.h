/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	mem_funcs.h
 *	
 *		Copyright � 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __mem_funcs__
#define __mem_funcs__

#include <ansi_parms.h>                 /* mm 970905*/

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

#define __min_bytes_for_long_copy	32		/* NEVER let this be < 16 */

#ifdef __cplusplus
extern "C" {
#endif

void	__copy_mem                (void * dst, const void * src, unsigned long n);
void	__move_mem                (void * dst, const void * src, unsigned long n);
void	__copy_longs_aligned      (void * dst, const void * src, unsigned long n);
void	__copy_longs_rev_aligned  (void * dst, const void * src, unsigned long n);
void	__copy_longs_unaligned    (void * dst, const void * src, unsigned long n);
void	__copy_longs_rev_unaligned(void * dst, const void * src, unsigned long n);

void	__fill_mem(void * dst, int val, unsigned long n);

#ifdef __cplusplus
}
#endif

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
 * mm 970905  added include of ansi_parms.h to avoid need for prefix file
 */
