# Fit Connect: Multi-User Gym & Fitness Management System

**Fit Connect** is a robust, console-based fitness tracking and gym management application engineered in C++. [cite_start]It utilizes advanced Object-Oriented Programming (OOP) paradigms and binary file persistence to provide a seamless, multi-role experience for gym members, professional trainers, and system administrators.

## 🚀 Key Features

### 👤 Regular User Interface
* [cite_start]**Comprehensive Tracking:** Log daily workouts including type, duration, intensity, and calories burnt[cite: 143, 148].
* [cite_start]**Nutrition Logging:** Track daily meals and calorie intake for strict dietary management[cite: 151, 155].
* [cite_start]**Progress Analysis:** Features a dynamic tier-based ranking system (Bronze to Champion) that calculates user progress based on workout consistency and intensity[cite: 121].
* [cite_start]**Social & Community:** Engage in a shared community forum and direct messaging with assigned personal trainers[cite: 71, 106, 126].
* [cite_start]**Location-Based Services:** Discover nearby gyms, nutrition stores, or "Workout Buddies" based on the user's registered location[cite: 86, 123].
* [cite_start]**Gamified Challenges:** Complete daily fitness challenges (Situps, Pushups, Planks) to earn rank points and upgrade tiers[cite: 93, 125].

### 👟 Trainer Interface
* [cite_start]**Client Management:** Access and monitor the list of assigned customers and their fitness data[cite: 102].
* [cite_start]**Professional Profile:** Manage availability timings and specialized package pricing[cite: 80, 89, 91].
* [cite_start]**Communication Hub:** Send direct feedback and workout instructions to clients through a dedicated chat system[cite: 103, 104].

### 🔑 Admin Interface
* [cite_start]**System Oversight:** Authorized to view detailed profiles and logs (workout/nutrition) for all registered users and trainers[cite: 138, 141].
* [cite_start]**Account Management:** Capability to manually add new users or trainers and moderate the community forum[cite: 136].

## 🛠️ Technical Implementation

### Core OOP Principles
* [cite_start]**Inheritance & Abstraction:** Implements a base abstract `Users` class inherited by `regUsers`, `Trainers`, and `Admin`[cite: 51, 110, 131].
* [cite_start]**Polymorphism:** Utilizes virtual functions for managing user totals and account-specific operations[cite: 57, 58].
* [cite_start]**Encapsulation:** Protects sensitive data like passwords and emails using private/protected access modifiers[cite: 52, 54].
* [cite_start]**Persistence:** All system data is managed via binary file handling (`.bin`), ensuring persistence across sessions[cite: 60, 63, 65].
* [cite_start]**Static Members:** Tracks global user counts using static class variables to ensure unique ID generation[cite: 78, 87, 130].

### 📂 File Architecture
* [cite_start]`users.bin`: Stores regular member account details[cite: 63].
* [cite_start]`trainers.bin`: Stores professional trainer profiles[cite: 65].
* [cite_start]`admin.bin`: Stores administrative credentials[cite: 67].
* [cite_start]`workout.bin` & `nLog.bin`: Houses individual fitness and dietary history[cite: 140, 141].
* [cite_start]`forum.bin` & `messages.bin`: Manages community posts and private chat records[cite: 68].

## 💻 Technical Stack
* [cite_start]**Language:** C++ [cite: 45]
* [cite_start]**Paradigm:** Object-Oriented Programming (OOP) [cite: 50]
* [cite_start]**Storage:** Binary File Handling (`fstream`) [cite: 60]
* **Design:** Modular header-based architecture

---
*Developed as an Object-Oriented Programming (CS2001) Project at FAST-NUCES.*