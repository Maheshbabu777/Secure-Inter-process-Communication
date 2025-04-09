# **Secure Inter-Process Communication Framework**  

This project demonstrates a **Secure Inter-Process Communication (IPC)** framework implemented in **C++**. The project focuses on enhancing security during communication between processes using encryption, authentication, and process management. It follows a modular design with separate components for encryption, IPC mechanisms, and process/memory management.  

---

## **Project Structure**  

The project is organized into the following directories and files for better modularity and maintainability:  

### **1. `src/`**  
This directory contains the primary source code for implementing inter-process communication, encryption, and process management.  

- **`src/interprocess.cpp`**  
  Implements inter-process communication mechanisms such as shared memory, message queues, and pipes.  

- **`src/security.cpp`**  
  Contains encryption and decryption functions to secure communication between processes. The encryption uses XOR-based logic.  

- **`src/management.cpp`**  
  Includes functionality for process management and secure memory handling.  

---

### **2. `include/`**  
This folder contains the header files for each corresponding source file. The header files define function prototypes, classes, and constants used in the implementation.  

- **`include/interprocess.h`**  
  Declares functions related to IPC, including shared memory and message queue handling.  

- **`include/security.h`**  
  Contains declarations for encryption and decryption functions.  

- **`include/management.h`**  
  Provides function prototypes for managing processes and memory allocation.  

---

### **3. `main.cpp`**  
This is the entry point of the project. It initializes the secure IPC system and demonstrates the workflow by integrating the functions from `src/` and `include/`. This file handles the user input for testing encryption and IPC functionality.  

---

### **4. `index.html`**  
This file provides a simple HTML interface for testing the encryption and decryption mechanism in the browser. It allows users to input a message and view the encrypted and decrypted results.  

---

## **How to Run the Project Locally**  

### **Prerequisites**  
Ensure you have the following installed:  
- **g++ Compiler or Ubuntu and  install system libraries** (for compiling the C++ code)  
- **Git** (for cloning the repository)  

---

### **Steps to Clone and Compile**  

1. **Clone the Repository:**  
   Open your terminal and run:  

   ```bash  
   git clone https://github.com/MaheshBabu777/Secure-Inter-process-Communication.git  
   cd Secure-Inter-process-Communication
   ```
# **Compile the C++ Code**  
   Use the following command to compile the project:  
  
   ```bash  
   g++ -o secureIPC src/interprocess.cpp src/security.cpp src/management.cpp main.cpp  
   ./secureIPC
   ```
**Running the HTML Interface**  

To run the HTML interface, follow these steps:  

1. Open the `index.html` file located in the project folder with any modern browser (like **Chrome**, **Firefox**, or **Edge**).  

2. Enter the following authentication credentials and a message to test the encryption process:  

   - **Username:** `user1`  
     **Password:** `user@001`  

   **OR**  

   - **Username:** `user2`  
     **Password:** `user@002`  

3. The HTML page will display the **encrypted** and **decrypted** version of the input message after successful authentication.
# **Project Functionality**  

## **1. Authentication**  
The project uses simple **hardcoded authentication** for demonstration purposes. You can modify it in `main.cpp` or `index.html` as needed.  

## **2. Encryption and Decryption**  
The encryption used in the project follows an **XOR-based algorithm** with a predefined secret key:  

```cpp  
const string secretKey = "Security789@";
```
# **Project Structure (Summary)**  

```bash  
Secure-Inter-process-Communication/  
│  
├── src/  
│   ├── interprocess.cpp         
│   ├── security.cpp             
│   └── management.cpp          
│  
├── include/  
│   ├── interprocess.h           
│   ├── security.h                
│   └── management.h              
│  
├── main.cpp                       
├── index.html                   
└── README.md                    
```
# **Links**  

- **GitHub Repository:** [https://github.com/Maheshbabu777/Secure-Inter-process-Communication.git](#)  
- **Live Demo (Web Interface):** https://maheshbabu777.github.io/Secure-Inter-process-Communication/ 

This project is designed to demonstrate the principles of **secure inter-process communication**. You can further extend it by integrating more **complex IPC mechanisms**, enhancing **authentication**, or using more **advanced encryption techniques**.
