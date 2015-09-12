#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>

typedef struct timer
{
	struct timeval start;
	struct timeval stop;
} timer;

void timer_start(timer *time);
void timer_stop(timer *time);
double timer_diff(timer *time);

#endif
