add_executable(time_tests
        main.cpp
        MockTimerListener.h
        TimerTest.h
        TimerTest.cpp
        MockClock.h
        )

#Link with GoogleTest
target_link_libraries(time_tests gtest gtest_main)
#Link with GoogleMock
target_link_libraries(time_tests gmock gmock_main)

target_link_libraries(time_tests MarkOS_time)