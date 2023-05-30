#include <Arduino.h>
#include "SigmaBoardInfo.hpp"
#include "SigmaLoger.hpp"

void SigmaBoardInfo::Info(SigmaLoger *Log, SigmaLogLevel level)
{
    Log->Append(F("CPU Freq: ")).Append(ESP.getCpuFreqMHz()).Log(level);
    Log->Append(F("Chip model: ")).Append(ESP.getChipModel()).Log(level);
    Log->Append(F("Chip Revision: ")).Append(ESP.getChipRevision()).Log(level);
    Log->Append(F("Number Core: ")).Append(ESP.getChipCores()).Log(level);
    Log->Append(F("Cycle Count: ")).Append(ESP.getCycleCount()).Log(level);
    Log->Append(F("Sdk Version: ")).Append(ESP.getSdkVersion()).Log(level);
    Log->Append(F("Flash Size: ")).Append(ESP.getFlashChipSize()).Log(level);
    Log->Append(F("Flash Speed: ")).Append(ESP.getFlashChipSpeed()).Log(level);
    Log->Append(F("Flash Mode: ")).Append(ESP.getFlashChipMode()).Log(level);
    Log->Append(F("Sketch Size: ")).Append(ESP.getSketchSize()).Log(level);
    Log->Append(F("Free Sketch Space: ")).Append(ESP.getFreeSketchSpace()).Log(level);
    Log->Append(F("Sketch MD5: ")).Append(ESP.getSketchMD5()).Log(level);
    Log->Append(F("Heap Size: ")).Append(ESP.getHeapSize()).Log(level);
    Log->Append(F("Free Heap: ")).Append(ESP.getFreeHeap()).Log(level);
    Log->Append(F("Max Alloc Heap: ")).Append(ESP.getMaxAllocHeap()).Log(level);
    Log->Append(F("Min Free Heap: ")).Append(ESP.getMinFreeHeap()).Log(level);
    Log->Append(F("Free Psram: ")).Append(ESP.getFreePsram()).Log(level);
    Log->Append(F("PsramSize: ")).Append(ESP.getPsramSize()).Log(level);
}

void SigmaBoardInfo::WiFiInfo(SigmaLoger *Log, SigmaLogLevel level)
{
    Log->Append(F("MAC: ")).Append(WiFi.macAddress()).Log(level);
    Log->Append(F("IP address: ")).Append(WiFi.localIP().toString()).Log(level);
    Log->Append(F("Gateway: ")).Append(WiFi.gatewayIP().toString()).Log(level);
    Log->Append(F("Subnet: ")).Append(WiFi.subnetMask().toString()).Log(level);
    Log->Append(F("DNS: ")).Append(WiFi.dnsIP().toString()).Log(level);
    Log->Append(F("Hostname: ")).Append(WiFi.getHostname()).Log(level);
    Log->Append(F("BSSID: ")).Append(WiFi.BSSIDstr()).Log(level);
    Log->Append(F("Channel: ")).Append(WiFi.channel()).Log(level);
    Log->Append(F("RSSI: ")).Append(WiFi.RSSI()).Log(level);
    Log->Append(F("SSID: ")).Append(WiFi.SSID()).Log(level);
    Log->Append(F("WiFi status: ")).Append(WiFi.status()).Log(level);
    Log->Append(F("WiFi Broadcast: ")).Append(WiFi.broadcastIP().toString()).Log(level);
    Log->Append(F("WiFi AutoReconnect: ")).Append(WiFi.getAutoReconnect()).Log(level);
    Log->Printf(F("WiFi StatusBits: %0x"), WiFi.getStatusBits()).Log(level);
}

String SigmaBoardInfo::WiFiErrorMsg(int code)
{

    if (code == WIFI_REASON_NO_AP_FOUND)
    {
        return F("WiFi lost connection because of AP not found");
    }
    else if (code == WIFI_REASON_AUTH_FAIL)
    {
        return F("WiFi lost connection because of authentication fail");
    }
    else if (code == WIFI_REASON_BEACON_TIMEOUT)
    {
        return F("WiFi lost connection because of response timeout");
    }
    else if (code == WIFI_REASON_HANDSHAKE_TIMEOUT)
    {
        return F("WiFi lost connection because of handshake timeout");
    }
    else if (code == WIFI_REASON_AUTH_EXPIRE)
    {
        return F("WiFi lost connection because of authentication expired");
    }
    else if (code == WIFI_REASON_ASSOC_EXPIRE)
    {
        return F("WiFi lost connection because of association expired");
    }
    else if (code == WIFI_REASON_NOT_AUTHED)
    {
        return F("WiFi lost connection because of authentication required");
    }
    else if (code == WIFI_REASON_NOT_ASSOCED)
    {
        return F("WiFi lost connection because of not associated");
    }
    else if (code == WIFI_REASON_ASSOC_LEAVE)
    {
        return F("WiFi lost connection because of association leaved");
    }
    else if (code == WIFI_REASON_ASSOC_NOT_AUTHED)
    {
        return F("WiFi lost connection because of associated is not authenticated");
    }
    else if (code == WIFI_REASON_DISASSOC_PWRCAP_BAD)
    {
        return F("WiFi lost connection because of WIFI_REASON_DISASSOC_PWRCAP_BAD");
    }
    else if (code == WIFI_REASON_DISASSOC_SUPCHAN_BAD)
    {
        return F("WiFi lost connection because of WIFI_REASON_DISASSOC_SUPCHAN_BAD");
    }
    else if (code == WIFI_REASON_IE_INVALID)
    {
        return F("WiFi lost connection because of WIFI_REASON_IE_INVALID");
    }
    else if (code == WIFI_REASON_MIC_FAILURE)
    {
        return F("WiFi lost connection because of WIFI_REASON_MIC_FAILURE");
    }
    String msg = F("WiFi lost connection because of unknown reason:");
    msg += String(code);
    return msg;
}
