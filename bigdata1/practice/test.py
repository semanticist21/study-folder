import numpy as np
import pandas as pd
from pandas.core.indexes.base import InvalidIndexError

data = pd.read_csv('./data2/Ex_CEOSalary.csv', encoding='utf-8')

print(data['industry'].value_counts())


data['industry']= data['industry'].replace([1,2,3,4], ['Service', 'IT', 'Finance', 'Others'])

print(data['industry'].value_counts())
print(data['industry'])

data['industry'].value_counts().plot(kind='bar')
