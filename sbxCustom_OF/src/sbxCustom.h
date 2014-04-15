//
//  customType.h
//  example_custom_object
//
//  Created by Bernardo Santos Schorr on 4/15/14.
//
//

#pragma once

//this is where we put in the name of our custom type and variables it will use. Remember to use the same name in testApp/ofApp!
#define CUSTOM_TYPE custom

//ugly hack to stringify preprocessor constants
#define STR1(x) #x
#define STR2(x) STR1(x)
#define CUSTOM_TYPE_STR STR2(CUSTOM_TYPE)

#include "ofMain.h"
#include "ofxSpacebrew.h"

namespace sbx {
    
    class CUSTOM_TYPE : public Spacebrew::Message {
    public:
        
        //constructor
        CUSTOM_TYPE( string _name="", string _type=CUSTOM_TYPE_STR, string _val="");
        
        void loadType ( string path );
        
        //setting the values
        template <typename T>
        void setValue ( string varName, T incomingValue ) {
            Json::Value v;
            Json::Reader reader;
            reader.parse(value, v);
            
            if (typeModel.isMember(varName)) {
                v[varName] = incomingValue;
                value = v.toStyledString();
            } else {
                cout << "Variable \"" + varName + "\"" + " is not a member of this custom type!" << endl;
            }
        }
        
        //setting them from incoming message
        void setValue ( Spacebrew::Message & m );
    
        //getting values for sbx object
        bool getBool( string varName );
        int getInt( string varName );
        float getFloat( string varName );
        string getString( string varName );
        
    private:
        
        Json::Value typeModel;
        
    };

}