/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.cpp
 #	source generated by 4D Plugin Wizard
 #	Project : Carbon Window Manager
 #	author : miyako
 #	2014/10/31
 #
 # --------------------------------------------------------------------------------*/


#include "4DPluginAPI.h"
#include "4DPlugin.h"

void PluginMain(PA_long32 selector, PA_PluginParameters params)
{
	try
	{
		PA_long32 pProcNum = selector;
		sLONG_PTR *pResult = (sLONG_PTR *)params->fResult;
		PackagePtr pParams = (PackagePtr)params->fParameters;

		CommandDispatcher(pProcNum, pResult, pParams); 
	}
	catch(...)
	{

	}
}

void CommandDispatcher (PA_long32 pProcNum, sLONG_PTR *pResult, PackagePtr pParams)
{
	switch(pProcNum)
	{
// --- Buttons

		case 1 :
			CWM_SET_MODIFIED(pResult, pParams);
			break;

		case 2 :
			CWM_Get_modified(pResult, pParams);
			break;

		case 3 :
			CWM_SET_ZOOM_BOX(pResult, pParams);
			break;

		case 4 :
			CWM_Get_zoom_box(pResult, pParams);
			break;

		case 5 :
			CWM_SET_CLOSE_BOX(pResult, pParams);
			break;

		case 6 :
			CWM_Get_close_box(pResult, pParams);
			break;

		case 7 :
			CWM_SET_COLLAPSE_BOX(pResult, pParams);
			break;

		case 8 :
			CWM_Get_collapse_box(pResult, pParams);
			break;

		case 9 :
			CWM_SET_WINDOW_ICON(pResult, pParams);
			break;

		case 10 :
			CWM_Get_window_icon(pResult, pParams);
			break;

	}
}

// ------------------------------------ Buttons -----------------------------------


void CWM_SET_MODIFIED(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_LONGINT Param2;
    
    Param1.fromParamAtIndex(pParams, 1);
    Param2.fromParamAtIndex(pParams, 2);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
#ifndef __LP64__ 
    SetWindowModified(windowRef, Param2.getIntValue());
#endif
}

void CWM_Get_modified(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_LONGINT returnValue;
    
    Param1.fromParamAtIndex(pParams, 1);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
#ifndef __LP64__ 
    returnValue.setIntValue(IsWindowModified(windowRef));
#endif
    
    returnValue.setReturn(pResult);
}

#ifndef __LP64__ 
void _setBox(WindowRef window, int attribute, int set) 
{
    int	attributes[] = {attribute, 0};
    
    if(set)
    {
        HIWindowChangeAttributes(window, attributes, 0);		
    }else{
        HIWindowChangeAttributes(window, 0, attributes);	
    }
}
int _getBox(WindowRef window, int attribute) 
{
    return HIWindowTestAttribute(window, attribute);
}
#endif

void CWM_SET_ZOOM_BOX(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_LONGINT Param2;
    
    Param1.fromParamAtIndex(pParams, 1);
    Param2.fromParamAtIndex(pParams, 2);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
#ifndef __LP64__ 
    _setBox(windowRef, kHIWindowBitZoomBox, Param2.getIntValue());
#endif
}

void CWM_Get_zoom_box(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_LONGINT returnValue;
    
    Param1.fromParamAtIndex(pParams, 1);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
#ifndef __LP64__ 
    returnValue.setIntValue(_getBox(windowRef, kHIWindowBitZoomBox));
#endif
    
    returnValue.setReturn(pResult);
}

void CWM_SET_CLOSE_BOX(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_LONGINT Param2;
    
    Param1.fromParamAtIndex(pParams, 1);
    Param2.fromParamAtIndex(pParams, 2);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
#ifndef __LP64__ 
    _setBox(windowRef, kHIWindowBitCloseBox, Param2.getIntValue());
#endif
}

void CWM_Get_close_box(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_LONGINT returnValue;
    
    Param1.fromParamAtIndex(pParams, 1);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
#ifndef __LP64__ 
    returnValue.setIntValue(_getBox(windowRef, kHIWindowBitCloseBox));
#endif
    
    returnValue.setReturn(pResult);
}

void CWM_SET_COLLAPSE_BOX(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_LONGINT Param2;
    
    Param1.fromParamAtIndex(pParams, 1);
    Param2.fromParamAtIndex(pParams, 2);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
#ifndef __LP64__ 
    _setBox(windowRef, kHIWindowBitCollapseBox, Param2.getIntValue());
#endif
}

void CWM_Get_collapse_box(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_LONGINT returnValue;
    
    Param1.fromParamAtIndex(pParams, 1);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
#ifndef __LP64__ 
    returnValue.setIntValue(_getBox(windowRef, kHIWindowBitCollapseBox));
#endif
    
    returnValue.setReturn(pResult);
}

void CWM_SET_WINDOW_ICON(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_PICTURE Param2;
    
    Param1.fromParamAtIndex(pParams, 1);
    Param2.fromParamAtIndex(pParams, 2);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
    //carbon api    
#ifndef __LP64__ 
    PA_Picture picture = Param2.createThumbnail(48,48);
    CGImageRef image = (CGImageRef)PA_CreateNativePictureForScreen(picture);
    if(image){
        NSString *temporaryIconPath = [NSTemporaryDirectory() stringByAppendingPathComponent:[[[NSUUID UUID]UUIDString]stringByAppendingString:@".icns"]]; 
        NSURL *url = [NSURL fileURLWithPath:temporaryIconPath];
        if(url){
            CGImageDestinationRef destination = CGImageDestinationCreateWithURL((CFURLRef)url, kUTTypeAppleICNS, 1, NULL);
            if(destination){
                CFMutableDictionaryRef properties = CFDictionaryCreateMutable(kCFAllocatorDefault, 0, NULL, NULL);
                CGImageDestinationAddImage(destination, image, properties);
                CGImageDestinationFinalize(destination);	
                CFRelease(destination);
                CFRelease(properties); 
                FSRef fsRef;
                IconRef iconRef;
                if(CFURLGetFSRef((CFURLRef)url, &fsRef))
                {
                    RegisterIconRefFromFSRef('cust', '4D65', &fsRef, &iconRef);
                    SetWindowProxyIcon(windowRef, iconRef);
                    ReleaseIconRef(iconRef);
                    UnregisterIconRef('cust', '4D65');
                }	                
            }        
        }
        CFRelease(image);
    }      
#endif    
}

void CWM_Get_window_icon(sLONG_PTR *pResult, PackagePtr pParams)
{
    C_LONGINT Param1;
    C_PICTURE returnValue;
    
    Param1.fromParamAtIndex(pParams, 1);
    
    WindowRef windowRef;
    windowRef = (WindowRef)PA_GetWindowPtr(reinterpret_cast<PA_WindowRef>(Param1.getIntValue()));
    
    //carbon api    
#ifndef __LP64__ 
    IconRef iconRef;
    if(GetWindowProxyIcon(windowRef, &iconRef) != errWindowDoesNotHaveProxy)
    {
        NSImage *icon = [[NSImage alloc]initWithIconRef:iconRef];
        returnValue.setImage(icon);
        [icon release];
    }
#endif
    
    returnValue.setReturn(pResult);
}