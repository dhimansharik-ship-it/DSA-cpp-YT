/*
    SORT AN ARRAY OF 0s, 1s AND 2s

    Problem Statement:
    ------------------
    Given an array containing only 0s, 1s, and 2s, sort the array
    in ascending order.

    Example:
    --------
    Input:
        arr = {2, 0, 2, 1, 1, 0}

    Output:
        {0, 0, 1, 1, 2, 2}

    We need to sort the array WITHOUT using any built-in sorting
    function.

    Approach:
    ---------
    We use the Dutch National Flag Algorithm.

    We maintain three pointers:

        low  -> boundary for 0s
        mid  -> current element
        high -> boundary for 2s

    The array is divided into four regions:

        [0 ... low-1]       -> 0s
        [low ... mid-1]     -> 1s
        [mid ... high]      -> unknown elements
        [high+1 ... n-1]    -> 2s

    Rules:
    -------
    If arr[mid] == 0:
        Swap arr[low] and arr[mid]
        Move low and mid forward.

    If arr[mid] == 1:
        Move mid forward.

    If arr[mid] == 2:
        Swap arr[mid] and arr[high]
        Move high backward.

        IMPORTANT:
        We do NOT move mid here because the element that comes
        from the high side has not been checked yet.

    Time Complexity:
    ----------------
    O(N)

    Space Complexity:
    -----------------
    O(1)

    This is an optimal solution because we sort the array in
    one traversal without using extra space.
*/

#include <iostream>
#include <vector>
using namespace std;


void sortColors(vector<int>& arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            // Put 0 at the beginning
            swap(arr[low], arr[mid]);

            low++;
            mid++;
        }

        else if (arr[mid] == 1)
        {
            // 1 is already in its correct region
            mid++;
        }

        else
        {
            // arr[mid] == 2
            // Put 2 at the end
            swap(arr[mid], arr[high]);

            high--;

            // Do NOT increment mid here
        }
    }
}


int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    sortColors(arr);

    cout << "Sorted array: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}