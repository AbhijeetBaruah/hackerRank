import numpy as np
#Examples
# Input:  n = "218765"
# Output: "251678"

# Input:  n = "1234"
# Output: "1243"

# Input: n = "4321"
# Output: "Not Possible"

# Input: n = "531465"
# Output: "531546"

# Input: n = "534976"
# Output: "536479"
arr = [2,1,8,7,6,5]

def swap(i,j):
    temp=arr[i]
    arr[i]=arr[j]
    arr[j]=temp

# some hints -> find if next greater is Possible or not(if they are is descending order then its not),
# some hints -> if the input is in ascending order then swap the last two digit
# otherwise then find the index from the backward where the ascending to descending is happening like 5--(ascending)-->6--(descending)->4--save the index
#   swap it with last element, and resort the last section [6,4]->[4,6]
def check():
    index=-1
    for i in range(len(arr)-1,1,-1):
        if(arr[i-1]<arr[i]):
            index=i-1
            swap(index,len(arr)-1)
            break
    if(index==-1):
        print("Not happening")
        return
    arr[index+1:]=sorted(arr[index+1:])
    print(arr)
check()
