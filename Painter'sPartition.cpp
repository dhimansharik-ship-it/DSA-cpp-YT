/*
    PAINTER'S PARTITION PROBLEM

    Problem Statement:
    ------------------
    Given an array of boards where boards[i] represents the length of the
    ith board, and K painters, partition the boards among the painters.

    Rules:
    1. Each painter must paint a contiguous sequence of boards.
    2. Every painter paints at least one board.
    3. All painters paint simultaneously.
    4. The time required to paint a board is equal to its length.
    5. We need to minimize the maximum time taken by any painter.

    Example:
    --------
    Boards = {10, 20, 30, 40}
    K = 2

    Possible partition:
        Painter 1 -> {10, 20, 30} = 60
        Painter 2 -> {40} = 40

    Maximum time = 60

    Another partition:
        Painter 1 -> {10, 20} = 30
        Painter 2 -> {30, 40} = 70

    Maximum time = 70

    Therefore, the minimum possible maximum time is 60.

    Approach:
    ---------
    We use Binary Search on Answer.

    Minimum possible answer = maximum board length
    Maximum possible answer = sum of all board lengths

    For every 'mid', we check:
    Can we paint all boards using at most K painters if no painter
    is allowed to paint more than 'mid' total length?

    If YES:
        We try to find an even smaller answer.
        high = mid - 1

    If NO:
        We need more time.
        low = mid + 1

    Time Complexity:
    ----------------
    O(N * log(sum of boards))

    Space Complexity:
    -----------------
    O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Function to check whether it is possible to paint
// all boards using at most K painters with maximum
// allowed workload = maxTime
bool isPossible(vector<int>& boards, int K, long long maxTime)
{
    int painters = 1;
    long long currentTime = 0;

    for (int board : boards)
    {
        // If adding this board exceeds the allowed time,
        // assign it to a new painter.
        if (currentTime + board > maxTime)
        {
            painters++;
            currentTime = board;

            // More than K painters are required
            if (painters > K)
                return false;
        }
        else
        {
            currentTime += board;
        }
    }

    return true;
}


long long painterPartition(vector<int>& boards, int K)
{
    long long low = *max_element(boards.begin(), boards.end());

    long long high = 0;
    for (int board : boards)
    {
        high += board;
    }

    long long answer = high;

    // Binary Search on Answer
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (isPossible(boards, K, mid))
        {
            // mid is a possible answer.
            // Try to find a smaller maximum time.
            answer = mid;
            high = mid - 1;
        }
        else
        {
            // mid is too small.
            // We need more time.
            low = mid + 1;
        }
    }

    return answer;
}


int main()
{
    vector<int> boards = {10, 20, 30, 40};

    int K = 2;

    cout << "Minimum maximum time = "
         << painterPartition(boards, K)
         << endl;

    return 0;
}