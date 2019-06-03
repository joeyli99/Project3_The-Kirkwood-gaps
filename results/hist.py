import numpy as np
import matplotlib.pyplot as plt

alldata=np.genfromtxt("DATA6-3-150-[(3000)_(50000)]randangle.txt")
plt.hist(alldata,200)
plt.xlabel('semi-major axis')
plt.ylabel('# of asteroids')
plt.show()