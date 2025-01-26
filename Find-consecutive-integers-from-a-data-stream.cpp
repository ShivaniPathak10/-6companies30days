class DataStream {
public:
    int size,lastUm,value,k;
    
    DataStream(int value, int k) {
       this->value=value;
       this->k=k;

       size=0;
       lastUm=-1;   
    }
    
    bool consec(int num) {
        size++;
        if(num!=value)
         lastUm=size-1;

         if(size>=k && (size-k)>lastUm){
            return true;
         }
         return false;                                                       
    }
};


/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */