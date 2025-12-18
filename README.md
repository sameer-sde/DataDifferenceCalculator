# Data Difference Calculator

A **C++ console application** that calculates the difference between two user-defined dates using the **Julian Day formula**. The program provides the **total number of days** between two dates and an **approximate difference in years, months, and days**. Results are saved automatically in a text file for future reference.

**GitHub Repository:** [https://github.com/sameer-sde/DataDifferenceCalculator](https://github.com/sameer-sde/DataDifferenceCalculator)

---

## Features

- Compute the difference between two dates.
- Shows total days and approximate difference in years, months, and days.
- Menu-driven interface:
  1. Compute new date difference
  2. View saved results
  3. Exit the program
- Input validation for correct dates.
- Automatically saves results in `DateDifferences.txt`.
- Built using **Object-Oriented Programming (OOP)** principles.

---

## Technologies Used

- **C++** (OOP)
- File handling for saving results
- Console-based user interface

---

## How to Run Locally

1. Clone the repository:

```bash
git clone https://github.com/sameer-sde/DataDifferenceCalculator.git
cd DataDifferenceCalculator
g++ main.cpp -o DataDifferenceCalculator.exe
.\DataDifferenceCalculator.exe
