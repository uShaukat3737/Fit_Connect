# Fit Connect: Multi-User Gym & Fitness Management System

**Fit Connect** is a robust, console-based fitness tracking and gym management application engineered in C++. [cite_start]It utilizes advanced Object-Oriented Programming (OOP) paradigms and binary file persistence to provide a seamless, multi-role experience for gym members, professional trainers, and system administrators.

## 🚀 Key Features

### 👤 Regular User Interface
* **Comprehensive Tracking:** Log daily workouts including type, duration, intensity, and calories burnt.
* **Nutrition Logging:** Track daily meals and calorie intake for strict dietary management.
* **Progress Analysis:** Features a dynamic tier-based ranking system (Bronze to Champion) that calculates user progress based on workout consistency and intensity.
* **Social & Community:** Engage in a shared community forum and direct messaging with assigned personal trainers.
* **Location-Based Services:** Discover nearby gyms, nutrition stores, or "Workout Buddies" based on the user's registered location.
* **Gamified Challenges:** Complete daily fitness challenges (Situps, Pushups, Planks) to earn rank points and upgrade tiers.

### 👟 Trainer Interface
* **Client Management:** Access and monitor the list of assigned customers and their fitness data.
* **Professional Profile:** Manage availability timings and specialized package pricing.
* **Communication Hub:** Send direct feedback and workout instructions to clients through a dedicated chat system.

### 🔑 Admin Interface
* **System Oversight:** Authorized to view detailed profiles and logs (workout/nutrition) for all registered users and trainers.
* **Account Management:** Capability to manually add new users or trainers and moderate the community forum.

## 🛠️ Technical Implementation

### Core OOP Principles
* **Inheritance & Abstraction:** Implements a base abstract `Users` class inherited by `regUsers`, `Trainers`, and `Admin`.
* **Polymorphism:** Utilizes virtual functions for managing user totals and account-specific operations.
* **Encapsulation:** Protects sensitive data like passwords and emails using private/protected access modifiers.
* **Persistence:** All system data is managed via binary file handling (`.bin`), ensuring persistence across sessions.
* **Static Members:** Tracks global user counts using static class variables to ensure unique ID generation.

### 📂 File Architecture
* `users.bin`: Stores regular member account details.
* `trainers.bin`: Stores professional trainer profiles.
* `admin.bin`: Stores administrative credentials.
* `workout.bin` & `nLog.bin`: Houses individual fitness and dietary history.
* `forum.bin` & `messages.bin`: Manages community posts and private chat records.

## 💻 Technical Stack
* **Language:** C++ 
* **Paradigm:** Object-Oriented Programming (OOP)
* **Storage:** Binary File Handling (`fstream`) 
* **Design:** Modular header-based architecture

---
*Developed as an Object-Oriented Programming (CS2001) Project at FAST-NUCES.*
