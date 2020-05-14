cmake_minimum_required(VERSION 3.14)
project(ionc-example-system
        VERSION 1.0.0
        LANGUAGES C CXX)


add_definitions(-DDECNUMDIGITS=34) # for decNumber

find_package(IonC REQUIRED)

add_executable(app main.c)
target_link_libraries(app PRIVATE IonC::ionc) # dynamic

add_executable(sapp main.c)
target_link_libraries(sapp PRIVATE IonC::ionc_static IonC::decNumber_static m) # static
