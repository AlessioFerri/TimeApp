/*
 * Timer.cpp
 *
 *  Created on: 07 set 2016
 *      Author: alessio
 */

#include "Timer.h"
#include "MyWxTimer.h"

void Timer::zero() {

	seconds = 0;
	minutes = 0;
	hours = 0;
	initialized = false;
	notify();
}

void Timer::init(unsigned int h, unsigned int m, unsigned int s) {
	initialized = true;
	seconds = s;
	minutes = m;
	hours = h;
	notify();
}

void Timer::subscribe(Observer*o) {
	observers.push_back(o);
}

void Timer::unsubscribe(Observer*o) {
	observers.remove(o);
}

void Timer::OnTimer() {

	if (seconds == 0 && minutes == 0 && hours == 0) {
		notifyFinish();

	} else {

		if (seconds == 0) {

			if (minutes != 0) {
				minutes--;
				notify();
			}

			else if (hours != 0) {
				hours--;
				notify();
				minutes = 59;
				notify();
			}
			seconds = 59;
			notify();
		}
		seconds--;
		notify();

	}
}

void Timer::notify() {
	for (auto itr = observers.begin(); itr != observers.end(); itr++)
		(*itr)->update(hours, minutes, seconds);
}

void Timer::notifyFinish() {
	for (auto itr = observers.begin(); itr != observers.end(); itr++)
		(*itr)->updateFinish();
}

