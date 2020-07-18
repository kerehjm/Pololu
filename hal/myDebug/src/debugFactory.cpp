#include "iUart.hpp"
#include "iDebug.hpp"
#include "myDebug.hpp"

iDebug * iDebug::create(eDebugLevel level)
{
    iDebug * debug = nullptr;
    iUart * uart = iUart::create();

    debug = new Debug(uart, level);
}