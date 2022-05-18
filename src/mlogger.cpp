#include "include/mlogger.hpp"

#include <iostream>

mLogger::mLogger()
{
}

mLogger::mLogger(const char *p_path, int p_flags, bool p_in_memory) : m_in_memory(p_in_memory)
{
  m_fileLog.Open(p_path, p_flags);
  if (p_in_memory)
  {
    fast.realloc(sysconf(_SC_PAGESIZE));
  }
}

mLogger::mLogger(const std::string &p_path, int p_flags, bool p_in_memory) : m_in_memory(p_in_memory)
{
  m_fileLog.Open(p_path.data(), p_flags);
}

mLogger::~mLogger()
{
}

void mLogger::mlogger_warning(const std::string &p_msg)
{
  int lenght = p_msg.size() + sizeof(WARNING);
  const char *warning =  WARNING;

  char *msg = (char *)fast.req(lenght);

  strcpy(msg, warning);
  strcat(msg, p_msg.c_str());

  if (!m_in_memory)
    m_fileLog.Write(msg, lenght);
  else
    std::cout << msg  << '\n';
}

void mLogger::mlogger_information(const std::string &p_msg)
{
  int lenght = p_msg.size() + sizeof(INFORMATION);
  const char *information = INFORMATION;

  char *msg = (char *)fast.req(lenght);

  strcpy(msg, information);
  strcat(msg, p_msg.c_str());

  if (!m_in_memory)
    m_fileLog.Write(msg, lenght);
  else
    std::cout << msg << '\n';
}

void mLogger::mlogger_about(const std::string &p_msg)
{
  int lenght = p_msg.size() + sizeof(ABOUT);
  const char *about = ABOUT;

  char *msg = (char *)fast.req(lenght);

  strcpy(msg, about);
  strcat(msg, p_msg.c_str());

  if (!m_in_memory)
    m_fileLog.Write(msg, lenght);
  else
    std::cout << msg << '\n';
}

void mLogger::mlogger_error(const std::string &p_msg)
{
  int lenght = p_msg.size() + sizeof(ERROR);
  const char *error = ERROR;

  char *msg = (char *)fast.req(lenght);

  strcpy(msg, error);
  strcat(msg, p_msg.c_str());

  if (!m_in_memory)
    m_fileLog.Write(msg, lenght);
  else
    std::cout << msg << '\n';
}

void mLogger::mlogger_load_log(const char *&p_path)
{
  FileDescriptorManage fileLoad;

  fileLoad.Open(p_path, O_RDONLY);
  m_fileLog.Write(fileLoad.Read(), fileLoad.Size());
}

void mLogger::mlogger_set_file(const char *&p_path, int p_flags)
{
  m_fileLog.Open(p_path, p_flags);
}