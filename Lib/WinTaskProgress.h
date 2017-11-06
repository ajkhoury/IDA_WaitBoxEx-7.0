
// Windows 7+ taskbar progress
// Sirmabus 2015
// http://www.macromonkey.com
#pragma once

namespace TaskProgress
{
    void __cdecl start(HWND hwnd);
    void __cdecl end();

    // Set current progress (from 0 to 100), or -1 to switch to indeterminate mode
    // Note: Indeterminate animation will not occur if animations are unchecked in Windows "Performance Options"
    void __cdecl setProgress(int progress);

    // Set taskbar tracking/view window source
    void __cdecl setTrackingWindow(HWND hwnd);
};