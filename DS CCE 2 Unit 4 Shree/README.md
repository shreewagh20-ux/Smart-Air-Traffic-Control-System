# Website Menu System Using Tree Data Structure

## Project Overview

The Website Menu System is a C++ project that uses a tree data structure to represent a website's menus and submenus. It displays the complete menu hierarchy and allows users to add and search for menu items.

## Objectives

- Understand the tree data structure.
- Represent website menus and submenus hierarchically.
- Display the complete menu hierarchy.
- Add new submenus dynamically.
- Search for a menu item by name.
- Practice recursion and dynamic memory allocation.

## Data Structure Used

**General Tree:** A tree is a non-linear data structure consisting of nodes connected by edges. Each node can have multiple child nodes.

In this project:
- The root node represents the Website Menu.
- Child nodes represent main menu items.
- Further child nodes represent submenus.
- A vector of pointers stores the child nodes of each menu.

## Features

1. Display the complete menu hierarchy.
2. Add a submenu under an existing menu.
3. Search for a menu item by name.
4. Exit the program.
5. Manage menu items dynamically.

## Technologies Used

- Programming Language: C++
- Header Files: `iostream`, `string`, `vector`
- Concepts: General Tree, Pointers, Recursion, Dynamic Memory Allocation

## Project Structure

```text
WebsiteMenuSystem/
├── main.cpp
└── README.md
```

## How to Compile and Run

### Using GCC

1. Save the source code as `main.cpp`.
2. Open a terminal in the project folder.
3. Compile the program:

   ```bash
   g++ main.cpp -o menu
   ```

4. Run the executable.

   **Windows:**
   ```bash
   menu.exe
   ```

   **Linux/macOS:**
   ```bash
   ./menu
   ```

## Sample Menu Hierarchy

```text
Website Menu
|-- Home
|-- About Us
|-- Services
    |-- Web Development
    |-- App Development
    |-- SEO
|-- Products
    |-- Laptops
    |-- Mobile Phones
|-- Contact
```

## Time Complexity

Let `n` be the total number of menu nodes and `h` be the height of the tree.

- Display hierarchy: `O(n)`
- Search menu item: `O(n)` in the worst case.
- Add submenu: `O(n)` to find the parent, then amortized `O(1)` to append the new child.
- Space complexity: `O(n)` for storing the tree.

## Limitations

Submenus added during execution are stored in memory only. They are not saved to a file or database, so changes are lost when the program exits.

## Conclusion

This project demonstrates how a tree data structure can organize a website's menu system. It uses recursion to display and search the hierarchy and dynamic memory allocation to add new submenus. The project provides practical experience with non-linear data structures.
