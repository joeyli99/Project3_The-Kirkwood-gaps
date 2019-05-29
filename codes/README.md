All codes are contained here.

try_jupiter.jl is the first edition of this problem. FAR FROM COMPLETE!

Known issue:

1. Symplectic methods are TOO slow. (GPU?)
2. Energy is not conserve in 12th RKN method.
3. The result is not correspond to experiment.
4. semi-major axis calculation may be wrong.

Update 5/29:
We add the C++ programme for this project.
The programme implement the algorithm by Yoshida http://cacs.usc.edu/education/phys516/Yoshida-symplectic-PLA00.pdf
The programme include a Hamiltonian class.
