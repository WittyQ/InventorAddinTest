

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for MyTestAddinInventor.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __MyTestAddinInventor_i_h__
#define __MyTestAddinInventor_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMyTestEnvent_FWD_DEFINED__
#define __IMyTestEnvent_FWD_DEFINED__
typedef interface IMyTestEnvent IMyTestEnvent;

#endif 	/* __IMyTestEnvent_FWD_DEFINED__ */


#ifndef __MyTestEnvent_FWD_DEFINED__
#define __MyTestEnvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class MyTestEnvent MyTestEnvent;
#else
typedef struct MyTestEnvent MyTestEnvent;
#endif /* __cplusplus */

#endif 	/* __MyTestEnvent_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMyTestEnvent_INTERFACE_DEFINED__
#define __IMyTestEnvent_INTERFACE_DEFINED__

/* interface IMyTestEnvent */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMyTestEnvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7c4b7cd7-f183-4ee8-af2a-4613fbd16b91")
    IMyTestEnvent : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Activate( 
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT_BOOL FirstTime) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Deactivate( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExecuteCommand( 
            /* [in] */ long CommandID) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Automation( 
            /* [retval][out] */ IDispatch **Result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMyTestEnventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMyTestEnvent * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMyTestEnvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMyTestEnvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMyTestEnvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMyTestEnvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMyTestEnvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMyTestEnvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IMyTestEnvent * This,
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT_BOOL FirstTime);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Deactivate )( 
            IMyTestEnvent * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExecuteCommand )( 
            IMyTestEnvent * This,
            /* [in] */ long CommandID);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Automation )( 
            IMyTestEnvent * This,
            /* [retval][out] */ IDispatch **Result);
        
        END_INTERFACE
    } IMyTestEnventVtbl;

    interface IMyTestEnvent
    {
        CONST_VTBL struct IMyTestEnventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMyTestEnvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMyTestEnvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMyTestEnvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMyTestEnvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMyTestEnvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMyTestEnvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMyTestEnvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMyTestEnvent_Activate(This,pDisp,FirstTime)	\
    ( (This)->lpVtbl -> Activate(This,pDisp,FirstTime) ) 

#define IMyTestEnvent_Deactivate(This)	\
    ( (This)->lpVtbl -> Deactivate(This) ) 

#define IMyTestEnvent_ExecuteCommand(This,CommandID)	\
    ( (This)->lpVtbl -> ExecuteCommand(This,CommandID) ) 

#define IMyTestEnvent_get_Automation(This,Result)	\
    ( (This)->lpVtbl -> get_Automation(This,Result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMyTestEnvent_INTERFACE_DEFINED__ */



#ifndef __MyTestAddinInventorLib_LIBRARY_DEFINED__
#define __MyTestAddinInventorLib_LIBRARY_DEFINED__

/* library MyTestAddinInventorLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_MyTestAddinInventorLib;

EXTERN_C const CLSID CLSID_MyTestEnvent;

#ifdef __cplusplus

class DECLSPEC_UUID("91243c24-5714-45cb-96e3-c603638d598f")
MyTestEnvent;
#endif
#endif /* __MyTestAddinInventorLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


