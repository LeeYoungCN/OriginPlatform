#ifndef PLATFORM_PUBLIC_TYPEDEF_H
#define PLATFORM_PUBLIC_TYPEDEF_H

typedef char INT8;
typedef unsigned char UINT8;
typedef short int INT16;
typedef unsigned short int UINT16;
typedef int INT32;
typedef unsigned int UINT32;
typedef long long int INT64;
typedef unsigned long long int UINT64;

typedef void VOID;
typedef char CHAR;
typedef bool BOOL;

enum class BinRet : UINT8 {
    OK = 0,
    ERR
};

#endif // PLATFORM_PUBLIC_TYPEDEF_H