from sklearn.neighbors import KNeighborsClassifier
import matplotlib.pyplot as plt
import numpy as np

bream_length = [25.4, 26.3, 26.5, 29.0, 29.0, 29.7, 29.7, 30.0, 33.5, 41.0]
bream_weight = [242.0, 290.0, 340.0, 363.0, 430.0, 450.0, 500.0, 600.0, 620.0, 680.0]

smelt_length = [
    9.8,
    10.5,
    10.6,
    11.0,
    11.2,
    11.8,
    11.8,
    11.3,
    12.0,
    12.2,
    12.4,
    13.0,
    14.3,
    15.0,
]
smelt_weight = [
    6.7,
    7.5,
    7.0,
    9.7,
    9.8,
    8.7,
    10.0,
    9.9,
    9.8,
    12.2,
    13.4,
    12.2,
    19.7,
    19.9,
]

plt.scatter(bream_length, bream_weight)
plt.scatter(smelt_length, smelt_weight)

plt.xlabel("length")
plt.ylabel("weight")
plt.show()

zip_data = lambda x, y: [[l, w] for l, w in zip(x, y)]

total_length = bream_length + smelt_length
total_weight = bream_length + smelt_weight

zipped = zip_data(total_length, total_weight)
train_data = np.array(zipped)

fish_target = [1] * len(bream_length) + [0] * len(smelt_length)

kn = KNeighborsClassifier()
kn.fit(train_data, fish_target)
score = kn.score(train_data, fish_target)

result = kn.predict(np.array([[30, 600]]))
print(result)