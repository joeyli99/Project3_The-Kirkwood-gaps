# Project3_The-Kirkwood-gaps
## Introduction

This repository contains the codes of a project in ICP, 2019 Spring. 

The project is about the Kirkwood gaps on the Asteroid Brid. Yinan Chen and I collaborate on this project.

We use the 8th-order symmetrical symplectic algorithm pubished by Yoshida in Physics Letters A and implement it by C++. Powered by OpenMP, we employ the parallel computation to simulate larger system with high speed and precision. 

## About codes

The codes are included in folder Parrallel_Asteroids. 

| File              | Description                                 |
| ----------------- | ------------------------------------------- |
| fmt\              | An external package.                        |
| Hamilton.h        | Head file, including the function prototype |
| Hamilton.cpp      | Implement of Yoshida-8th algorithm.         |
| the_asteroids.cpp | The main function                           |
| CMakeLists.txt    | cmake file.                                 |
| hist.py           | python plot file                            |
| demodata.txt      | demo data.                                  |

### Recommendation:

**Compiler**:  gcc 8.1.0 or above.

**CMake**: cmake 3.12 or above.

**Python**: python 3.7 and newest matplotlib and numpy.

### How to use?

1.  Use cmake to configuration the project
2. Build the project
3. Run the executable file (may take 15 mins).
4. Plot the data.

