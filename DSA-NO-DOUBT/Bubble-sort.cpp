#include <bits/stdc++.h>
void bubbleSort(vector<int> &arr, int n)
{
    int i = 0;
    for (int round = 0; round < n - 1; round++)
    {
        bool swapped = false;
        while (i < n - round - 1) //first we look at all n-1 indices. Then we look at n-2 indices, then n-3 indices and so on. This is because the largest element is bubbled to the end of the array in each round.
        //also not = sign as we access i+1 in the loop, so we need to stop at n-2 index.
            if (arr[i + 1] < arr[i])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
            i++;
        }
        if (swapped == false)
            break;
        i = 0;
    }
}

//I could code the original logic on my own. I did not think of the n-round-1 optimization and the swapped bool mechanism, which results in optimization of the number of passes needed.