# 🔐 Login & Authentication System in C++

## 📌 Overview
This project is a console-based **Login & Authentication System** built in C++. It demonstrates the evolution from a basic in-memory authentication system to a more realistic **file-based persistent system**.

The project is divided into two distinct versions to showcase the transition from temporary data structures to persistent storage.

---

## 🚀 Features
* **User Registration:** Create a new account with unique credentials.
* **User Login:** Secure authentication against stored data.
* **Duplicate Validation:** Prevents multiple accounts with the same username.
* **Persistent Storage:** Data remains available even after the program closes (Version 2).
* **Clean Interface:** Simple, menu-driven console UI.

---

## 📦 System Versions

### 🔹 Version 1: Vector-Based System (`version1.cpp`)
* **Storage:** Uses `std::vector` (In-memory).
* **Pros:** Extremely fast execution.
* **Cons:** Data is temporary and lost once the program terminates.
* **Concepts:** Classes, Objects, STL Vectors, Loops, and Conditionals.

### 🔹 Version 2: File-Based System (`version2.cpp`)
* **Storage:** Uses `database.txt` (Hard drive).
* **Pros:** Data is persistent; simulates real-world backend behavior.
* **Cons:** Slower than memory access (File I/O overhead).
* **Concepts:** `ifstream`, `ofstream`, File Buffering, and Data Persistence.

---

## 📁 Project Structure
```text
📦 Login-System
┣ 📜 version1.cpp      # Vector-based login system
┣ 📜 version2.cpp      # File-based login system
┣ 📜 database.txt      # Stores credentials (auto-created)
┗ 📜 README.md         # Project documentation
```
---
# 🧠 Key Concepts & Technical Architecture

## 🛠 Concepts Covered
* **Object-Oriented Programming (OOP):** Encapsulating user data within specialized classes to ensure data integrity and modularity.
* **Standard Template Library (STL):** Utilizing `std::vector` for efficient, dynamic in-memory data management.
* **File Handling:** Managing data streams between the application and physical storage using `ifstream` and `ofstream`.
* **Authentication Logic:** Implementing robust search and match algorithms to verify identity.
* **System Design:** Analyzing and understanding the critical trade-offs between **Memory (Speed)** and **Disk (Persistence)** storage.

---

## 🔄 Program Flow

### 📝 Registration
1.  **Input:** User provides a new Username and Password.
2.  **Validation:** System performs a search to check for existing duplicates.
3.  **Storage:** * *Version 1:* Appends data to a `std::vector`.
    * *Version 2:* Appends data to `database.txt`.

### 🔑 Login
1.  **Input:** User enters credentials.
2.  **Search:** System performs a **Linear Search** through the storage medium.
3.  **Verification:** Compares input strings against stored records.
4.  **Outcome:** Access is either **Granted** (Success) or **Denied** (Failure).

---

## ⚠️ Security Note
> [!WARNING]
> **IMPORTANT:** Passwords in this project are stored in **plain text** for educational purposes. In a production environment, passwords should always be salted and hashed (e.g., using BCrypt or SHA-256) to prevent data exposure.

---

## 🔮 Future Improvements
- [ ] **Password Hashing:** Integrate SHA-256 for secure, non-reversible storage.
- [ ] **Validation Rules:** Enforce complexity requirements (special characters, length).
- [ ] **Account Management:** Implement "Forgot Password" and "Delete Account" functionality.
- [ ] **GUI Upgrade:** Transition from a Console UI to a graphical window using **Qt** or **SFML**.

---

## 👨‍💻 Author

**Muhammad Nauman** 

---

### ⭐ Support the Project
If you found this project helpful for your learning journey, consider giving it a **Star** to support the work!
