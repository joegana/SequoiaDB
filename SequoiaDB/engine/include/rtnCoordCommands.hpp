/*******************************************************************************

   Copyright (C) 2011-2014 SequoiaDB Ltd.

   This program is free software: you can redistribute it and/or modify
   it under the term of the GNU Affero General Public License, version 3,
   as published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warrenty of
   MARCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program. If not, see <http://www.gnu.org/license/>.

   Source File Name = rtnCoordCommands.hpp

   Descriptive Name = Runtime Coord Common

   When/how to use: this program may be used on binary and text-formatted
   versions of runtime component. This file contains code logic for
   common functions for coordinator node.

   Dependencies: N/A

   Restrictions: N/A

   Change Activity:
   defect Date        Who Description
   ====== =========== === ==============================================

   Last Changed =

*******************************************************************************/

#ifndef RTNCOORDCOMMANDS_HPP__
#define RTNCOORDCOMMANDS_HPP__

#include "rtnCoordOperator.hpp"
#include "rtnCoordQuery.hpp"
#include "msgDef.hpp"
#include "rtnQueryOptions.hpp"
namespace engine
{
   #define COORD_CMD_DEFAULT                  "COORD_CMD_DEFAULT"
   #define COORD_CMD_BACKUP_OFFLINE           CMD_ADMIN_PREFIX CMD_NAME_BACKUP_OFFLINE
   #define COORD_CMD_LIST_BACKUPS             CMD_ADMIN_PREFIX CMD_NAME_LIST_BACKUPS
   #define COORD_CMD_REMOVE_BACKUP            CMD_ADMIN_PREFIX CMD_NAME_REMOVE_BACKUP
   #define COORD_CMD_LISTGROUPS               CMD_ADMIN_PREFIX CMD_NAME_LIST_GROUPS
   #define COORD_CMD_LISTCOLLECTIONSPACES     CMD_ADMIN_PREFIX CMD_NAME_LIST_COLLECTIONSPACES
   #define COORD_CMD_LISTCOLLECTIONS          CMD_ADMIN_PREFIX CMD_NAME_LIST_COLLECTIONS
   #define COORD_CMD_LISTUSERS                CMD_ADMIN_PREFIX CMD_NAME_LIST_USERS
   #define COORD_CMD_CREATECOLLECTIONSPACE    CMD_ADMIN_PREFIX CMD_NAME_CREATE_COLLECTIONSPACE
   #define COORD_CMD_CREATECOLLECTION         CMD_ADMIN_PREFIX CMD_NAME_CREATE_COLLECTION
   #define COORD_CMD_ALTERCOLLECTION          CMD_ADMIN_PREFIX CMD_NAME_ALTER_COLLECTION
   #define COORD_CMD_DROPCOLLECTION           CMD_ADMIN_PREFIX CMD_NAME_DROP_COLLECTION
   #define COORD_CMD_DROPCOLLECTIONSPACE      CMD_ADMIN_PREFIX CMD_NAME_DROP_COLLECTIONSPACE
   #define COORD_CMD_SNAPSHOTCONTEXTS         CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_CONTEXTS
   #define COORD_CMD_SNAPSHOTCONTEXTSCUR      CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_CONTEXTS_CURRENT
   #define COORD_CMD_SNAPSHOTSESSIONS         CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_SESSIONS
   #define COORD_CMD_SNAPSHOTSESSIONSCUR      CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_SESSIONS_CURRENT
   #define COORD_CMD_SNAPSHOTDATABASE         CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_DATABASE
   #define COORD_CMD_SNAPSHOTSYSTEM           CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_SYSTEM
   #define COORD_CMD_SNAPSHOTRESET            CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_RESET
   #define COORD_CMD_SNAPSHOTCOLLECTIONS      CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_COLLECTIONS
   #define COORD_CMD_SNAPSHOTCOLLECTIONSPACES CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_COLLECTIONSPACES
   #define COORD_CMD_SNAPSHOTCATALOG          CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_CATA
   #define COORD_CMD_SNAPSHOTTRANSCUR         CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_TRANSACTIONS_CUR
   #define COORD_CMD_SNAPSHOTTRANS            CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_TRANSACTIONS
   #define COORD_CMD_TESTCOLLECTIONSPACE      CMD_ADMIN_PREFIX CMD_NAME_TEST_COLLECTIONSPACE
   #define COORD_CMD_TESTCOLLECTION           CMD_ADMIN_PREFIX CMD_NAME_TEST_COLLECTION
   #define COORD_CMD_CREATEGROUP              CMD_ADMIN_PREFIX CMD_NAME_CREATE_GROUP
   #define COORD_CMD_REMOVEGROUP              CMD_ADMIN_PREFIX CMD_NAME_REMOVE_GROUP
   #define COORD_CMD_CREATENODE               CMD_ADMIN_PREFIX CMD_NAME_CREATE_NODE
   #define COORD_CMD_REMOVENODE               CMD_ADMIN_PREFIX CMD_NAME_REMOVE_NODE
   #define COORD_CMD_UPDATENODE               CMD_ADMIN_PREFIX CMD_NAME_UPDATE_NODE
   #define COORD_CMD_ACTIVEGROUP              CMD_ADMIN_PREFIX CMD_NAME_ACTIVE_GROUP
   #define COORD_CMD_CREATEINDEX              CMD_ADMIN_PREFIX CMD_NAME_CREATE_INDEX
   #define COORD_CMD_DROPINDEX                CMD_ADMIN_PREFIX CMD_NAME_DROP_INDEX
   #define COORD_CMD_STARTUPNODE              CMD_ADMIN_PREFIX CMD_NAME_STARTUP_NODE
   #define COORD_CMD_SHUTDOWNNODE             CMD_ADMIN_PREFIX CMD_NAME_SHUTDOWN_NODE
   #define COORD_CMD_SHUTDOWNGROUP            CMD_ADMIN_PREFIX CMD_NAME_SHUTDOWN_GROUP
   #define COORD_CMD_SPLIT                    CMD_ADMIN_PREFIX CMD_NAME_SPLIT
   #define COORD_CMD_WAITTASK                 CMD_ADMIN_PREFIX CMD_NAME_WAITTASK
   #define COORD_CMD_GETCOUNT                 CMD_ADMIN_PREFIX CMD_NAME_GET_COUNT
   #define COORD_CMD_GETINDEXES               CMD_ADMIN_PREFIX CMD_NAME_GET_INDEXES
   #define COORD_CMD_GETDATABLOCKS            CMD_ADMIN_PREFIX CMD_NAME_GET_DATABLOCKS
   #define COORD_CMD_GETQUERYMETA             CMD_ADMIN_PREFIX CMD_NAME_GET_QUERYMETA
   #define COORD_CMD_CREATECATAGROUP          CMD_ADMIN_PREFIX CMD_NAME_CREATE_CATA_GROUP
   #define COORD_CMD_TRACESTART               CMD_ADMIN_PREFIX CMD_NAME_TRACE_START
   #define COORD_CMD_TRACERESUME              CMD_ADMIN_PREFIX CMD_NAME_TRACE_RESUME
   #define COORD_CMD_TRACESTOP                CMD_ADMIN_PREFIX CMD_NAME_TRACE_STOP
   #define COORD_CMD_TRACESTATUS              CMD_ADMIN_PREFIX CMD_NAME_TRACE_STATUS
   #define COORD_CMD_EXPCONFIG                CMD_ADMIN_PREFIX CMD_NAME_EXPORT_CONFIG
   #define COORD_CMD_SNAPSHOTDBINTR           CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_DATABASE_INTR
   #define COORD_CMD_SNAPSHOTSYSINTR          CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_SYSTEM_INTR
   #define COORD_CMD_SNAPSHOTCLINTR           CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_COLLECTION_INTR
   #define COORD_CMD_SNAPSHOTCSINTR           CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_SPACE_INTR
   #define COORD_CMD_SNAPSHOTCTXINTR          CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_CONTEX_INTR
   #define COORD_CMD_SNAPSHOTCTXCURINTR       CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_CONTEXCUR_INTR
   #define COORD_CMD_SNAPSHOTSESSINTR         CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_SESSION_INTR
   #define COORD_CMD_SNAPSHOTSESSCURINTR      CMD_ADMIN_PREFIX CMD_NAME_SNAPSHOT_SESSIONCUR_INTR
   #define COORD_CMD_CRT_PROCEDURE            CMD_ADMIN_PREFIX CMD_NAME_CRT_PROCEDURE
   #define COORD_CMD_EVAL                     CMD_ADMIN_PREFIX CMD_NAME_EVAL
   #define COORD_CMD_RM_PROCEDURE             CMD_ADMIN_PREFIX CMD_NAME_RM_PROCEDURE
   #define COORD_CMD_LIST_PROCEDURES          CMD_ADMIN_PREFIX CMD_NAME_LIST_PROCEDURES
   #define COORD_CMD_LINK                     CMD_ADMIN_PREFIX CMD_NAME_LINK_CL
   #define COORD_CMD_UNLINK                   CMD_ADMIN_PREFIX CMD_NAME_UNLINK_CL
   #define COORD_CMD_LIST_TASKS               CMD_ADMIN_PREFIX CMD_NAME_LIST_TASKS
   #define COORD_CMD_CANCEL_TASK              CMD_ADMIN_PREFIX CMD_NAME_CANCEL_TASK
   #define COORD_CMD_SET_SESS_ATTR            CMD_ADMIN_PREFIX CMD_NAME_SETSESS_ATTR
   #define COORD_CMD_CREATE_DOMAIN            CMD_ADMIN_PREFIX CMD_NAME_CREATE_DOMAIN
   #define COORD_CMD_DROP_DOMAIN              CMD_ADMIN_PREFIX CMD_NAME_DROP_DOMAIN
   #define COORD_CMD_ALTER_DOMAIN             CMD_ADMIN_PREFIX CMD_NAME_ALTER_DOMAIN
   #define COORD_CMD_ADD_DOMAIN_GROUP         CMD_ADMIN_PREFIX CMD_NAME_ADD_DOMAIN_GROUP
   #define COORD_CMD_REMOVE_DOMAIN_GROUP      CMD_ADMIN_PREFIX CMD_NAME_REMOVE_DOMAIN_GROUP
   #define COORD_CMD_LIST_DOMAINS             CMD_ADMIN_PREFIX CMD_NAME_LIST_DOMAINS
   #define COORD_CMD_LIST_CS_IN_DOMAIN        CMD_ADMIN_PREFIX CMD_NAME_LIST_CS_IN_DOMAIN
   #define COORD_CMD_LIST_CL_IN_DOMAIN        CMD_ADMIN_PREFIX CMD_NAME_LIST_CL_IN_DOMAIN
   #define COORD_CMD_INVALIDATE_CACHE         CMD_ADMIN_PREFIX CMD_NAME_INVALIDATE_CACHE
   #define COORD_CMD_LIST_LOBS                CMD_ADMIN_PREFIX CMD_NAME_LIST_LOBS
   #define COORD_CMD_ALTER_IMAGE              CMD_ADMIN_PREFIX CMD_NAME_ALTER_IMAGE
   #define COORD_CMD_REELECT                  CMD_ADMIN_PREFIX CMD_NAME_REELECT
   #define COORD_CMD_TRUNCATE                 CMD_ADMIN_PREFIX CMD_NAME_TRUNCATE

   class rtnCoordCommand : virtual public rtnCoordOperator
   {
   public:
      rtnCoordCommand(){};
      virtual ~rtnCoordCommand(){};

   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) = 0 ;
        
      virtual INT32 queryOnCatalog( CHAR *pReceiveBuffer,
                                    SINT32 packSize,
                                    INT32 requestType,
                                    pmdEDUCB *cb,
                                    MsgOpReply &replyHeader,
                                    rtnContextBuf *buf ) ;

      virtual INT32 executeOnDataGroup ( MsgHeader *pMsg,
                                         CoordGroupList &groupLst,
                                         CoordGroupList &sendGroupLst,
                                         netMultiRouteAgent *pRouteAgent,
                                         pmdEDUCB *cb,
                                         BOOLEAN onPrimary,
                                         std::set<INT32> *ignoreRCList = NULL,
                                         std::map<UINT64, SINT64> *contexts = NULL );
      virtual INT32 executeOnCataGroup ( CHAR *pBuffer,
                                       netMultiRouteAgent *pRouteAgent,
                                       pmdEDUCB *cb,
                                       rtnContextCoord *pContext = NULL,
                                       CoordGroupList *pGroupList = NULL,
                                       std::vector<BSONObj> *pReplyObjs = NULL );
      virtual INT32 processCatReply( MsgOpReply *pReply,
                                     CoordGroupList &groupLst );

      INT32 queryOnCatalog( const rtnQueryOptions &options,
                            pmdEDUCB *cb,
                            SINT64 &contextID ) ;

      INT32 queryOnCataAndPushToVec( const rtnQueryOptions &options,
                                     pmdEDUCB *cb,
                                     std::vector<BSONObj> &objs ) ;
   protected:
      virtual void _printDebug ( CHAR *pReceiveBuffer, const CHAR *pFuncName ) ;

   private:
      INT32 _getReplyObjsFromQueue( REPLY_QUE &replyQueue,
                                    pmdEDUCB *cb,
                                    rtnContextCoord *context ) ;
   };

   class rtnCoordDefaultCommand : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordBackupBase : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;

   protected:
      INT32          _getFilterFromMsg( CHAR *pReceiveBuffer, SINT32 packSize,
                                        BSONObj &filterObj,
                                        BSONObj *pOrderByObj = NULL,
                                        INT64 *pNumToReturn = NULL,
                                        INT64 *pNumToSkip = NULL ) ;
      INT32          _processReply( pmdEDUCB *cb, REPLY_QUE &replyQue,
                                    ROUTE_RC_MAP &failedNodes,
                                    rtnContextCoord *pContext ) ;
      INT32          _buildFailedNodeReply( ROUTE_RC_MAP &failedNodes,
                                            rtnContextCoord *pContext ) ;

   protected:
      virtual FILTER_BSON_ID  _getGroupMatherIndex () = 0 ;
      virtual NODE_SEL_STY    _nodeSelWhenNoFilter () = 0 ;
      virtual BOOLEAN         _allowFailed () = 0 ;
      virtual BOOLEAN         _useContext () = 0 ;

   } ;

   class rtnCoordListBackup : public rtnCoordBackupBase
   {
   protected:
      virtual FILTER_BSON_ID  _getGroupMatherIndex () ;
      virtual NODE_SEL_STY    _nodeSelWhenNoFilter () ;
      virtual BOOLEAN         _allowFailed () ;
      virtual BOOLEAN         _useContext () ;
   } ;

   class rtnCoordRemoveBackup : public rtnCoordBackupBase
   {
   protected:
      virtual FILTER_BSON_ID  _getGroupMatherIndex () ;
      virtual NODE_SEL_STY    _nodeSelWhenNoFilter () ;
      virtual BOOLEAN         _allowFailed () ;
      virtual BOOLEAN         _useContext () ;
   } ;

   class rtnCoordBackupOffline : public rtnCoordBackupBase
   {
   /*public:
      INT32 execute( CHAR *pReceiveBuffer, SINT32 packSize,
                     CHAR **ppResultBuffer, pmdEDUCB *cb,
                     MsgOpReply &replyHeader,
                     BSONObj **ppErrorObj ) ;*/
   protected:
      virtual FILTER_BSON_ID  _getGroupMatherIndex () ;
      virtual NODE_SEL_STY    _nodeSelWhenNoFilter () ;
      virtual BOOLEAN         _allowFailed () ;
      virtual BOOLEAN         _useContext () ;
   } ;

   class rtnCoordCMDListGroups : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };
   class rtnCoordCMDSnapshotOnNode : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint ) = 0;
   };
   class rtnCoordCMDSnapshotIntrBase : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   private:
      INT32 getNodes( pmdEDUCB *cb, bson::BSONObj &query, ROUTE_SET &nodes,
                     bson::BSONObj &newQuery );
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint ) = 0;
      INT32 processReply( _pmdEDUCB * pEDUCB, REPLY_QUE &replyQue,
                        ROUTE_RC_MAP &failedNodes, rtnContextCoord *pContext );
      INT32 buildFailedNodeReply( ROUTE_RC_MAP &failedNodes, rtnContext *pContext );
   };
   class rtnCoordCMDSnapshotDBIntr : public rtnCoordCMDSnapshotIntrBase
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotSysIntr : public rtnCoordCMDSnapshotIntrBase
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotClIntr : public rtnCoordCMDSnapshotIntrBase
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotCsIntr : public rtnCoordCMDSnapshotIntrBase
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotCtxIntr : public rtnCoordCMDSnapshotIntrBase
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotCtxCurIntr : public rtnCoordCMDSnapshotIntrBase
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotSessionIntr : public rtnCoordCMDSnapshotIntrBase
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotSessionCurIntr : public rtnCoordCMDSnapshotIntrBase
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotReset : public rtnCoordCMDSnapshotIntrBase
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapShotBase : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;

   protected:
      virtual INT32 appendObjs( const CHAR *pInputBuffer,
                              CHAR *&pOutputBuffer,
                              INT32 &bufferSize,
                              INT32 &addObjNum,
                              INT32 &bufUsed );

      INT32 appendObj( bson::BSONObj &obj,
                        CHAR *&pOutputBuffer,
                        INT32 &bufferSize,
                        INT32 &bufUsed );

   private:
      INT32 parseMatcher( bson::BSONObj &query,
                        bson::BSONObj &nodesMatcher,
                        bson::BSONObj &newMatcher );

      virtual INT32 generateAggrObjs( CHAR *pInputBuffer,
                                    CHAR *&pOutputBuffer,
                                    INT32 &objNum,
                                    CHAR *&pCLName,
                                    BSONObj &selector );
      virtual INT32 appendAggrObjs( CHAR *&pOutputBuffer,
                                    INT32 &bufferSize,
                                    INT32 &addObjNum,
                                    INT32 &bufUsed ) = 0;

      virtual const CHAR *getIntrCMDName() = 0;

      INT32 openContext( BSONObj &objs,
                         INT32 objNum,
                         const BSONObj &selector,
                         pmdEDUCB *cb,
                         SINT64 &contextID ) ;
   };
   class rtnCoordCMDSnapshotDataBase: public rtnCoordCMDSnapShotBase
   {
   private:
      virtual INT32 appendAggrObjs( CHAR *&pOutputBuffer,
                                    INT32 &bufferSize,
                                    INT32 &addObjNum,
                                    INT32 &bufUsed );
      virtual const CHAR *getIntrCMDName();
   };
   class rtnCoordCMDSnapshotSystem: public rtnCoordCMDSnapShotBase
   {
   private:
      virtual INT32 appendAggrObjs( CHAR *&pOutputBuffer,
                                    INT32 &bufferSize,
                                    INT32 &addObjNum,
                                    INT32 &bufUsed );
      virtual const CHAR *getIntrCMDName();
   };

   class rtnCoordCMDSnapshotCollections: public rtnCoordCMDSnapShotBase
   {
   private:
      virtual INT32 appendAggrObjs( CHAR *&pOutputBuffer,
                                    INT32 &bufferSize,
                                    INT32 &addObjNum,
                                    INT32 &bufUsed );
      virtual const CHAR *getIntrCMDName();
   };

   class rtnCoordCMDSnapshotSpaces: public rtnCoordCMDSnapShotBase
   {
   private:
      virtual INT32 appendAggrObjs( CHAR *&pOutputBuffer,
                                    INT32 &bufferSize,
                                    INT32 &addObjNum,
                                    INT32 &bufUsed );
      virtual const CHAR *getIntrCMDName();
   };

   class rtnCoordCMDSnapshotContexts: public rtnCoordCMDSnapShotBase
   {
   private:
      virtual INT32 appendAggrObjs( CHAR *&pOutputBuffer,
                                    INT32 &bufferSize,
                                    INT32 &addObjNum,
                                    INT32 &bufUsed );
      virtual const CHAR *getIntrCMDName();
   };

   class rtnCoordCMDSnapshotContextsCur: public rtnCoordCMDSnapShotBase
   {
   private:
      virtual INT32 appendAggrObjs( CHAR *&pOutputBuffer,
                                    INT32 &bufferSize,
                                    INT32 &addObjNum,
                                    INT32 &bufUsed );
      virtual const CHAR *getIntrCMDName();
   };

   class rtnCoordCMDSnapshotSessions: public rtnCoordCMDSnapShotBase
   {
   private:
      virtual INT32 appendAggrObjs( CHAR *&pOutputBuffer,
                                    INT32 &bufferSize,
                                    INT32 &addObjNum,
                                    INT32 &bufUsed );
      virtual const CHAR *getIntrCMDName();
   };

   class rtnCoordCMDSnapshotSessionsCur: public rtnCoordCMDSnapShotBase
   {
   private:
      virtual INT32 appendAggrObjs( CHAR *&pOutputBuffer,
                                    INT32 &bufferSize,
                                    INT32 &addObjNum,
                                    INT32 &bufUsed );
      virtual const CHAR *getIntrCMDName();
   };

   class rtnCoordCMDSnapshotDataBaseTmp : public rtnCoordCMDSnapshotOnNode
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotSystemTmp : public rtnCoordCMDSnapshotOnNode
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotSessionsTmp : public rtnCoordCMDSnapshotOnNode
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotContextsTmp : public rtnCoordCMDSnapshotOnNode
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDSnapshotCollectionsTmp : public rtnCoordCommand
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };
   class rtnCoordCMDSnapshotCollectionSpacesTmp : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };
   class rtnCoordCMDSnapshotResetTmp : public rtnCoordCMDSnapshotOnNode
   {
   private:
      virtual INT32 BuildRequestMsg  ( CHAR **ppBuffer, INT32 *bufferSize,
                              SINT32 flag, SINT64 numToSkip,
                              SINT64 numToReturn, bson::BSONObj *query,
                              bson::BSONObj *fieldSelector,
                              bson::BSONObj *orderBy,
                              bson::BSONObj *hint );
   };
   class rtnCoordCMDCreateCollectionSpace : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDCreateCollection : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;

   private:
      INT32 _notifyDataGroupsToStartTask( const BSONElement &task,
                                          netMultiRouteAgent *agent,
                                          pmdEDUCB *cb ) ;
   };

   class rtnCoordCMDAlterCollection : public rtnCoordCommand
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMD2PhaseCommit : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   protected:
      virtual void getIgnoreRCList( std::set<INT32> &ignoreRCList );

      virtual INT32 getGroupList( CHAR *pReceiveBuffer, CoordGroupList &groupLst,
                                 CoordGroupList &sendGroupLst,
                                 pmdEDUCB * cb,
                                 BOOLEAN isNeedRefresh ) = 0;

   private:
      virtual void fillReply( MsgHeader *pSrcMsg,
                              INT32 rc, 
                              MsgOpReply &replyHeader );

      virtual INT32 doP1OnDataGroup( CHAR *pReceiveBuffer,
                                    pmdEDUCB * cb,
                                    SINT64 &contextID,
                                    std::set<INT32> &ignoreRCList,
                                    BOOLEAN isNeedRefresh );

      virtual INT32 doP2OnDataGroup( CHAR *pReceiveBuffer,
                                    pmdEDUCB * cb,
                                    SINT64 &contextID );

      virtual INT32 doOnCataGroup( CHAR *pReceiveBuffer,
                                    pmdEDUCB * cb ) = 0;

      virtual INT32 complete( CHAR *pReceiveBuffer,
                              pmdEDUCB * cb );
   };

   class rtnCoordCMDDropCollection : public rtnCoordCMD2PhaseCommit
   {
   protected:
      virtual INT32 getGroupList( CHAR *pReceiveBuffer,
                                 CoordGroupList &groupLst,
                                 CoordGroupList &sendGroupLst,
                                 pmdEDUCB * cb,
                                 BOOLEAN isNeedRefresh );

      virtual void getIgnoreRCList( std::set<INT32> &ignoreRCList );

   private:
      virtual INT32 doOnCataGroup( CHAR *pReceiveBuffer,
                                    pmdEDUCB * cb );

      virtual INT32 complete( CHAR *pReceiveBuffer,
                              pmdEDUCB * cb );

      INT32 getCLName( CHAR *pReceiveBuffer,
                     std::string &strCLName );
   };

   class rtnCoordCMDDropCollectionSpace : public rtnCoordCMD2PhaseCommit
   {
   protected:
      virtual INT32 getGroupList( CHAR *pReceiveBuffer,
                                 CoordGroupList &groupLst,
                                 CoordGroupList &sendGroupLst,
                                 pmdEDUCB * cb,
                                 BOOLEAN isNeedRefresh );

      virtual void getIgnoreRCList( std::set<INT32> &ignoreRCList );

   private:
      virtual INT32 doOnCataGroup( CHAR *pReceiveBuffer,
                                    pmdEDUCB * cb );
   };

   class rtnCoordCMDQueryBase : public rtnCoordCommand
   {
   public:
      virtual INT32 queryToCataNodeGroup( CHAR *pBuffer,
                                          netMultiRouteAgent *pRouteAgent,
                                          pmdEDUCB *cb,
                                          rtnContextCoord *pContext );
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
      virtual INT32 buildQueryRequest( CHAR *pIntput,
                                       pmdEDUCB *cb,
                                       CHAR **pOutput ) = 0;
   };

   class rtnCoordCMDSnapshotCata : public rtnCoordCMDQueryBase
   {
   public:
      virtual INT32 buildQueryRequest( CHAR *pIntput,
                                       pmdEDUCB *cb,
                                       CHAR **ppOutput );
   };

   class rtnCoordCMDListCollectionSpace : public rtnCoordCMDQueryBase
   {
   public:
      virtual INT32 buildQueryRequest( CHAR *pIntput,
                                       pmdEDUCB *cb,
                                       CHAR **ppOutput );
   };

   class rtnCoordCMDListCollection : public rtnCoordCMDQueryBase
   {
   public:
      virtual INT32 buildQueryRequest( CHAR *pIntput,
                                       pmdEDUCB *cb,
                                       CHAR **ppOutput );
   };

   class rtnCoordCMDListUser : public rtnCoordCMDQueryBase
   {
   protected:
      virtual INT32 buildQueryRequest( CHAR *pIntput,
                                       pmdEDUCB *cb,
                                       CHAR **ppOutput );
   };

   class rtnCoordCMDTestCollectionSpace : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDTestCollection : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDCreateGroup : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDRemoveGroup : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDConfigNode
   {
   public:
      INT32 getNodeInfo( char *pQuery, bson::BSONObj &NodeInfo );
      INT32 getNodeConf( char *pQuery, bson::BSONObj &nodeConf,
                         CoordGroupInfoPtr &catGroupInfo );
   };

   class rtnCoordCMDCreateNode : public rtnCoordCommand,
                                 public rtnCoordCMDConfigNode
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDRemoveNode : public rtnCoordCommand,
                                 public rtnCoordCMDConfigNode
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
      virtual INT32 processCatReply( MsgOpReply *pReply,
                                     CoordGroupList &groupLst )
      {
         return MSG_CAT_DEL_NODE_RSP == (UINT32)(pReply->header.opCode) ?
                pReply->flags :
                this->rtnCoordCommand::processCatReply(pReply, groupLst );
      }
   private:
      INT32 _validateOnDataNode( const BSONElement &groupName,
                                 const BSONElement &host,
                                 const BSONElement &srv,
                                 pmdEDUCB *cb ) ;
   } ;

   class rtnCoordCMDUpdateNode : public rtnCoordCommand,
                                 public rtnCoordCMDConfigNode
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };


   class rtnCoordCMDActiveGroup : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   private:
      INT32 executeOnCataGroup ( CHAR *pBuffer,
                                 netMultiRouteAgent *pRouteAgent,
                                 pmdEDUCB *cb,
                                 bson::BSONObj &boGroupInfo ) ;
      INT32 startNodes( bson::BSONObj &boGroupInfo,
                        vector<bson::BSONObj> &objList ) ;

      INT32 startNodes( clsGroupItem *pItem,
                        vector<bson::BSONObj> &objList ) ;

   };

   class rtnCoordCMDCreateIndex : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDDropIndex : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDOperateOnNode : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
      virtual SINT32 getOpType()=0;
   };

   class rtnCoordCMDStartupNode : public rtnCoordCMDOperateOnNode
   {
   public:
      virtual SINT32 getOpType();
   };

   class rtnCoordCMDShutdownNode : public rtnCoordCMDOperateOnNode
   {
   public:
      virtual SINT32 getOpType();
   };

   class rtnCoordCMDOperateOnGroup : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
      INT32 opOnGroup( bson::BSONObj &boGroupInfo );
      virtual SINT32 getOpType()=0;
   };

   class rtnCoordCMDShutdownGroup : public rtnCoordCMDOperateOnGroup
   {
   public:
      virtual SINT32 getOpType();
   };

   class rtnCoordCMDSplit : public rtnCoordCommand
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;

      INT32         getCLCount( const CHAR *clFullName,
                                CoordGroupList &groupList,
                                pmdEDUCB *cb, UINT64 &count ) ;

   protected:
      INT32 _getBoundByPercent( const CHAR *cl,
                                FLOAT64 percent,
                                CoordCataInfoPtr &cataInfo,
                                CoordGroupList &groupList,
                                pmdEDUCB *cb,
                                BSONObj &lowBound,
                                BSONObj &upBound ) ;

      INT32 _getBoundByCondition( const CHAR *cl,
                                  const BSONObj &begin,
                                  const BSONObj &end,
                                  CoordGroupList &groupList,
                                  pmdEDUCB *cb,
                                  CoordCataInfoPtr &cataInfo,
                                  BSONObj &lowBound,
                                  BSONObj &upBound ) ;

   private:
      INT32 _getBoundRecordOnData( const CHAR *cl,
                                   const BSONObj &condition,
                                   const BSONObj &hint,
                                   INT32 flag,
                                   INT64 skip,
                                   CoordGroupList &groupList,
                                   pmdEDUCB *cb,
                                   BSONObj &shardingKey,
                                   BSONObj &record ) ;

   } ;

   class rtnCoordCmdWaitTask : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCmdListTask : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCmdCancelTask : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDStatisticsBase : virtual public rtnCoordCommand,
                                    virtual public rtnCoordQuery
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   private:
      virtual INT32 generateResult( rtnContext *pContext,
                                    netMultiRouteAgent *pRouteAgent,
                                    pmdEDUCB *cb ) = 0 ;
   } ;

   class rtnCoordCMDGetIndexes : public rtnCoordCMDStatisticsBase
   {
      typedef std::map< std::string, bson::BSONObj > CoordIndexMap;
   private :
      virtual INT32 generateResult( rtnContext *pContext,
                                 netMultiRouteAgent *pRouteAgent,
                                 pmdEDUCB *cb );
   } ;
   class rtnCoordCMDGetCount : public rtnCoordCMDStatisticsBase
   {
   private :
      virtual INT32 generateResult( rtnContext *pContext,
                                 netMultiRouteAgent *pRouteAgent,
                                 pmdEDUCB *cb );
   };
   class rtnCoordCMDGetDatablocks : public rtnCoordCMDStatisticsBase
   {
   private :
      virtual INT32 generateResult( rtnContext *pContext,
                                    netMultiRouteAgent *pRouteAgent,
                                    pmdEDUCB *cb ) ;
   } ;

   class rtnCoordCMDGetQueryMeta : public rtnCoordCMDGetDatablocks
   {
   } ;

   class rtnCoordCMDCreateCataGroup : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   private:
      INT32 getNodeConf( CHAR *pQuery, bson::BSONObj &boNodeConfig );
      INT32 getNodeInfo( CHAR *pQuery, bson::BSONObj &boNodeInfo );
   };

   class rtnCoordCMDTraceStart : public rtnCoordCommand
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDTraceResume : public rtnCoordCommand
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDTraceStop : public rtnCoordCommand
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDTraceStatus : public rtnCoordCommand
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDExpConfig : public rtnCoordCommand
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;

   private:
      INT32 _getNodesSet( pmdEDUCB *cb, ROUTE_SET &nSet ) ;
   } ;

   class rtnCoordCMDCrtProcedure : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;

      INT32 processCatReply( MsgOpReply *pReply,
                             CoordGroupList &groupLst ) ;
   } ;

   class rtnCoordCMDEval : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   private:
      INT32 _buildContext( _spdSession *session,
                           pmdEDUCB *cb,
                           SINT64 &contextID ) ;
   } ;

   class rtnCoordCMDRmProcedure : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;

      INT32 processCatReply( MsgOpReply *pReply,
                             CoordGroupList &groupLst ) ;
   } ;

   class rtnCoordCMDListProcedures : public rtnCoordCMDQueryBase
   {
   public:
      virtual INT32 buildQueryRequest( CHAR *pIntput,
                                       pmdEDUCB *cb,
                                       CHAR **ppOutput );
   } ;

   class rtnCoordCMDLinkCollection : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDUnlinkCollection : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDSetSessionAttr : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   };

   class rtnCoordCMDCreateDomain : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDDropDomain : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDAlterDomain : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDAddDomainGroup : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDRemoveDomainGroup : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDListDomains : public rtnCoordCMDQueryBase
   {
   public:
      virtual INT32 buildQueryRequest( CHAR *pIntput,
                                       pmdEDUCB *cb,
                                       CHAR **ppOutput );
   } ;

   class rtnCoordCMDListCSInDomain : public rtnCoordCMDQueryBase
   {
   public:
      virtual INT32 buildQueryRequest( CHAR *pIntput,
                                       pmdEDUCB *cb,
                                       CHAR **ppOutput );
   } ;


   class rtnCoordCMDListCLInDomain : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;

   private:
      INT32 _rebuildListResult( const std::vector<BSONObj> &infoFromCata,
                                pmdEDUCB *cb,
                                SINT64 &contextID ) ;
   } ;

   class rtnCoordCMDOnMultiNodes : public rtnCoordCommand
   {
   protected:
      INT32 _extractExecRange( const BSONObj &condition,
                               pmdEDUCB *cb,
                               ROUTE_SET &range ) ;

      INT32 _executeOnMultiNodes( CHAR *msg,
                                  pmdEDUCB *cb,
                                  ROUTE_SET &nodes,
                                  ROUTE_RC_MAP &uncompleted ) ;

   } ;

   class rtnCoordCMDInvalidateCache : public rtnCoordCMDOnMultiNodes
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDListLobs : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDReelection : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDTruncate : public rtnCoordCommand
   {
   public:
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;
   } ;

   class rtnCoordCMDQueryOnMain : public rtnCoordCommand
   {
   public :
      virtual INT32 execute( CHAR *pReceiveBuffer,
                             SINT32 packSize,
                             pmdEDUCB *cb,
                             MsgOpReply &replyHeader,
                             rtnContextBuf *buf ) ;

      virtual INT32 processReply( pmdEDUCB *cb, REPLY_QUE replyQue,
                                  rtnContextCoord *pContext,
                                  CoordGroupList &retryGroups ) ;

      virtual INT32 getGroups( pmdEDUCB *cb, CoordGroupList &groupList ) = 0 ;
   } ;

   class rtnCoordSnapshotTransCur : public rtnCoordCMDQueryOnMain
   {
   public:
      virtual INT32 getGroups( pmdEDUCB *cb, CoordGroupList &groupList ) ;
   } ;

   class rtnCoordSnapshotTrans : public rtnCoordCMDQueryOnMain
   {
   public:
      virtual INT32 getGroups( pmdEDUCB *cb, CoordGroupList &groupList ) ;
   } ;
}
#endif
