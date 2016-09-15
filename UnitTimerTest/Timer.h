/*
 * Timer.h
 *
 *  Created on: 07 set 2016
 *      Author: alessio
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <wx/wx.h>
#include "Subject.h"
#include <list>

class Timer: public Subject {
public:
	Timer() {

		initialized = false;
		seconds = 0;
		minutes = 0;
		hours = 0;

	}

	virtual ~Timer() {
	}

	virtual void zero();
	virtual void init(unsigned int h, unsigned int m, unsigned int s);

	virtual void subscribe(Observer*o) override;
	virtual void unsubscribe(Observer*o) override;
	virtual void notify() override;
	virtual void notifyFinish() override;

	void OnTimer();

	bool isInitialized() const {
		return initialized;
	}

	void setInitialized(bool initialized) {
		this->initialized = initialized;
	}

protected:
	std::list<Observer*> observers;
	bool initialized;
	unsigned int hours, minutes, seconds;

};

#endif /* TIMER_H_ */
