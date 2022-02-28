#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

/* Parameters (default storage) */
typedef struct par_hysteresis_tag
{
    uint16_t off_limit;  /* parateter: off_limit */
    uint16_t on_limit;   /* parateter: on_limit */
    uint16_t output_on;  /* Computed Parameter: output_on */
    uint16_t output_off; /* Computed Parameter: output_off */
} par_hysteresis_t;

/* Model step function */
void lld_hysteresis_process(uint8_t *p_relay_mode, uint16_t *p_sig_in,
                            uint16_t *p_sig_out, const par_hysteresis_t *p_hysteresis_par)
{
    /* Relay: '<Root>/Relay' incorporates:
     *  Inport: '<Root>/sig_in'
     */
    if ((*p_sig_in) >= p_hysteresis_par->on_limit)
    {
        (*p_relay_mode) = 1U;
    }
    else
    {
        if ((*p_sig_in) <= p_hysteresis_par->off_limit)
        {
            (*p_relay_mode) = 0U;
        }
    }

    if (*p_relay_mode == 1U)
    {
        /* Outport: '<Root>/sig_out' */
        (*p_sig_out) = p_hysteresis_par->output_on;
    }
    else
    {
        /* Outport: '<Root>/sig_out' */
        (*p_sig_out) = p_hysteresis_par->output_off;
    }
}

const par_hysteresis_t test_config = {
    12U,
    20U,
    1U,
    0U};
uint8_t test_relay_mode;
uint16_t test_input;
uint16_t test_output;

int main(void)
{
    int i = 0;

    for (i = 0; i < 100; i++)
    {
        test_input = rand() % 100;

        lld_hysteresis_process(&test_relay_mode, &test_input, &test_output, &test_config);
        printf("%3d: %d ---> %d\n", i, test_input, test_output);
    }

    return 0;
}
