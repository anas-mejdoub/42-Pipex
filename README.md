<h1>42-Pipex Project</h1>
<h1>Description</h1>

This project is part of the curriculum at 42 school and focuses on the concept of inter-process communication and file manipulation in Unix-like operating systems using pipelines.
Table of Contents

<h3>#Introduction</h3>
<h3>#Requirements</h3>
<h3>#Installation</h3>
<h3>#Usage</h3>
<h3>#Examples</h3>
<h3>#Contributing</h3>
<h3>#License</h3>

<h1>Introduction</h1>

Pipex is a project that involves creating a program that simulates the behavior of the shell command-line with redirections, pipes, and input/output files. It aims to deepen the understanding of how processes communicate and how file descriptors are manipulated in Unix systems.
Requirements

To run Pipex, you will need:

1-A Unix-like operating system (e.g., Linux, macOS)</br>
2-GCC compiler</br>
3-Make utility</br>

<h1>Installation</h1>

To install Pipex, follow these steps:

1-Clone this repository to your local machine.</br>
2-Navigate to the project directory.</br>
3-Run the make command to compile the program.</br>

<h1>Usage</h1>

To use Pipex, follow these steps:

1-Open a terminal window.</br>
2-Navigate to the directory where Pipex is installed.</br>
3-Run the program with the desired arguments and input/output files.</br>

    ./pipex file1 cmd1 cmd2 file2
Replace file1, cmd1, cmd2, and file2 with your specific inputs.
<h1>Examples</h1>

Here are some examples of how to use Pipex:

Redirecting input from a file and output to another file:</br>

    ./pipex infile "ls -l" "wc -l" outfile
Using a pipe between commands:

    ./pipex infile "grep a1" "sort" outfile
<h1>Contributing</h1>

Contributions to Pipex are welcome! If you find any bugs or have suggestions for improvements, please create a pull request or open an issue on GitHub.













