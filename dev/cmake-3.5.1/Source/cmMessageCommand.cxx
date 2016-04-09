/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#include "cmMessageCommand.h"

// cmLibraryCommand
bool cmMessageCommand
::InitialPass(std::vector<std::string> const& args, cmExecutionStatus &)
{
  if(args.size() < 1 )
    {
    this->SetError("called with incorrect number of arguments");
    return false;
    }
  std::vector<std::string>::const_iterator i = args.begin();

  cmake::MessageType type = cmake::MESSAGE;
  bool status = false;
  bool fatal = false;
  cmake* cm = this->Makefile->GetCMakeInstance();
  if (*i == "SEND_ERROR")
    {
    type = cmake::FATAL_ERROR;
    ++i;
    }
  else if (*i == "FATAL_ERROR")
    {
    fatal = true;
    type = cmake::FATAL_ERROR;
    ++i;
    }
  else if (*i == "WARNING")
    {
    type = cmake::WARNING;
    ++i;
    }
  else if (*i == "AUTHOR_WARNING")
    {
    if (cm->GetDevWarningsAsErrors(this->Makefile))
      {
      fatal = true;
      type = cmake::AUTHOR_ERROR;
      }
    else if (!cm->GetSuppressDevWarnings(this->Makefile))
      {
      type = cmake::AUTHOR_WARNING;
      }
    else
      {
      return true;
      }
    ++i;
    }
  else if (*i == "STATUS")
    {
    status = true;
    ++i;
    }
  else if (*i == "DEPRECATION")
    {
    if (cm->GetDeprecatedWarningsAsErrors(this->Makefile))
      {
      fatal = true;
      type = cmake::DEPRECATION_ERROR;
      }
    else if (!cm->GetSuppressDeprecatedWarnings(this->Makefile))
      {
      type = cmake::DEPRECATION_WARNING;
      }
    else
      {
      return true;
      }
    ++i;
    }

  std::string message = cmJoin(cmMakeRange(i, args.end()), std::string());

  if (type != cmake::MESSAGE)
    {
    // we've overriden the message type, above, so force IssueMessage to use it
    this->Makefile->IssueMessage(type, message, true);
    }
  else
    {
    if (status)
      {
      this->Makefile->DisplayStatus(message.c_str(), -1);
      }
    else
      {
      cmSystemTools::Message(message.c_str());
      }
    }
  if(fatal)
    {
    cmSystemTools::SetFatalErrorOccured();
    }
  return true;
}

