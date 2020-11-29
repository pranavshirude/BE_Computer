import pandas as pd
from sklearn.metrics import confusion_matrix, accuracy_score, classification_report
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB

data = pd.read_csv("PimaIndiansDiabetes.csv")

#split dataset
train_set, test_set = train_test_split(data,test_size=0.40,shuffle=True)

train_x = train_set[train_set.columns[0:8]]
train_y = train_set[train_set.columns[-1]]
test_x = test_set[train_set.columns[0:8]]
test_y = test_set[train_set.columns[-1]]

nb = GaussianNB()
nb.fit(train_x, train_y)
predict_y = nb.predict(test_x)

print(accuracy_score(test_y, predict_y)*100)
print(confusion_matrix(test_y, predict_y))
print(classification_report(test_y, predict_y))
data.hist()













'''
import pandas as pd
import random

a = [random.randint(1,11) for i in range(100)]
b = [random.randint(1,11) for i in range(100)]

dict = {"Acad":a, "extra": b}

data = pd.DataFrame(dict)

data.to_csv("dataset.csv")
'''