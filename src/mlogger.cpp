#include "include/mlogger.hpp"

mLogger::mLogger()
{
}

mLogger::mLogger(const char *p_path, int p_flags, bool p_in_memory) : m_in_memory(p_in_memory)
{
  if (p_in_memory)
    fast.realloc(sysconf(_SC_PAGESIZE));
  else
    m_fileLog.Open(p_path, p_flags);
}

mLogger::mLogger(const std::string &p_path, int p_flags, bool p_in_memory) : m_in_memory(p_in_memory)
{
  if (p_in_memory)
    fast.realloc(sysconf(_SC_PAGESIZE));
  else
    m_fileLog.Open(p_path.data(), p_flags);
}

mLogger::~mLogger()
{
}

const char *mLogger::mlogger_warning(const std::string &p_msg)
{
  int lenght = p_msg.size() + sizeof(WARNING);
  const char *warning = WARNING;

  char *msg = (char *)fast.req(lenght);

  strncpy(msg, warning, lenght);
  strncat(msg, p_msg.c_str(), lenght);

  if (!m_in_memory)
    m_fileLog.Write(msg, lenght);

  return msg;
}

const char *mLogger::mlogger_information(const std::string &p_msg)
{
  int lenght = p_msg.size() + sizeof(INFORMATION);
  const char *information = INFORMATION;

  char *msg = (char *)fast.req(lenght);

  strncpy(msg, information, sizeof(INFORMATION));
  strncat(msg, p_msg.c_str(), lenght);

  if (!m_in_memory)
    m_fileLog.Write(msg, lenght);

  return msg;
}

const char *mLogger::mlogger_about(const std::string &p_msg)
{
  int lenght = p_msg.size() + sizeof(ABOUT);
  const char *about = ABOUT;

  char *msg = (char *)fast.req(lenght);

  strncpy(msg, about, sizeof(ABOUT));
  strncat(msg, p_msg.c_str(), lenght);

  if (!m_in_memory)
    m_fileLog.Write(msg, lenght);

  return msg;
}

const char *mLogger::mlogger_error(const std::string &p_msg)
{
  int lenght = p_msg.size() + sizeof(ERROR);
  const char *error = ERROR;

  char *msg = (char *)fast.req(lenght);

  strncpy(msg, error, sizeof(ERROR));
  strncat(msg, p_msg.c_str(), lenght);

  if (!m_in_memory)
    m_fileLog.Write(msg, lenght);

  return msg;
}

const char *mLogger::mlogger_sucess(const std::string &p_msg)
{
  int lenght = p_msg.size() + sizeof(SUCESS);
  const char *error = SUCESS;

  char *msg = (char *)fast.req(lenght);

  strncpy(msg, error, sizeof(SUCESS));
  strncat(msg, p_msg.c_str(), lenght);

  if (!m_in_memory)
    m_fileLog.Write(msg, lenght);

  return msg;
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