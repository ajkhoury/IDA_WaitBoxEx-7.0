
// WaitBoxEx: Custom IDA Pro wait box
// By Sirmabus
// Version 1.3
// http://www.macromonkey.com
// License: Qt 5.4.1 LGPL  http://www.qt.io/faq/
#pragma once

// Define MATERIAL_DESIGN_STYLE for a "material design" inspired style

#ifndef _LIB
#ifndef MATERIAL_DESIGN_STYLE
	#ifndef _DEBUG
        #ifdef __X64__
	    #pragma comment(lib, "WaitBoxEx64.LiB")
        #else
        #pragma comment(lib, "WaitBoxEx.LiB")
        #endif
	#else
        #ifdef __X64__
        #pragma comment(lib, "WaitBoxExD64.LiB")
        #else
        #pragma comment(lib, "WaitBoxExD.LiB")
        #endif
	#endif
#else
	#ifndef _DEBUG	
        #ifdef __X64__
        #pragma comment(lib, "WaitBoxExMd64.LiB")
        #else
        #pragma comment(lib, "WaitBoxExMd.LiB")
        #endif
	#else
        #ifdef __X64__
        #pragma comment(lib, "WaitBoxExMdD64.LiB")
        #else
        #pragma comment(lib, "WaitBoxExMdD.LiB")
        #endif
	#endif
#endif
#endif

namespace WaitBox
{
    // Show the modal wait box dialog
    void _cdecl show(LPCSTR titleText = "Progress", LPCSTR labelText = "Please wait..", LPCSTR styleSheet = NULL, LPCSTR icon = NULL);

    // Stop the wait box
    void _cdecl hide();

    // Check if user canceled and optionally the update progress too w/built-in timed update limiter.
    // Progress range: 0 to 100, or -1 to switch to indeterminate mode.
    BOOL _cdecl updateAndCancelCheck(int progress = 0);

    // Returns TRUE if ready for internal update
    BOOL _cdecl isUpdateTime();

    // Returns TRUE if wait box up
    BOOL _cdecl isShowing();

    // Change the label text
    void _cdecl setLabelText(LPCSTR labelText);

    // Convenience wrapper of Qt function "QApplication::processEvents();" to tick IDA's Qt event queue
    void _cdecl processIdaEvents();
};


