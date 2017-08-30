#include "product.h"
#include "comment.h"

Product::Product()
{
}

void Product::run()
{
	for (int i = 0; i < knDataSize; i++)
	{
		freeBytes.acquire();
		buffer[i%knBufferSize] = (i%knBufferSize);
		usedBytes.release();
	}
}
