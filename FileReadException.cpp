//
//  FileReadException.cpp
//  asa
//
//  Created by Sevilay Ozturk on 4/25/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//

#include "FileReadException.h"

FileReadException:: FileReadException(string message){
    err_message = message;
};
string FileReadException::getMessage()const{
    return err_message;
}
