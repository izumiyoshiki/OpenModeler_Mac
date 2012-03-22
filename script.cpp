#include "script.h"
std::string Script::script = "";

Script::Script(const char *filename)
{
    HSQUIRRELVM v;
    v = sq_open(1024); // creates a VM with initial stack size 1024

    //REGISTRATION OF STDLIB
    //sq_pushroottable(v); //push the root table where the std function will be registered
    //sqstd_register_iolib(v);  //registers a library
    // ... call here other stdlibs string,math etc...
    //sq_pop(v,1); //pops the root table
    //END REGISTRATION OF STDLIB

    sqstd_seterrorhandlers(v); //registers the default error handlers

    sq_setprintfunc(v, printFunc, errorFunc); //sets the print function

    sq_pushroottable(v); //push the root table(were the globals of the script will be stored)
    if(SQ_SUCCEEDED(sqstd_dofile(v, _SC(filename), SQFalse, SQTrue))) // also prints syntax errors if any
    {
        call_foo(v,1,2.5,_SC("teststring"));
    }
    else
    {
        script = "path error!";
    }

    sq_pop(v,1); //pops the root table
    sq_close(v);
}

void Script::printFunc(HSQUIRRELVM v,const SQChar *s,...)
{
    switch (sq_gettype(v, -2)) {
        case OT_INTEGER:
            SQInteger  ret;
            sq_getinteger(v, -2, &ret);
            sq_pop(v, 1);
            script += ret;
            break;
        case OT_FLOAT:
            SQFloat  fret;
            sq_getfloat(v, -2, &fret);
            sq_pop(v, 1);
            script += fret;
            break;
        case OT_STRING:
            const SQChar *cret;
            sq_getstring(v, -1, &cret);
            sq_pop(v, 1);
            script += cret;
            break;
        case OT_TABLE:
            break;
        case OT_ARRAY:
            break;
        case OT_USERDATA:
            break;
        case OT_CLOSURE:
            break;
        case OT_NATIVECLOSURE:
            break;
        case OT_GENERATOR:
            break;
        case OT_USERPOINTER:
            break;
        case OT_BOOL:
            break;
        case OT_THREAD:
            break;
        case OT_FUNCPROTO:
            break;
        case OT_CLASS:
            break;
        case OT_WEAKREF:
            break;
        case OT_OUTER:
            break;
        case OT_NULL:
            break;
        case OT_INSTANCE:
            break;

//        default:
            //return sq_throwerror(v, "invalid param"); // 例外を投げる    }
    }

}

void Script::errorFunc(HSQUIRRELVM v,const SQChar *s,...)
{
    va_list vl;
    va_start(vl, s);
    scvprintf(stderr, s, vl);
    va_end(vl);
}

void Script::call_foo(HSQUIRRELVM v, int n,float f,const SQChar *s)
{
    SQInteger top = sq_gettop(v); //saves the stack size before the call
    sq_pushroottable(v); //pushes the global table
    sq_pushstring(v,_SC("foo"),-1);
    if(SQ_SUCCEEDED(sq_get(v,-2))) { //gets the field 'foo' from the global table
        sq_pushroottable(v); //push the 'this' (in this case is the global table)
        sq_pushinteger(v,n);
        sq_pushfloat(v,f);
        sq_pushstring(v,s,-1);
        sq_call(v,4,SQFalse,SQTrue); //calls the function
    }
    sq_settop(v,top); //restores the original stack size
}
