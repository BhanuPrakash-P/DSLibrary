# DSLibrary
Library for data structures like LL, DLL

## LinkedList
source code is available under LL, DLL directories.
### Build
    ```cmake .. -B . -DCMAKE_C_FLAGS=-DDEBUG```
Makefile gets generated under build directoty. So, goto build directory and run ```make``` command.
This will compile the code and generate required libraries(libll.so, libdll.so) and sample application(sampleApp).

### Memory leaks
Since the libraries can not access application specific data, it is the responsibility of the application to free the memory before calling deinit function.
The following command can be used to check the memory leaks in sample application.
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./sampleApp 