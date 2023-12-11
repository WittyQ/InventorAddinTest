// MyTestEnvent.h : Declaration of the CMyTestEnvent

#pragma once
#include "resource.h"       // main symbols



#include "MyTestAddinInventor_i.h"


#define APPLICATION_EVENTS 0

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CMyTestEnvent

class ATL_NO_VTABLE CMyTestEnvent :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMyTestEnvent, &CLSID_MyTestEnvent>,
	public IDispatchImpl<IMyTestEnvent, &IID_IMyTestEnvent, &LIBID_MyTestAddinInventorLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispEventImpl<APPLICATION_EVENTS, CMyTestEnvent, &DIID_ApplicationEventsSink, &LIBID_Inventor, 1, 0>
{
public:
	CMyTestEnvent()
	{
		MessageBoxA(NULL, "Class created success", "Happy", MB_OK);
	}

public:
	virtual /* [id] */ HRESULT STDMETHODCALLTYPE Activate(
		/* [in] */ IDispatch* pDisp,
		/* [in] */ VARIANT_BOOL FirstTime);

	virtual /* [id] */ HRESULT STDMETHODCALLTYPE Deactivate(void);

	virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExecuteCommand(
		/* [in] */ long CommandID);

	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Automation(
		/* [retval][out] */ IDispatch** Result);

	STDMETHOD(onEvent_OnDocumentChange)(Document* DocumentObject, EventTimingEnum BeforeOrAfter, CommandTypesEnum ReasonsForChange, NameValueMap* Context, HandlingCodeEnum* HandlingCode);
	STDMETHOD(onEvent_OnOpenDocument)(Document* DocumentObject, _bstr_t* FullDocumentName, EventTimingEnum BeforeOrAfter, NameValueMap* Context, HandlingCodeEnum* HandlingCode);
	STDMETHOD(onEvent_OnSaveDocument)(Document* DocumentObject, EventTimingEnum BeforeOrAfter, NameValueMap* Context, HandlingCodeEnum* HandlingCode);
DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CMyTestEnvent)
	COM_INTERFACE_ENTRY(IMyTestEnvent)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

//Bind the Event and Response function
BEGIN_SINK_MAP(CMyTestEnvent)
	SINK_ENTRY_EX(APPLICATION_EVENTS, DIID_ApplicationEventsSink, ApplicationEventsSink_OnDocumentChange, onEvent_OnDocumentChange)
	SINK_ENTRY_EX(APPLICATION_EVENTS, DIID_ApplicationEventsSink, ApplicationEventsSink_OnOpenDocument, onEvent_OnOpenDocument)
	SINK_ENTRY_EX(APPLICATION_EVENTS, DIID_ApplicationEventsSink, ApplicationEventsSink_OnSaveDocument, onEvent_OnSaveDocument)
END_SINK_MAP()


DECLARE_PROTECT_FINAL_CONSTRUCT()

HRESULT FinalConstruct()
{
	return S_OK;
}

void FinalRelease()
{
}

public:

private:
	CComPtr<ApplicationAddInSite> m_pAddInSite;
	CComPtr<Application> m_pApplication;
	CComPtr<ApplicationAddIns> m_pAppAddIns;
	CComPtr<ApplicationEventsObject> m_pAppEvent;
};

OBJECT_ENTRY_AUTO(__uuidof(MyTestEnvent), CMyTestEnvent)
