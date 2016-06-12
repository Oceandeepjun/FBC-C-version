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

void printReturnInfo(SOCKET sckfd,char *buf, int bufSize);

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
	if(LOBYTE(wsadata.wVersion)!=2||HIBYTE(wsadata.wVersion)!=0){
		WSACleanup();
		printf("Client Version check failed!\n");
		return -1;
	}


//	/*--------------------------------UDP Client----------------------------------------*/
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
//	SOCKET sockfdClient;
//	SOCKADDR_IN destAddr;
//	sockfdClient = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
//	destAddr.sin_family = AF_INET;
//	destAddr.sin_port = htons(8000);
//	destAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
//
//	if(connect(sockfdClient,(SOCKADDR *)&destAddr,sizeof(destAddr))<0){
//		printf("connect error!\n");
//		return -1;
//	}
//	int recvSIZE=5;
//	char cbuf[recvSIZE];
//	int clen,clensum;
//	char msg[255];
//
//	int timeout=5000;
//	setsockopt(sockfdClient,SOL_SOCKET,SO_RCVTIMEO,(const char *)&timeout,sizeof(timeout));
//
//	while((clen = recv(sockfdClient,cbuf,recvSIZE,0))>0){
//		clensum = clen;
//		cbuf[clen]='\0';
//		printf("Received data: %s",cbuf);
////		printf("errno: %d\n",errno);
//		while((clen = recv(sockfdClient,cbuf,recvSIZE,0))>0){
//			clensum+=clen;
//			cbuf[clen]='\0';
//			printf("%s",cbuf);
//		}
//		printf("\n");
//		printf("Last error: %d\nclensum:%d\n",WSAGetLastError(),clensum);
//		printf("Inout msg:");
//		scanf("%s",msg);
//		if(strcmp(msg,"q")){
//			send(sockfdClient,msg,strlen(msg),0);
//		}
//		else {
//				printf("Process stop!\n");
//				break;
//			}
//		}
//
//	printf("Last error: %d\n",WSAGetLastError());
//	closesocket(sockfdClient);

/*-------------------------------FTP Client-------------------------------------*/
//	SOCKET ftpfd,rftpfd;
//	struct sockaddr_in ftpcaddr;
////	HOSTENT *hp;
//
//	memset(&ftpcaddr,0,sizeof(struct sockaddr_in));
//	ftpfd = socket(AF_INET,SOCK_STREAM,0);
////	hp = gethostbyname("WIN-S739H01RFKO");
//	ftpcaddr.sin_family = AF_INET;
//	ftpcaddr.sin_port = htons(21);
//	ftpcaddr.sin_addr.S_un.S_addr = inet_addr("192.168.9.235");
//
////	printf("%s\n%s\n%s\n",hp->h_name,hp->h_addr_list[0],*(hp->h_aliases));
////	memcpy(&ftpcaddr.sin_addr.S_un.S_addr,hp->h_addr_list[0],hp->h_length);
////	char *str;
////	str = inet_ntoa(ftpcaddr.sin_addr);
////	printf("%s\n",str);
//	if(connect(ftpfd,(SOCKADDR *)&ftpcaddr,sizeof(ftpcaddr))<0){
//		printf("error\n");
//		return -1;
//	}
//
//	int BUFSIZE=100;
//	char rbuf[BUFSIZE];
//	char wbuf[BUFSIZE];
//	printReturnInfo(ftpfd,rbuf,BUFSIZE);
//
//	char uname[] = "ftpuser";
//	char pswd[]  = "123456_aA";
//
//	sprintf(wbuf,"USER %s\r\n",uname);			/*USER send the username*/
//	send(ftpfd,wbuf,strlen(wbuf),0);
//	printReturnInfo(ftpfd,rbuf,BUFSIZE);
//
//	sprintf(wbuf,"PASS %s\r\n",pswd);			/*PASS send the password*/
//	send(ftpfd,wbuf,strlen(wbuf),0);
//	printReturnInfo(ftpfd,rbuf,BUFSIZE);
//
//	sprintf(wbuf,"PASV\r\n");					/*PASV set to passive mode*/
//	send(ftpfd,wbuf,strlen(wbuf),0);
//	printReturnInfo(ftpfd,rbuf,BUFSIZE);
//	int ipaddr[6];
//	sscanf(rbuf,"%*[^(](%d,%d,%d,%d,%d,%d)",ipaddr,ipaddr+1,ipaddr+2,ipaddr+3,ipaddr+4,ipaddr+5);
////	printf("%d.%d.%d.%d.%d\n",ipaddr[0],ipaddr[2],ipaddr[3],ipaddr[4],ipaddr[5]);
//
//	u_short portToRead = ipaddr[4]*256+ipaddr[5];
//	ftpcaddr.sin_port = htons(portToRead);
//	rftpfd = socket(AF_INET,SOCK_STREAM,0);
//
//	if(connect(rftpfd,(SOCKADDR *)&ftpcaddr,sizeof(ftpcaddr))<0){		/*connect to the data stream socket*/
//		 printf("Data stream connection failed!\n");
//		 return -1;
//	}
//	sprintf(wbuf,"CWD %s\r\n","test");
//	send(ftpfd,wbuf,strlen(wbuf),0);
//	printReturnInfo(ftpfd,rbuf,BUFSIZE);
//
//	sprintf(wbuf,"SIZE %s\r\n","ftp.txt");
//	send(ftpfd,wbuf,strlen(wbuf),0);
//	printReturnInfo(ftpfd,rbuf,BUFSIZE);
//
//	sprintf(wbuf,"RETR %s\r\n","ftp.txt");
//	send(ftpfd,wbuf,strlen(wbuf),0);
//	printReturnInfo(ftpfd,rbuf,BUFSIZE);
//
//	FILE *fp = fopen("ftp.txt","wt+");
//
//	int dataLen;
//	int i=0;
//	while((dataLen = recv(rftpfd,rbuf,BUFSIZE,0))>0){
//		i++;
//		rbuf[dataLen]='\0';
//		fputs(rbuf,fp);
//	}
//	printf("i=%d\n",i);
//	fclose(fp);
//	closesocket(rftpfd);
//	printReturnInfo(ftpfd,rbuf,BUFSIZE);
//
//	sprintf(wbuf,"QUIT\r\n");
//	send(ftpfd,wbuf,strlen(wbuf),0);
//	printReturnInfo(ftpfd,rbuf,BUFSIZE);
//	closesocket(ftpfd);

	system("ftp -i -n -s:af.bat");

	return 0;

}

void printReturnInfo(SOCKET sckfd,char *buf, int bufSize){
	int rlen;
	rlen = recv(sckfd,buf,bufSize,0);
	printf("last error:%d\n",WSAGetLastError());
	buf[rlen] = '\0';
	printf("%s\n",buf);
}
