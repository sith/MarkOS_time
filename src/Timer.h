//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef MARK1_TIMER_H
#define MARK1_TIMER_H


#include <collections/LinkedList.h>

#include "TimerListener.h"
#include "TimerTask.h"
#include "CycleListener.h"
#include "Clock.h"

class Timer : public mark_os::cycle::CycleListener {
    Pointer<List<TimerTask>> tasks{new LinkedList<TimerTask>()};
    Clock *clock;
public:

    Timer();

    Timer(Clock *clock);

    virtual ~Timer();

    void onEvent(unsigned long cycleNumber) override;

    void addTimer(int milliseconds, TimerListener &timerListener);

    void removeTasksForListener(TimerListener &timerListener);
};


#endif //MARK1_TIMER_H
