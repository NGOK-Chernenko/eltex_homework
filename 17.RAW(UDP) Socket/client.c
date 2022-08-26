#include "header.h"

int main() {
  struct sockaddr_in servAddr;
  int socketFd = 0;

  socketFd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
  checkRes(&socketFd, "socket error");
  printf("|CLIENT| - socket ready\n");

  memset(&servAddr, 0, sizeof(struct sockaddr_in));

  servAddr.sin_family = AF_INET;
  servAddr.sin_port = htons(SERVER_PORT);
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

  datagramSent(socketFd, servAddr);

  close(socketFd);
  exit(EXIT_FAILURE);
}
