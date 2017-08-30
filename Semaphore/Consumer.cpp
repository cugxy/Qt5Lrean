#include "Consumer.h"
#include "comment.h"

Consumer::Consumer()
{
}

void Consumer::run()
{
	for (int i = 0; i < knDataSize; i++)
	{
		usedBytes.acquire();
		fprintf(stderr, "%d", buffer[i%knBufferSize]);
		if (i % 16 == 0 && i != 0)
			fprintf(stderr, "\n");
		freeBytes.release();
	}
	fprintf(stderr, "\n");
}
