#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>
#include <stdlib.h>

/* Definition assert() function. */
#define configASSERT(x)                  if((x)==0) { for( ;; ); }
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configAPPLICATION_ALLOCATED_HEAP 0
#define configTOTAL_HEAP_SIZE            8192
#define PRIVILEGED_FUNCTION
#define portBYTE_ALIGNMENT               8
#define PRIVILEGED_DATA
#define portMAX_DELAY                    ( uint32_t ) 0xffffffffUL

#if portBYTE_ALIGNMENT == 32
    #define portBYTE_ALIGNMENT_MASK    ( 0x001f )
#elif portBYTE_ALIGNMENT == 16
    #define portBYTE_ALIGNMENT_MASK    ( 0x000f )
#elif portBYTE_ALIGNMENT == 8
    #define portBYTE_ALIGNMENT_MASK    ( 0x0007 )
#elif portBYTE_ALIGNMENT == 4
    #define portBYTE_ALIGNMENT_MASK    ( 0x0003 )
#elif portBYTE_ALIGNMENT == 2
    #define portBYTE_ALIGNMENT_MASK    ( 0x0001 )
#elif portBYTE_ALIGNMENT == 1
    #define portBYTE_ALIGNMENT_MASK    ( 0x0000 )
#else /* if portBYTE_ALIGNMENT == 32 */
    #error "Invalid portBYTE_ALIGNMENT definition"
#endif /* if portBYTE_ALIGNMENT == 32 */

/* Used to pass information about the heap out of vPortGetHeapStats(). */
typedef struct xHeapStats
{
    /* The total heap size currently available - this is the sum of all the free blocks, not the largest block that can be allocated. */
    size_t xAvailableHeapSpaceInBytes;
    /* The maximum size, in bytes, of all the free blocks within the heap at the time vPortGetHeapStats() is called. */
    size_t xSizeOfLargestFreeBlockInBytes;
    /* The minimum size, in bytes, of all the free blocks within the heap at the time vPortGetHeapStats() is called. */
    size_t xSizeOfSmallestFreeBlockInBytes;
    /* The number of free memory blocks within the heap at the time vPortGetHeapStats() is called. */
    size_t xNumberOfFreeBlocks;
    /* The minimum amount of total free memory (sum of all free blocks) there has been in the heap since the system booted. */
    size_t xMinimumEverFreeBytesRemaining;
    /* The number of calls to pvPortMalloc() that have returned a valid memory block. */
    size_t xNumberOfSuccessfulAllocations;
    /* The number of calls to vPortFree() that has successfully freed a block of memory. */
    size_t xNumberOfSuccessfulFrees;
} HeapStats_t;


size_t xPortGetFreeHeapSize(void);
void vPortGetHeapStats(HeapStats_t * pxHeapStats);
size_t xPortGetMinimumEverFreeHeapSize( void );

#define free vPortFree
void vPortFree( void * pv );
#define malloc pvPortMalloc
void * pvPortMalloc( size_t xWantedSize );
void head_init(void);

#endif
