#include <windows.h>

#ifndef hr_timer
#include "hr_time.h"
#define hr_timer
#endif

void startTimer(stopWatch *timer) {
	QueryPerformanceCounter(&timer->start);
}

void stopTimer(stopWatch *timer) {
	QueryPerformanceCounter(&timer->stop);
}

double LIToSecs(LARGE_INTEGER * L) {
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	return ((double)L->QuadPart / (double)frequency.QuadPart);
}
double getElapsedTime(stopWatch *timer) {
	LARGE_INTEGER time;
	time.QuadPart = timer->stop.QuadPart - timer->start.QuadPart;
	return LIToSecs(&time);
}