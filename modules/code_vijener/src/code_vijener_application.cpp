// Copyright 2017 Korniakov Kirill

#include "include/code_vijener.h"
#include "include/code_vijener_application.h"

#include <string>
#include <regex>

CodeVijenerApplication::CodeVijenerApplication(): _message("") {}

std::string CodeVijenerApplication::operator()(int argc, const char **argv) {
  if (!validateArguments(argc, argv)) {
    return _message;
  }

  try {
    Code_vijener Code_vijener(argv[2], argv[3]);
    if (strcmp(argv[1], "encode") == 0) {
      return Code_vijener.Encoder();
    } else if (strcmp(argv[1], "decode") == 0) {
      return Code_vijener.Decoder();
    }
  } catch (std::string& str) {
    return str;
  }

  return "";
}

void CodeVijenerApplication::help(const char *appname, const char *message) {
  _message =
          std::string(message) +
          "This is a complex code vijener application.\n\n" +
          "Please provide arguments in the following format:\n\n"+
          " $ " + appname + " <encode|decode> <word> <key> \n\n.";
}

bool CodeVijenerApplication::validateArguments(int argc, const char **argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 4) {
    help(argv[0], "ERROR: Should be 3 arguments.\n\n");
    return false;
  }

  if (strcmp(argv[1], "encode") != 0 && strcmp(argv[1], "decode") != 0) {
    help(argv[0], "ERROR: Possible operations only encode or decode.\n\n");
    return false;
  }

  std::regex regex("[a-zA-Z]+");
  if (!std::regex_match(argv[2], regex) || !std::regex_match(argv[3], regex)) {
    help(argv[0], "ERROR: should be English characters only.\n\n");
    return false;
  }

  return true;
}
