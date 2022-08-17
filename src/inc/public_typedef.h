#ifndef PUBLIC_TYPEDEF_H
#define PUBLIC_TYPEDEF_H

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

struct OP_TimeSt {
    UINT32 year;
    UINT32 month;
    UINT32 day;
    UINT32 hour;
    UINT32 minute;
    UINT32 second;
};

#endif // PUBLIC_TYPEDEF_H