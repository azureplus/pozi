/*
 * main.cpp
 *
 *  Created on: 2014��8��23��
 *      Author: liuzhenhua
 */
#include "../include/ScheServer.h"

int main(){
    server::ScheServer server(6700,6704);
    server.execute();
	return 0;
}



