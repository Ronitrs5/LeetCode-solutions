#include<bits/stdc++.h>
using namespace std;

class Closest{
    public:

    vector<vector<int>> solution(vector<vector<int>> coordinates, int k){

        int n = coordinates.size();
        vector<vector<int>> ans;
        vector<double> distanceOfAllPoints;
        priority_queue<pair<double, int>> q;

        //calculate euclidean distance all all the points from the origin
        for(int i = 0; i < n; i++){
            int xSquare = coordinates[i][0] * coordinates[i][0]; 
            int ySquare = coordinates[i][1] * coordinates[i][1]; 

            double distance = sqrt(xSquare + ySquare);

            distanceOfAllPoints.push_back(distance);
        }

        for(int i = 0; i < n; i++){
            q.push({distanceOfAllPoints[i], i});

            if(q.size() > k)
                q.pop();
        }

        while(!q.empty()){
            ans.push_back({coordinates[q.top().second][0], coordinates[q.top().second][1]});
            q.pop();
        }
        return ans;

    }
};

int main(){
    int n;
    cout<<"Enter number of points: ";
    cin>>n;

    cout<<"Enter the value of k: ";
    int k;
    cin>>k;

    Closest closest;

    vector<vector<int>> coordinates;

    cout<<"Enter x and y coordinates for n points: ";
    for(int i = 0; i < n; i++){
        int x,y;
        cin>>x>>y;
        coordinates.push_back({x,y});
    }


    //fetching answer from the class and storing it 
    vector<vector<int>> ans = closest.solution(coordinates, k);

    cout<<"K closest points from origin are: "<<endl;
    for(int i = 0; i < ans.size(); i++)
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    
}