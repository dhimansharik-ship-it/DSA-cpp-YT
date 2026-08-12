/*
    AGGRESSIVE COWS PROBLEM

    Problem Statement:
    ------------------
    You are given N stalls placed at different positions along a straight
    line and K cows.

    You have to place the K cows in the stalls such that the minimum
    distance between any two cows is as LARGE as possible.

    Example:
    --------
    Stall positions = {1, 2, 4, 8, 9}
    K = 3

    We need to place 3 cows.

    One possible arrangement:
        Cow 1 -> Stall 1
        Cow 2 -> Stall 4
        Cow 3 -> Stall 8

    Distances:
        4 - 1 = 3
        8 - 4 = 4

    Minimum distance = 3

    Another arrangement:
        Cow 1 -> Stall 1
        Cow 2 -> Stall 4
        Cow 3 -> Stall 9

    Distances:
        4 - 1 = 3
        9 - 4 = 5

    Minimum distance = 3

    The maximum possible minimum distance is 3.

    Approach:
    ---------
    We use Binary Search on Answer.

    First, sort the stall positions.

    Minimum possible distance = 1
    Maximum possible distance = last stall - first stall

    For every 'mid', we check:

    Can we place K cows such that the distance between every
    two consecutive cows is at least 'mid'?

    If YES:
        'mid' is a possible answer.
        We try to increase the distance.
        low = mid + 1

    If NO:
        'mid' is too large.
        We need to decrease the distance.
        high = mid - 1

    Time Complexity:
    ----------------
    Sorting: O(N log N)
    Binary Search: O(N log(maxPosition - minPosition))

    Overall:
    O(N log N + N log(maxPosition - minPosition))

    Space Complexity:
    O(1) extra space (ignoring sorting space)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Function to check whether we can place K cows
// with at least 'minDistance' between them
bool isPossible(vector<int>& stalls, int K, int minDistance)
{
    // Place the first cow in the first stall
    int cowsPlaced = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        // If the current stall is far enough
        // from the last cow
        if (stalls[i] - lastPosition >= minDistance)
        {
            cowsPlaced++;
            lastPosition = stalls[i];

            // We successfully placed all cows
            if (cowsPlaced == K)
                return true;
        }
    }

    // Could not place all K cows
    return false;
}


int aggressiveCows(vector<int>& stalls, int K)
{
    // Stalls must be sorted for the greedy approach
    sort(stalls.begin(), stalls.end());

    int low = 1;

    int high = stalls.back() - stalls.front();

    int answer = 0;

    // Binary Search on Answer
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(stalls, K, mid))
        {
            // mid is possible.
            // Try to find a larger minimum distance.
            answer = mid;
            low = mid + 1;
        }
        else
        {
            // mid is not possible.
            // Try a smaller distance.
            high = mid - 1;
        }
    }

    return answer;
}


int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};

    int K = 3;

    cout << "Maximum minimum distance = "
         << aggressiveCows(stalls, K)
         << endl;

    return 0;
}