import pandas as pd
import numpy as np
from inspect import signature as sg

from pandas.core.reshape.reshape import get_dummies
from inspect import signature

signature = sg
data = pd.read_csv('test_src/train.csv')

x = data.drop(['Name', 'Cabin', 'PassengerId','Ticket','Name'], axis=1)

x.fillna({'Age' : x['Age'].median()}, inplace=True)
index = x[x['Embarked'].isnull()].index

x.drop(index, inplace=True)

y = x.pop('Survived')
from sklearn.model_selection import RandomizedSearchCV
from sklearn.model_selection import GridSearchCV
from sklearn.model_selection import train_test_split
from sklearn.metrics import roc_auc_score
from scipy.stats import randint

# not need to scale, Label encoder
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import LabelEncoder

cols = ['Sex', 'Embarked']

encoder = LabelEncoder()
for col in cols :
    x[col] = encoder.fit_transform(x[col])
# params = {'n_estimators' : randint(low=100, high=300)}
model = DecisionTreeClassifier()
# print(model.get_params().keys())
# rand = RandomizedSearchCV(model, params, cv=5, n_iter = 30)
# rand.fit(x,y)
# best = rand.best_params_

# model_best = RandomForestClassifier(n_estimators = best)
model.fit(x,y)
result = model.predict(x)
result = pd.DataFrame(result)
auc = roc_auc_score(y,result)


#need to scale, one-hot encoding
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC 
from sklearn.preprocessing import MinMaxScaler

scaler = MinMaxScaler()
x = scaler.fit_transform(x)

model = LogisticRegression()
param = {'C': randint(low=1, high=100)}
rand = RandomizedSearchCV(model,param,cv=5, n_iter=50)
rand.fit(x,y)
best = rand.best_params_
model = LogisticRegression(C=4)
model.fit(x,y)
result = model.predict(x)

aa = roc_auc_score(y,result)
print(aa)