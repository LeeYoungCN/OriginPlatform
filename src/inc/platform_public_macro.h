#ifndef PUBLIC_MACRO_H
#define PUBLIC_MACRO_H

#define TO_U16(num) static_cast<UINT16>(num)
#define TO_U32(num) static_cast<UINT32>(num)

#define U32_ITEM_OF(arr) TO_U32(sizeof(arr)/sizeof(arr[0]))
#define INS(className) className::GetInstance()

#define BIN_OK BinRet::OK
#define BIN_ERR BinRet::ERR

#define IS_OK(ret) (ret == BinRet::OK)
#define BOOL_TO_BIN_RET(boolVal) (boolVal ? BIN_OK : BIN_ERR)
#define RETURN_BIN_RET(boolVal) return BOOL_TO_BIN_RET(boolVal)
#define RETURN_ERR_IF_TRUE(boolVal) if (boolVal) {return BIN_ERR;}
#define RETURN_OK_IF_TRUE(boolVal)  if (boolVal) {return BIN_OK;}

#define GET_BIT(val, bitPos) ((val >> bitPos) & 0x1)
#define SET_BIT(val, bitPos) ((0x1 >> bitPos) | val)
#define RESET_BIT(val, bitPos) ((~(0x1 >> bitPos)) & val)

#define BOOL_OR(x, y) (x || y)
#define BOOL_AND(x, y) (x && y)
#define BOOL_NOR(x, y) (!(x || y))
#define BOOL_NAND(x, y) (!(x && y))
#define BOOL_XOR(x, y) ((x && !y) || (!x && y))

#endif // PUBLIC_MACRO_H