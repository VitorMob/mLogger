#pragma once

#include <string>
#include "file_manager.hpp"

#define WARNING "Warning: "
#define INFORMATION "Information: "
#define ABOUT "About: "

#define DEFAULT_NAME_LOGGER "mLogger.log"

class mLogger
{
 public:
  mLogger ( );
  explicit mLogger ( const char *__restrict__ = DEFAULT_NAME_LOGGER, bool = false );
  mLogger ( const std::string & = DEFAULT_NAME_LOGGER, bool  = false );
  ~mLogger();

  // functions for usage logging
  void mlogger_set_file ( const char *&__restrict__ );
  void mlogger_warning ( const std::string &, ... );
  void mlogger_information ( const std::string &, ... );
  void mlogger_about ( const std::string &, ... );
  void mlogger_load_log ( const char *&__restrict__   );

 private:
  std::string m_msg;
  bool in_memory;

  FileDescriptorManage m_fileLog;
};
