import numpy as np
import matplotlib.pyplot as plt

#IVdata=np.genfromtxt("sample_data\IV5-30-1720-[(2000)_(2000)]randangle.txt")
# r=IVdata[:, 0]
# phi=IVdata[:, 1]

Enddata=np.genfromtxt("sample_data\DATA5-29-852-[(2000)_(20000)].txt")
r=Enddata
phi=np.random.rand(20000)*2*(np.pi)
plt.scatter(r*np.cos(phi), r*np.sin(phi),s=0.01)
# plt.plot(IVdata, Enddata-IVdata)
# # plt.hist(alldata,200)
# plt.xlabel('semi-major axis')
# plt.ylabel('Delta a')
plt.show()
plt.hist(Enddata,bins=200)
plt.show()