import numpy as np
import matplotlib.pyplot as plt
from statistics import mean

f = open("theta_file.txt", "r")
lines = f.readlines()
theta = []

for line in enumerate(lines):
	theta.append(float(line[1]))

print("Mean at whatevever theta " + str(mean(theta)))
plt.hist(theta, bins=[0, 10, 20, 30, 40, 50,60,70,80,90])
plt.show()
