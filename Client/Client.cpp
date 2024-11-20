#include "pch.h"
#include "Client.h"
#include "MyNexus.h"
#include <memory>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    std::shared_ptr<MyNexus> myNexus = std::make_shared<MyNexus>();
    myNexus->ignite(hInstance, lpCmdLine, nCmdShow);
    _CrtDumpMemoryLeaks();
}