import numpy as np

def findingTheBreakPointOrNumberInHalfTheArray(num):
    prev=givenArr[0]
    dic=dict()
    for i in range(0,len(givenArr)-1):
        if(num==givenArr[i]):
            return [i,0] #index of the position with true to show that the number is there
        if(givenArr[i]<prev):
            return [i,1] #index of the position from where the rotation is happening
            break
    return [-1,2] ##not in the list as well as list is sorted without rotation
def callBinary(sortedArr,find):
    #for the array under inspection
    low=0
    max=len(sortedArr)-1 #as index is 0 based
    while(low<=max):
        mid=(low+max)//2
        if(sortedArr[mid]==find):
            return mid
        if(sortedArr[mid]<find):
            low=mid+1
        else:
            max=mid-1
    return -1
    
givenArr=[5,6,7,8,9,1,2,3,4]
find2=9
lis = findingTheBreakPointOrNumberInHalfTheArray(find2)
x = lis[1]
if(x==0):
    print("index is",lis[0])
elif(x==1):
    val=callBinary(givenArr[lis[0]:],find2)
    if(val!=-1):
        print(lis[0]+val)
    else:
        print("Not in the list")
else:
    print("Not in the list")
