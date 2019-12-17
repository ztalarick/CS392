//Zachary Talarick
//I pledge my honor that I have abided by the Stevens Honor System.

#ifndef __SIGNAL_H__
#define __SIGNAL_H__

#include <signal.h>

void my_signal(void);

static void handler(int sig, siginfo_t *siginfo, void*context);


#endif
