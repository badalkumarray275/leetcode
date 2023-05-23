class FrequencyTracker {
public:
    
    map<int,int>count;
    map<int,int>freq;
    
    FrequencyTracker() {
        
        
        
    }
    
    void add(int number) {
        
        count[number]++;
        if(count[number]>0)
        {
            freq[count[number]-1]--;
        }
        freq[count[number]]++;
    }
    
    void deleteOne(int number) {
        
        
        if(count[number]==0) return ;
        freq[count[number]]--;
        count[number]--;
        if(count[number]>0)
            freq[count[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        
        return freq[frequency];
        
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */