/*
 * MyWxTimer.h
 *
 *  Created on: 13 set 2016
 *      Author: alessio
 */

#ifndef MYWXTIMER_H_
#define MYWXTIMER_H_
#include "Timer.h"

class MyWxTimer: public wxTimer {
public:
	MyWxTimer(Timer* t) :
			timer(t) {
	}

	virtual ~MyWxTimer() {
		delete timer;
	}

	void Notify() override;

protected:

	Timer*timer;
};

#endif /* MYWXTIMER_H_ */
