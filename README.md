# ✈️ Resolving Overbooked Flight 

**CSE207 Data Structures Project**  
*A Priority Queue & Stack Solution for Airline Waitlist Management*  

---


## 📌 Overview  
This project efficiently resolves overbooked flight scenarios by prioritizing passengers using a **binary heap-based priority queue** and managing waitlisted customers with a **stack**. The system calculates priority scores based on mileage, loyalty years, and booking sequence to determine boarding order.

---

## 🚀 Key Features  
- **Priority Queue Implementation**: Built using a max-heap to dynamically manage passenger priorities.
- **Real-time Priority Calculation**: Uses `Priority = (Mileage/1000) + Years - Sequence`.
- **Waitlist Stack**: Stores passengers who will receive tickets later in LIFO order.
- **File Handling**: Reads passenger details from a passengers.txt file.
- **Efficient Sorting**: Uses a priority queue to sort passengers dynamically.
- **Automated Sorting & Reporting**: Generates a detailed priority list and post-flight customer details.

##📂 Project Structure
📁 Resolving-Overbooked-Flight
│-- 📄 project_code.c  (Contains the priority queue & stack logic)
│-- 📄 passengers.txt  (Contains input passenger data)
│-- 📄 README.md  (Project description )




