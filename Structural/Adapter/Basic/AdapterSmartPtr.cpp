#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

// 1. Target interface expected by the client
class IReports {
public:
    virtual string getJsonData(const string& data) = 0;
    virtual ~IReports() {}
};

// 2. Adaptee: provides XML data from a raw input
class XmlDataProvider {
public:
    string getXmlData(const string& data) {
        size_t sep = data.find(':');
        if (sep == string::npos) {
            throw invalid_argument("Invalid input format. Expected 'name:id'");
        }
        string name = data.substr(0, sep);
        string id   = data.substr(sep + 1);
        return "<user><name>" + name + "</name><id>" + id + "</id></user>";
    }
};

// 3. Adapter: implements IReports by converting XML → JSON
class XmlDataProviderAdapter : public IReports {
private:
    shared_ptr<XmlDataProvider> xmlProvider;
public:
    XmlDataProviderAdapter(shared_ptr<XmlDataProvider> provider) : xmlProvider(provider) {}

    string getJsonData(const string& data) override {
        string xml = xmlProvider->getXmlData(data);

        size_t startName = xml.find("<name>") + 6;
        size_t endName   = xml.find("</name>");
        size_t startId   = xml.find("<id>") + 4;
        size_t endId     = xml.find("</id>");

        if (startName == string::npos || endName == string::npos ||
            startId == string::npos || endId == string::npos) {
            throw runtime_error("Malformed XML");
        }

        string name = xml.substr(startName, endName - startName);
        string id   = xml.substr(startId, endId - startId);

        return "{\"name\":\"" + name + "\", \"id\":" + id + "}";
    }
};

// 4. Client code works only with IReports
class Client {
public:
    void getReport(shared_ptr<IReports> report, const string& rawData) {
        try {
            cout << "Processed JSON: " << report->getJsonData(rawData) << endl;
        } catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }
};

// 5. Main function
int main() {
    auto xmlProv = make_shared<XmlDataProvider>();
    auto adapter = make_shared<XmlDataProviderAdapter>(xmlProv);

    Client client;

    client.getReport(adapter, "Alice:42");        // ✅ Valid
    client.getReport(adapter, "Bob42");           // ❌ Invalid, no ':'

    return 0;
}
