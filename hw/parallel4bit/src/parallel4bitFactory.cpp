#include <stdint.h>
#include <stddef.h>
#include "iPinHw.hpp"
#include "iLcdHw.hpp"
#include "iParallel4bit.hpp"
#include "parallel4bit.hpp"

iParallel4bit * iParallel4bit::create(iPinHw * rs, iPinHw * e, iPinHw * db4, iPinHw * db5,
        iPinHw * db6, iPinHw * db7) 
{
    iParallel4bit * parallel4bit = new Parallel4bit(rs, e, db4, db5, db6, db7);
    return parallel4bit;
}