# Clinic System

A command-line clinic management system implemented in C that provides patient management and appointment scheduling functionality. The system uses a custom hash table implementation for efficient data storage and retrieval.

## Features

### Admin Mode
- **Patient Management**: Add and edit patient information
- **Appointment Scheduling**: Reserve and cancel appointment slots
- **Secure Access**: Admin login required for administrative functions

### User Mode
- **Patient Information**: View patient details by ID
- **Appointment Viewing**: Check current reservations and slot availability

### Technical Features
- **Hash Table Implementation**: Custom hash table for efficient data storage
- **Dynamic Memory Management**: Proper memory allocation and deallocation
- **Modular Design**: Separated into logical modules (main, functions, hashtable)

## Project Structure

```
Clinic-System/
├── main.c          # Main program entry point and menu system
├── functions.c     # Implementation of clinic operations
├── functions.h     # Function prototypes and Patient struct definition
├── hashtable.c     # Custom hash table implementation
├── hashtable.h     # Hash table interface and data structures
├── main.exe        # Compiled executable (Windows)
└── README.md       # This file
```

## Installation

### Prerequisites
- GCC compiler (GNU Compiler Collection)
- Windows/Linux/macOS operating system

### Compilation

To compile the project, use the following command:

```bash
gcc main.c functions.c hashtable.c -o main.exe
```

This will create an executable file named `main.exe` (on Windows) or `main` (on Linux/macOS).

## Usage

### Running the Program

1. Compile the source code using the command above
2. Run the executable:
   ```bash
   ./main.exe
   ```

### Program Interface

The program provides a menu-driven interface with two main modes:

#### Main Menu
- **1) Admin Mode**: Access administrative functions
- **2) User Mode**: Access user functions
- **0) Exit**: Close the program

#### Admin Mode
- **1) Add**: Add a new patient to the system
- **2) Edit**: Modify existing patient information
- **3) Reserve**: Schedule an appointment slot
- **4) Cancel**: Cancel an existing reservation
- **0) Back**: Return to main menu

#### User Mode
- **1) View Patient**: Look up patient information by ID
- **2) View Reservations**: Display current appointment schedule
- **0) Back**: Return to main menu

## Data Structures

### Patient Structure
```c
typedef struct {
    int id;           // Unique patient identifier
    char name[50];    // Patient name
    int age;          // Patient age
    char gender;      // Gender ('M' or 'F')
    int slot;         // Appointment slot (-1 if no reservation, 0-4 for slots)
} Patient;
```

### Hash Table
The system uses a custom hash table implementation with:
- Dynamic resizing based on collision count
- Separate chaining for collision resolution
- Configurable hash and comparison functions

## Features in Detail

### Patient Management
- Add new patients with ID, name, age, and gender
- Edit existing patient information
- Unique patient IDs for identification

### Appointment System
- 5 available appointment slots (0-4)
- Reserve slots for patients
- Cancel existing reservations
- View current reservation status

### Security
- Admin authentication required for administrative functions
- Separate user and admin interfaces

## Technical Implementation

### Hash Table Operations
- **Insertion**: O(1) average case
- **Lookup**: O(1) average case
- **Deletion**: O(1) average case
- **Dynamic resizing**: Automatic table expansion when needed

### Memory Management
- Proper allocation and deallocation of hash table structures
- Cleanup of all allocated memory on program exit
- Prevention of memory leaks

## Contributing

Feel free to contribute to this project by:
1. Forking the repository
2. Creating a feature branch
3. Making your changes
4. Submitting a pull request

## License

This project is open source and available under the [LICENSE](LICENSE) file.

## Author

Haaaaaaaaaax - Clinic System Management

---

**Note**: This is a command-line application designed for educational purposes and demonstrates data structures and algorithms implementation in C.
