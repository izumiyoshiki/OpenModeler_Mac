#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>
#include <stdarg.h>
#include <stdio.h>

#include <include/squirrel.h>
#include <include/sqstdio.h>
#include <include/sqstdaux.h>

#ifdef SQUNICODE

#define scvprintf vfwprintf
#else

#define scvprintf vfprintf
#endif

class Script
{
private:
    static std::string script;
public:
    Script(const char *filename);
    static void printFunc(HSQUIRRELVM v,const SQChar *s,...);
    static void errorFunc(HSQUIRRELVM v,const SQChar *s,...);
    void call_foo(HSQUIRRELVM v, int n,float f,const SQChar *s);
    std::string getScript(){return script;}
};
#endif // SCRIPT_H
