All codes are contained here.

try_jupiter.jl is the first edition of this problem. FAR FROM COMPLETE!

Known issue:

1. Symplectic methods are TOO slow. (GPU?) [Solved by using C++ 5/31]
2. Energy is not conserve in 12th RKN method. [Using Symplectic 5/31]
3. The result is not correspond to experiment. [Better! 5/31]
4. semi-major axis calculation may be wrong. [Not sure 5/31]

### Update 5/29:

sWe add the C++ program for this project.
The program implements the algorithm by Yoshida http://cacs.usc.edu/education/phys516/Yoshida-symplectic-PLA00.pdf
The program include a Hamiltonian class.

### Update 5/31

Some improvement of this program.

1. we make the time in Hamitonian class public. Which is a fool wrong.
2. Some improvement of speed.
