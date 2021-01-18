#pragma once

#ifndef __GET_RAND_H__
#define __GET_RAND_H__

#include <stdint.h>


extern "C"
{
	void get_rand_data(void* data, uint32_t datalen);
}




#endif //__GET_RAND_H__

