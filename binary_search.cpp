//
// Created by Asif Muztaba on 12/2/2021.
// Author URI www.asifmuztaba.com
//
#include <iostream>
class BinarySearch{
private:
    int arr[10],n,item;
public:
    bool result=false;
    BinarySearch() {
        std::cout<<"Enter the array size";
        std::cin>>n;
        std::cout<<"Enter the array items with spaces";
        for(int i=0;i< this->n;i++){
            std::cin>> this->arr[i];
        }
        std::cout<<"Enter the search term";
        std::cin>>item;
        this->sort_array();
        if(this->binary_search_core(0,item,n)) result= true;
    }
    void sort_array(){
        for(int i=0;i<= this->n-1;i++){
            for(int j=0;j<=(this->n-2);j++){
                if(this->arr[j]>this->arr[j+1]){
                    int temp=this->arr[j];
                    this->arr[j]=this->arr[j+1];
                    this->arr[j+1]=temp;
                }
            }
        }
    }
    bool binary_search_core(int start, int item, int last){
        int mid=(start+last)/2;
        if(item==arr[mid]) return true;
        if(mid>this->n) return false;
        for(int i=start; i<=last;i++){
            if(item<this->arr[mid]){
                this->binary_search_core(start,item, mid-1);
            } else{
                this->binary_search_core(mid+1,item,last);
            }
        }
        return false;
    }

};
int main (){
    BinarySearch b;
    if(b.result){
        std::cout<<"Number Found";
    } else{
        std::cout<<"Number Not Found";
    }
    return 0;
}
