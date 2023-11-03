#include "heap.h"
#include <stdio.h>

void report_heap_status(void)
{
    HeapStats_t status;

    vPortGetHeapStats(&status);

    printf("************ status of heap ************\n");
    printf("xAvailableHeapSpaceInBytes = %ld\n", status.xAvailableHeapSpaceInBytes);
    printf("xMinimumEverFreeBytesRemaining = %ld\n", status.xMinimumEverFreeBytesRemaining);
    printf("xNumberOfFreeBlocks = %ld\n", status.xNumberOfFreeBlocks);
    printf("xNumberOfSuccessfulAllocations = %ld\n", status.xNumberOfSuccessfulAllocations);
    printf("xNumberOfSuccessfulFrees = %ld\n", status.xNumberOfSuccessfulFrees);
    printf("xSizeOfLargestFreeBlockInBytes = %ld\n", status.xSizeOfLargestFreeBlockInBytes);
    printf("xSizeOfSmallestFreeBlockInBytes = %ld\n", status.xSizeOfSmallestFreeBlockInBytes);
}

int main(void)
{
    /* printf("start initialisation...\n"); */
    heap_init();
    /* int free_size_init = xPortGetFreeHeapSize(); */
    /* printf("xPortGetFreeHeapSize() = %d\n", free_size_init); */
    /* printf("prvHeapInit ram cost: %d\n", configTOTAL_HEAP_SIZE - free_size_init); */
    /* report_heap_status(); */

    printf("-----------------------------------------------------------------------------\n");
    printf("sizeof int is :%ld\n", sizeof(int));
    int free_size_before = xPortGetFreeHeapSize();
    printf("free memory size before malloc a int size: %d\n", free_size_before);
    int *a = malloc(sizeof(int));
    int free_size_after = xPortGetFreeHeapSize();
    printf("free memory size after malloc a int size = %d\n", free_size_after);
    printf("ram cost for a int malloc: %d\n", free_size_before - free_size_after);
    report_heap_status();


    printf("-----------------------------------------------------------------------------\n");
    printf("sizeof 2 int is :%ld\n", 2 * sizeof(int));
    free_size_before = xPortGetFreeHeapSize();
    printf("free memory size before malloc 2 int size: %d\n", free_size_before);
    int *b = malloc(2 * sizeof(int));
    free_size_after = xPortGetFreeHeapSize();
    printf("free memory size after malloc 2 int size = %d\n", free_size_after);
    printf("ram cost for 2 int malloc: %d\n", free_size_before - free_size_after);
    report_heap_status();

    printf("-----------------------------------------------------------------------------\n");
    printf("sizeof 8 int is :%ld\n", 8 * sizeof(int));
    free_size_before = xPortGetFreeHeapSize();
    printf("free memory size before malloc 8 int size: %d\n", free_size_before);
    int *c = malloc(8 * sizeof(int));
    free_size_after = xPortGetFreeHeapSize();
    printf("free memory size after malloc 8 int size = %d\n", free_size_after);
    printf("ram cost for 8 int malloc: %d\n", free_size_before - free_size_after);
    report_heap_status();
    free(a);
    report_heap_status();
    free(b);
    report_heap_status();
    free(c);
    report_heap_status();
    printf("heap size after free all blocks: %d\n", xPortGetFreeHeapSize());

    return 0;
}
