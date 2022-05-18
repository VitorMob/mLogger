#pragma once

#include <string>
#include "file_manager.hpp"
#include "arena.hpp"

#define WARNING "\033[43;1;37mWarning:\033[0;000m "
#define INFORMATION "\033[46;1;37mInformation:\033[0;000m "
#define ABOUT "\033[47;1;37mAbout:\033[0;000m "
#define ERROR "\033[41;1;37mError:\033[0;000m "
#define SUCESS "\033[42m\033[42mSUCESS:\033[0;000m "


#define DEFAULT_NAME_LOGGER "mLogger.log"

class mLogger
{
 public:
  mLogger();
  explicit mLogger ( const char * = DEFAULT_NAME_LOGGER, int = O_WRONLY | O_APPEND, bool = false );
  mLogger ( const std::string & = DEFAULT_NAME_LOGGER, int = O_WRONLY | O_APPEND, bool = false );
  ~mLogger();

  // functions for usage logging
  void mlogger_set_file ( const char *&, int = O_WRONLY | O_APPEND );
  const char *mlogger_warning ( const std::string & );
  const char *mlogger_information ( const std::string & );
  const char *mlogger_about ( const std::string & );
  const char *mlogger_error ( const std::string & );
  const char *mlogger_sucess ( const std::string & );
  void mlogger_load_log ( const char*& );

 private:
  bool m_in_memory;
  Arena fast;


  FileDescriptorManage m_fileLog;
};
