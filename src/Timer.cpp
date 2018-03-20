#include "Timer.h"

void Timer::addTimer(int milliseconds, TimerListener &timerListener) {
    tasks.get()->add(new TimerTask(clock->getTime() + milliseconds, &timerListener));
}

void Timer::onEvent(unsigned long cycleNumber) {
    auto iteratorPointer = tasks.get()->iterator();
    auto *iterator = iteratorPointer.get();
    long currentTime = clock->getTime();
    while (iterator->hasNext()) {
        auto timerTask = iterator->next();
        if (timerTask->isDone(currentTime)) {
            timerTask->getListener()->onEvent();
            TimerTask *doneTask = iterator->remove();
            delete doneTask;
        }
    }
}

Timer::Timer() = default;

Timer::Timer(Clock *clock) : clock(clock) {}

void Timer::removeTasksForListener(TimerListener &timerListener) {
    auto iteratorPointer = tasks.get()->iterator();
    Iterator<TimerTask> *iterator = iteratorPointer.get();
    while (iterator->hasNext()) {
        TimerTask *timerTask = iterator->next();
        if (timerTask->getListener() == &timerListener) {
            delete iterator->remove();
        }
    }
}

Timer::~Timer() {
}
