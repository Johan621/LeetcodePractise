class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n,false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int key: rooms[x]){
                if(!visited[key]){
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        for(bool idx: visited){
            if(idx == false) return false;
        }
        return true;
    }
};