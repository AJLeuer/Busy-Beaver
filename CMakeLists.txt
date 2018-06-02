cmake_minimum_required(VERSION 3.10)
project(Busy_Beaver)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(Busy_Beaver
        src/Util/Util.cpp
        src/Model/BusyBeaverProgram.hpp
        src/Model/FourStateBusyBeaver.cpp
        src/Model/FourStateBusyBeaver.hpp
        src/Model/TuringMachine.cpp
        src/Model/TuringMachine.hpp
        src/Model/TwoStateBusyBeaver.cpp
        src/Model/TwoStateBusyBeaver.hpp
        src/main.cpp)
