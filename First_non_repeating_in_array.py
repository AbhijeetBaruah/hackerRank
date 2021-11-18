
import numpy as np
randnums= np.random.randint(1,50,50)
print(randnums)
dic = dict()
for i in randnums:
    if i in dic:
        dic[i]=dic[i]+1
    else:
        dic[i]=1
print(dic)

for i in randnums:
    j = dic[i]
    if j==1:
        print(i)
        break
