🎓 CGPA Calculator System (Console-Based in C++)
📌 Overview

The CGPA Calculator System is a console-based C++ application designed to manage academic records and calculate both GPA (Grade Point Average) and CGPA (Cumulative Grade Point Average).

This project simulates a real-world academic system where students can input course details semester-wise and evaluate their overall academic performance.

🚀 Features
➕ Add courses with grade and credit hours
📋 View all courses of the current semester
💾 Save semester data
📊 Calculate GPA for a specific semester
🎯 Calculate overall CGPA (all semesters)
❌ Exit system
🧱 Project Structure
🔹 Course Class

Represents an individual course:

Course ID
Grade (0.0 – 4.0 scale)
Credit Hours
🔹 System Class

Core logic handler of the application:

Stores current semester courses
Stores all semesters using nested vectors
Performs GPA & CGPA calculations
🧠 Concepts Used
Object-Oriented Programming (OOP)
Classes & Objects
Constructors
Vectors (vector and vector<vector<>>)
Nested Data Structures
Loops & Conditional Logic
Real-world problem modeling
📐 GPA & CGPA Logic
✅ GPA Formula
GPA = Σ (grade × credit hours) / Σ (credit hours)
✅ CGPA Formula
CGPA = Σ (all semesters grade points) / Σ (all semesters credit hours)
🔄 Program Flow
Add courses for a semester
View entered courses
Save semester data
Repeat for multiple semesters
Calculate:
GPA (semester-wise)
CGPA (overall)
💡 Example Menu
1. Add Course
2. Show Courses
3. Save Semester Courses
4. Calculate GPA
5. Calculate CGPA
6. Exit
🎯 Learning Outcomes
Built a multi-level data management system
Learned how to use nested vectors for real-world data
Implemented weighted average calculations
Understood difference between GPA and CGPA
Improved problem-solving and system design skills
🔮 Future Improvements
Add grade letter system (A, B, C → GPA conversion)
Edit/Delete course functionality
File handling (save/load data)
GUI version (Qt / Web-based)
Semester-wise detailed report
👨‍💻 Author

Muhammad Nauman

⭐ GitHub Note

If you found this project helpful, consider giving it a ⭐ and sharing it!