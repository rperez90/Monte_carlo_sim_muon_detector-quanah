import numpy as np
#import fileinput

f = open("batch_numbereventsHPCC.mac", "r+")

lines=f.readlines()
target = "/run/beamOn -1\n"
#num = int(raw_input("number of events: ")
num = "/run/beamOn 1500\n"

for line in lines:
	#line.replace(target,num)
	print(line)	
