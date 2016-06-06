/*
 * serverMain.c
 *
 *  Created on: 2016Äê6ÔÂ2ÈÕ
 *      Author: Ajun
 *      This is socketTest Server
 */
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main(){

	WSADATA wsaDATA;
	WORD sockVersion = MAKEWORD(2,0);
	if(WSAStartup(sockVersion,&wsaDATA)!=0){
		printf("Server sock initialization failed!\n");
		return -1;
	}
/*---------------------------UDP Server--------------------------*/
//	SOCKET serSock = socket(AF_INET,SOCK_DGRAM,0);
//
//	if(serSock == INVALID_SOCKET){
//		printf("Server sock creating failed!\n");
//		return 0;
//	}
//
//	SOCKADDR_IN serlLocal,destAddr;
//	memset(&serlLocal,0,sizeof(SOCKADDR_IN));
//	serlLocal.sin_family = AF_INET;
//	serlLocal.sin_port = htons(8000);
//	serlLocal.sin_addr.S_un.S_addr = INADDR_ANY;
//
//	destAddr.sin_family = AF_INET;
//	destAddr.sin_port = htons(8001);
//	destAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
//
//	if(bind(serSock,(SOCKADDR *)&serlLocal,sizeof(SOCKADDR))==SOCKET_ERROR){
//		printf("Server bind error!\n");
//		return -1;
//	}
//	//ioctlsocket(serSock,FIONBIO,0);                     /*set to block if non-block*/
//
//	int tv=10000;
//	setsockopt(serSock,SOL_SOCKET,SO_RCVTIMEO,(const char *)&tv,sizeof(tv));/*set timeout */
//
//	char buf[255];
//	SOCKADDR_IN sourceAddr;
//	int len;
//	int slen=sizeof(SOCKADDR_IN);
//	printf("waiting for client!\n");
//	while(1){
//	len=recvfrom(serSock,buf,255,0,(SOCKADDR *)&sourceAddr,&slen);
//	printf("LastError: %d\n",WSAGetLastError());
//	if(WSAGetLastError()==WSAETIMEDOUT) break;
//	printf("Received a package from: %s\n",inet_ntoa(sourceAddr.sin_addr));
//	buf[len]='\0';
//	printf("The Data Received: %s\n",buf);
//	sendto(serSock,buf,sizeof(buf),0,(SOCKADDR *)&destAddr,sizeof(SOCKADDR));
//
//	}
//	closesocket(serSock);

/*-------------------------------TCP Server---------------------------*/
	SOCKET sockfdLocal,sockfdRemote;
	SOCKADDR_IN localAddr,remoteAddr;

	if((sockfdLocal = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))<0){
		printf("sockServer creating failed!\n");
		return -1;
	}

	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(8000);
	localAddr.sin_addr.S_un.S_addr = INADDR_ANY;

//	FD_SET fdset;

	if(bind(sockfdLocal,(SOCKADDR *)&localAddr,sizeof(SOCKADDR))<0){
		printf("Bind error!\n");
		return -1;
	}

	listen(sockfdLocal,5);
	int len = sizeof(remoteAddr);
	if((sockfdRemote=accept(sockfdLocal,(SOCKADDR *)&remoteAddr,&len))<0){
		printf("Listen error!\n");
		return -1;
	}

	char Welstr[]="Welcome stranger!!!!";
	int slen;
	send(sockfdRemote,Welstr,strlen(Welstr),0);

	int recvSIZE=5;
	char sbuf[recvSIZE];

	while((slen = recv(sockfdRemote,sbuf,recvSIZE,0))>0){
		sbuf[slen]='\0';
		printf("Received from: %s\nReceived data: %s\n",inet_ntoa(remoteAddr.sin_addr),sbuf);
		printf("Last error: %d\nrecv return:%d\n",WSAGetLastError(),slen);
		send(sockfdRemote,sbuf,strlen(sbuf),0);
		}
	printf("Server process stopped!\n");
	closesocket(sockfdLocal);
	return 0;

}

