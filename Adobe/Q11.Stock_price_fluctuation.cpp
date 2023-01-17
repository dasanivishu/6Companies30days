class StockPrice {
public:
    multiset<int>pric;//store price
    map<int,int>m;//[timestamp,price]

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(m.find(timestamp)!=m.end())
         pric.erase(pric.find(m[timestamp]));//delete one instance
        m[timestamp]=price;
        pric.insert(price);
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        return *pric.rbegin();
    }
    
    int minimum() {
        return *pric.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
