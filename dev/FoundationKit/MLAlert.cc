/* -------------------------------------------

	Copyright ZKA Web Services Co

------------------------------------------- */

#include <FoundationKit/MLAlert.h>
#include <FoundationKit/MLApplication.h>

#include <cstdarg>
#include <cstdio>

#ifdef _WIN32
#define _WIN32_IE 0x0300

#include <FoundationKit/Win32/Win32.h>
#else
#include <FoundationKit/ZKA/ZKA.h>
#endif // ifdef _WIN32

#ifdef _WIN32
extern "C" int swprintf(
	wchar_t* const		 _Buffer,
	size_t const		 _BufferCount,
	wchar_t const* const _Format,
	...);
#endif // ifdef _WIN32

/// @brief Defines the alert modal for the MLKit.

MLAlert::MLAlert()	= default;
MLAlert::~MLAlert() = default;

/// @brief Shows a modal with title and message.
/// @param title the title.
/// @param format the message format.
/// @param va_list params of format.
/// @return if the user clicked ok.
bool MLAlert::runModal(const MLChar* title, const MLChar* format, ...)
{
	va_list va;
	va_start(va, format);

	MLChar msg[4096];

	vsnprintf(msg, 4096, format, va);

	va_end(va);

	auto isOk = !MLAlertBox(title, msg);

	return isOk;
}

/// @brief Shows an error modal with title and message.
/// @param title the title.
/// @param format the message format.
/// @param va_list params of format.
/// @return what the user choose.
int MLAlert::runErrorModal(const MLChar* title, const MLChar* format, ...)
{
	va_list va;
	va_start(va, format);

	MLChar msg[4096];

	vsnprintf(msg, 4096, format, va);

	va_end(va);

#ifdef _WIN32
	int isOk = ::MessageBoxA(nullptr, msg, title, MB_ABORTRETRYIGNORE | MB_ICONERROR);
#elif defined(__APPLE__)
	auto isOk = !MLAlertBox(msg, title);
#else
	auto isOk = !MLAlertBox(title, msg);
#endif

	return isOk;
}

/// @brief Shows a modal with no title.
/// @param message
/// @return
bool MLAlert::runModal(const MLChar* message)
{
#ifdef _WIN32
	return ::MessageBoxA(nullptr, message, MLApplication::shared().getAppName().asConstBytes(), MB_OK | MB_ICONINFORMATION) == IDOK;
#else
	return !::MLAlertBox(message, MLApplication::shared().getAppName().asConstBytes());
#endif
}

const MLString MLAlert::toString()
{
	constexpr auto cLen = 4096;

	MLString str = MLString(cLen);
	str += "{}";

	return str;
}