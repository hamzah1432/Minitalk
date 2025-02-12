# Minitalk

A small data exchange program using UNIX signals.

## Overview

This project involves creating a communication program in the form of a client and server. The server must be started first and print its PID after launch. The client takes two parameters:
- Server PID
- String to send

The communication between client and server must be done only using UNIX signals: SIGUSR1 and SIGUSR2.

## About 42 School Project

This project is part of the 42 School curriculum, designed to deepen understanding of:
- UNIX signals and their handling
- Bit manipulation and binary operations
- Process communication
- System programming concepts
- Code optimization and reliability

The project challenges students to implement efficient inter-process communication using minimal system calls, reinforcing fundamental concepts of UNIX systems programming.

### Learning Objectives
- Master UNIX signals for inter-process communication
- Understand binary operations and bit manipulation
- Implement robust error handling
- Manage system resources effectively
- Write clean and maintainable code

## Requirements

- Unix-like operating system (Linux/MacOS)
- GCC compiler
- Make

## Installation

```bash
git clone <repository-url>
cd Minitalk
make
```

## Usage

1. Start the server:
```bash
./server
```

2. Note the displayed PID

3. Send a message using the client:
```bash
./client [server_pid] [message]
```

## Implementation Details

- Server acknowledges every message received by sending back a signal to the client
- Supports Unicode characters
- Handles errors and edge cases
- Uses only the following functions:
  - write
  - signal
  - sigemptyset
  - sigaddset
  - sigaction
  - kill
  - getpid
  - malloc
  - free
  - pause
  - sleep
  - usleep
  - exit

### How Signals Are Used

```
Client -> Server: SIGUSR1 = Binary 1
Client -> Server: SIGUSR2 = Binary 0
Server -> Client: SIGUSR1 = Message received
```

### Performance

- Efficient bit-by-bit transmission
- Minimal CPU usage
- Handles messages of any length
- Signal queue management to prevent data loss

### Bonus Features

- Support for Unicode characters
- Server acknowledgment
- Colorized output
- Real-time transmission feedback

## Troubleshooting

Common issues and solutions:
- If server doesn't respond: Check if PID is correct
- If message is corrupted: Ensure no other processes are sending signals
- For slow transmission: Adjust the microsleep duration
- Permission denied: Run with appropriate user permissions

## Project Structure

```
.
├── Makefile
├── includes/
│   └── minitalk.h
├── src/
│   ├── server.c
│   └── client.c
└── README.md
```

## Author

- halmuhis

## License

This project is part of 42 School curriculum.