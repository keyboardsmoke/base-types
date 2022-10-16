#pragma once

// I wanted this header to work without any dependencies, conflicts or pollution
// It is based on stdint, and other headers like it
// The only bit of pollution that exists is the namespace
// I was going to make it configurable but just fork it, jeez man

    // Exact-width integer types
#if defined(_MSC_VER)
using i8 = __int8;
using u8 = unsigned __int8;
using i16 = __int16;
using u16 = unsigned __int16;
using i32 = __int32;
using u32 = unsigned __int32;
using i64 = __int64;
using u64 = unsigned __int64;

#if defined(__x86_64__) || defined(_M_AMD64) || defined(_M_ARM64) || defined(__aarch64__)
using imax = i64;
using umax = u64;
using iptr = i64;
using uptr = u64;
using isize = i64;
using usize = u64;
#elif defined(__i386__) || defined(_M_IX86) || defined(_M_ARM) || defined(__arm__)
using imax = i32;
using umax = u32;
using iptr = i32;
using uptr = u32;
using isize = i32;
using usize = u32;
#endif
#else
using i8 = signed char;
using u8 = unsigned char;
using i16 = short;
using u16 = unsigned short;
using i32 = int;
using u32 = unsigned int;
#if defined(__APPLE__)
using i64 = long;
using u64 = unsigned long long;
#else
using i64 = long long;
using u64 = unsigned long;
#endif

#if defined(__x86_64__) || defined(_M_AMD64) || defined(_M_ARM64) || defined(__aarch64__)
using imax = long int;
using umax = unsigned long long;
using iptr = long;
using uptr = unsigned long;
using isize = imax;
using usize = umax;
#elif defined(__i386__) || defined(_M_IX86) || defined(_M_ARM) || defined(__arm__)
using imax = long long int;
using umax = long long unsigned int;
using iptr = long;
using uptr = unsigned long;
using isize = imax;
using usize = umax;
#endif
#endif

// Extremely basic sanity checking
static_assert(sizeof(i8) == 1, "Invalid i8 size");
static_assert(sizeof(u8) == 1, "Invalid u8 size");
static_assert(sizeof(i16) == 2, "Invalid i16 size");
static_assert(sizeof(u16) == 2, "Invalid u16 size");
static_assert(sizeof(i32) == 4, "Invalid i32 size");
static_assert(sizeof(u32) == 4, "Invalid u32 size");
static_assert(sizeof(i64) == 8, "Invalid i64 size");
static_assert(sizeof(u64) == 8, "Invalid u64 size");

// I expect these to be able to hold pointers
static_assert(sizeof(uptr) == sizeof(void*), "Invalid uptr size");
static_assert(sizeof(iptr) == sizeof(void*), "Invalid uptr size");

// Some axioms here
static_assert(sizeof(umax) >= sizeof(uptr), "umax < uptr");
static_assert(sizeof(imax) >= sizeof(iptr), "imax < iptr");