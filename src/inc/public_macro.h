#ifndef PUBLIC_MACRO_H
#define PUBLIC_MACRO_H

#define ITEM_OF(arr) static_cast<UINT32>(sizeof(arr)/sizeof(arr[0]))
#define INS(className) className::GetInstance()

#endif // PUBLIC_MACRO_H