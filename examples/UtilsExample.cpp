#include <Arduino.h>
#include <SigmaLoger.hpp>
#include <SigmaBoardInfo.hpp>

void my_publisher(SigmaLogLevel level, const char *message)
{
  // You can add any function here: send log to MQTT, to Serial, to SD card, etc.
  // You can add any filters based on level here
  Serial.printf("[%d] %s\n", level, message);
}

const char *my_timestamp()
{
  // You can add any function here: get timestamp from RTC, from NTP, etc.
  static char timestamp[16];
  sprintf(timestamp, "ts=%.3f", millis() / 1000.0);
  return timestamp;
}

void setup()
{
  Serial.begin(115200);
  Serial.println("--------------------");
  // The maximum length of one line is 512 chars. You have got an error when you try to add more chars.
  // But it will not crash an application
  SigmaLoger *sigmaLoger = new SigmaLoger(512, my_publisher, my_timestamp);
  sigmaLoger->Append(F("LOG1.Hello, ")).Append("World!").Debug();
  sigmaLoger->Debug("LOG1.Just a simple message");
  SigmaLogLevel level = SIGMALOG_INFO;
  sigmaLoger->Printf("LOG1.This is a %s message", "formatted").Log(level);

  // The second Loger with default settings:
  SigmaLoger *sigmaLoger2 = new SigmaLoger(512);
  sigmaLoger2->Append(F("LOG2.Hello, ")).Append("World!").Debug();
  sigmaLoger2->Debug("LOG2.Just a simple message");
  sigmaLoger2->Printf("LOG2.This is a %s message", "formatted").Log(level);

  // The third Loger with no log and no timestamp settings.
  // All the messages will be ignored
  SigmaLoger *sigmaLoger3 = new SigmaLoger(512, NULL, NULL);
  sigmaLoger3->Append(F("LOG3.Hello, ")).Append("World!").Debug();
  sigmaLoger3->Debug("LOG3.Just a simple message");
  sigmaLoger3->Printf("LOG3.This is a %s message", "formatted").Log(level);

// BoardInfo Examples
sigmaLoger2->Internal("----- BoardInfo -----");
SigmaBoardInfo::Info(sigmaLoger2);
sigmaLoger2->Internal("--------------------");
sigmaLoger2->Internal("----- WiFiInfo -----");
SigmaBoardInfo::WiFiInfo(sigmaLoger2);
sigmaLoger2->Internal("--------------------");
sigmaLoger2->Internal("----- WiFi Error -----");
sigmaLoger2->Internal(SigmaBoardInfo::WiFiErrorMsg(200).c_str());
}

void loop()
{
  // put your main code here, to run repeatedly:
}
