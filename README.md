# RNA-tool

**RNA-tool** is a command-line application designed to convert chord progressions into roman numeral analysis and vice versa. It also allows transposition of chord progressions. 

I made this project mostly because I didn't want to spend a lot of time analyzing my own or other people's music, and my ears aren't trained to the point I could do it on the fly.

## Features

- **Chord to Roman Numeral Conversion:** Convert chord progressions into roman numeral analysis relative to a given key.
- **Roman Numeral to Chord Conversion:** Input a progression using roman numerals and have it converted to chords.
- **Transposition:** Easily transpose chord progressions by a specified number of semitones.
- **Interactive CLI:** A simple text-based interface to manipulate chord progressions.

## Planned Updates

- **Chord Inversions:** Support for chord inversions in both input and conversion.
- **Visual GUI:** A graphical user interface for a more intuitive experience.
- **Extended Analysis Options:** Additional analysis modes for minor keys, modal progressions, etc.
- **Improved Parsing:** Enhanced error detection and more flexible chord notation.

## Compilation Instructions

This project uses CMake (version 3.14 or later) and requires a C++17 compiler.

### Prerequisites

- [CMake](https://cmake.org/) (v3.14+)
- A C++ compiler supporting C++17 (e.g., GCC, Clang, or MSVC)
- [fmt](https://github.com/fmtlib/fmt) library installed on your system

### Build Steps

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/RNA-tool.git
   cd RNA-tool
   ```

2. **Create a build directory and navigate into it:**

   ```bash
   mkdir build
   cd build
   ```

3. **Run CMake configuration:**

   ```bash
   cmake ..
   ```

4. **Compile the project:**

   ```bash
   cmake --build .
   ```

5. **Run the executable:**

   On Linux/macOS:
   ```bash
   ./RNA-tool
   ```
   On Windows:
   ```bash
   RNA-tool.exe
   ```

## Usage Instructions

When you run the program, you will be prompted with the following options:

1. **Input Type Selection:**
   - Type `roman` if you want to enter a progression using roman numeral notation (e.g., `I vi IV V`).
   - Type `chords` if you prefer entering chord symbols (e.g., `C Am F G` or `C#m7 Gdim`).

2. **Enter the Key:**
   - Input the key (e.g., `C`, `C#`, `Db`, etc.).

3. **Enter the Progression:**
   - Type your progression tokens (space-separated).

4. **Operations:**
   - **Transpose:** Choose to transpose the progression by a specified number of semitones (input can be negative).
   - **Convert:** Convert between chord symbols and roman numeral analysis based on your initial input type.

5. **Next Steps:**
   - After each operation, you can choose to:
     - Continue with the current (possibly transposed) progression.
     - Reset to the original progression.
     - Input a new progression.
     - Exit the program.

The program is interactive and will guide you through these options via the command-line prompts.

## Developer Mode

For developers, additional install rules and developer-specific configurations can be enabled by setting the `RNA-tool_DEVELOPER_MODE` variable in your CMake configuration.

Enjoy using RNA-tool! Feel free to contribute or suggest improvements for upcoming features.


