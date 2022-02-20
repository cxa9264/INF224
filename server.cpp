#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include "tcpserver/tcpserver.h"
#include "Server.h"
#include "Table.h"


#define PORT 3331

using namespace std;

typedef map<string, bool (Table::*)(const string, ostream &) const> InstConstMap;
typedef map<string, bool (Table::*)(const string, ostream &)> InstEditMap;

class RequestProcessor {
private:
    InstConstMap constInstructions;
    InstEditMap editInstructions;
    Table *table{};
public:
    RequestProcessor(Table *table);
    bool requestProcessing(string const &, string &) const;
};

RequestProcessor::RequestProcessor(Table *table_) : table{table_} {
    constInstructions["findMedia"] = &Table::findMultimediaDisplay;
    constInstructions["findGroup"] = &Table::findGroupDisplay;
    constInstructions["play"] = &Table::showMedia;
    editInstructions["deleteGroup"] = &Table::removeGroup;
    editInstructions["deleteMedia"] = &Table::removeMultimedia;
}

bool RequestProcessor::requestProcessing(string const &request, string &response) const {

    stringstream ssRequest(request);
    
    string instruction, name = "", buffer;
    ssRequest >> instruction >> name;
    while (ssRequest >> buffer) {
        name = name + " " + buffer;
    }
    
    InstConstMap::const_iterator itConst = constInstructions.find(instruction);
    InstEditMap::const_iterator itEdit = editInstructions.find(instruction);

    if (itConst != constInstructions.end()) {
        stringstream ssResponse;
        bool stat = (table->*(itConst->second))(name, ssResponse);
        cout << ssResponse.str();
        if (stat) {
            response = ssResponse.str();
            replace(response.begin(), response.end(), '\n', '>');
        } else {
            response = "Target " + name + " not found!";
        }
    } else if (itEdit != editInstructions.end()) {
        stringstream ssResponse;
        bool stat = (table->*(itEdit->second))(name, ssResponse);
        cout << ssResponse.str();
        if (stat) {
            response = ssResponse.str();
            replace(response.begin(), response.end(), '\n', '>');
        } else {
            response = "Target " + name + " not found!";
        }
    } else {
        response = "Instruction " + instruction + " not found!";
    }
    return true;
}

int startServer(Table *table) {
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