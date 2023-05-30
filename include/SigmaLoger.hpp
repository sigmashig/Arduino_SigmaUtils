#pragma once
#include <Arduino.h>
#include <SafeString.h>

typedef enum
{
	SIGMALOG_OFF = 0,
	SIGMALOG_INTERNAL,
	SIGMALOG_FATAL,
	SIGMALOG_ERROR,
	SIGMALOG_WARN,
	SIGMALOG_INFO,
	SIGMALOG_DEBUG,
	SIGMALOG_ALL
} SigmaLogLevel;

typedef void (*SigmaLogPublisher)(SigmaLogLevel level, const char *message);
typedef const char *(*SigmaLogTimestamp)();

class SigmaLoger
{
public:
	SigmaLoger(int size, SigmaLogPublisher publisher = SigmaLoger::SerialPrint, SigmaLogTimestamp timestamp = SigmaLoger::Timestamp);
	// RmLoger &printf(const char *format, va_list args);
	SigmaLoger &Printf(const char *format, ...)
	{
		va_list args;
		va_start(args, format);
		SigmaLoger &p = printf(format, args);
		va_end(args);
		return p;
	};
	SigmaLoger &Printf(const __FlashStringHelper *format, ...)
	{
		va_list args;
		va_start(args, format);
		SigmaLoger &p = printf((const char *)format, args);
		va_end(args);
		return p;
	};

	SigmaLoger &Clear()
	{
		loger->clear();
		return *this;
	};
	SigmaLoger &Append(const SafeString &str)
	{
		loger->concat((SafeString &)str);
		return *this;
	};
	SigmaLoger &Append(int str)
	{
		loger->concat(str);
		return *this;
	};
	SigmaLoger &Append(long str)
	{
		loger->concat(str);
		return *this;
	};
	SigmaLoger &Append(unsigned int str)
	{
		loger->concat(str);
		return *this;
	};
	SigmaLoger &Append(unsigned long str)
	{
		loger->concat(str);
		return *this;
	};
	SigmaLoger &Append(double str)
	{
		loger->concat(str);
		return *this;
	};
	SigmaLoger &Append(const __FlashStringHelper *str)
	{
		loger->concat(str);
		return *this;
	};
	SigmaLoger &Append(const char *str)
	{
		loger->concat(str);
		return *this;
	};
	SigmaLoger &Append(String str)
	{
		loger->concat(str.c_str());
		return *this;
	};

	void Log(SigmaLogLevel level);
	void Info(const char *message = NULL)
	{
		if (message != NULL)
		{
			loger->concat(message);
		}
		Log(SIGMALOG_INFO);
	}
	void Info(const __FlashStringHelper *message)
	{
		loger->concat(message);
		Log(SIGMALOG_INFO);
	}

	void Warn(const char *message = NULL)
	{
		if (message != NULL)
		{
			loger->concat(message);
		}
		Log(SIGMALOG_WARN);
	}
	void Debug(const char *message = NULL)
	{
		if (message != NULL)
		{
			loger->concat(message);
		}
		Log(SIGMALOG_DEBUG);
	}
	void Error(const char *message = NULL)
	{
		if (message != NULL)
		{
			loger->concat(message);
		}
		Log(SIGMALOG_ERROR);
	}
	void Fatal(const char *message = NULL)
	{
		if (message != NULL)
		{
			loger->concat(message);
		}
		Log(SIGMALOG_FATAL);
	}
	void Internal(const char *message = NULL)
	{
		if (message != NULL)
		{
			loger->concat(message);
		}
		Log(SIGMALOG_INTERNAL);
	}
	void Warn(const __FlashStringHelper *message)
	{
		loger->concat(message);
		Log(SIGMALOG_WARN);
	}
	void Debug(const __FlashStringHelper *message)
	{
		loger->concat(message);
		Log(SIGMALOG_DEBUG);
	}
	void Error(const __FlashStringHelper *message)
	{
		loger->concat(message);
		Log(SIGMALOG_ERROR);
	}
	void Fatal(const __FlashStringHelper *message)
	{
		loger->concat(message);
		Log(SIGMALOG_FATAL);
	}
	void Internal(const __FlashStringHelper *message)
	{
		loger->concat(message);
		Log(SIGMALOG_INTERNAL);
	}

private:
	int size;
	char *loger_SAFEBUFFER;
	SafeString *loger;
	SigmaLogPublisher publisher;
	SigmaLogTimestamp timestamp;
	SigmaLoger &printf(const char *format, va_list args);

	static void SerialPrint(SigmaLogLevel level, const char *message);
	static const char *Timestamp();
};
extern SigmaLoger *Log;