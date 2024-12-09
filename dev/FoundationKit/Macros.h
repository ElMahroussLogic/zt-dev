/* -------------------------------------------

	Copyright (C) 2024, Amlal EL Mahrouss, all rights reserved.

------------------------------------------- */

#pragma once

#define ML_INLINE inline
#define ML_CONST  const
#define ML_STATIC static

#define ML_DEPRECATED __attribute__((deprecated))

#ifdef __x86_64__
#define ML_AMD64	1
#define ML_PLATFORM "AMD64"
#endif

#ifdef __aarch64__
#define ML_ARM64	1
#define ML_PLATFORM "ARM64"
#endif

#if !defined(OBJC_BOOL_DEFINED) && !defined(_WIN32)
#define BOOL bool

#define YES true
#define NO	false
#endif // if !defined(OBJC_BOOL_DEFINED)  || !defined(_WIN32)

#if defined(_WIN32)
#define YES true
#define NO	false
#endif // defined(_WIN32)

#define kMathPI (3.14159265358979323846)
#define kMathEuler (2.718281828459045235360287471352)

#define ML_OBJECT : public MLObject

#define ML_UNUSED(X) ((void)(X))

#ifndef ML_PACKED
#if defined(__TOOLCHAINKIT__)
#define ML_PACKED __attribute__((packed))
#define ML_EXPORT __attribute__((libexport))
#define ML_IMPORT __attribute__((libimport))
#else
#define ML_PACKED
#define ML_EXPORT
#define ML_IMPORT
#endif
#endif // ifndef PACKED

#ifndef __cplusplus
#define ML_EXTERN_C extern
#else
#define ML_EXTERN_C extern "C"
#endif

typedef char				   MLChar;
typedef unsigned char		   MLUtf8Char;
typedef wchar_t				   MLUtf16Char;
typedef int					   MLInteger;
typedef long long int		   MLInteger64;
typedef unsigned char		   MLInteger8;
typedef unsigned int		   MLUnsignedInteger;
typedef unsigned long long int MLUnsignedInteger64;
typedef long long int		   MLLong;
typedef void*				   MLPointer;
typedef long long int		   MLSizeType;
typedef double				   MLReal;

#define ML_MUST_PASS(X)                   \
	if (!(X))                             \
	{                                     \
		MLAssert(#X, __FILE__, __LINE__); \
	}

#define ML_COPY_DELETE(KLASS)                \
	KLASS& operator=(const KLASS&) = delete; \
	KLASS(const KLASS&)			   = delete;

#define ML_COPY_DEFAULT(KLASS)                \
	KLASS& operator=(const KLASS&) = default; \
	KLASS(const KLASS&)			   = default;

#define ML_MOVE_DELETE(KLASS)           \
	KLASS& operator=(KLASS&&) = delete; \
	KLASS(KLASS&&)			  = delete;

#define ML_MOVE_DEFAULT(KLASS)           \
	KLASS& operator=(KLASS&&) = default; \
	KLASS(KLASS&&)			  = default;
