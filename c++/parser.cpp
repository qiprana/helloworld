#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <list>

using namespace std;

void DEBUG(string str){
  //  cout<<str<<endl;
}

string queryHRML(map<string,string> tagMap, string input){
    map<string,string>::iterator itr = tagMap.find(input);
     if(itr == tagMap.end())
         return "Not Found!";
    else
        return tagMap[input];
} 

void splitStr(vector<string>& splitVector, string attributes){
    DEBUG("To process:"+attributes);
    
    string data = "";
    for(int i= 0; i< attributes.length(); i++){
        if(attributes[i] == ' ' ){ // end of line of a space, push to vector
           splitVector.push_back(data);
           data="";
        }else if (i == attributes.length()-1){// reading the last char{
            data = data + attributes[i];
            splitVector.push_back(data);
        }else{
          data = data + attributes[i]; // keep reading
        }
        
    }
    //print vector
    for(int j = 0; j<splitVector.size();j++){
        DEBUG(splitVector[j]);
   
    }
    DEBUG("\n");
    //cout<<endl;
}

void processHRML(vector<string>& tagNames, map<string,string>& tagMap, string input){
      string rawInput = input.substr(1,input.length()-2); // strip off  < and >
      DEBUG("RawInput:"+rawInput);  
      
      //tag1 value = "HelloWorld" value2 = "xyz"
      size_t pos = rawInput.find_first_of(' ');
      
      if( pos == string::npos){
          // no attributes. just the tag name. Add to tagNames list
          tagNames.push_back(rawInput);   
      }else{
          // get the tag name and move on to attributes.
          string tag = rawInput.substr(0,pos);
          DEBUG("Tag:"+tag);
          
          //put it to tagNames 
          tagNames.push_back(tag);
          
          // process remaining str her: [value = "HelloWorld" value2 = "xyz"]
          vector<string> splitVector;
          splitStr(splitVector, rawInput.substr(pos+1));
          //time to put the key - value pait
          string key,value;
          for(int i= 0; i<splitVector.size()/3;i++){
              string tmpkey = splitVector[i*3];
              string tmpvalue = splitVector[(i*3)+2];
              
              
              //construct the key - concatenation of all the tagNames with ".", followed by ~
              //tag1.tag2~name
              string key = tagNames[0]; // assuming there is atleast one tag name.
              for(int j = 1; j <tagNames.size();j++ ){
                  key = key + "."+tagNames[j]; 
              }
              // add a ~ and the tmpKey to make thefinal key
              key = key + "~" + tmpkey;
              DEBUG("Key = "+key+"\n");
              //construct the value - strip off the quotes
              value = tmpvalue.substr(1,tmpvalue.length()-2);
              DEBUG("Value = " + value + "\n");
              //addd to map
              tagMap[key] = value;
          }
          
          
      }
    
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numLines, numQueries;
    cin >> numLines >> numQueries;
    string input;
    map<string,string> tagMap;
    //key format tag1.tag2~name
    string tagName;
    vector<string> tagNames;
    for(int i = 0; i< numLines; i++){
        getline(cin>>std::noskipws>>std::ws, input);
        DEBUG("Input:"+input);
        
        //if not end of tag, process the line and add to tagMap and list of tags seen so far
        if(input[0] == '<' && input[1] == '/'){
           //else if end of tag, remove last tag from list.
           if(tagNames.size()>=1){
               tagNames.pop_back();
           }
        }else{
          processHRML(tagNames, tagMap, input); // process the input line and put into hash map
        } 
        
    }
    
    for(int j = 0; j< numQueries; j++){
        getline(cin>>std::noskipws>>std::ws, input);
        DEBUG("Input:"+input);
       
        cout<<queryHRML(tagMap, input)<<endl; // read from hash map and print
    }
    return 0;
}


