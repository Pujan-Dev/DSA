def BubbleSort(arr):
    n =len(arr)
    for i in range(n-1): #for(i=0li<n i++)
        swapped =False
        for j in range(i,n-1): #for (j=i)
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
                swapped=True
        if not swapped:
            break
    return arr


arr=[1,4,2,7,4,5,7,9]
print(BubbleSort(arr))


## insertion sort

def InsertionSort(arr):
    for i in range(1,len(arr)):
        key =arr[i]
        j=i-1
        while j>=0 and arr[j]>key:
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key
    return arr

print("InsertionSort:",InsertionSort(arr))
