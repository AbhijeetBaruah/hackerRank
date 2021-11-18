
import numpy as np

#making a random array
randnums= np.random.randint(1,50,50)
print(randnums)
dic = dict()

#creating a dictionary to count the repeatition
for i in randnums:
    if i in dic:
        dic[i]=dic[i]+1
    else:
        dic[i]=1
print(dic)
#finding the first non repeating
for i in randnums:
    j = dic[i]
    if j==1:
        print(i)
        break
