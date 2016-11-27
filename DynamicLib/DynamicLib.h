// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DYNAMICLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DYNAMICLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif

// This class is exported from the DynamicLib.dll
class DYNAMICLIB_API CDynamicLib {
public:
	CDynamicLib(void);
	// TODO: add your methods here.

	int getValue();
};

extern DYNAMICLIB_API int nDynamicLib;

DYNAMICLIB_API int fnDynamicLib(void);
