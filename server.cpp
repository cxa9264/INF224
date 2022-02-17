#include <string>
#include <iostream>
#include "tcpserver/tcpserver.h"
#include "server.h"

#define PORT 3331

using namespace std;

int startServer() {
    // create TCP server
    TCPServer *server = 
        new TCPServer([&](string const &request, string &response){
            // the request sent by the client to the server
            cout << "request: " << request << endl;
            // the response that the server sends back to the client
            response = "RECEIVED: " + request;
            // return false would close the connecytion with the client
            return true;
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