


#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define SCH_MAX_TASKS (3)  /* Number of tasks */


/**
 * sTask data struct store all data associate with each task
 * 
 * pTasks: pointer to task function.
 * Delay:  Delay (ticks) until the function will (next) be run
 * Period: Interval (ticks) between subsequent runs..
 * RunMe:  Incremented (by scheduler) when task is due to execute.
 *
 */
typedef struct data
{
    // Pointer to the task (must be a 'void (void)' function)
    void (* pTask)(void);
    // Delay (ticks) until the function will (next) be run
    uint16_t Delay;
    // Interval (ticks) between subsequent runs.
    uint16_t Period;
    // Incremented (by scheduler) when task is due to execute
    uint8_t RunMe;
} sTask;


void SCHEDULER(void);



#endif
