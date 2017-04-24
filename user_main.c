/*
 * user_main.c
 *
 *  Created on: 6.02.2015 ã.
 *      Author: Svetlin
 */
#define DEBUG
#undef DEBUG							// comment for DEBUG
#define USE_US_TIMER					// set to usec timer

#include <c_types.h>
#include <ip_addr.h>
#include <ets_sys.h>
#include <espconn.h>
#include <osapi.h>
#include <mem.h>
#include <gpio.h>
#include <os_type.h>
#include <user_interface.h>
#include "user_config.h"
// mul machine includes
#include "globals.h"					// will include ProcessorSpecific.h
#include "mySubroutines.c"
#include "ESPuart.c"
#include "ESPWiFi.c"
#include "ESPdevice.c"
#include "ESPfile.c"
#include "ProcessorSpecific.c"
#include "math$Expressions.c"
#include "mul.c"


#define SIG 0
#define user_procTaskPrio        0
#define user_procTaskQueueLen    1
os_event_t    user_procTaskQueue[user_procTaskQueueLen];
static void user_procTask(os_event_t *events);

static volatile os_timer_t main_timer;

static void user_procTask(os_event_t *events)								// try not to ICACHE!
{
	u8 i;
	if (mode.f.R ) {												//&& mode.f.W||| && !EP2outBD.UOWN for USB machine
	   // toUSB(m_program[h],0,h);
		u8 *g= myStreams[reqPipe0].txPipe.val+*myStreams[reqPipe0].txPipe.len;
		while(*myStreams[reqPipe0].txPipe.len < MAX_BUFFER && r_len>0){
			*g++=*h++;
			(*myStreams[reqPipe0].txPipe.len)++;
			r_len--;
		}
		if(*myStreams[reqPipe0].txPipe.len>0) myStreams[reqPipe0].state=PIPE_SEND;
		if(r_len==0){
			if(*myInterfaces[INTERFACES_NUM - 1].closeInterface>0)(*myInterfaces[INTERFACES_NUM - 1].closeInterface)(INTERFACES_NUM - 1);
			mode.f.R = 0;
		}
	}
	//TRACE_DEBUG("|\r\n");
	if(~ ME_BUSY){																// prevent overlap execution
		ME_BUSY=TRUE;
		doIns();
		mul();
	   for(i=0; i<sizeof(RANGE)*8; i++){                                       // Try to send if some pipe miss to send in code
		   if(myStreams[i].state==PIPE_SEND) {
			   //TRACE_DEBUG("send%d\r\n",i);
			   u8 u=myStreams[i].intf_num;
			   if(myInterfaces[u].state == INTF_CONNECT)(*myInterfaces[u].sendInterface)(i);
		   }
		}
		ME_BUSY=FALSE;
	}
}

//Init function
void ICACHE_FLASH_ATTR user_init()
{
	//system_update_cpu_freq(160);
	system_timer_reinit();
	ETS_GPIO_INTR_DISABLE();                                            // Disable gpio interrupts
	wifi_station_set_auto_connect(0);									// Disable auto connect on power on
	wifi_set_sleep_type(NONE_SLEEP_T);

#ifdef DEBUG
	system_set_os_print(1);
#else
	system_set_os_print(0);
#endif

    os_timer_disarm(&main_timer);                                       // Disarm main timer
    os_timer_setfn(&main_timer, (os_timer_func_t *) doTimers, NULL); 	// Setup main timer
    os_timer_arm_us(&main_timer, 250, 1);                               // Arm main timer, 0.25 uSec, repeat

    HDinit();															// Processor specific; Must open Pipe0!
#ifdef USE_FS
    initFS();															// file system
#endif
    mulInit();															// in mul

    //Start os task
    system_os_task(user_procTask, user_procTaskPrio,user_procTaskQueue, user_procTaskQueueLen);

    // Startup done
}
