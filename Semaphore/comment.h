
#ifndef COMMENT
#define COMMENT

#include <QSemaphore>
#include <QThread>

const int knDataSize = 1000;
const int knBufferSize = 80;
int buffer[knBufferSize];

QSemaphore freeBytes(knBufferSize);
QSemaphore usedBytes(0);
#endif //COMMENT