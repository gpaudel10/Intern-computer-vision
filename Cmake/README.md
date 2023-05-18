## Compiling C++ projects using Makefile and CMakeLists.txt

In this task I have learned more about what are makefiles and CMakeLists.txt. And compiled some simple c++ programs using the using both makefile as well as CMakeLists.txt. Also I have learned how to compile C++ programs with the g++ compiler provided by GCC, and how to use Make to automate the compilation process.

#### What is Cmake?
Cmake is a build system generator that can generate Makefiles or other build systems for a variety of platforms and compilers. It allows us to:
* structure and build C/C++ projects.
* Integrate third-party dependencies.
* Package projects.

So before get to the task, I have downloaded the CMake with the following command:
`sudo apt install cmake`

#### CMakeLists.txt 
CMakeLists.txt is the input file for CMake and describes the project's sources files, libraries, and other dependencies. It is more portbale and cross-platform alternative to Makefiles and allows for the greater flexibility in the configuring the build process. So I was provided the general syntax of CMakeList.txt as:

```
cmake_minimum_required(VERSION <version number>)

project(<project-name>)

add_library(<library-name> <library>)

add_executable(<executable-filename> <source-files>)

target_link_library(<executable-filename> MODE <library-name>)

target_include_directories(<executable-filename> MODE <path>)

include_directories(<path>)

find_package(<pkg-name>)

set(<variable-name> variable)


\\for conditions
if()  
endif() 

while()
endwhile()
```

And I had performed the following steps to compile the simple c++ code:

Step 1 : `mkdir simple_cmake_example` 
making the project directory.

Step 2 : create the main.cpp file in that directory.
`cd simple_cmake_example`
`code main.cpp`

```#include<iostream>

int main()
{

std::cout<<"helloooooooooo\n";
    return 0;
}
```

And to compile this main.cpp file use:

`g++ -o main main.cpp`
And run this as:  `./ main`

This is the simple way of compiling the code.
Now following the syntax as mentioned above I had first created the CMakeList.txt and performed as:

Step1:
```
cmake_minimum_required(VERSION 3.20)
project(practicecmake)
add_executable(main main.cpp)
```

Just adding the executable main.cpp file with `add_executable` with target(executable as main).

Step2:
`mkdir build` because sourcefile and build file should be seperated.

Step3:
To invoke cmake in the correct path use `cmake`.
And it generates the makefile and when we call the `make` it builds the project out of it by generating the object file.

Step4: 
Print to excute that object file as `./ main`

> "more to learn about adding libraries and subdirectories"



### Using Makefile

So makefile is a script that specifies the dependencies between the source files and how they should be compiled to create the final executable. It is used to automate the build process and can save a lot of time when working on the large projects with so many source files.

I have created the separated directory to practice makefile as: `mkdir simple_makefile_example`

With the general syntax provided for makefile as:

```<exectable-filename>: <dependent-filenames1>
     g++ <dependent-filenames1> -o <executable-filename>

<dependent-filename1>: <.cpp files>
     g++ <.cpp> -I/<include-path> -L<library-path> -l<library>

clean:
     rm *.o <other-files>

```
First of all I have created main.cpp where simple program with main function that create the message object as m and that message object calls `printMessage()`. Also has header file that provide the information to create the message object.


```
#include "message.h"
#include <cstdlib>

using namespace std;
int main()
{
    message m;
    m.printMessage();
    return 0;
}
```

And message.h contains the class as message, which has object that does not return anything.And it also has some files guard protecting the body from being included more than one time.

```

#ifndef MESSAGE_H
#define MESSAGE_H

class message{
    public:

    void printMessage();
};

#endif // MESSAGE_H
```
And lastly we have message.cpp that has message to print.

```
#include<iostream>
#include "message.h"

using namespace std;

void message::printMessage(){
    cout<<"this is makefile example\n";
}
```
Now makefile is created in the correct directory following the syntax as:

```
final: main.o message.o
	g++ main.o message.o -o final

main.o: main.cpp
	g++ -c main.cpp

message.o: message.cpp message.h
	g++ -c message.cpp

clean:
	rm *.o final
```    
Here I named the target as  `final` and the objects file main.o and message.o are if changed then they are recompiled into a single excutable `final` as `g++ main.o message.0 -o final`.
And at last `rm *.o` when invoked clean all the `.o` files.

So simply type `make` to create the object files and executable files. Finally type `./final` to see the result. Also I have explore more by changing the messages. 

**In this way i have learned basics of compiling the c++ projects using makefile and CMakeList.txt.** 
