#pragma once
#include <string>
using namespace std;


class URI {
    string protocol;
    string host;
    string path;

public:
    URI(string protocol, string host, string path) : 
        protocol(protocol),
        host(host),
        path(path)
    {}

    string str() const {
        return protocol + "://" + host + path;
    }   
};