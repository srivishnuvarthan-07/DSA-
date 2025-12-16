#include <bits/stdc++.h>
using namespace std;


/*

method in priority_queue
push()   -   O(logn);
pop()    -   O(logn);
top()    -   O(1);
size()   -   o(1);
empty()  -   O(1);

*/

int main()
{

    // Create a max-heap priority queue (default)
    priority_queue<int> pq;

    // Insert elements
    pq.push(30);
    pq.push(10);
    pq.push(20);
    pq.push(40);

    cout << "Elements removed from priority queue in order:\n";

    // Remove elements (largest element comes out first)
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    
     // Create a min-heap priority queue 
    priority_queue<int,vector<int>,greater<int>>pq1;
    pq.push(30);
    pq.push(10);
    pq.push(20);
    pq.push(40);

    cout << "Elements removed from priority queue in order:\n";

    // Remove elements (smallest element comes out first)
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

}