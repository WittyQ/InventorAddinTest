// dllmain.h : Declaration of module class.

class CMyTestAddinInventorModule : public ATL::CAtlDllModuleT< CMyTestAddinInventorModule >
{
public :
	DECLARE_LIBID(LIBID_MyTestAddinInventorLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MYTESTADDININVENTOR, "{a60d8bcf-eaf9-4604-b0b4-5c6e8d54d96e}")
};

extern class CMyTestAddinInventorModule _AtlModule;
