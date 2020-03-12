#ifndef _PYNVME_PMU_H_
#define  _PYNVME_PMU_H_

#include <stdint.h>

struct pynvme_power_state 
{
	uint16_t mp;				/* bits 15:00: maximum power */

	uint8_t reserved1;

	uint8_t mps		    : 1;		/* bit 24: max power scale */
	uint8_t nops		: 1;		/* bit 25: non-operational state */
	uint8_t reserved2	: 6;

	uint32_t enlat;				/* bits 63:32: entry latency in microseconds */
	uint32_t exlat;				/* bits 95:64: exit latency in microseconds */

	uint8_t rrt		    : 5;		/* bits 100:96: relative read throughput */
	uint8_t reserved3	: 3;

	uint8_t rrl		    : 5;		/* bits 108:104: relative read latency */
	uint8_t reserved4	: 3;

	uint8_t rwt		    : 5;		/* bits 116:112: relative write throughput */
	uint8_t reserved5	: 3;

	uint8_t rwl		    : 5;		/* bits 124:120: relative write latency */
	uint8_t reserved6	: 3;

	uint8_t reserved7[16];
};
SPDK_STATIC_ASSERT(sizeof(struct pynvme_power_state) == 32, "Incorrect size");

struct pynvme_pmu
{
    struct   pynvme_power_state ps[32];
    uint8_t  npss;
    uint8_t  apsta:1;
    uint8_t  apste:1;
    uint8_t  nopme:1;
    uint8_t  apste:1;
    uint8_t  reserved:4;
};


#endif // _PYNVME_PMU_H_
