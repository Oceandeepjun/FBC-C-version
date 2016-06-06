/*
 * clientMain.c
 *
 *  Created on: 2016Äê6ÔÂ2ÈÕ
 *      Author: Ajun
 *      This is the socketTest client.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <errno.h>
typedef enum{ true,false}bool;
int main(){
	WORD wVersionRequested;
	WSADATA wsadata;

	int err;
	wVersionRequested = MAKEWORD(2,0);
	err = WSAStartup(wVersionRequested,&wsadata);
	/*--------------socket intialization check------------*/
	if(0!=err){
	}
	/*-------------------Version 2.0 check----------------*/
	if(LOBYTE(wsadata.wVersion)!=2||HIBYTE(wsadata.wVersion)!=2){
		WSACleanup();
		printf("Client Version check failed!\n");
		return -1;
	}


//	/*----------------------UDP Client--------------------*/
//	SOCKET  sock;     //usigined int
//
//	sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP); 		/*Creating*/
//	//sock = socket(AF_INET,SOCK_DGRAM,0)               /*This is  recommended
//
//	if(sock==INVALID_SOCKET){			                /*Creating check*/
//		printf("Client socket creating failed!\n");
//	}
//
////	bool opt = true;								    /*Set to broadcast*/
////	setsockopt(sock,);
//
//	SOCKADDR_IN destaddr;   //struct sockaddr_in
//	destaddr.sin_family = AF_INET;
//	destaddr.sin_port = htons(8000);
//	destaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
//
//	SOCKADDR_IN Localaddr;
//	Localaddr.sin_family=AF_INET;
//	Localaddr.sin_port = htons(8001);
//	Localaddr.sin_addr.S_un.S_addr = INADDR_ANY;
//	if(SOCKET_ERROR==bind(sock,(SOCKADDR *)&Localaddr,sizeof(SOCKADDR))){
//		printf("Bind error!\n");
//		return -1;
//	}
//
//	char szMsg[]="This is a UDP test package from client.";
//	char buf[255];
//	SOCKADDR_IN sourceAddr;
//	int len;
//	int slen=sizeof(SOCKADDR_IN);
//	int timeout=10000;
//	setsockopt(sock,SOL_SOCKET,SO_RCVTIMEO,(const char *)&timeout,sizeof(timeout));
//
//	while(1){
//	scanf("%s",szMsg);
//	if(!strcmp(szMsg,"quit")) break;
//	sendto(sock,szMsg,sizeof(szMsg),0,(SOCKADDR *)&destaddr,sizeof(destaddr));
//
//	if((len=recvfrom(sock,buf,255,0,(SOCKADDR *)&sourceAddr,&slen))<0){
//		printf("Client receive error!\n");
//		//return -1;
//	}
//	printf("LastError: %d\n",WSAGetLastError());
//	printf("Received a package from: %s\n",inet_ntoa(sourceAddr.sin_addr));
//	buf[len]='\0';
//	printf("The Data Received: %s\n",buf);
//	}
//
//	printf("Process quit!");
//	closesocket(sock);

/*-------------------------TCP Client----------------------------------*/
	SOCKET sockfdClient;
	SOCKADDR_IN destAddr;
	sockfdClient = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	destAddr.sin_family = AF_INET;
	destAddr.sin_port = htons(8000);
	destAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if(connect(sockfdClient,(SOCKADDR *)&destAddr,sizeof(destAddr))<0){
		printf("connect error!\n");
		return -1;
	}
	int recvSIZE=5;
	char cbuf[recvSIZE];
	int clen,clensum;
	char msg[255];

	int timeout=5000;
	setsockopt(sockfdClient,SOL_SOCKET,SO_RCVTIMEO,(const char *)&timeout,sizeof(timeout));

	while((clen = recv(sockfdClient,cbuf,recvSIZE,0))>0){
		clensum = clen;
		cbuf[clen]='\0';
		printf("Received data: %s",cbuf);
		printf("errno: %d\n",errno);
		while((clen = recv(sockfdClient,cbuf,recvSIZE,0))>0){
			clensum+=clen;
			cbuf[clen]='\0';
			printf("%s",cbuf);
		}
		printf("\n");
		printf("Last error: %d\nclensum:%d\n",WSAGetLastError(),clensum);
		printf("Inout msg:");
		scanf("%s",msg);
		if(strcmp(msg,"q")){
			send(sockfdClient,msg,strlen(msg),0);
		}
		else {
				printf("Process stop!\n");
				break;
			}
		}

//	while(1){
//		printf("Inout msg:");
//		scanf("%s",msg);
//		if(strcmp(msg,"q")){
//			send(sockfdClient,msg,strlen(msg),0);
//			clen = recv(sockfdClient,cbuf,255,0);
//			cbuf[clen]='\0';
//			printf("Received data: %s\n",cbuf);
//		}
//		else {
//			printf("Process stop!\n");
//			break;
//		}
//	}

	printf("Last error: %d\n",WSAGetLastError());
	closesocket(sockfdClient);
	return 0;
}
