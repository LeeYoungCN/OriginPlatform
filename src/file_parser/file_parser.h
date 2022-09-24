#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>


#define MAX_FILE_NAME_LEN 256
#define MAX_KEY_STR_LEN 256
#define MAX_VAL_STR_LEN 256
#define MAX_KAY_VAL_DATA_NUM 100

#define CLASS_METHOD(intstPtr) (className *)(intstPtr)

typedef struct KeyValsData {
    const char key[MAX_KEY_STR_LEN];
    const char val[MAX_VAL_STR_LEN];
} KeyValsData;

typedef struct FileDataParser {
    const char fileName[MAX_FILE_NAME_LEN];
    KeyValsData container[MAX_KAY_VAL_DATA_NUM];
    unsigned int dataNum;
    int (*init)(FileDataParser *self);
    int (*readFile)(FileDataParser *self, const char *fileName);
} FileDataParser;

FileDataParser *CreateFileDataParser();
void DestroyFileDataParser(FileDataParser *instPtr);
int FileDataParserInit(FileDataParser *self, const char *fileName);


#ifdef __cplusplus
}
#endif
#endif // FILE_PARSER_H
