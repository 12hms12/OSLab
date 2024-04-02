#include<iostream>
#include<array>
#include<unordered_map>
#include<climits>
#include<list>

using namespace std;

bool exists(int n, int arr[], int size){
    for(int i = 0; i < size; i++){
        if(n == arr[i]) return true;
    }
    return false;
}

void FIFO(){
    int n, i, PageNum, index = 0;
    int fault = 0;
    cout << "Enter Number of frames: ";
    cin >> n;
    int frame[n];
    cout << "Enter Number of pages: ";
    cin >> PageNum;
    int arr[PageNum];
    cout << "Enter Page Numbers:\n";
    for(i = 0; i < PageNum; i++){
        cin >> arr[i];
    }

    for(i = 0; i < PageNum; i++){
        if(!exists(arr[i], frame, n)){
            fault++;
            frame[index] = arr[i];
            index = (index + 1) % n;
        }
        cout << "\nFrame:\t";
        for(int j = 0; j < min(i,n); j++)
            cout << frame[j] << " ";
        cout << "\nPage Fault: " << fault << endl;
    }

}

void optimal() {
    int n, PageNum, i;
    int fault = 0;
    cout << "Enter Number of frames: ";
    cin >> n;
    int frame[n]; // Assuming a maximum size for the frame
    cout << "Enter Number of pages: ";
    cin >> PageNum;
    int arr[PageNum]; // Assuming a maximum size for the page array
    cout << "Enter Page Numbers:\n";
    for (i = 0; i < PageNum; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> nextPageIndex;

    for (int i = 0; i < PageNum; ++i) {
        nextPageIndex[arr[i]] = INT_MAX;
        for (int j = i + 1; j < PageNum; ++j) {
            if (arr[i] == arr[j]) {
                nextPageIndex[arr[i]] = j;
                break;
            }
        }
    }

    for (int i = 0; i < PageNum; ++i) {
        if (!exists(arr[i], frame, n)) {
            fault++;
            int farthest = -1, idx = -1;
            for (int j = 0; j < n; ++j) {
                if (nextPageIndex[frame[j]] == INT_MAX) {
                    idx = j;
                    break;
                }
                if (nextPageIndex[frame[j]] > farthest) {
                    farthest = nextPageIndex[frame[j]];
                    idx = j;
                }
            }
            frame[idx] = arr[i];
        }
        cout << "\nFrame:\t";
        for (int j = 0; j < min(i, n); j++)
            cout << frame[j] << " ";
        cout << "\nPage Fault: " << fault << endl;
    }
}

void LRU() {
    int n, PageNum, i;
    int fault = 0;
    cout << "Enter Number of frames: ";
    cin >> n;
    int frame[n]; // Assuming a maximum size for the frame
    cout << "Enter Number of pages: ";
    cin >> PageNum;
    int arr[PageNum]; // Assuming a maximum size for the page array
    cout << "Enter Page Numbers:\n";
    for (i = 0; i < PageNum; i++) {
        cin >> arr[i];
    }

    unordered_map<int, list<int>::iterator> pageTable;
    list<int> lruList;

    for (int i = 0; i < PageNum; ++i) {
        if (pageTable.find(arr[i]) != pageTable.end()) {
            lruList.erase(pageTable[arr[i]]);
        } else {
            if (lruList.size() == n) {
                int last = lruList.back();
                lruList.pop_back();
                pageTable.erase(last);
            }
            fault++;
        }
        lruList.push_front(arr[i]);
        pageTable[arr[i]] = lruList.begin();

        cout << "\nFrame:\t";
        for (auto it = lruList.begin(); it != lruList.end(); ++it)
            cout << *it << " ";
        cout << "\nPage Fault: " << fault << endl;
    }
}

int main(){

    while(1){
        int choice;
        cout<<"Enter\n1 for FIFO\n2 for Optimal\n3 for LRU\n4 for exiting\n";
        cin>>choice;
        if(choice == 1) {
            FIFO();
        }
        else if(choice == 2){
            optimal();
        }
        else if(choice == 3) {
            LRU();
        }
        else exit(0);
    }

    return 0;
}



