#include "stdio.h"
#include "stdint.h"

#define QUEUE_FALSE 0
#define QUEUE_TRUE 1

#define OVERWRITE_QUEUE QUEUE_TRUE
#define QUEUE_SIZE 10

typedef enum queue_rc_tag
{
    RC_SUCCESS = 0,
    RC_QUEUEEMPTY,
    RC_QUEUEFULL,
    RC_PARAMERROR
} queue_rc_t;

uint8_t queue_head;
uint8_t queue_tail = 0xFF;
uint8_t queue_count;
uint32_t data_queue[QUEUE_SIZE];

queue_rc_t enqueue_data(uint32_t *p_data)
{
    queue_rc_t rc = RC_SUCCESS;

    if ((OVERWRITE_QUEUE == QUEUE_TRUE) || (queue_count < QUEUE_SIZE))
    {
        if (queue_count < QUEUE_SIZE)
        {
            queue_count++;
            queue_tail++;
            if (queue_tail >= QUEUE_SIZE)
            {
                queue_tail = 0;
            }
            else
            {
                /* no code */
            }
        }
        data_queue[queue_tail] = *p_data;
    }
    else
    {
        rc = RC_QUEUEFULL;
    }

    return rc;
}

queue_rc_t dequeue_data(uint32_t *p_data)
{
    queue_rc_t rc = RC_SUCCESS;

    if (queue_count == 0)
    {
        rc = RC_QUEUEEMPTY;
    }
    else
    {
        *p_data = data_queue[queue_head];
        queue_head++;
        if (queue_head >= QUEUE_SIZE)
        {
            queue_head = 0;
        }
        else
        {
            /* no code */
        }
        queue_count--;
    }

    return rc;
}

int main(void)
{
    uint32_t num = 0U;
    uint32_t i = 0U;
    uint32_t read_data;

    for (i = 0; i < 15; i++)
    {
        enqueue_data(&num);
        num++;
    }

    for (i = 0; i < QUEUE_SIZE; i++)
    {
        printf("%d, ", data_queue[i]);
    }

    printf("\n");

    printf("try to read from queue...\n");

    while(RC_SUCCESS == dequeue_data(&read_data))
    {
        printf("%d, ", read_data);
    }

    printf("\n");

    return 0;
}

