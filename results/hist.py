import numpy as np
import matplotlib.pyplot as plt

alldata=np.genfromtxt("DATA6-2-171-[(2000)_(4000)]randangle.txt")
plt.hist(alldata,300)
plt.xlabel('semi-major axis')
plt.ylabel('# of asteroids')
plt.show()