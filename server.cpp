#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include "tcpserver/tcpserver.h"
#include "server.h"
#include "Table.h"

#define PORT 3331

using namespace std;
typedef map<string, function<bool(const string, ostream &)> > InstMap;

class RequestProcessor {
private:
    InstMap instructions;
public:
    RequestProcessor();
    bool requestProcessing(string const &, string &) const;
};

RequestProcessor::RequestProcessor() {
    instructions["findMedia"] = Table::findMultimediaDisplay;
    instructions["findGroup"] = Table::findGroupDisplay;
    instructions["play"] = Table::showMedia;
}

bool RequestProcessor::requestProcessing(string const &request, string &response) const {

    stringstream ssRequest(request);
    
    string instruction, name;
    ssRequest >> instruction >> name;

    InstMap::const_iterator it = instructions.find(instruction);
    if (it != instructions.end()) {
        stringstream ssResponse;
        bool stat = it->second(name, ssResponse);
        if (stat) {
            response = ssResponse.str();
        }
    } else {
        return false;
    }
}

int startServer() {
    // create TCP server
    RequestProcessor requestProcessor;

    TCPServer *server = 
        new TCPServer([&](string const &request, string &response){
            return requestProcessor.requestProcessing(reqeust, response);
        });
    
    // start loop
    cout << "Starting server on port " << PORT << endl;

    int status = server->run(PORT);

    if (status < 0) {
        cerr << "Could not start server on port " << PORT << endl;
        return 1;
    }
    return 0;
}