#include "include/mlogger.hpp"
#include <stdarg.h>

#define format(p_format , ...) va_list args; 

mLogger::mLogger()
{

}

mLogger::mLogger ( const char *__restrict__ p_path, bool p_in_memory )
{
  m_fileLog.Open ( p_path,  O_CREAT | O_RDWR );
}

mLogger::mLogger ( const std::string &p_path, bool p_in_memory )
{
  m_fileLog.Open ( p_path.data(), O_CREAT );
}

mLogger::~mLogger()
{

}

void mLogger::mlogger_warning ( const std::string &p_msg, ... )
{
  m_msg = WARNING + p_msg + '\n';
  m_fileLog.Write ( m_msg.data(), m_msg.size() );
}

void mLogger::mlogger_information ( const std::string &p_msg, ... )
{
  m_msg = INFORMATION + p_msg + '\n';
  format(m_msg, ...);
  m_fileLog.Write ( m_msg.data(), m_msg.size() );
}

void mLogger::mlogger_about ( const std::string &p_msg, ... )
{
  m_msg = ABOUT + p_msg + '\n';
  m_fileLog.Write ( m_msg.data(), m_msg.size() );
}

void mLogger::mlogger_load_log ( const char *&__restrict__ p_path )
{
  FileDescriptorManage fileLoad;

  fileLoad.Open ( p_path, O_RDONLY );
  m_fileLog.Write ( fileLoad.Read(), fileLoad.Size() );
}

void mLogger::mlogger_set_file ( const char *&__restrict__ p_path )
{
  m_fileLog.Open ( p_path, O_CREAT );
}
