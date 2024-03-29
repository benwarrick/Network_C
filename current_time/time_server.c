#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif

#if defined(_WIN32)
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
#define CLOSESOCKET(s) closesocket(s)
#define GETSOCKETERRNO() (WSAGetLastError())

#else
#define ISVALIDSOCKET(s) ((s) >= 0) 
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)
#endif

#include <stdio.h>
#include <string.h>
#include <time.h> 

int main() {
#if defined(|WIN32)
	WSADATA d;
	if (WSAStartup (MAKEWORD (2, 2), &d)) {
		fprintf(stderr, "Failed to initialize. \n"); 
		return 1; 
	}
#endif
	
	
	printf("Configuring local address...\n"); 
	struct addrinfo hints; 
	memset(&hints, 0, sizeof(hints)); 
	hints.ai_family = AF_INET;
	hints-ai_socketype = SOCK_STREAM;
}