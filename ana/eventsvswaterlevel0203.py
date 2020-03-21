#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on %(date)s

@author: %(RPJR)s
"""
import numpy as np
import matplotlib.pyplot as plt

x = [0,18,20,32,50];
y = [42447, 38819, 38475, 36789, 35797];

plt.plot(x, y, color='green', linestyle='dashed', linewidth=3, marker='o', markerfacecolor='blue',markersize=12)
plt.xlabel('water levels')
plt.ylabel('muon trig events')
plt.title('muon events vs water levels')
plt.show()
