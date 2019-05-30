import numpy as np
import matplotlib.pyplot as plt

alldata=np.genfromtxt("results\pi2\DATA5-29-1640-[(2000)_(100000)]pi.txt")
plt.hist(alldata,300)
plt.xlabel('semi-major axis')
plt.ylabel('# of asteroids')
plt.show()