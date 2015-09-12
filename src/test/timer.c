#include "timer.h"
#include <stdlib.h>


double timer_diff (timer *time)
{ 
  struct timeval diff;

  diff.tv_sec  = time->stop.tv_sec - time->start.tv_sec ;
  diff.tv_usec = time->stop.tv_usec - time->start.tv_usec;

  return (double)(diff.tv_sec + (double)diff.tv_usec / (double)1000000);
}

void timer_start (timer *time)
{
	gettimeofday(&time->start, NULL);
}

void timer_stop (timer *time)
{
	gettimeofday(&time->stop, NULL);
}

