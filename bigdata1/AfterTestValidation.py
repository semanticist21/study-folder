import pandas as pd
import numpy as np

data = pd.read_csv('TravelInsurancePrediction.csv')

data = data.iloc[:,1:]

from sklearn.preprocessing import LabelEncoder

encoder = LabelEncoder()
cols = ['Employment Type', 'GraduateOrNot', 'FrequentFlyer','EverTravelledAbroad']

for col in cols:
    data[col] = encoder.fit_transform(data[col])

data.info()

x = data.iloc[:, 0:8]
y = data.iloc[:, 8]

from sklearn.model_selection import train_test_split

x_train,x_test,y_train,y_test = train_test_split(x,y,stratify=y)

from sklearn.ensemble import RandomForestClassifier
model = RandomForestClassifier()
model.fit(x_test,y_test)
score = pd.DataFrame(model.predict_proba(x)).iloc[:,1]

from sklearn.metrics import roc_auc_score

from sklearn.svm import SVC
from sklearn.linear_model import LogisticRegression

model = LogisticRegression()
model.fit(x, y)
score = pd.DataFrame(model.predict_proba(x_test)).iloc[:,0]

roc = roc_auc_score(y_test, score)
print(roc)