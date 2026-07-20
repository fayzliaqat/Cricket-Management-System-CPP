# 🏏 Cricket Management System C++

A menu-driven C++ console application built around cricket statistics, custom team registration, schedule viewing, trivia, and a hand-cricket mini game.

This was an early semester programming project created to practice C++ fundamentals such as functions, structures, vectors, arrays, file handling, random number generation, and console-based interaction.

---

## 📌 Project Overview

The **Cricket Management System** is a beginner-level C++ project that combines cricket information management with simple entertainment modules.

The application allows users to view ODI World Cup 2023 team statistics, register a custom playing eleven, read team and schedule information from text files, play a hand cricket game against the computer, attempt a cricket quiz, and view Pakistan cricket schedule details.

This is not a commercial cricket platform. It is an academic console-based project designed to demonstrate programming logic, file-based data handling, and modular function usage in C++.

---

## 🎯 Purpose of the Project

The goal of this project was to strengthen core programming concepts in C++ through a cricket-themed application. Instead of creating a small one-feature beginner program, this system combines multiple modules into one menu-based workflow.

The project helped practice:

- Writing reusable functions
- Designing a menu-driven program
- Reading data from external files
- Working with vectors and structures
- Handling user input
- Creating simple game logic
- Organizing a larger beginner-level C++ file

---

## ✨ Features

### 1. Main Menu Interface

The application starts with a console menu:

```text
1. Show Important Statistics of ODI CWC23
2. Register Your Own Team
3. Play Hand Cricket
4. Overview of Pakistan Team Schedule
5. Play Trivia/Quiz
6. Overview of upcoming ICC Events
7. Exit
```

### 2. ODI CWC23 Team Statistics

The program displays cricket statistics for selected international teams:

- Pakistan
- India
- England
- Australia

The data is stored in text files and loaded when the user selects the relevant team.

### 3. Custom Team Registration

Users can register their own playing eleven by entering player information. This module demonstrates user input handling, vectors, structures, loops, and formatted output.

### 4. Hand Cricket Game

The project includes a simple hand cricket game against the computer. It uses random number generation for computer choices and includes toss logic, batting/bowling flow, score calculation, and result display.

### 5. Cricket Trivia Quiz

The quiz module stores cricket-related questions and checks user answers. It demonstrates structure-based question storage, random question selection, validation logic, and score calculation.

### 6. Pakistan Schedule Viewer

The system reads Pakistan cricket schedule data from a text file and displays match type, opponent, date, time, and venue.

### 7. Upcoming ICC Events

The program also includes a section for upcoming ICC events using structured event data.

---

## 🛠️ Tech Stack

| Category | Technology |
|---|---|
| Programming Language | C++ |
| Interface | Console / Terminal |
| Storage | Text Files |
| Compiler | g++ / MinGW / Code::Blocks / Dev-C++ |
| Programming Style | Procedural + Structure-based C++ |

---

## 🧠 Concepts Used

- Functions and function prototypes
- Structures
- Vectors
- Arrays
- Loops and conditional statements
- Switch-case menu handling
- File input/output using `fstream`
- Random number generation using `cstdlib` and `ctime`
- String handling
- Console-based user interaction
- Basic game logic

---

## 📁 Project Structure

```text
Cricket-Management-System-CPP/
│
├── MAIN_FAF_PROJECT.cpp
├── PakistanSchedule.txt
├── PakistanTeamStats.txt
├── IndiaTeamStats.txt
├── EnglandTeamStats.txt
├── AustraliaTeamStats.txt
└── README.md
```

---

## 📄 Important Files

| File | Description |
|---|---|
| `MAIN_FAF_PROJECT.cpp` | Main C++ source file containing the full application logic |
| `PakistanSchedule.txt` | Pakistan cricket schedule dataset |
| `PakistanTeamStats.txt` | Pakistan team player statistics |
| `IndiaTeamStats.txt` | India team player statistics |
| `EnglandTeamStats.txt` | England team player statistics |
| `AustraliaTeamStats.txt` | Australia team player statistics |

---

## 🚀 How to Run Locally

### 1. Install a C++ Compiler

You can use MinGW, g++, Code::Blocks, Dev-C++, or VS Code with the C++ extension.

Check compiler installation:

```bash
g++ --version
```

### 2. Clone the Repository

```bash
git clone https://github.com/fayzliaqat/Cricket-Management-System-CPP.git
cd Cricket-Management-System-CPP
```

### 3. Compile the Code

```bash
g++ MAIN_FAF_PROJECT.cpp -o cricket_app
```

### 4. Run the Program

#### Windows

```bash
cricket_app.exe
```

#### macOS / Linux

```bash
./cricket_app
```

---

## ⚠️ Important Running Note

The project depends on external `.txt` files. Keep the data files in the same folder as the source code or executable.

If the text files are missing, moved, or renamed, the file-based modules may not display data correctly.

---

## 🧪 Example Program Flow

```text
--------------------------------------------
------ Cricket Management Application ------
--------------------------------------------

Enter your choice:
```

After selecting an option, the program opens the relevant module and displays output in the terminal.

---

## ✅ Current Status

This project is complete as a beginner-level C++ academic project. It works as a console application and demonstrates programming fundamentals through cricket-themed modules.

---

## ⚠️ Limitations

- Console-based only
- No graphical user interface
- No database integration
- Data is stored in simple text files
- Some inputs may require exact formatting
- The code is mostly procedural and can be improved using classes
- Error handling can be improved

---

## 🔮 Future Improvements

- Convert the project into a full OOP-based system
- Add better input validation
- Add file-writing support for custom teams
- Add a points table module
- Add player search functionality
- Add match simulation
- Add tournament management features
- Separate code into multiple source/header files
- Improve code readability and modular structure

---

## 👨‍💻 Author

**Fayz Liaqat**  
Artificial Intelligence Student
