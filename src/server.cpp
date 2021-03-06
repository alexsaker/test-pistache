

#include "pistache/endpoint.h"

using namespace Pistache;

class HelloHandler : public Http::Handler
{
public:
    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Http::Request &request, Http::ResponseWriter response) override
    {
        UNUSED(request);
        response.send(Pistache::Http::Code::Ok, "Hello World\n");
    }
};

int main()
{
    int thr = 2;
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));
    auto opts = Http::Endpoint::options().threads(thr);
    Http::listenAndServe<HelloHandler>(addr, opts);
}
