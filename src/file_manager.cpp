#include "include/file_manager.hpp"
#include "include/arena.hpp"

#include <sys/stat.h>
#include <stdexcept>

#if DEBUG
  #include <iostream>
#endif

Arena m_fast(ARENA_ALLOCATION);

FileDescriptorManage::FileDescriptorManage() : m_openFile ( 0 ),
                                               m_heapFile ( nullptr ),
                                               m_sizeFile ( 0 ),
                                               m_nameFile ( nullptr )
{
}

FileDescriptorManage::~FileDescriptorManage()
{
  if ( m_openFile >  0 )
    close ( m_openFile );
}

FileDescriptorManage::FileDescriptorManage(const FileDescriptorManage &p_manager) 
{
  m_openFile = p_manager.m_openFile;  
  m_heapFile = p_manager.m_heapFile;
  m_sizeFile = p_manager.m_sizeFile;  
  m_nameFile = p_manager.m_nameFile;
}

FileDescriptorManage FileDescriptorManage::operator=(const FileDescriptorManage &p_manager)
{
  m_openFile = p_manager.m_openFile;
  m_heapFile = p_manager.m_heapFile;
  m_sizeFile = p_manager.m_sizeFile;  
  m_nameFile = p_manager.m_nameFile;

  return *this;
}

bool FileDescriptorManage::Open ( const char *p_path , int p_mode)
{
  bool status_exit = false;

  if ( m_openFile > 0 )
    close ( m_openFile );

  m_openFile = open ( p_path, p_mode );
  struct stat statusFile;

  if ( m_openFile > 0 )
  {
    fstat ( m_openFile, &statusFile );
    m_sizeFile = statusFile.st_size;
    m_nameFile = p_path;
    status_exit = true;
  }

  return status_exit;
}

const char *FileDescriptorManage::Read()
{
  if ( m_openFile <= 0 )
    return nullptr;

  m_heapFile = ( char * ) m_fast.req ( m_sizeFile );

  if ( m_heapFile == nullptr )
  {
    m_fast.dell();
    m_heapFile = ( char * ) m_fast.req ( m_sizeFile );
  }

#if DEBUG
  std::cout << "[DEBUG]\n\t File: " << m_nameFile <<
            "\n\t Requests Memory: " <<  m_sizeFile << " Bytes\n" <<
              "\t Arena Free: " << m_fast.afree() << " Bytes\n";
#endif

  read ( m_openFile, (void*)m_heapFile, m_sizeFile );

  return m_heapFile;
}

ssize_t FileDescriptorManage::Write(const char* p_buffer, ssize_t p_size) noexcept
{
  if(m_openFile <= 0)
    std::runtime_error("File not opened, verify if file open sucess");
  
  return write(m_openFile, p_buffer, p_size);
}

ssize_t FileDescriptorManage::Size()
{
  return m_sizeFile;
}

const char *FileDescriptorManage::Buffer()
{
  return m_heapFile;
}
