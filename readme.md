# CP Algorithms Repository  

This is my personal repository for competitive programming solutions and algorithmic problem-solving. It includes solutions for various platforms such as CSES, Project Euler, and HackerRank, along with useful scripts and utilities for streamlined development.  

## 📌 Features  
- Organized problem solutions categorized by platform.  
- Preconfigured `tfcpp.json` for easy execution.  
- Utility scripts for efficient testing and debugging.  
- Custom C++ format utilities in the `fmt` directory.  

## 🚀 Running a Solution  
To run a specific problem solution, first modify `tfcpp.json` and then simply execute:  
```sh
./run.bat
```  

This will:  
1. Compile the `main.cpp` file.  
2. Execute the solution with necessary debugging utilities enabled.  

if io_files flag is True then Make sure your input is placed in `.in.txt`, and the output will be written to `.out.txt`.  
else make sure to add the input in the files debug test cases

## 📂 Repository Structure  
```
CP-Algorithms/
│   .gitignore
│   readme.md
│   run.bat
│   tfcpp.json
├───cses/                        # CSES problem set solutions
├───fmt/                         # Custom C++ format utilities
├───hackerrank/                  # HackerRank contest solutions
├───projecteuler/                # Project Euler solutions
└───scripts/                     # Helper scripts for execution
```

## 🛠 Dependencies  
Ensure you have the following installed:  
- A C++ (`g++`) compiler (GCC, Clang, MSVC, etc.)
- `fmt-display-cpp`: [Fmt Display C++](https://github.com/thefcraft/fmt-display-cpp)  

## 📝 Contribution  
This is a personal repository, but if you find something useful or have suggestions, feel free to open an issue or submit a pull request.  

## 📜 License  
This project is for personal and educational use. Feel free to reference and modify the code for your own learning purposes!  