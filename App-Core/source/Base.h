#pragma once
#include <stdint.h>
#include <raylib.h>
#include <stdio.h>
#include <string>
#include <random>

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef bool b8;

#define DefWinWidth 1280
#define DefWinHeight 720
#define DefPlayerSize 50


#define V2_FMT "<%.3f, %.3f>\n"
#define V3_FMT "<%.3f, %.3f, %.3f>\n"
#define V4_FMT "<%.3f, %.3f, %.3f, %.3f>\n"

#define V2_OPEN(v) v.x, v.y
#define V3_OPEN(v) v.x, v.y, v.z
#define V4_OPEN(v) v.x, v.y, v.z, v.w


#define LEN(array) sizeof(array) / sizeof(array[0])