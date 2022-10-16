#pragma once

#if defined(__STDC__) || defined(_STDINT_H_INCLUDED) || defined(_STDINT_H) || defined(_PSTDINT_H_INCLUDED) || defined(_STDINT)
#error stdint already defined, why are you including stdint_types.hpp?
#else

// I wanted this header to work without any dependencies, conflicts or pollution
// It is based on stdint, and other headers like it
// The only bit of pollution that exists is the namespace
// I was going to make it configurable but just fork it, jeez man

// Exact-width integer types
#ifdef _MSC_VER
using int8_t = __int8;
using uint8_t = unsigned __int8;
using int16_t = __int16;
using uint16_t = unsigned __int16;
using int32_t = __int32;
using uint32_t = unsigned __int32;
using int64_t = __int64;
using uint64_t = unsigned __int64;

#if defined(__x86_64__) || defined(_M_AMD64) || defined(_M_ARM64) || defined(__aarch64__)
using intmax_t = int64_t;
using uintmax_t = uint64_t;
using intptr_t = int64_t;
using uintptr_t = uint64_t;
#if defined(__i386__) || defined(_M_IX86) || defined(_M_ARM) || defined(__arm__)
using intmax_t = int32_t;
using uintmax_t = uint32_t;
using intptr_t = int32_t;
using uintptr_t = uint32_t;
#endif
#else
using int8_t = signed char;
using uint8_t = unsigned char;
using int16_t = short;
using uint16_t = unsigned short;
using int32_t = int;
using uint32_t = unsigned int;
#ifdef __APPLE__
using int64_t = long;
using uint64_t = unsigned long long;
#else
using int64_t = long long;
using uint64_t = unsigned long;
#endif

#if defined(__x86_64__) || defined(_M_AMD64) || defined(_M_ARM64) || defined(__aarch64__)
using intmax_t = long int;
using uintmax_t = unsigned long long;
using intptr_t = long;
using uintptr_t = unsigned long;
#if defined(__i386__) || defined(_M_IX86) || defined(_M_ARM) || defined(__arm__)
using intmax_t = long long int;
using uintmax_t = long long unsigned int;
using intptr_t = long;
using uintptr_t = unsigned long;
#endif
#endif

// Extremely basic sanity checking
static_assert(sizeof(int8_t) == 1, "Invalid i8 size");
static_assert(sizeof(uint8_t) == 1, "Invalid u8 size");
static_assert(sizeof(int16_t) == 2, "Invalid i16 size");
static_assert(sizeof(uint16_t) == 2, "Invalid u16 size");
static_assert(sizeof(int32_t) == 4, "Invalid i32 size");
static_assert(sizeof(uint32_t) == 4, "Invalid u32 size");
static_assert(sizeof(int64_t) == 8, "Invalid i64 size");
static_assert(sizeof(uint64_t) == 8, "Invalid u64 size");

// I expect these to be able to hold pointers
static_assert(sizeof(uintptr_t) == sizeof(void*), "Invalid uintptr_t size");
static_assert(sizeof(intptr_t) == sizeof(void*), "Invalid intptr_t size");

// Some axioms here
static_assert(sizeof(uintmax_t) >= sizeof(uintptr_t), "uintmax_t < uintptr_t");
static_assert(sizeof(intmax_t) >= sizeof(intptr_t), "intmax_t < intptr_t");

#endif