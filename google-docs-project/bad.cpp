#include<bits/stdc++.h>
using namespace std;

class DocumentEditor{
    public:
    vector<string> documentElements ;  
    DocumentEditor(){} ; 
    void addText(string text){
        documentElements.push_back(text) ;
    }
    void addImage(string path){
        documentElements.push_back(path) ;
    }
    void renderDoc(){
        for(int i = 0 ; i<documentElements.size() ; i++){
            if(documentElements[i].length()>4 && documentElements[i].substr(documentElements[i].length()-4) == ".png" || documentElements[i].substr(documentElements[i].length()-4) == ".jpg"){
                cout<<"Image: "<<documentElements[i]<<endl;
            }
            else{
                cout<<"Text: "<<documentElements[i]<<endl;

            }
        }
    }
    void saveDoc(){
        cout<<"File open"<<endl ; 
        cout<<"File saved"<<endl ;
        cout<<"File closed"<<endl ;
    }
} ; 

// client side part 
int main(){
    DocumentEditor doc ;
    doc.addText("Hello") ;
    doc.addImage("image.png") ;
    doc.renderDoc() ;
    doc.saveDoc() ;
}