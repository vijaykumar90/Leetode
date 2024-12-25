class ParkingSystem {
private:
    int bigspace;
    int mediumspace;
    int smallspace;
    int bigLimit = 0;
    int mediumLimit = 0;
    int smallLimit = 0;
public:
    ParkingSystem(int big, int medium, int small) {
        bigspace = big;
        mediumspace = medium;
        smallspace = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if (bigLimit<bigspace){
                bigLimit++;
                return true;
            }else{
                return false;
            }
        }else if(carType == 2){
            if (mediumLimit<mediumspace){
                mediumLimit++;
                return true;
            }else{
                return false;
            }
        }else if(carType == 3){
            if (smallLimit<smallspace){
                smallLimit++;
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
