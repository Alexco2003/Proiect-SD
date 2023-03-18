import numpy as np
import matplotlib.pyplot as plt

data = []

with open('countsort.txt', 'r') as file: #Aici schimb fisierul in functie de ce sortare analizez acum (countsort.txt, mergesort.txt, quicksort.txt, shellsort.txt, radixsort.txt, radixsort256.txt)
    for line in file:
        values = line.split()
        n = int(values[0].split('=')[1])
        maxim = int(values[1].split('=')[1])
        t = int(values[3])
        data.append([n, maxim, t])

data = np.array(data)

n_values = np.unique(data[:, 0])
maxim_values = np.unique(data[:, 1])

fig, ax = plt.subplots(figsize=(12, 8))

im = ax.imshow(data[:, 2].reshape(len(n_values), len(maxim_values)), cmap='Blues')

ax.set_xticks(np.arange(len(maxim_values)))
ax.set_yticks(np.arange(len(n_values)))
ax.set_xticklabels(maxim_values)
ax.set_yticklabels(n_values)
ax.set_xlabel('MAXIM (Maximum Value)')
ax.set_ylabel('N (vector size)')
plt.title('Countsort') #Aici schimb titlul in functie de ce sortare analizez acum (Countsort, Mergesort, Quicksort, Shellsort, Radixsort, Radixsort256)

for i in range(len(n_values)):
    for j in range(len(maxim_values)):
        text = ax.text(j, i, data[i*len(maxim_values)+j, 2], ha='center', va='center', color='black')

cbar = fig.colorbar(im, ax=ax, orientation='vertical', shrink=0.5)
sm = plt.cm.ScalarMappable(cmap='Blues', norm=plt.Normalize(vmin=data[:, 2].min(), vmax=data[:, 2].max()))
sm.set_array([])
cbar.set_ticks(data[:, 2])
cbar.set_label('Time (microseconds)', rotation=270, labelpad=15)



plt.show()
