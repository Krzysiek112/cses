#include <bits/stdc++.h>
using namespace std;

/*
Observations:
its always the best to choose the room with the minimum number from the pool of rooms already used

Approach: priority queue + sorting
lets sort the intervals by the starting interval

while traversing sorted arrivals, check if there is an available room
if not -> add another room
if yes -> replace the room with the earliest end time with the current end time

a room will be available if its end time is strictly less than the start of another

the priority queue stores (end time, room number) and is a min-heap

rooms[i] is the room number of the i'th customer

since we are sorting the arrivals, we also need to map each sorted index to its original
*/

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> arrivals(n);
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;

        arrivals[i] = {start, end, i};
    }

    sort(arrivals.begin(), arrivals.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> rooms(n);

    for (auto& [start, end, i] : arrivals) {
        int room_count = pq.size();

        int earliest_end = pq.empty() ? INT_MAX : pq.top().first;
        int room_number = pq.empty() ? INT_MAX : pq.top().second;

        if (earliest_end < start) {
            pq.pop();

            pq.push({end, room_number});
            rooms[i] = room_number;
        }
        else {
            pq.push({end, room_count});
            rooms[i] = room_count;
        }
    }
    cout << pq.size() << "\n";
    for (const int& room : rooms) {
        cout << room + 1 << " ";
    }

    return 0;
}