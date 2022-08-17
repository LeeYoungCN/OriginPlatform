#ifndef PUBLIC_MACRO_H
#define PUBLIC_MACRO_H

#define TO_U16(num) static_cast<UINT16>(num)
#define TO_U32(num) static_cast<UINT32>(num)

#define U32_ITEM_OF(arr) TO_U32(sizeof(arr)/sizeof(arr[0]))
#define INS(className) className::GetInstance()

#define OP_OK BinRet::OK
#define OP_ERR BinRet::ERR

#define IS_OK(ret) (ret == BinRet::OK)

#endif // PUBLIC_MACRO_H