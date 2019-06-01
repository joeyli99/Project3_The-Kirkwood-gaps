import numpy as np
import matplotlib.pyplot as plt

alldata=np.genfromtxt("DATA5-30-1720-[(2000)_(100000)]randangle.txt")
plt.hist(alldata,500)
plt.xlabel('semi-major axis')
plt.ylabel('# of asteroids')
plt.show()