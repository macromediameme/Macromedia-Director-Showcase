/***************************************************************************
**
* Copyright � 1994-2001 Macromedia, Inc. All Rights Reserved
*
* THE CODE IS PROVIDED TO YOU ON AN "AS IS" BASIS AND "WITH ALL FAULTS,"
WITHOUT ANY TECHNICAL SUPPORT OR WARRANTY OF ANY KIND FROM MACROMEDIA. YOU
ASSUME ALL RISKS THAT THE CODE IS SUITABLE OR ACCURATE FOR YOUR NEEDS AND
YOUR USE OF THE CODE IS AT YOUR OWN DISCRETION AND RISK. MACROMEDIA
DISCLAIMS ALL EXPRESS AND IMPLIED WARRANTIES FOR CODE INCLUDING, WITHOUT
LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR
PURPOSE. ALSO, THERE IS NO WARRANTY OF NON-INFRINGEMENT, TITLE OR QUIET
ENJOYMENT.

YOUR USE OF THIS CODE IS SUBJECT TO THE TERMS, CONDITIONS AND RESTRICTIONS
SET FORTH IN THE CORRESPONDING LICENSE AGREEMENT BETWEEN YOU AND
MACROMEDIA.

****************************************************************************/

// DBCB_App.h: interface for the DBCB_App class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __DBCB_App__
#define __DBCB_App__

#include "DBCBTable.h"
#include "SvrObject.h"
#include "DBGeneric.h"

class DBCB_App : public DBCBTable  
{
	public:
		DBCB_App(SvrObject *, DBGeneric *);
		virtual ~DBCB_App();

		void Create(SvrObject *);
		void deleteApp(SvrObject *svrObj, const char *appname, MoaError *err);

		virtual	void	UpdateFileStructure( void );
		virtual void	MakeTagInfo( Tag4info & outInfo );

		IDNUM	getID(SvrObjectPtr, const char *, MoaError *);

		void createApp(SvrObjectPtr, const IDNUM, const char *, MoaError *);

	protected:

		virtual void	ZapIndexField( void );

};

#endif // __DBCB_App__
