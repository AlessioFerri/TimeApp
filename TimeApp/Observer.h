/*
 * Observer.h
 *
 *  Created on: 07 set 2016
 *      Author: alessio
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer{
public:
	virtual ~Observer(){}
	virtual void attach() = 0;
	virtual void detach() = 0;
	virtual void update(unsigned int h,unsigned int m,unsigned int s) = 0;
};



#endif /* OBSERVER_H_ */
