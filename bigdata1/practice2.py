import pandas as pd
import numpy as np
from inspect import signature

df = pd.read_csv('Data2/house_price.csv')
sg = signature

# print(sg(df.sort_values))

data = df.sample(frac = 0.8)

data.info()
df.info()
