# Cursor C Library

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Description

This library is inspired by functions from the deprecated `conio.h` file that is no longer available on Linux.

The Cursor C Library provides a set of functions for controlling and manipulating the cursor position on a text-based console. It includes functions such as `goto_xy`, `goto_x`, `goto_y`, `get_pos`, `get_x`, `get_y`, and `clrscr` that allow you to easily change and retrieve the cursor position, as well as clear the screen.

This library simplifies cursor manipulation, making it convenient to build text-based user interfaces, command-line applications, or any program that requires precise control over the cursor position.

## Installation

**Note: This library is designed only for Linux.**

To use the Cursor C Library in your project, follow these steps:

1. Clone this repository to your local machine or download the source code.
```shell
git clone https://github.com/m1ad3n/cursor.git
```

2. cd into the repository and make the library target
```shell
cd cursor
make library
```

3. Now install library file and header file
```shell
make install
```

## Usage
**Functions**
- `void goto_xy(int x, int y)`: Sets the cursor position to the specified coordinates (x, y).
- `void goto_x(int x)`: Sets the cursor position to the specified x-coordinate, keeping the y-coordinate unchanged.
- `void goto_y(int y)`: Sets the cursor position to the specified y-coordinate, keeping the x-coordinate unchanged.
- `void get_pos(int* x, int* y)`: Retrieves the current cursor position and stores it in the variables pointed to by x and y.
- `int get_x()`: Returns the current x-coordinate of the cursor.
- `int get_y()`: Returns the current y-coordinate of the cursor.
- `void clrscr()`: Clears the console screen.

## Example
Here's a simple example demonstrating the usage of the Cursor C Library:

```c
#include <stdio.h>
#include <cursor.h>

int main() {
    int x, y;

    // Clear the screen
    clrscr();

    // Get the current cursor position
    get_pos(&x, &y);
    printf("Current position: [%d, %d]\n", x, y);

    // Move the cursor to position (10, 5)
    goto_xy(10, 5);

    return 0;
}
```

This program clears the screen using the `clrscr` function, retrieves and prints the current cursor position and moves the cursor to position (10, 5).

## TODO
- [x] goto_xy
- [x] get_pos
- [ ] textcolor
- [ ] textbackground
- [ ] getch

## Contributing
Contributions to the Cursor C Library are welcome! If you find any issues or have suggestions for improvement, please feel free to open an issue or submit a pull request. Make sure to follow the project's coding conventions and provide detailed information about your changes.

## License
This project is licensed under the [MIT License](LICENSE)