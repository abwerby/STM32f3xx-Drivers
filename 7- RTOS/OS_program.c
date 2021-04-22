/*
 * File:   OS_Programe.c
 * Author: abdelrhman
 *
 * This file contain the scheduler function implementation 
 * and the ISR function for the TIM0 and EXTI (RB0) pin.
 * 
 * Created on July 6, 2020, 11:39 AM
 */


#include <stdint.h>
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NUM_OVF 8
#define TIM0_PRELOAD_Value  48
#define NULL ((void *)0)

uint8_t num_ovf = 0;
sTask SCH_tasks_G[SCH_MAX_TASKS];
uint8_t SCH_state = SCH_STOP;
uint32_t SYS_TICK = 0;


/**
 * SCH_Add_Task()
 * Causes a task (function) to be executed at regular intervals
 * or after a user-defined delay
 * @param Pointer to function.
 * @param Delay time.
 * @param periodic time.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
uint8_t OS_Add_Task(void (* pFunction)(), const uint16_t DELAY, const uint16_t PERIOD)
{
    uint8_t Index = 0;
    // First find a gap in the array (if there is one)
    while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
    {
        Index++;
    }
    // Have we reached the end of the list?
    if (Index == SCH_MAX_TASKS)
    {
        return SCH_MAX_TASKS;
    }
    // If we're here, there is a space in the task array
    SCH_tasks_G[Index].pTask = pFunction;
    SCH_tasks_G[Index].Delay = DELAY;
    SCH_tasks_G[Index].Period = PERIOD;
    SCH_tasks_G[Index].RunMe = 0;
    return Index; // return position of task (to allow later deletion)
}

/**
 * SCH_Init_T0()
 * Scheduler initialization function. Prepares scheduler
 * data structures and sets up timer interrupts at required rate.
 * Must call this function before using the scheduler.
 * @param void.
 * @return void.
 */
void OS_Init(void)
{
    uint8_t i;
    for (i = 0; i < SCH_MAX_TASKS; i++)
    {
        OS_Delete_Task(i);
    }
    // Now set up Timer 0
    STK_Set_CallBack(SCHEDULER);
}

/*------------------------------------------------------------------*-
SCH_Delete_Task()
Removes a task from the scheduler. Note that this does
*not* delete the associated function from memory:
it simply means that it is no longer called by the scheduler.
TASK_INDEX - The task index. Provided by SCH_Add_Task().
RETURN VALUE: RETURN_ERROR or RETURN_NORMAL
-*------------------------------------------------------------------*/
uint8_t OS_Delete_Task(const uint8_t TASK_INDEX)
{
    uint8_t Return_code;
    if (SCH_tasks_G[TASK_INDEX].pTask == 0)
    {
        Return_code = RETURN_ERROR;
    }
    else
    {
        Return_code = RETURN_NORMAL;
    }
    SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
    SCH_tasks_G[TASK_INDEX].Delay = 0;
    SCH_tasks_G[TASK_INDEX].Period = 0;
    SCH_tasks_G[TASK_INDEX].RunMe = 0;
    return Return_code; 
}


/**
 * SCH_Dispatch_Tasks()
 * This is the 'dispatcher' function. When a task (function)
 * is due to run, SCH_Dispatch_Tasks() will run it.
 * This function must be called (repeatedly) from the main loop.
 * 
 * @param void.
 * @return void.
 */
void OS_Dispatch_Tasks(void)
{
    uint8_t Index;
    // Dispatches (runs) the next task (if one is ready)
    for (Index = 0; Index < SCH_MAX_TASKS; Index++)
    {
        if (SCH_tasks_G[Index].RunMe > 0)
        {
            (*SCH_tasks_G[Index].pTask)(); // Run the task
            SCH_tasks_G[Index].RunMe -= 1; // Reset / reduce RunMe flag
            // Periodic tasks will automatically run again
            // if this is a ' one shot ' task, remove it from the array
            if (SCH_tasks_G[Index].Period == 0)
            {
                OS_Delete_Task(Index);
            }
        }
    }
}

void OS_Stop(void)
{
    STK_Set_CallBack(NULL);
}

void SCHEDULER(void)
{
    for (uint8_t Index = 0; Index < SCH_MAX_TASKS; Index++)
    {
        // Check if there is a task at this location
        if (SCH_tasks_G[Index].pTask)
        {
            if (SCH_tasks_G[Index].Delay == 0)
            {
                // The task is due to run
                SCH_tasks_G[Index].RunMe += 1; // Inc. the 'RunMe' flag
                if (SCH_tasks_G[Index].Period)
                {
                    // Schedule periodic tasks to run again
                    SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            }
            else
            {
                // Not yet ready to run: just decrement the delay
                SCH_tasks_G[Index].Delay -= 1;
            }
        }
    }
}
