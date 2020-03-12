#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pmu.h"


#define GET_ID_DATA_NPSS(data)      ((uint8_t *)(data))[263] 
#define GET_ID_APSTA(data)          ((uint8_t *)(data))[265] 
#define  GET_ID_PS_ADDR(data)       (&((uint8_t *)(data))[2048])

void pynvme_pmu_init(struct pynvme_pmu *pmu,  void *id_data,uint32_t npss)
{
    pmu->npss = GET_ID_DATA_NPSS(id_data);
    pmu->apsta = GET_ID_APSTA(id_data);
    memcpy(pmu->ps, GET_ID_PS_ADDR(id_data),  pmu->npss * sizeof(struct pynvme_power_state ))
}

/*
*   return  device reported  entry latencyin ms
*/
uint32_t pynmve_got_entry_latency(struct pynvme_pmu *pmu, uint8_t ps)
{
    return 0;
}


/*
*   return  device reported  exit latencyin ms
*/
uint32_t pynmve_got_exit_latency(struct pynvme_pmu *pmu, uint8_t ps)
{

    return 0;
}


/*
*   return  tested  entry latencyin ms
*/
uint32_t pynmve_got_test_entry_latency(struct pynvme_pmu *pmu, uint8_t ps)
{

    return 0;
}


/*
*   return  tested  exit latencyin ms
*/
uint32_t pynmve_got_test_exit_latency(struct pynvme_pmu *pmu, uint8_t ps)
{

    return 0;
}


/*
*   return  device reported max power in mW  
*/
uint32_t pynvme_got_max_power(struct pynvme_pmu *pmu, uint8_t ps)
{

    return 0;
}


/*
*   return max power test result  in mW  
*/
uint32_t pynvme_got_tested_max_power(struct pynvme_pmu *pmu, uint8_t ps)
{

    return 0;
}


/*
*   return device reported active power  in mW  
*/
uint32_t pynvme_got_active_power(struct pynvme_pmu *pmu, uint8_t ps)
{

    return 0;
}


/*
*   return active power test result  in mW  
*/
uint32_t pynvme_got_tested_active_power(struct pynvme_pmu *pmu, uint8_t ps)
{

    return 0;
}

/*
*   return device reported idle power  in mW  
*/
uint32_t pynvme_got_idle_power(struct pynvme_pmu *pmu, uint8_t ps)
{

    return 0;
}


/*
*   return active power test result  in mW  
*/
uint32_t pynvme_got_tested_idle_power(struct pynvme_pmu *pmu, uint8_t ps)
{
    return 0;
}