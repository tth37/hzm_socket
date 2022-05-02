#include <arpa/inet.h>
#include <hzm_socket/hello.hpp>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>



int main() {

  // create a socket server
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    std::cerr << "socket error" << std::endl;
    return -1;
  }
  // bind
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8888);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  int ret = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (ret == -1) {
    std::cerr << "bind error" << std::endl;
    return -1;
  }
  // listen
  ret = listen(server_fd, 5);
  if (ret == -1) {
    std::cerr << "listen error" << std::endl;
    return -1;
  }
  // accept
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_fd == -1) {
    std::cerr << "accept error" << std::endl;
    return -1;
  }
  // recv
  hzm::Hello hello;
  ret = recv(client_fd, &hello, sizeof(hello), 0);
  if (ret == -1) {
    std::cerr << "recv error" << std::endl;
    return -1;
  }
  // send
  hello.set_name("hzm");
  ret = send(client_fd, &hello, sizeof(hello), 0);
  if (ret == -1) {
    std::cerr << "send error" << std::endl;
    return -1;
  }

  while (1) {

  }




  // create a socket client
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    std::cerr << "socket error" << std::endl;
    return -1;
  }
  // bind
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  // connect
  int ret = connect(client_socket, (struct sockaddr *)&server_addr,
                    sizeof(server_addr));
  if (ret < 0) {
    std::cerr << "connect error" << std::endl;
    return -1;
  }
  // send


  return 0;
}