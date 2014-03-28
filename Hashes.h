#pragma once

#include "Types.h"

#include "MurmurHash1.h"
#include "MurmurHash2.h"
#include "MurmurHash3.h"

//----------
// These are _not_ hash functions (even though people tend to use crc32 as one...)

void sumhash               ( const void * key, int len, uint32_t seed, void * out );
void sumhash32             ( const void * key, int len, uint32_t seed, void * out );

void DoNothingHash         ( const void * key, int len, uint32_t seed, void * out );
void crc32                 ( const void * key, int len, uint32_t seed, void * out );

void randhash_32           ( const void * key, int len, uint32_t seed, void * out );
void randhash_64           ( const void * key, int len, uint32_t seed, void * out );
void randhash_128          ( const void * key, int len, uint32_t seed, void * out );

//----------
// Cryptographic hashes

void md5_32                ( const void * key, int len, uint32_t seed, void * out );
void sha1_32a              ( const void * key, int len, uint32_t seed, void * out );
#if 0
void sha1_64a              ( const void * key, int len, uint32_t seed, void * out );
void sha2_32a              ( const void * key, int len, uint32_t seed, void * out );
void sha2_64a              ( const void * key, int len, uint32_t seed, void * out );
void BLAKE2_32a            ( const void * key, int len, uint32_t seed, void * out );
void BLAKE2_64a            ( const void * key, int len, uint32_t seed, void * out );
void bcrypt_64a            ( const void * key, int len, uint32_t seed, void * out );
void scrypt_64a            ( const void * key, int len, uint32_t seed, void * out );
#endif

//----------
// General purpose hashes

#ifdef __SSE2__
void hasshe2_test          ( const void * key, int len, uint32_t seed, void * out );
#endif
#if defined(__SSE4_2__) && defined(__x86_64__)
void crc32c_hw_test        ( const void * key, int len, uint32_t seed, void * out );
void crc32c_hw1_test       ( const void * key, int len, uint32_t seed, void * out );
void crc64c_hw_test        ( const void * key, int len, uint32_t seed, void * out );
void CityHashCrc128_test   ( const void * key, int len, uint32_t seed, void * out );
#endif
void FNV32a                ( const void * key, int len, uint32_t seed, void * out );
void FNV64a                ( const void * key, int len, uint32_t seed, void * out );
void Bernstein             ( const void * key, int len, uint32_t seed, void * out );
void SuperFastHash         ( const void * key, int len, uint32_t seed, void * out );
void lookup3_test          ( const void * key, int len, uint32_t seed, void * out );
void MurmurOAAT_test       ( const void * key, int len, uint32_t seed, void * out );
void Crap8_test            ( const void * key, int len, uint32_t seed, void * out );
void CityHash128_test      ( const void * key, int len, uint32_t seed, void * out );
void CityHash64_test       ( const void * key, int len, uint32_t seed, void * out );

void SpookyHash32_test     ( const void * key, int len, uint32_t seed, void * out );
void SpookyHash64_test     ( const void * key, int len, uint32_t seed, void * out );
void SpookyHash128_test    ( const void * key, int len, uint32_t seed, void * out );

uint32_t MurmurOAAT ( const void * key, int len, uint32_t seed );

//----------
// MurmurHash2

void MurmurHash2_test      ( const void * key, int len, uint32_t seed, void * out );
void MurmurHash2A_test     ( const void * key, int len, uint32_t seed, void * out );

//-----------------------------------------------------------------------------
// Test harnesses for Murmur1/2

inline void MurmurHash1_test ( const void * key, int len, uint32_t seed, void * out )
{
  *(uint32_t*)out = MurmurHash1(key,len,seed);
}

inline void MurmurHash2_test ( const void * key, int len, uint32_t seed, void * out )
{
  *(uint32_t*)out = MurmurHash2(key,len,seed);
}

inline void MurmurHash2A_test ( const void * key, int len, uint32_t seed, void * out )
{
  *(uint32_t*)out = MurmurHash2A(key,len,seed);
}

inline void MurmurHash64A_test ( const void * key, int len, uint32_t seed, void * out )
{
  *(uint64_t*)out = MurmurHash64A(key,len,seed);
}

inline void MurmurHash64B_test ( const void * key, int len, uint32_t seed, void * out )
{
  *(uint64_t*)out = MurmurHash64B(key,len,seed);
}