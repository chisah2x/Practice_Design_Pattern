#include<iostream>
#include<memory>
#include <string>
#include <unordered_map>

using namespace std;

class Document
{
    public:
    virtual void fillContent(const string& content) = 0;
    virtual void print() = 0;
    virtual unique_ptr<Document> clone() const = 0;
};

class Resume : public Document
{
    private:
    string content;

    public:
    void fillContent(const string& text) override
    {
        content = "Resume: " + text;;
    }

    void print() override
    {
        cout << content << endl;
    }

    unique_ptr<Document> clone() const override
    {
        return make_unique<Resume>(*this);
    }
};

class Invoice : public Document
{
    private:
    string content;

    public:
    void fillContent(const string& text) override
    {
        content = "Invoice: " + text;;
    }

    void print() override
    {
        cout << content << endl;
    }

    unique_ptr<Document> clone() const override
    {
        return make_unique<Invoice>(*this);
    }
};

class DocumentFactory
{
     unordered_map<string, unique_ptr<Document>>  prototypes;

     public:
     void RegisterTemplate(const string& name, unique_ptr<Document> prototype)
     {
        prototypes[name] = move(prototype);
     }

     unique_ptr<Document> createDocument(string name) const{
        if(prototypes.find(name) != prototypes.end())
        {
            return prototypes.at(name)->clone();
        }
        throw runtime_error("Template not found");
     }
};

int main()
{
    DocumentFactory factory;
    factory.RegisterTemplate("resume", make_unique<Resume>());
    factory.RegisterTemplate("invoice", make_unique<Invoice>());

    auto myResume = factory.createDocument("resume");
    myResume->fillContent("Chirag, ML engineer");
    myResume->print();

    auto myInvoice = factory.createDocument("invoice");
    myInvoice->fillContent("Invoice #001, $500");
    myInvoice->print();
    return 0;
}