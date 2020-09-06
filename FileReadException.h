//
//  FileReadException.hpp
//  asa
//
//  Created by Sevilay Ozturk on 4/25/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//

#ifndef FileReadException_h
#define FileReadException_h
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string>

class FileReadException{
private:
    string err_message;
public:
    FileReadException(string message);
    string getMessage() const;
    
};



#endif /* FileReadException_hpp */
