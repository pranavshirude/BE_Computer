import pandas as pd
from pandas.plotting import scatter_matrix

list1 = ["sepal_length","sepal_width","petal_length","petal_width","class"]

data = pd.read_csv("iris.csv", names=list1)

print( data.shape )
#print( data.head(5))
print( data.describe())

#plotting
data.plot(kind="box")
data.hist()
scatter_matrix(data,diagonal='kde') 