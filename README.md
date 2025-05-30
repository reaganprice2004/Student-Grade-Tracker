# 🎓 Student-Grade-Tracker (C)
**Timeline:** created November 2023

Welcome to my first C language mini-project --- a **Student Grade Tracker**, a simple and intuitive application to help students and teachers track academic performance efficiently. 

## 🚀 Features
- Add student names and assign grades
- View a list of all students with their grades
- Calculate and display the class average
- Save student data to `grades.txt`
- Load student data from `grades.txt` on startup

## 🔨 Built With
- **Language:** C (ANSI C standard)
- **File Handling:** Uses `grades.txt` to persist data
- **Compiler:** GCC or any standard C compiler

## 🧪 How to Run It Locally
Prerequisites:
- Linux/macOS: GCC via `sudo apt install gcc` or `brew install gcc`
- Windows: [MinGW](https://www.mingw-w64.org/) or use [WSL](https://learn.microsoft.com/en-us/windows/wsl/)

### 🧰 Compilation
'''bash
gcc -o grade_tracker grade_tracker.c
And run
./grade_tracker

## 🚀 How to Use
Upon launching the program, any saved data in `grades.txt` will be loaded automatically. You'll be presented with a menu:
<pre> 
1. Add student
2. View students
3. Class average
4. Save & Exit Choose:
</pre>
Just enter the number of the option that you would like to choose, and the code will react accordingly!

## 💡 Future Ideas
- Edit/delete students
- Sorting students: Could be done by alphabet, or by grade level
- Grade validation: Add stricter input validation (e.g., only accept grades between 0 and 100)
- GPA Calculator: Convert numeric grades to GPA values and display
- Statistics: Show additional stats like the highest and lowest grade, and grade distribution
- GUI Version: Create a graphical user interface version using a toolkit like GTK or ncurses

## 🤝 Contributions
Got cool ideas? Open a pull request or suggest a feature! I'd love to expand this into something more fun and interactive!

## 📚 License
MIT - Feel free to use, modify, whatever you feel like!
