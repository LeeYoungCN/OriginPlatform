#include "file_parser.h"
#include <stdlib.h>

FileDataParser *CreateFileDataParser(const char *fileName)
{
    FileDataParser *intPtr = (FileDataParser *)malloc(sizeof(FileDataParser));
    intPtr->init = Init;
    return intPtr;
}

int Init(FileDataParser *self)
{
    return 0;
}