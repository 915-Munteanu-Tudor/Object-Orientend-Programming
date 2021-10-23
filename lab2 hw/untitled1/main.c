#include "Ui.h"
#include <crtdbg.h>
#include <stdio.h>
#include "DinamicArray.h"

int main()
{
    run_cmd();
    testsDynamicArray();
	printf("There are %d memory leaks.", _CrtDumpMemoryLeaks());
    return 0;
}

