Pipex Project
Description

This project is part of the curriculum at 42 school and focuses on the concept of inter-process communication and file manipulation in Unix-like operating systems using pipelines.
Table of Contents

    Introduction
    Requirements
    Installation
    Usage
    Examples
    Contributing
    License

Introduction

Pipex is a project that involves creating a program that simulates the behavior of the shell command-line with redirections, pipes, and input/output files. It aims to deepen the understanding of how processes communicate and how file descriptors are manipulated in Unix systems.
Requirements

To run Pipex, you will need:

    A Unix-like operating system (e.g., Linux, macOS)
    GCC compiler
    Make utility

Installation

To install Pipex, follow these steps:

    Clone this repository to your local machine.
    Navigate to the project directory.
    Run the make command to compile the program.

Usage

To use Pipex, follow these steps:

    Open a terminal window.
    Navigate to the directory where Pipex is installed.
    Run the program with the desired arguments and input/output files.
    ./pipex file1 cmd1 cmd2 file2
Replace file1, cmd1, cmd2, and file2 with your specific inputs.
<h1>Examples</h1>

Here are some examples of how to use Pipex:

    Redirecting input from a file and output to another file:
    ./pipex infile "ls -l" "wc -l" outfile
Using a pipe between commands:

    ./pipex infile "grep a1" "sort" outfile
Contributing

Contributions to Pipex are welcome! If you find any bugs or have suggestions for improvements, please create a pull request or open an issue on GitHub.
License

This project is licensed under the MIT License - see the LICENSE file for details.













