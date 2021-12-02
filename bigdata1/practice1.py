from sklearn.ensemble import BaggingClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import SVC
from scipy.stats import randint
from sklearn.model_selection import RandomizedSearchCV
from sklearn.model_selection import GridSearchCV
import pandas as pd
import numpy as np
from inspect import signature

gender = pd.read_csv("test_src/gender_submission.csv")
test = pd.read_csv("test_src/test.csv")
train = pd.read_csv("test_src/train.csv")
sg = signature

# train data
x = train.loc[:, ['Pclass', 'Sex', 'Age',
                  'SibSp', 'Parch', 'Fare', 'Embarked']]
y = train.pop('Survived')

# test data
test = test.loc[:, ['Pclass', 'Sex', 'Age',
                    'SibSp', 'Parch', 'Fare', 'Embarked']]
gender = gender.pop('Survived')

# fill Age null
x['Age'] = x['Age'].fillna(x['Age'].mean())
test['Age'] = test['Age'].fillna(test['Age'].mean())
test.fillna({'Fare': test['Fare'].mean()}, inplace=True)

# one hot encoding
x = pd.get_dummies(x)
test = pd.get_dummies(test)
q3 = x['Fare'].quantile(0.75)
q1 = x['Fare'].quantile(0.25)
iqr = q3 - q1
q3_test = x['Fare'].quantile(0.75)
q1_test = x['Fare'].quantile(0.25)
iqr = q3_test - q1_test

data_integrated = pd.concat([x,y], axis=1)
x_small = data_integrated[(data_integrated['Fare'] < q3 + iqr*1.5) & (data_integrated['Fare'] > q1 - iqr*1.5)]
y = x_small.pop('Survived')
#
from sklearn.preprocessing import MinMaxScaler
scaler= MinMaxScaler()
print(dir(MinMaxScaler))
x_small = scaler.fit_transform(x_small)
test = scaler.transform(test)
print(x_small)
#model
model = SVC()
bagging = BaggingClassifier(
    base_estimator=model, random_state=42, n_estimators=10)
bagging.fit(x_small, y)
score = bagging.score(x_small, y)
score2 = bagging.score(test, gender)
print(score)
print(score2)

model2 = RandomForestClassifier()
model2.fit(x_small, y)
score = model2.score(x_small, y)
score2 = model2.score(test, gender)
print(score)
print(score2)

