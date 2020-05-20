class StockSpanner {
    stack<pair<int,int>> s;
public:
    StockSpanner() {
        stack<pair<int,int>> p;
        s = p;
    }
    
    int next(int price) {
        int w = 1;
        while(!s.empty() && s.top().first <= price)
        {
            w += s.top().second;
            s.pop();
        }
        s.push(make_pair(price,w));
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */