//
// Copyright (c) .NET Foundation and Contributors
// See LICENSE file in the project root for full license information.
//


#ifndef WIN_DEV_WIFI_NATIVE_TARGET_H
#define WIN_DEV_WIFI_NATIVE_TARGET_H

#include <nanoCLR_Interop.h>
#include <nanoCLR_Runtime.h>
#include <nanoCLR_Checks.h>
#include <esp32_os.h>


struct Library_win_dev_wifi_native_Windows_Devices_WiFi_WiFiAdapter
{
    static const int FIELD_STATIC__s_eventListener = 0;

    static const int FIELD___networkInterface = 1;
    static const int FIELD___syncLock = 2;
    static const int FIELD__AvailableNetworksChanged = 3;
    static const int FIELD___disposedValue = 4;

    NANOCLR_NATIVE_DECLARE(DisposeNative___VOID);
    NANOCLR_NATIVE_DECLARE(NativeInit___VOID);
    NANOCLR_NATIVE_DECLARE(NativeConnect___WindowsDevicesWiFiWiFiConnectionStatus__STRING__STRING__WindowsDevicesWiFiWiFiReconnectionKind);
    NANOCLR_NATIVE_DECLARE(NativeDisconnect___VOID);
    NANOCLR_NATIVE_DECLARE(NativeScanAsync___VOID);
    NANOCLR_NATIVE_DECLARE(GetNativeScanReport___SZARRAY_U1);
    NANOCLR_NATIVE_DECLARE(NativeFindWirelessAdapters___STATIC__SZARRAY_U1);

    //--//

    static HRESULT GetNetInterfaceIndex(CLR_RT_StackFrame& stack, int * pNetIndex);
};

struct Library_win_dev_wifi_native_Windows_Devices_WiFi_WiFiAvailableNetwork
{
    static const int FIELD___bsid = 1;
    static const int FIELD___ssid = 2;
    static const int FIELD___rssi = 3;
    static const int FIELD___networkKind = 4;


    //--//

};

struct Library_win_dev_wifi_native_Windows_Devices_WiFi_WiFiConnectionResult
{
    static const int FIELD___ConnectionStatus = 1;


    //--//

};

struct Library_win_dev_wifi_native_Windows_Devices_WiFi_WiFiEvent
{
    static const int FIELD__EventType = 3;
    static const int FIELD__Time = 4;


    //--//

};

struct Library_win_dev_wifi_native_Windows_Devices_WiFi_WiFiEventListener
{
    static const int FIELD__wifiAdapters = 1;


    //--//

};

struct Library_win_dev_wifi_native_Windows_Devices_WiFi_WiFiNetworkReport
{
    static const int FIELD___wifiNetworks = 1;


    //--//

};

extern const CLR_RT_NativeAssemblyData g_CLR_AssemblyNative_Windows_Devices_Wifi;

#endif //WIN_DEV_WIFI_NATIVE_TARGET_H
