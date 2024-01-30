---

# Pixel Art Animator

## Overview

Pixel Art Animator is a C++ project designed to create and animate pixel art using ASCII characters and XWindows graphics. It leverages object-oriented programming techniques, including the Observer pattern, to dynamically update the art as it changes state. The project includes a flexible system for adding graphical and textual elements to the animations, allowing for a wide range of creative possibilities.

## Building the Project

To build the project, you will need a C++14 compatible compiler and the X11 development libraries installed on your system. The project uses a Makefile for easy compilation.

### Dependencies

- C++14 compatible compiler (e.g., g++)
- X11 development libraries

### Compilation

Navigate to the project directory and use the Makefile provided:

```bash
make
```

This will compile the project using `g++`, with the output executable named `a4q3`.

### Running the Project

To run the project, execute the compiled binary:

```bash
./a4q3
```

## Key Techniques and Classes

### Observer Pattern

The project uses the Observer pattern to manage updates to the pixel art. Classes `Subject` and `Observer` define the core of this pattern, with `Studio` acting as a `Subject` and various components such as `addgraphics` and `addtext` implementing the `Observer` interface to receive updates.

### Decorator Pattern

The Decorator pattern is used to dynamically add functionality to the ASCII art. Classes derived from `decorator`, such as `filledbox`, `blinkingbox`, `movingbox`, and `maskbox`, add various effects to the base art defined by `AsciiArt`.

### ASCII Art and Animation

The `AsciiArt` class serves as the base for creating art pieces. Derived classes and decorators add text or graphical elements to the art. The `Studio` class manages the animation, utilizing a tick system to progress the animation state and using observer objects to update the display accordingly.

### Graphical Output

The project interfaces with the XWindow system for graphical output, managed by classes `Xwindow` and `addgraphics`. These allow the ASCII art to be rendered in a graphical window, with colors and shapes representing different ASCII characters.

### Textual Output

For textual output, the `addtext` observer class attaches to the `Studio` subject, rendering the ASCII art in the console as text, with various ASCII characters representing different elements of the pixel art.

## Cleaning Up

To clean up the build artifacts, run:

```bash
make clean
```

This command removes the object files, the executable, and dependency files generated during the build.

## Note

This README assumes you have a working knowledge of C++ and Unix-based systems. Ensure all necessary libraries are installed before compiling and running the project.

---
