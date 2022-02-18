#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include "tcpserver/tcpserver.h"
#include "server.h"
#include "Table.h"

#define PORT 3331

using namespace std;

typedef map<string, bool (Table::*)(const string, ostream &) const> InstMap;

class RequestProcessor {
private:
    InstMap instructions;
    const Table *table{};
public:
    RequestProcessor(const Table *table);
    bool requestProcessing(string const &, string &) const;
};

RequestProcessor::RequestProcessor(const Table *table_) : table{table_} {
    instructions["findMedia"] = &Table::findMultimediaDisplay;
    instructions["findGroup"] = &Table::findGroupDisplay;
    instructions["play"] = &Table::showMedia;
}

bool RequestProcessor::requestProcessing(string const &request, string &response) const {

    stringstream ssRequest(request);
    
    string instruction, name;
    ssRequest >> instruction >> name;

    InstMap::const_iterator it = instructions.find(instruction);

    if (it != instructions.end()) {
        stringstream ssResponse;
        bool stat = (table->*(it->second))(name, ssResponse);
        cout << ssResponse.str();
        if (stat) {
            response = ssResponse.str();
        } else {
            response = "Target " + name + " not found!";
        }
    } else {
        response = "Instruction " + instruction + " not found!";
    }
    return true;
}

int startServer(const Table *table) {
    // create TCP server
    RequestProcessor requestProcessor(table);

    TCPServer *server = 
        new TCPServer([&](string const &request, string &response){
            return requestProcessor.requestProcessing(request, response);
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