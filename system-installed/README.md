
# Using `ion-c` as an installed library 

Example "hello world" program that uses
[ion-c](https://github.com/amzn/ion-c).

The code show how to use CMake to build an executable that depends
on ion-c. The example builds the same code as two executables

1. A dynamically linked executable (`app`)
1. A statically linked executable (`sapp`)

Tested on manjaro unix. 

# Steps 

1. Check out [ion-c](https://github.com/amzn/ion-c) build and install 
    1. `git clone https://github.com/amzn/ion-c.git`
    1. `cd ion-c` 
    1. ./build-release.sh
    1. `cd build/release`
    1. `make`
    1. `sudo make install`
1. Check out tihs repository build and run 
    1. `git clone https://github.com/therapon/ion-c-examples.git`
    1. `cd ion-c-examples`
    1. `./build-release.sh`
    1. `./build/release/app` -- prints `hello world`
    1. `./build/release/sapp` -- prints `hello world`
