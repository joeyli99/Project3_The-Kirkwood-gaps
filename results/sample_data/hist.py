import numpy as np
import matplotlib.pyplot as plt

#IVdata=np.genfromtxt("IV2019-06-05-23--03-[n=20000,year=2000].txt")
#r=IVdata[:, 0]
#phi=IVdata[:, 1]

Enddata=np.genfromtxt("DATA2019-06-05-23-03-[n=20000,year=2000].txt")
#r=Enddata
#phi=np.random.rand(20000)*2*(np.pi)
#plt.scatter(r*np.cos(phi), r*np.sin(phi),s=0.01)
#plt.plot(r, Enddata-r)
# # plt.hist(alldata,200)
# plt.xlabel('semi-major axis')
# plt.ylabel('Delta a')
# plt.show()
plt.hist(Enddata,bins=200)
plt.show()