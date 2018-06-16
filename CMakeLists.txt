cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(BoostMQ VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS system REQUIRED)
add_library(boost INTERFACE IMPORTED)
set_property(TARGET boost PROPERTY
    INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

# 1-task-1
set(TASK_Q_PRODUCER ./1-task-q/producer.cpp)
add_executable(TaskQProducer ${TASK_Q_PRODUCER})
target_link_libraries(TaskQProducer LINK_PUBLIC ${Boost_LIBRARIES})

set(TASK_Q_CONSUMER ./1-task-q/consumer.cpp)
add_executable(TaskQConsumer ${TASK_Q_CONSUMER})
target_link_libraries(TaskQConsumer LINK_PUBLIC ${Boost_LIBRARIES})

set(TASK_Q_RESET ./1-task-q/reset.cpp)
add_executable(TaskQReset ${TASK_Q_RESET})
target_link_libraries(TaskQReset LINK_PUBLIC ${Boost_LIBRARIES})
