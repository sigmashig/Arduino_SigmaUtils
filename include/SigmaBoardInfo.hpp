#pragma once
#include <WiFi.h>
#include "SigmaLoger.hpp"

class SigmaBoardInfo
{
    public:
        static void Info(SigmaLoger *Log, SigmaLogLevel level = SIGMALOG_INTERNAL);
        static void WiFiInfo(SigmaLoger *Log, SigmaLogLevel level = SIGMALOG_INTERNAL);
        static String WiFiErrorMsg(int code);
};