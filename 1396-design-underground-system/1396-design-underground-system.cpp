class UndergroundSystem {
    
    private : unordered_map<int,pair<string,int>>checkInn;
              unordered_map<string, pair<double, int>> avg;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInn[id] = { stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
   
        string name = checkInn[id].first  + " " + stationName;
        double interval = t - checkInn[id].second;
        avg[name].first += interval;
        avg[name].second++;
    }
   
    
    double getAverageTime(string startStation, string endStation) {
        string str =  startStation + " " + endStation;
        return avg[str].first/avg[str].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */