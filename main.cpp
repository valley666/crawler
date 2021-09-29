#include <iostream>
#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

using namespace std;

int main() {
    // initialize RestClient
    RestClient::init();

    // get a connection object
    RestClient::Connection* conn = new RestClient::Connection("https://www.google.com");
    //RestClient::Connection* conn = new RestClient::Connection("baidu.com");

    // configure basic auth
    //conn->SetBasicAuth("WarMachine68", "WARMACHINEROX");
    conn->SetProxy("http://192.168.88.237:10809");

    // set connection timeout to 5s
    conn->SetTimeout(5);

    // set custom user agent
    // (this will result in the UA "foo/cool restclient-cpp/VERSION")
    conn->SetUserAgent("PostmanRuntime/7.28.4");

    // enable following of redirects (default is off)
    conn->FollowRedirects(true);
    // and limit the number of redirects (default is -1, unlimited)
    conn->FollowRedirects(true, 3);

    // set headers
    RestClient::HeaderFields headers;
    //headers["Accept"] = "application/json";
    conn->SetHeaders(headers);

    // append additional headers
    //conn->AppendHeader("X-MY-HEADER", "foo");

    // if using a non-standard Certificate Authority (CA) trust file
    //conn->SetCAInfoFilePath("/etc/custom-ca.crt");

    RestClient::Response response = conn->get("/search?q=book");
    //RestClient::Response response = conn->get("/");
    if(response.code != 200)
    {
        //cout <<
        return -1;
    }

    std::cout << response.body << std::endl;
    //RestClient::Response r = conn->head("/get");
    //RestClient::Response r = conn->del("/delete");
    //RestClient::Response r = conn->options("/options");

    // set different content header for POST, PUT and PATCH
    //conn->AppendHeader("Content-Type", "application/json");
    //RestClient::Response r = conn->post("/post", "{\"foo\": \"bla\"}");
    //RestClient::Response r = conn->put("/put", "application/json", "{\"foo\": \"bla\"}");
    //RestClient::Response r = conn->patch("/patch", "text/plain", "foobar");
}
