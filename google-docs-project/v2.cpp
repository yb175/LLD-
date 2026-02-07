// this is a better design following SOLID Principles 
#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
    public : 
    virtual void render() = 0 ;
    virtual ~DocumentElement() = default;
} ; 
class TextElement : public DocumentElement{
    public : 
    string text ;
    TextElement(string text){
        this->text = text ;
    }
    void render() override{
        cout<<"Text: "<<text<<endl ;
    }

} ; 

class ImageElement : public DocumentElement{
    public : 
    string path ; 
    ImageElement(string path){
        this->path = path ;  
    }
    void render() override{
        cout<<"Image: "<<path<<endl ; 
    }
} ; 

class NewLineElement : public DocumentElement{
    public : 
    void render() override{
        cout<<endl ; 
    }
} ; 

class TabElement : public DocumentElement{
    public : 
    void render() override{
        cout<<"\t" ; 
    }
} ; 
class Document {
    public : 
    vector<DocumentElement*> DocumentElements ; 
    void add(DocumentElement* element ){
        DocumentElements.push_back(element) ; 
    }
    void render(){
        for(int i = 0 ; i<DocumentElements.size();i++){
            DocumentElements[i]->render() ; 
        }
    }
    ~Document(){
        for(int i = 0 ; i<DocumentElements.size();i++){
            delete DocumentElements[i] ; 
        }
    }
} ; 

class DbPersistence{
    public : 
    virtual void save()=0 ; 
    virtual ~DbPersistence() = default;
};

class SaveToDb : public DbPersistence{
    public : 
    void save() override{
        cout<<"Document saved to db"<<endl ; 
    }
};
int main(){
    Document d ; 
    DbPersistence* mongoDB ; 
    mongoDB = new SaveToDb() ; 
    d.add(new TextElement("foo bar")) ; 
    d.add(new NewLineElement()) ;
    d.add(new ImageElement("image.jpg")) ; 
    d.add(new TabElement()) ;
    d.render() ; 
    mongoDB->save() ; 
    delete mongoDB ;
    return 0 ; 
}