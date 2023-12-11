// MyTestEnvent.cpp : Implementation of CMyTestEnvent

#include "pch.h"
#include "MyTestEnvent.h"

#include <codecvt>  
#include <comdef.h> 
// CMyTestEnvent

#define CLSID_SHARE_VIEW L"{71C28F1E-B01A-430A-96DD-2C36EA4C29BE}"

HRESULT __stdcall CMyTestEnvent::Activate(IDispatch* pDisp, VARIANT_BOOL FirstTime)
{
	MessageBoxA(NULL, "Activate success", "Happy", MB_OK);
	//Sign In
	HRESULT hr = S_OK;
	if (pDisp == NULL)
	{
		return E_INVALIDARG;
	}
	hr = pDisp->QueryInterface(__uuidof (m_pAddInSite), reinterpret_cast<void**>(&m_pAddInSite));
	ATLASSERT(SUCCEEDED(hr));
	if (FAILED(hr))
	{
		return hr;
	}

	//----- get the Inventor application object
	hr = m_pAddInSite->get_Application(&m_pApplication);
	ATLASSERT(SUCCEEDED(hr));
	if (FAILED(hr))
	{
		return hr;
	}

	//----- get the Inventor applicationAddIns object
	hr = m_pApplication->get_ApplicationAddIns(&m_pAppAddIns);
	ATLASSERT(SUCCEEDED(hr));
	if (FAILED(hr))
	{
		return hr;
	}

	//----- get the Inventor applicationEvents object
	hr = m_pApplication->get_ApplicationEvents(&m_pAppEvent);
	ATLASSERT(SUCCEEDED(hr));
	if (FAILED(hr))
	{
		return hr;
	}

	//
	hr = IDispEventImpl<APPLICATION_EVENTS, CMyTestEnvent, &DIID_ApplicationEventsSink, &LIBID_Inventor, 1, 0>::DispEventAdvise(m_pAppEvent);
	return hr;
}

HRESULT __stdcall CMyTestEnvent::Deactivate(void)
{
	HRESULT hr = IDispEventImpl<APPLICATION_EVENTS, CMyTestEnvent, &DIID_ApplicationEventsSink, &LIBID_Inventor, 1, 0>::DispEventUnadvise(m_pAppEvent);
	m_pAppEvent.Release();
	m_pAddInSite.Release();
	m_pApplication.Release();

	return hr;
}

HRESULT __stdcall CMyTestEnvent::ExecuteCommand(long CommandID)
{
	return E_NOTIMPL;
}

HRESULT __stdcall CMyTestEnvent::get_Automation(IDispatch** Result)
{
	return E_NOTIMPL;
}

STDMETHODIMP_(HRESULT __stdcall) CMyTestEnvent::onEvent_OnDocumentChange(Document* DocumentObject, EventTimingEnum BeforeOrAfter, CommandTypesEnum ReasonsForChange, NameValueMap* Context, HandlingCodeEnum* HandlingCode)
{
	MessageBoxA(NULL, "OnDocumentChange Success", "Happy", MB_OK);
	return S_OK;
}

STDMETHODIMP_(HRESULT __stdcall) CMyTestEnvent::onEvent_OnOpenDocument(Document* DocumentObject, _bstr_t* FullDocumentName, EventTimingEnum BeforeOrAfter, NameValueMap* Context, HandlingCodeEnum* HandlingCode)
{
	MessageBoxA(NULL, "OnDocumentOpen Success", "Happy", MB_OK);
	HRESULT ht = S_OK;
	if (kAfter == BeforeOrAfter)
	{
		for (long i = 1; i <= m_pAppAddIns->GetCount(); i++)
		{
			CComPtr<ApplicationAddIn> pAppAddIn;
			HRESULT ht1 = m_pAppAddIns->get_Item(i, &pAppAddIn);
			if (SUCCEEDED(ht1))
			{
				_bstr_t strDisName = pAppAddIn->GetDisplayName();
				_bstr_t bstrClassID = pAppAddIn->GetClassIdString();
				if (bstrClassID.length() != 0)
				{
					if (wcsstr(bstrClassID.GetBSTR(), CLSID_SHARE_VIEW) != nullptr)
					{
						HRESULT ht2 = pAppAddIn->Deactivate();
						if (SUCCEEDED(ht2)) {
							pAppAddIn->PutHidden(true);
							MessageBoxA(NULL, "Share View addin is unloaded and hidded", "test", MB_OK);
						}
						break;
					}
				}
			}
		}
	}
	return ht;
}

STDMETHODIMP_(HRESULT __stdcall) CMyTestEnvent::onEvent_OnSaveDocument(Document* DocumentObject, EventTimingEnum BeforeOrAfter, NameValueMap* Context, HandlingCodeEnum* HandlingCode)
{
	MessageBoxA(NULL, "OnDocumentSave Success", "Happy", MB_OK);
	return S_OK;
}
