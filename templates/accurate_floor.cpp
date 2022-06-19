auto accurateFloor = [&] (int a, int b){
    if(a >= 0) return a/b; 
    else return (a-b+1)/b;
    // while(val*b > a) val--;
    // return val;
};