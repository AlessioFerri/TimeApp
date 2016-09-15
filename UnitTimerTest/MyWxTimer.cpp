/*
 * MyWxTimer.cpp
 *
 *  Created on: 13 set 2016
 *      Author: alessio
 */

#include "MyWxTimer.h"

void MyWxTimer::Notify(){
	timer->OnTimer();
}

