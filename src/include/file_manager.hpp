#pragma once

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>



#define ARENA_ALLOCATION  2048

class FileDescriptorManage
{
 private:
  int m_openFile;
  const char *m_heapFile;
  ssize_t m_sizeFile;
  const char *m_nameFile;

 public:
  FileDescriptorManage();
  ~FileDescriptorManage();
  
  FileDescriptorManage(const FileDescriptorManage & p_manager);
  FileDescriptorManage operator=(const FileDescriptorManage &p_manager);  

  bool Open ( const char *p_path , int );
  const char *Read();
  ssize_t Size();
  const char* Buffer(); 
  ssize_t Write(const char *p_buffer, ssize_t p_size) noexcept;

};
