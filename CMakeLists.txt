cmake_minimum_required(VERSION 3.10)
project(MarkOS_time)

add_library(${PROJECT_NAME}
        src/Clock.h
        src/Timer.cpp
        src/Timer.h
        src/TimerListener.h
        src/TimerTask.cpp
        src/TimerTask.h
        )

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_commons)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_cycle)
target_include_directories(${PROJECT_NAME} PUBLIC src)

add_subdirectory(test)