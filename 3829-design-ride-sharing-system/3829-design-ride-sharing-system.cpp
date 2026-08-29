class RideSharingSystem {
public:
    queue<int>riders;
    queue<int>drivers;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    // when there is no match
    vector<int> matchDriverWithRider() {
        if(!drivers.size() | !riders.size()){
            return{-1,-1};
        }
        int riderId=riders.front();
        riders.pop();
        int driverId=drivers.front();
        drivers.pop();
        return{driverId,riderId};
    }
    
    void cancelRider(int riderId) {
        vector<int> tempRiders;
        while(!riders.empty()){
            int rider= riders.front();
            riders.pop();
            if(rider==riderId) continue;
            tempRiders.push_back(rider);
        }
        for(int i : tempRiders){
            riders.push(i);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */