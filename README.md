## 📌 Overview  
This project efficiently resolves overbooked flight scenarios by prioritizing passengers using a **binary heap-based priority queue** and managing waitlisted customers with a **stack**. The system calculates priority scores based on mileage, loyalty years, and booking sequence to determine boarding order.

---

## 🚀 Key Features  
- **Priority Queue Implementation**: Built using a max-heap to dynamically manage passenger priorities.
- **Real-time Priority Calculation**: Uses `Priority = (Mileage/1000) + Years - Sequence`.
- **Waitlist Stack**: Stores passengers who will receive tickets later in LIFO order.
- **Automated Sorting & Reporting**: Generates a detailed priority list and post-flight customer details.



