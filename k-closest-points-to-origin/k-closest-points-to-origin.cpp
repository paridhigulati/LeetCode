
    /*Since we can do operator overloading on user defined objects so create a class Point and do< opeartor overloading to sort elements in priority queue using distance formula. Please read comments for more explanation.

* Point class, used to overload 
* operator< for used defined object of 
* class Point.
*/
class Point {
  public:
    int x;
    int y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

/*
* Opeartor< overloading -> when this(<) operator is 
* used to compare two objects in priority queue
* it will compare based on distance formula 
* if (x1*x1 y1*y1) > (x2*x2 + y2*y2) means first point
* is more near to origion than second point
*/
bool operator<(const Point &v1, const Point &v2){
    return (v1.x * v1.x + v1.y * v1.y) > (v2.x * v2.x + v2.y * v2.y);
}
    
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        /*
        * Put all points in priority queue
        */
        priority_queue<Point> pq;
        for(int i=0;i<points.size();i++){
            pq.push(Point(points[i][0], points[i][1]));
        }
        
        /*
        * Add top k elements from priority queue to 
        * ans vector
        */
        vector<vector<int>>  ans;
        int i = 0;
        while(i++ < k) {
            // Add point to ans vector by constructing a vector
            vector<int> temp = {pq.top().x, pq.top().y};
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};