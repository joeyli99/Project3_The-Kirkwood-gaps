All codes are contained here.

try_jupiter.jl is the first edition of this problem. FAR FROM COMPLETE!

Known issue:

1. Symplectic methods are TOO slow. (GPU?) [Solved by using C++ 5/31] [6/3 No problem]
2. Energy is not conserve in 12th RKN method. [Using Symplectic 5/31]
3. The result is not correspond to experiment. [Better! 5/31]
4. semi-major axis calculation may be wrong. [Not sure 5/31]

### Update 5/29:

We add the C++ program for this project.
The program implements the algorithm by Yoshida http://cacs.usc.edu/education/phys516/Yoshida-symplectic-PLA00.pdf
The program include a Hamiltonian class.

### Update 5/31

Some improvement of this program.

1. we make the time in Hamitonian class public. Which is a fool wrong.
2. Some improvement of speed.

### Update 6/2

Improvement of the speed, we use vector.reserve()
Now, the function can solve this symplectic ode (2000 years 1/16 steps) in 0.15s. 

### Update 6/3

We use the **parallel computation** to improve the speed of our program (OpenMP). Further, under the consideration of the dimension of this problem is fixed, we use std::array to replace the std::vector.  

Now, the program can finish a 2000 years, 4000 asteriods problem by 1/16 step in 90S (i5-7300HQ).

