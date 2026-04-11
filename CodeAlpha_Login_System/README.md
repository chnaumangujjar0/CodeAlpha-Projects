#🔐 Login & Authentication System in C++
#📌 Overview

This project is a console-based Login & Authentication System built in C++. It demonstrates the evolution from a basic in-memory authentication system to a more realistic file-based persistent system.

The project is divided into two versions:

Version 1: Uses vector (in-memory storage)
Version 2: Uses file handling (.txt database) for persistent storage

This showcases practical understanding of OOP, STL, and File Handling, which are essential for real-world backend systems.

##🚀 Features
✅ Common Features
User Registration (Sign Up)
User Login (Authentication)
Duplicate Username Validation
Simple Console Interface
Logout System
##📦 Version 1 – Vector-Based System (version1.cpp)
Stores users in a vector
Fast and simple implementation
Data is temporary (lost after program ends)
##💡 Concepts Used:
Classes & Objects
Vectors (STL)
Loops & Conditionals
##💾 Version 2 – File-Based System (version2.cpp)
Stores users in a file (database.txt)
Data is persistent (saved permanently)
Simulates real-world login systems
##💡 Concepts Used:
File Handling (ifstream, ofstream)
Data Persistence
Input/Output Streams
##📁 Project Structure
📦 Login-System
┣ 📜 version1.cpp → Vector-based login system
┣ 📜 version2.cpp → File-based login system
┣ 📜 database.txt → Stores user credentials (auto-created)
┗ 📜 README.md → Project documentation
##🧠 Concepts Covered
Object-Oriented Programming (OOP)
Data Structures (Vector)
File Handling in C++
Authentication Logic
Input Validation
System Design Basics
##🔄 Program Flow
🔹 Registration
Enter username
Check for duplicates
Save user (vector/file)
##🔹 Login
Enter credentials
Match with stored data
Grant or deny access
##💡 Learning Outcomes
Understood difference between temporary vs persistent storage
Implemented real-world authentication logic
Gained hands-on experience with file handling
Improved problem-solving and system design thinking
##⚠️ Note
Passwords are stored in plain text (for learning purposes only)
In real-world applications, passwords should be encrypted/hashed
##🔮 Future Improvements
Password encryption (hashing)
Username & password validation rules
Forgot password functionality
File-based user update/delete
GUI version
##👨‍💻 Author

Muhammad Nauman

##⭐ GitHub Note

If you found this project helpful, consider giving it a ⭐ to support the work!
