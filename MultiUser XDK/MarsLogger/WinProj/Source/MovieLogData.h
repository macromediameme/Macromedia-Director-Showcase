/*************************************************************************
* Copyright � 1994-2001 Macromedia, Inc. All Rights Reserved
*
* THE CODE IS PROVIDED TO YOU ON AN "AS IS" BASIS AND "WITH ALL FAULTS,"
* WITHOUT ANY TECHNICAL SUPPORT OR WARRANTY OF ANY KIND FROM MACROMEDIA. YOU
* ASSUME ALL RISKS THAT THE CODE IS SUITABLE OR ACCURATE FOR YOUR NEEDS AND
* YOUR USE OF THE CODE IS AT YOUR OWN DISCRETION AND RISK. MACROMEDIA
* DISCLAIMS ALL EXPRESS AND IMPLIED WARRANTIES FOR CODE INCLUDING, WITHOUT
* LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR
* PURPOSE. ALSO, THERE IS NO WARRANTY OF NON-INFRINGEMENT, TITLE OR QUIET
* ENJOYMENT.
*
* YOUR USE OF THIS CODE IS SUBJECT TO THE TERMS, CONDITIONS AND RESTRICTIONS
* SET FORTH IN THE CORRESPONDING LICENSE AGREEMENT BETWEEN YOU AND MACROMEDIA.
*	Name: MovieLogData.h
*
* 	Purpose: Class to hold info about movies for the log
*
****************************************************************************/

#pragma once
#if	!defined(__MovieLogData__)
#define __MovieLogData__

#include	"BString.h"
#include	<vector.h>


//++------------------------------------------------------------------------------
//	class MovieLogData
//++------------------------------------------------------------------------------
class MovieLogData
{
	public:

		MovieLogData();
		~MovieLogData();

		MovieLogData( const MovieLogData & inData );
		MovieLogData &		operator = ( const MovieLogData & inData );

		long			GetMaxUsers( void )	const				{ return mMaxUsers;			}
		void			SetMaxUsers( long newVal )				{ mMaxUsers = newVal;		}

		long			GetTotalUsers( void ) const				{ return mTotalUsers;		}
		void			SetTotalUsers( long newVal )			{ mTotalUsers = newVal;		}
		void			IncrementTotalUsers( void )				{ mTotalUsers++;			}

		long			GetTempData( void )	const				{ return mTempData;			}
		void			SetTempData( long newVal )				{ mTempData = newVal;		}

		void			SetTotalHangTime( double val )			{ mTotalHangTime = val;		}
		double			GetTotalHangTime( void ) const			{ return mTotalHangTime;	}
		void			IncrementTotalHangTime( double incr )	{ mTotalHangTime += incr;	}

		const BString &	GetMovieID( void )	const				{ return mMovieID;			}
		void			SetMovieID( const BString & inID )		{ mMovieID = inID;			}

	protected:

		long		mMaxUsers;			// Maximum user count
		long		mTotalUsers;		// Total users logged on
		long		mTempData;			// Temp flag for misc. scanning usage

		double		mTotalHangTime;		// Total user-minutes that have been logged on

		BString		mMovieID;			// Movie ID
};
typedef	vector< MovieLogData >	MovieLogDataList;



#endif // __MovieLogData__


