/**
 * @file types.h
 * @brief Various system types.
 */
#pragma once

#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t u8;   ///<  8-bit unsigned integer
typedef uint16_t u16; ///< 16-bit unsigned integer
typedef uint32_t u32; ///< 32-bit unsigned integer
typedef uint64_t u64; ///< 64-bit unsigned integer

typedef int8_t s8;   ///<  8-bit signed integer
typedef int16_t s16; ///< 16-bit signed integer
typedef int32_t s32; ///< 32-bit signed integer
typedef int64_t s64; ///< 64-bit signed integer

typedef volatile u8 vu8;   ///<  8-bit volatile unsigned integer.
typedef volatile u16 vu16; ///< 16-bit volatile unsigned integer.
typedef volatile u32 vu32; ///< 32-bit volatile unsigned integer.
typedef volatile u64 vu64; ///< 64-bit volatile unsigned integer.

typedef volatile s8 vs8;   ///<  8-bit volatile signed integer.
typedef volatile s16 vs16; ///< 16-bit volatile signed integer.
typedef volatile s32 vs32; ///< 32-bit volatile signed integer.
typedef volatile s64 vs64; ///< 64-bit volatile signed integer.

typedef u32 Handle;                 ///< Resource handle.
typedef s32 Result;                 ///< Function result.
typedef void (*ThreadFunc)(void *); ///< Thread entrypoint function.
typedef void (*voidfn)(void);

/// Creates a bitmask from a bit number.
#define BIT(n) (1U<<(n))

/// Aligns a struct (and other types?) to m, making sure that the size of the struct is a multiple of m.
#define ALIGN(m)   __attribute__((aligned(m)))

/// Packs a struct (and other types?) so it won't include padding bytes.
#define PACK     __attribute__((packed))

#define USED       __attribute__((used))
#define UNUSED     __attribute__((unused))

#ifndef LIBCTRU_NO_DEPRECATION
    /// Flags a function as deprecated.
    #define DEPRECATED __attribute__ ((deprecated))
#else
    /// Flags a function as deprecated.
    #define DEPRECATED
#endif

#define NAKED __attribute__((naked))
#define NORETURN __attribute__((noreturn))

#endif