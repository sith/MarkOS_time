//
// Created by Oleksandra Baukh on 1/22/18.
//

#ifndef MARKOS_TIMERTEST_H
#define MARKOS_TIMERTEST_H


#include <gtest/gtest.h>
#include <Cycle.h>
#include "MockClock.h"
#include "Timer.h"

class TimerTest : public ::testing::Test {
protected:
    void SetUp() override;

    void TearDown() override;

    Timer *timer;
    MockClock *clock;
    Cycle *cycle;
};


#endif //MARKOS_TIMERTEST_H
