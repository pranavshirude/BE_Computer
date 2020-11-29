import pandas as pd
import numpy as np
from sklearn.metrics import accuracy_score, confusion_matrix;
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier

data = pd.read_csv("2010-capitalbikeshare-tripdata.csv")

X = np.asarray(data[['Duration', 'Start station number', 'End station number']])
Y = np.asarray(data['Member type'])


train_x, test_x, train_y, test_y = train_test_split(X,Y, test_size=0.35, shuffle=True )


dt = DecisionTreeClassifier()
dt.fit(train_x, train_y)
predict_y = dt.predict(test_x)

print(accuracy_score(test_y, predict_y)*100)

print(confusion_matrix(test_y, predict_y))