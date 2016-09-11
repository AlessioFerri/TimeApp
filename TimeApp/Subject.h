/*
 * Subject.h
 *
 *  Created on: 07 set 2016
 *      Author: alessio
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_
#include "Observer.h"

class Subject{
public:
	virtual ~Subject(){}
	virtual void subscribe(Observer*o) = 0;
	virtual void unsubscribe(Observer* o) = 0;
	virtual void notify() = 0;

};



#endif /* SUBJECT_H_ */
