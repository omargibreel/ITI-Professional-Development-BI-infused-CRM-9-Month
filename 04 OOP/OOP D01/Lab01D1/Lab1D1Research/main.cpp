#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;


//5-[search]
///on turnary operator ()?value1:value2;
        //if(don)
        //condition ? expression_if_true : expression_if_false;
        //The ternary operator returns a value based on a condition: if the condition is true , it returns the first value; otherwise, it returns the second value.


///[Report] dynamic vs. static linking
    /*                           static linking                                 dynamic linking

  definition ------>            the process of combining all                    the process of linking external libraries
                                necessary library routines and                  and references at runtime
                                external reference into a single                , when the program is loaded or executed
                                executable file at compile-time
                                I THINK at compilation time


  linking time --->             Occurs at compile-time. 	                    Occurs at runtime.



  file size ------>             Generally larger file size, as all              Smaller file size, as libraries are
                                required libraries are included                 linked dynamically at runtime.
                                in the executable.


  flexibility ---->             Less flexible, as any updates or changes        More flexible, as libraries
                                to the libraries require recompilation and      can be updated or replaced
                                relinking of the entire program. 	            without recompiling the program.


  performance ---->             Faster program startup and direct execution,    Slightly slower program startup due to the
                                as all libraries are already linked.            additional linking process, but overall performance
                                                                                impact is minimal.

  example -------->             Executables with file extensions like           Executables with file extensions like
                                .exe, .elf, .a, .lib, etc.                      .dll, .so, .dylib, etc.


    */

    return 0;
}
