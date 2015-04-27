## *Grunwald_CSCI2270_FinalProject*

# **Project Summary**
This is a linked list class that utilizes a circular doubly linked list and a sentinel node to implement a LIFO, FIFO and Alphabetized Priority Queue depending on what the user needs. The list can be initialized as any of the three linked list types and can be converted between any of the data types at any time. By converting from LIFO or FIFO to Alphabetized Priority Queue, the linked list will be alphabetized and the linked list connections will be reformatted. The push function will add the value it is run with in the appropriate position of the linked list based on its current typing, and the pop function will pop a value off of the linked list according to the typing of the linked list as well.The peek functions will return the values stroed in the node that would be popped off first and last respectively. The print function will print the contents of the linked list in the order they would be popped off with numerical representation of the depth from the sentinel node.

# **How To Run**
The class is contained in the llist.h header file and the llist.cpp file. llist.cpp has descriptions of each of the functions along with prototypes and pre and postconditions of the function. A driver file to test the code is included in the repository called llistDriverFile.cpp. To install the files on your machine, clone the repository to your machine. Compile the code in your editor of choice, making sure to link the driver file to the header file and the code file.

Run the driver file and a menu will come up with all of the public methods to test. I have written the driver file such that you cannot break the code by ignoring the preconditions of each function. For example, you cannot pop anything from the linked list if the list is empty, and you cannot do anything at all if the list is uninitialized. The driver file will also not accept non-numerical input when a number is expected.

# **Dependencies**
The only other libraries that the class uses are iostream and string but both are already included in the include statements of the header file and the driver file.

# **System Requirements**
Currently the class is known to work on Linux, but has been untested on any other OS.

# **Group Members**
Jacob Grunwald

# **Contributors**
None

# **Open Issues/Bugs**
None that I know of. 

I think a could good additions to the class would be a function that randomly pops a node out of the linked list and returns that nodes value. Another addition could be a search function for the class to check if a certain string is in the linked list already. One last thing I can think of for an addition would be a Reverse Alphabetized Priority Queue type for the linked list.
