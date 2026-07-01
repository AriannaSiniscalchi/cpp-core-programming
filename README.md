# 🟦 C++ Core Programming Projects
*Computer Engineering Coursework • University of Bergamo (UniBG)*

---

### 💻 Overview
This repository contains a collection of software projects, algorithms, and academic laboratory assignments developed to establish a rock-solid foundation in `C++` programming. The codebase tracks the complete first-semester curriculum: moving from procedural programming fundamentals and control flows to pointer manipulation, in-memory data records, and an introduction to non-linear hierarchical data structures (Binary Trees).

---

### 🛠️ Technical Stack & Core Concepts

| Category | Topics Implemented |
| :--- | :--- |
| **🟢 Procedural Logic** | Control structures (`switch-case`), iterative loops (`do-while`, `while`), code modularization via custom functions, and parameter passing. |
| **🔵 Data Structures** | Single-dimensional arrays, matrix manipulation, custom data records, and in-memory relational databases using `struct`. |
| **🟠 Memory & Pointers** | Advanced low-level string manipulation using pointer arithmetic (`char *`) and dynamic memory allocation (`new`). |
| **🟡 Advanced Concepts** | Non-linear hierarchical data structures, node allocation, and recursive tree traversal algorithms (Binary Trees). |

---

### 📂 Detailed File Index

Below is a comprehensive breakdown of each source file included in this repository, highlighting its core functionality and technical implementation details.

#### 📄 Calcolatrice.cpp
* **Description:** A CLI application simulating an interactive menu-driven calculator. It processes three user-defined variables within strict boundaries and performs fundamental arithmetic operations.
* **Technical Focus:** Comprehensive `switch-case` handling, explicit type casting (`static_cast<double>`), decimal output formatting using `fixed` and `setprecision`, and deterministic error prevention for division-by-zero scenarios.

#### 📄 Convertitore_temperature.cpp
* **Description:** A utility program designed to automatically generate Celsius-to-Fahrenheit conversion tables based on a user-defined range and incremental step size.
* **Technical Focus:** Formal and robust input validation (enforcing absolute zero limits and upper thresholds) paired with symmetric tabular formatting via `<iomanip>` and `setw`.

#### 📄 Array.cpp
* **Description:** A suite of statistical and mathematical algorithms applied to a static array of 50 elements, dynamically generated within a predefined range ($1 - 100$).
* **Technical Focus:** Maximum and minimum value lookup algorithms, arithmetic mean calculation, mode computation (using frequency/occurrence mapping arrays), and absolute mathematical threshold filtering using `fabs()`.

#### 📄 Strings.cpp
* **Description:** A menu-driven application for low-level string manipulation, featuring string reversing, uppercase conversions, whitespace removal, and word counting.
* **Technical Focus:** Pointer arithmetic applied to legacy C-style strings (`char *`), strict null-terminator (`\0`) lifecycle management, and direct character manipulation using ASCII values.

#### 📄 Structs_1.cpp
* **Description:** A lightweight, in-memory simulation of a university relational database designed to map logical connections between student records and academic exam scores.
* **Technical Focus:** Compound data structure definition (`struct`), arrays of structures, nested loops for database querying using logical primary keys (Matricola), and robust input buffer clearing via `cin.ignore`.

#### 📄 List.cpp *(Binary Tree)*
* **Description:** A from-scratch implementation of a non-linear hierarchical data structure (a Binary Tree of integers) complete with depth-first traversal algorithms.
* **Technical Focus:** Dynamic memory allocation via structure pointers (`Node *`), recursive link establishment (`left`, `right`), and recursive traversal methodologies to print leaf nodes and root components.
