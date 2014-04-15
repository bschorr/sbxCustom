//
//  customType.cpp
//  example_custom_object
//
//  Created by Bernardo Santos Schorr on 4/15/14.
//
//

#include "sbxCustom.h"

namespace sbx {
    
    CUSTOM_TYPE::CUSTOM_TYPE (string _name, string _type, string _val) {
        
        name = _name;
        type = _type;
        _default = value = _val;
        
    }
    
    void CUSTOM_TYPE::loadType( string path ) {
        string loadModel = ofBufferFromFile(path);
        Json::Reader reader;
        reader.parse(loadModel, typeModel);
    }
    
    void CUSTOM_TYPE::setValue( Spacebrew::Message & m ) {
        if ( m.type == CUSTOM_TYPE_STR ){
            Json::Value v;
            Json::Reader reader;
            reader.parse(m.value, v);
            value = v.toStyledString();
        } else {
            "Type \"" + m.type + "\"" + " is not compatible!";
        }
    }
    
    bool CUSTOM_TYPE::getBool( string varName ) {

        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        return v[varName].asBool();
    }
    
    int CUSTOM_TYPE::getInt( string varName ) {
        
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        return v[varName].asInt();
    }
    
    float CUSTOM_TYPE::getFloat ( string varName ) {
        
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        return v[varName].asFloat();
        
    }
    
    string CUSTOM_TYPE::getString ( string varName ) {
        
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        return v[varName].asString();
        
    }
    
}