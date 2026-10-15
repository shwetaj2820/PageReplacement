#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> frames;
    int capacity;
    int n;
    int faults = 0;

    cout << "Enter number of frames";
    cin >> capacity;

    cout << "Enter number of page requests";
    cin >> n;

    vector<int> requests(n);

    cout << "enter page sequence: ";
    for(int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    int evict = 0;

    for(int page : requests) {
        if(find(frames.begin(), frames.end(), page) != frames.end()) {
            cout << page << " HIT " << "\n";
        } else {
            cout << page << " PAGE FAULT " << "\n";
            faults++;

            if(frames.size() < capacity) {
                frames.push_back(page);
            } else {
                cout << "evicting page: " << frames[evict] << "\n";
                frames[evict] = page;
                evict = (evict + 1) % capacity;
            }

            cout<< "Frames: ";
            for(int p : frames) {
                cout << p << " ";
            }
            cout << "\n";
        }
    }
    
    cout << "Total page faults: " << faults << "\n";
    return 0;
}