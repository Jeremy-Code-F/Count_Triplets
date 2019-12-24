//https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps&h_r=next-challenge&h_v=zen

//shove the array into a map


//iterate through array
    //foreach n check if n * 4 exists in the map
        // if so check if n * 4^2 exists in the map
            //if so that matches so add those indexes 
#include<bits/stdc++.h>
using namespace std;

long countTriplets(vector<long> arr, long r){
    map<long, int> mp;

    sort(arr.begin(), arr.end());

    for(long arrElem : arr){
        printf("Inserting: %lu \n", arrElem);
        
        mp[arrElem]++;
    }

    int totalMatches = 1;
    for(auto arrElem : arr){
        int potentialMatches = 1;
        cout << "Array element: " << arrElem << endl;
        
        if(mp[arrElem * r] >= 1){
            cout << "Potential matches: " << potentialMatches << endl;
            potentialMatches *= mp[arrElem * r];
            cout << "Potential matches: " << potentialMatches << endl;
            if(mp[arrElem * (r * r)]  >= 1){
                potentialMatches = mp[arrElem * (r * r)];
                totalMatches += potentialMatches;
                
                //This one works
                cout << "Match: " << arrElem << " " << arrElem * r << " " << arrElem * (r * r) << endl;
            }
        }
    }

    cout << "Matches: " << totalMatches << endl;
}


int main(){

    vector<long> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(4);
    countTriplets(vect, 2);
}