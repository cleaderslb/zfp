#include <stdlib.h>
#include "include/zfp/types.h"
#include "hashBase.c"

// all functions are used to hash 32-bit valued arrays (int32, float)

static uint32
hashArray(const void* arr, int nx, int sx)
{
  uint32 h = 0;
  const int32* p;
  for (p = (int32*)arr; nx > 0; p += sx, nx--) {
    uint32 val = (uint32)(*p);
    hashValue(val, &h);
  }
  return hashFinish(h);
}

static uint32
hash2dStridedBlock(const void* arr, int sx, int sy)
{
  const int32* p = (int32*)arr;
  uint32 h = 0;
  uint x, y;
  for (y = 0; y < 4; p += sy - 4*sx, y++) {
    for (x = 0; x < 4; p += sx, x++) {
      uint32 val = (uint32)(*p);
      hashValue(val, &h);
    }
  }
  return hashFinish(h);
}

static uint32
hash3dStridedBlock(const void* arr, int sx, int sy, int sz)
{
  const int32* p = (int32*)arr;
  uint32 h = 0;
  uint x, y, z;
  for (z = 0; z < 4; p += sz - 4*sy, z++) {
    for (y = 0; y < 4; p += sy - 4*sx, y++) {
      for (x = 0; x < 4; p += sx, x++) {
        uint32 val = (uint32)(*p);
        hashValue(val, &h);
      }
    }
  }
  return hashFinish(h);
}
