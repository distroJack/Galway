
import matplotlib.pyplot as plt
import csv

with open('maunal_zebra.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=',')
    test = []
    for row in spamreader:
        test += [int(x) for x in row]

    print(test)

    plt.plot(range(1,len(test)+1), test)

plt.show()
