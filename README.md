Smart Air Traffic Control System

1. Project Overview

The Smart Air Traffic Control System is a menu-driven C++ application designed to manage aircraft records at an airport. It allows users to add aircraft details, view flight schedules, search for specific flights, update flight statuses, and delete aircraft records.

This project demonstrates the practical application of Data Structures, particularly Singly Linked Lists, for dynamic memory management and record handling.

2. Objectives

- To maintain aircraft and flight schedule records efficiently.
- To implement a singly linked list in C++.
- To perform insertion, searching, traversal, updating, and deletion operations.
- To manage dynamically allocated memory.
- To provide a simple, interactive, menu-driven interface.

3. Features

- Add Aircraft: Enter flight ID, airline name, destination, operation, runway number, and status.
- Display Aircraft Schedule: View all registered aircraft records.
- Search Aircraft: Find an aircraft using its unique flight ID.
- Update Aircraft Status: Modify the current status of a flight.
- Delete Aircraft: Remove an aircraft record from the system.
- Duplicate ID Prevention: Prevents adding aircraft with an existing flight ID.
- Memory Management: Frees allocated memory when the application exits.

4. Technologies Used

- Programming Language: C++
- Data Structure: Singly Linked List
- Libraries: "iostream", "string"
- Concepts: Structures, pointers, dynamic memory allocation, functions, loops, and switch-case statements.

5. Data Structure Used

Singly Linked List

The project uses a singly linked list to store aircraft records dynamically. Each node contains the aircraft's information and a pointer to the next node.

Each node stores:

- Flight ID
- Airline name
- Destination
- Operation (Landing/Departure)
- Runway number
- Flight status
- Pointer to the next aircraft node

The "head" pointer points to the first node in the list. If no aircraft records exist, "head" is "nullptr".

6. Operations and Time Complexity

Operation| Time Complexity
Add Aircraft| O(n)
Display Aircraft| O(n)
Search Aircraft| O(n)
Update Aircraft Status| O(n)
Delete Aircraft| O(n)
Clear All Records| O(n)

Here, "n" represents the number of aircraft records stored in the linked list.

7. How to Run the Project

Requirements

- A C++ compiler such as GCC or MinGW
- An IDE or code editor such as Visual Studio Code, Code::Blocks, or Dev-C++

Steps

1. Save the source code in a file named "main.cpp".
2. Open a terminal in the directory containing the file.
3. Compile the program using:

g++ main.cpp -o air_traffic_control

4. Run the compiled program.

Windows:

air_traffic_control.exe

Linux/macOS:

./air_traffic_control

8. Menu Options

When the program starts, the following menu is displayed:

1. Add Aircraft
2. Display Aircraft Schedule
3. Search Aircraft
4. Update Aircraft Status
5. Delete Aircraft
6. Exit

Enter the corresponding number to perform an operation.

9. Limitations

- Aircraft records are stored only in memory.
- All records are lost when the program terminates.
- The system does not automatically detect runway conflicts.
- It does not connect to real airport systems or provide live flight information.
- Input validation is limited.

10. Future Scope

- Integrate file handling or a database for permanent record storage.
- Implement priority-based scheduling for emergency aircraft.
- Detect runway scheduling conflicts.
- Add arrival and departure time management.
- Develop a graphical user interface.
- Introduce automated alerts and more advanced scheduling algorithms.

11. Conclusion

The Smart Air Traffic Control System demonstrates how a singly linked list can be used to manage aircraft records through basic data structure operations. The project provides practical experience with pointers, dynamic memory allocation, searching, insertion, deletion, and traversal in C++.

It serves as an educational prototype for understanding how computer-based systems can organize and manage aircraft scheduling information.



Project Type: Data Structures and Algorithms
Language: C++
Primary Data Structure: Singly Linked List
