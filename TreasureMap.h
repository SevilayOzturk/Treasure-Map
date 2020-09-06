//
//  TreasureMap.hpp
//  asa
//
//  Created by Sevilay Ozturk on 4/25/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//

#ifndef TreasureMap_h
#define TreasureMap_h
#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
class TreasureMap{
private:
    T *steps;
    int current_step;
    int total_steps;
    int max_steps;
public:
    TreasureMap(){
        total_steps = 0;
        current_step = 0;
        max_steps = 10;
        steps = new T[max_steps];
    }
    TreasureMap(int nMax_steps){
        total_steps = 0;
        current_step = 0;
        max_steps = nMax_steps;
        steps = new T[max_steps];
        
    }
    T* getSteps(){
        return steps;
    }
    
    int getCurrentStep(){
        return current_step;
    }
    int getTotalSteps(){
        return total_steps;
    }
    void addStep(T element){
        if(total_steps == max_steps){
            cout << "Cannot add more steps, TreasureMap is full" << endl;
            return;
        }
        
        steps[total_steps] = element;
        total_steps +=1;
        
    }
    void removeStep(int index){
        
        if(index < 0 || index > total_steps -1)
            cout << "Cannot remove step, invalid index" << endl;
        
        for(int x= index; x < total_steps -1 ; x++)
            steps[x] = steps[x+1];
        total_steps -= 1;
        
           
    }
    void nextStep(){
        if(current_step == total_steps -1){
            cout << "Cannot goto next step, treasure has already been found!" << endl;
            return;
        }
        current_step+=1;
        cout <<"Going from "<< steps[current_step-1] << " to "  << steps[current_step] << endl;
        if(current_step == total_steps-1){
            cout<<"Congratulations, you have found the treasure!"<< endl;
        }
                    
    }
    void backtrack(){
        if(current_step == 0){
            cout << "Cannot backtrack, you're at the very first step!" << endl;
            return;
        }
         current_step-=1;
               cout <<"Backtracking from "<< steps[current_step+1] << " to " << steps[current_step] << endl;
        
    }
    TreasureMap operator + (TreasureMap &treasuremap){
        if(total_steps != treasuremap.total_steps){
            cout << "Cannot add map due to mismatching number of steps" << endl;
            TreasureMap <T> newmap;
            return newmap;
        }
            TreasureMap<T> map(max_steps);
            map.total_steps = total_steps;
            for(int y =0; y < total_steps; y++){
                map.steps[y] = steps[y] + treasuremap.steps[y];
            
                }
            return map;
    }
    bool operator==(const TreasureMap &treasuremap){
            if(total_steps != treasuremap.total_steps){
            return false;
            }
            for(int i =0; i< total_steps; i++){
                if(steps[i] != treasuremap.steps[i]){
                    return false;
                }
            }
            return true;
    }
};



#endif /* TreasureMap_hpp */
